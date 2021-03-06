#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo/photo.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <cvimagewidget.h>

#include <QScrollBar>
#include <QThread>
#include <QClipboard>
#include <QStandardPaths>
#include <QVector>




static int red_line[3] = {220,20,60};
static int green_line[3] = {50,205,50};
static int blue_line[3] = {65,105,255};
static int purple_line[3] = {128,0,128};
static int orange_line[3] = {255,165,0};
static int pink_line[3] = {255,105,180};
static int yellow_line[3] = {255,255,0};
static int black_line[3] = {0,0,0};
static int white_line[3] = {255,255,255};
static int length_line[4] = {-1,-1,-1,-1};
static int angle_line[6] = {-1,-1,-1,-1,-1,-1};
static float intensity_line[3] = {-1,-1,0.0};
static int crop_box_line[2] = {-1,-1};
static int box_grab = 0;
QVector<int> intensity_profile;

QString settings_file = "./settings.ini";

int CROP_BOX_SIZE = DEFAULT_CROP_BOX_SIZE;
int PREVIEW_FPS = DEFAULT_PREVIEW_FPS;
float MM_PER_PIXEL = DEFAULT_MM_PER_PIXEL;
int INTENSITY_LINE_LENGTH = DEFAULT_INTENSITY_LINE_LENGTH;


eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    //detect screen resolution and set starting size
    int set_width;
    int set_height;
    QRect screen_dimension = QApplication::desktop()->screenGeometry();
    if (screen_dimension.width() <= 1366)
    {
        set_width = 1300;
    }else if (screen_dimension.width() <= 1680){
        set_width = 1500;
    }else{
        set_width = 1700;
    }
    if (screen_dimension.height() <= 768){
        set_height = 700;
    }else if (screen_dimension.height() <=900){
        set_height = 800;
    }else{
        set_height = 980;
    }

    this->setGeometry(QRect(10,40,set_width,set_height));


    //hide the camera controls which are not yet functional
    ui->gain_slider->setHidden(true);
    ui->label_gain->setHidden(true);
    ui->spin_gain->setHidden(true);
    ui->exposure_slider->setHidden(true);
    ui->label_exposure->setHidden(true);
    ui->spin_exposure->setHidden(true);

    read_setting_values();  //get saved settings from ini file

    preview_timer = new QTimer(this);

    //QDir::setCurrent(QDir::currentPath());      //set the starting path for the files
    QStringList doc_path = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    QDir::setCurrent(doc_path[0]);  //set my documents as default folder


    set_combo_line_colour();        //set icon and entries for combo_line_colour on process tab

    connect(preview_timer, SIGNAL(timeout()), this, SLOT(update_video()));
    //set scrollbars to centre captured image when zoom level changes
    connect(ui->scrollArea_Capture->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_vertical_capture(int,int)));
    connect(ui->scrollArea_Capture->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_horizontal_capture(int,int)));
    //set scrollbars to centre process image when zoom level changes
    connect(ui->scrollArea_Analyse->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_vertical_analyse(int,int)));
    connect(ui->scrollArea_Analyse->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_horizontal_analyse(int,int)));
    //set image manipulation slots
    connect(ui->check_background, SIGNAL(stateChanged(int)),this, SLOT(apply_smooth_bg()));
    connect(ui->check_bw, SIGNAL(stateChanged(int)), this, SLOT(apply_manipulations()));
    connect(ui->check_gaussian, SIGNAL(stateChanged(int)), this, SLOT(apply_smooth_bg()));
    connect(ui->spin_gauss, SIGNAL(valueChanged(int)), this, SLOT(apply_smooth_bg()));
    connect(ui->check_invert, SIGNAL(stateChanged(int)), this, SLOT(apply_manipulations()));
    connect(ui->slider_low_point, SIGNAL(valueChanged(int)), this, SLOT(threshold_low()));
    connect(ui->spin_low_point, SIGNAL(editingFinished()), this, SLOT(threshold_low()));
    connect(ui->slider_high_point, SIGNAL(valueChanged(int)), this, SLOT(threshold_high()));
    connect(ui->spin_high_point, SIGNAL(editingFinished()), this, SLOT(threshold_high()));
    //connect sliders and spinners
    connect(ui->slider_low_point, SIGNAL(valueChanged(int)), ui->spin_low_point, SLOT(setValue(int)));
    connect(ui->spin_low_point, SIGNAL(valueChanged(int)), ui->slider_low_point, SLOT(setValue(int)));
    connect(ui->slider_high_point, SIGNAL(valueChanged(int)), ui->spin_high_point, SLOT(setValue(int)));
    connect(ui->spin_high_point, SIGNAL(valueChanged(int)), ui->slider_high_point, SLOT(setValue(int)));
    connect(ui->rotate_slider, SIGNAL(sliderMoved(int)), this, SLOT(change_rotate_spinbox(int)));
    //connect(ui->rotate_slider, SIGNAL(valueChanged(int)), this, SLOT(change_rotate_spinbox(int)));
    connect(ui->rotate_spinbox, SIGNAL(valueChanged(double)), this, SLOT(change_rotate_slider(double)));

    //populate combo box showing the attached camera devices
    int cam_no = 0;
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = QCamera::deviceDescription(deviceName);  //for reading in actual camera type
        cam_no = cam_no + 1;
        QString cam_no_str = QString::number(cam_no);
        ui->device_list->addItem("Detector " + cam_no_str); //use to fill combo box with detector number in place of camera
        //ui->device_list->addItem(description);    //used to fill combo box with actual camera type
    }


    if (ui->device_list->currentIndex() != -1)              //ignore if no cameras connected
    {
        set_camera(ui->device_list->currentIndex());        //use selected camera in list
        preview_timer->start(1000/PREVIEW_FPS);      //gets the preview video working
        }
    int index_c = ui->zoom_setting->findText("Fit");          //set default zoom to 'fit to window'
    int index_p = ui->zoom_setting_process->findText("Fit");  //same for the process tab window
    ui->zoom_setting->setCurrentIndex(index_c);
    ui->zoom_setting_process->setCurrentIndex(index_p);
    ui->combo_line_thickness->setCurrentIndex(1);           //set default line thickness to 2 pixels

}

eVBL::~eVBL()
{
    delete ui;
}

void eVBL::on_evbl_tabs_currentChanged(int index)   //make changes when new main tab selected
{
    //qDebug() << "evbl tab change";
    switch(index)
    {
    case 0:
        //start camera preview
        if (ui->device_list->currentIndex() != -1)          //ignore if no cameras connected
        {
            preview_timer->start(1000/PREVIEW_FPS);  //gets the preview video working
        }
        break;
    case 1:
        //stop preview camera
        preview_timer->stop();
        break;
    default:
        break;
    }

}

void eVBL::update_video()  //update preview video window. Called from timer function every EVBL_PREVIEW_WINDOW_REFRESH milliseconds
{
    videoCapture.read(preview_frame);
    //avoid camera crash
    cv::Size s = preview_frame.size();
    if (s.height == 0 || s.width == 0){
        return; //exit if image not aquired properly
    }
    cv::resize(preview_frame,output_preview,cv::Size(EVBL_PREVIEW_WINDOW_WIDTH,EVBL_PREVIEW_WINDOW_HEIGHT),0,0,cv::INTER_LINEAR);
    ui->previewVideo->showImage(output_preview);
}

void eVBL::on_capture_frame_button_clicked()      //take single shot from camera
{

    //qDebug() << "take shot";
    if (ui->device_list->currentIndex() == -1){return;}   //ignore if no cameras connected

    //remove background logo
    ui->capture_picture->setVisible(0);

    preview_frame.copyTo(buffered_snapshot);
    display_capture(buffered_snapshot);

}

void eVBL::read_setting_values()    //read in ini file values
{

    QSettings settings(settings_file, QSettings::IniFormat);
    CROP_BOX_SIZE = settings.value("General/crop_box_size",DEFAULT_CROP_BOX_SIZE).toInt();
    PREVIEW_FPS = settings.value("General/preview_fps",DEFAULT_PREVIEW_FPS).toInt();
    MM_PER_PIXEL = settings.value("General/mm_per_pixel",DEFAULT_MM_PER_PIXEL).toFloat();
    INTENSITY_LINE_LENGTH = settings.value("General/intensity_line_length",DEFAULT_INTENSITY_LINE_LENGTH).toInt();
    intensity_profile.resize(INTENSITY_LINE_LENGTH);

    apply_overlay_lines();
}

void eVBL::on_multi_frame_button_clicked()   //take multiple series of shots and average them
{
    //qDebug() << "multi shot";
    if (ui->device_list->currentIndex() == -1){return;}   //ignore if no cameras connected
    preview_timer->stop();
    this->setCursor(Qt::WaitCursor);
    int frames = ui->spin_multi->value();
    cv::Mat averaged_image;
    cv::Mat float_image;

    //remove background logo
    ui->capture_picture->setVisible(0);

    display_capture(preview_frame);
    ui->multishot_status->setText("Shot 1");
    preview_frame.convertTo(float_image,CV_32F);
    averaged_image = float_image/frames;
    for(int i = 2; i <= frames; i++)
    {
        update_video();
        ui->multishot_status->setText("Shot " + QString::number(i));
        //qDebug() << i;
        //display_capture(preview_frame);
        preview_frame.convertTo(float_image,CV_32F);
        averaged_image += float_image/frames;
    }

    ui->multishot_status->setText("Displaying");
    averaged_image.convertTo(buffered_snapshot,CV_8U);
    display_capture(buffered_snapshot);

    preview_timer->start();
    ui->multishot_status->setText("Done!");
    this->setCursor(Qt::ArrowCursor);

    //qDebug() << "pew pew...";
}


void eVBL::display_capture(cv::Mat display) //resize and store to buffer image captured from camera
{
    //qDebug() << "display capture";
    if (display.empty() == true)
    {
        //qDebug() << "empty frame";
        return;
    }


    float val;
    QString str_val = ui->zoom_setting->currentText();
    if (str_val == "Fit")
    {
        float width_scale = (ui->scrollArea_Capture->width()-4) / videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
        float height_scale = (ui->scrollArea_Capture->height()-4) / videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
        if (width_scale <= height_scale)
        {
            val = width_scale;
        }
        else
        {
            val = height_scale;
        }

    }
    else
    {
        QString strip_val = str_val.replace("%","");
        val = strip_val.toFloat() / 100.0 ;
    }
    cv::Mat output_display;
    cv::resize(display,output_display,cv::Size(),val,val,cv::INTER_LINEAR);

    float image_width = videoCapture.get(CV_CAP_PROP_FRAME_WIDTH) * val;
    float image_height = videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT) * val;

    ui->captured_display->setMinimumSize(image_width,image_height);
    ui->captured_display->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    ui->captured_display->showImage(output_display);

}

void eVBL::set_camera(int index)    //set the camera parameters when new camera selected
{
    //qDebug() << "set camera";
    if(index == -1)
    {
        //qDebug() << "no camera";
        return;
    }
    videoCapture.open(index);//(ui->device_list->currentIndex());
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 10000);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 10000);

    //initialise exposure and gain settings
    //qDebug() << "auto" << videoCapture.get(CV_CAP_PROP_AUTO_EXPOSURE);
    //videoCapture.set(CV_CAP_PROP_AUTO_EXPOSURE,0.0);
    //qDebug() << "auto" << videoCapture.get(CV_CAP_PROP_AUTO_EXPOSURE);
    //set_exposure = videoCapture.get(CV_CAP_PROP_EXPOSURE);
    //set_gain = videoCapture.get(CV_CAP_PROP_GAIN);
    //qDebug() << videoCapture.get(CV_CAP_PROP_EXPOSURE);
    //qDebug() << videoCapture.get(CV_CAP_PROP_GAIN);
    QString image_height = QString::number(videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT));
    QString image_width = QString::number(videoCapture.get(CV_CAP_PROP_FRAME_WIDTH));
    ui->label_resolution->setText("Size: " + image_width + " x " + image_height + " pixels");

}

void eVBL::on_device_list_currentIndexChanged(int index)    //change used camera when selected
{
    //qDebug() << "camera change";
    videoCapture.release();
    set_camera(index);

}

void eVBL::on_zoom_setting_currentIndexChanged()    //resice capture displayed image on zoom change
{
    if(buffered_snapshot.empty() == false)
    {
    display_capture(buffered_snapshot);
    }
}

void eVBL::on_zoom_setting_process_currentIndexChanged()    //resize analyse displayed image on zoom change
{
    apply_overlay_lines(); //display_analyse(manipulated_image);
}

void eVBL::on_save_image_button_clicked()   //save buffered captured camera image
{
    if(buffered_snapshot.empty())
    {
        return;
    }
    //stop preview timer
    preview_timer->stop();

    //get text to create auto filename
    QString initials = ui->info_initials->text();
    QString school = ui->info_school->text();
    QString distance = ui->info_distance->text();
    QString object = ui->combo_object->currentText();
    QString object_number = ui->combo_objectnumber->currentText();
    QString wavelength = ui->combo_wavelength->currentText();

    //check all field are filled
    if((initials == "")||(school == "")||(distance == ""))
    {
        QStringList errors;
        if(initials == ""){errors << "initials";}
        if(school == ""){errors << "school";}
        if(distance == ""){errors << "distance";}
        QString error_message;
        switch(errors.size())
        {
        case 1:
            error_message = "You haven't filled out the " + errors[0] + " field!";
            break;
        case 2:
            error_message = "You haven't filled out the " + errors[0] + " or " + errors[1] + " fields!!";
            break;
        case 3:
            error_message = "you haven't filled out the " + errors[0] + ", " + errors[1] + " or " + errors[2] + " fields!!!";
            break;
        default:
            error_message = "Something strange happened...";
            break;
        }
        //qDebug() << error_message;
        QMessageBox input_error;
        input_error.setText(error_message + "\nDo you still want to continue saving the image?");
        input_error.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        input_error.setDefaultButton(QMessageBox::No);
        int reply = input_error.exec();

       if(reply == QMessageBox::No)
        {
           //start preview camera again
           if (ui->device_list->currentIndex() != -1)          //ignore if no cameras connected
            {
               preview_timer->start(1000/PREVIEW_FPS);  //gets the preview video working
            }
            return;
        }
    }

    QString auto_name = school + "_" + initials + "_" + object + "_" + wavelength + "_" + distance + "_" + object_number;
    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",QDir::currentPath() + "/" + auto_name,tr("Tiff (*.tif);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = savefilename.toUtf8();
    const char *cv_filesave = ba.data();
    if (savefilename.isEmpty())
     {
        //start preview camera again
        if (ui->device_list->currentIndex() != -1)          //ignore if no cameras connected
         {
            preview_timer->start(1000/PREVIEW_FPS);  //gets the preview video working
         }
        return;
    }

    //qDebug() << cv_filesave;
    cv::imwrite(cv_filesave,buffered_snapshot);
    //start preview camera again
    if (ui->device_list->currentIndex() != -1)          //ignore if no cameras connected
    {
        preview_timer->start(1000/PREVIEW_FPS);  //gets the preview video working
    }


}

void eVBL::recentre_vertical_capture(int min_bar, int max_bar)  //cntre capture scroll bar
{
    Q_UNUSED(min_bar);
    //set scroll bar to centre
    ui->scrollArea_Capture->verticalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_horizontal_capture(int min_bar, int max_bar)    //centre capture scroll bar
{
    Q_UNUSED(min_bar);
    //set scrollbar to centre
    ui->scrollArea_Capture->horizontalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_vertical_analyse(int min_bar, int max_bar)  //cetre analyse scroll bar
{
    Q_UNUSED(min_bar);
    //set scroll bar to centre
    ui->scrollArea_Analyse->verticalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_horizontal_analyse(int min_bar, int max_bar)    //centre analyse scroll bar
{
    Q_UNUSED(min_bar);
    //set scrollbar to centre
    ui->scrollArea_Analyse->horizontalScrollBar()->setValue(max_bar/2);

}

void eVBL::change_rotate_slider(double val)                         //change double value of rotate spinbox when slider moved
{
    intensity_line[2] = val * PI / 180;
    draw_intensity_line();
    double set_val = val * 10.0;
    //qDebug() << "slider set" << set_val;
    ui->rotate_slider->setValue(set_val);
}

void eVBL::change_rotate_spinbox(int val)                           //change int value of rotate slider when spinbox changed
{
    double set_val = static_cast<double>(val) / 10.0;
    //qDebug() << "spin set" << set_val;
    ui->rotate_spinbox->setValue(set_val);
}

void eVBL::on_open_analysis_button_clicked()    //open image file to be analysed in process tab
{
    QString loadfilename = QFileDialog::getOpenFileName(this,"Open Image",QDir::currentPath(),tr("Tiff (*.tif *.tiff);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = loadfilename.toUtf8();
    const char *cv_fileload = ba.data();
    if (loadfilename.isEmpty()){return;}

    //remove background logo if active
    ui->analyse_picture->setVisible(0);


    //set file as analyse_image
    analyse_image_saved = cv::imread(cv_fileload,CV_LOAD_IMAGE_COLOR);
    //send to add smooth_background for smoothing and background before display
    check_background_size();
    apply_smooth_bg();

    //create copy for analyse overlay
    analyse_image_saved.copyTo(analyse_overlay);
    QFile file(loadfilename);
    QFileInfo fileInfo(file.fileName());
    QString fileout(fileInfo.fileName());

    ui->label_loaded_file->setText(fileout);
    cv::Size s = analyse_image_saved.size();
    ui->label_resolution_process->setText("Size: " + QString::number(s.width) + " x " + QString::number(s.height) + " pixels");
    reset_crop_box();
    reset_intensity_line();

    if(ui->anal_type_tab->currentIndex() == 2)  //if intensity
    {
        draw_intensity_line();
    }
    if(ui->anal_type_tab->currentIndex() == 3)  //if crop box
    {
        draw_crop_box();
    }

}

void eVBL::on_background_button_clicked()   //load background file and apply to picture if box checked
{
    QString loadfilename = QFileDialog::getOpenFileName(this,"Load Background",QDir::currentPath(),tr("Tiff (*.tif *.tiff);;Bitmap (*.bmp);;All Files (*.*)"));
    QByteArray ba = loadfilename.toUtf8();
    const char *cv_fileload = ba.data();
    if (loadfilename.isEmpty())
    {
       return;
    }
    else
    {
        QFile file(loadfilename);
        QFileInfo fileInfo(file.fileName());
        QString fileout(fileInfo.fileName());

        //set file as analyse_image
        background_image = cv::imread(cv_fileload,CV_LOAD_IMAGE_COLOR);
        ui->label_loaded_background->setText(fileout);
        check_background_size();
        // if box already checked apply the manipulation
        if(ui->check_background->isChecked())
        {
            apply_smooth_bg();
        }
    }
}

void eVBL::check_background_size()  //make sure background is same size as image
{
    if((analyse_image_saved.empty()) == true || (background_image.empty() == true)){return;}
    cv::Size bg_size = background_image.size();
    cv::Size im_size = analyse_image_saved.size();

    if(bg_size != im_size)  //if background image not right size
    {
        ui->check_background->setChecked(false);    //uncheck background
        ui->check_background->setEnabled(false);    //disable background
        ui->label_background_warning->setText("<font color='red'>background file wrong size!!!</font>"); //warning message
    }else{
        ui->check_background->setEnabled(true);
        ui->label_background_warning->setText(""); //warning message
    }
}

void eVBL::display_analyse(cv::Mat display) //apply zoom settings and display image in process tab
{
    if (display.empty() == true)
    {
        return;
    }
    float val;
    QString str_val = ui->zoom_setting_process->currentText();

    cv::Size image_size = display.size();
    float original_width = image_size.width;
    float original_height = image_size.height;

    if (str_val == "Fit")
    {
        float width_scale = (ui->scrollArea_Analyse->width()-4) / original_width;
        float height_scale = (ui->scrollArea_Analyse->height()-4) / original_height;

        if (width_scale <= height_scale)
        {
            val = width_scale;
        }
        else
        {
            val = height_scale;
        }

    }
    else
    {
        QString strip_val = str_val.replace("%","");
        val = strip_val.toFloat() / 100.0 ;
    }

    cv::resize(display,analyse_image_displayed,cv::Size(),val,val,cv::INTER_LINEAR);

    float image_width = original_width * val;
    float image_height = original_height * val;



    //analyse_image_displayed = (analyse_image_displayed*pix_val_range)/255 + min_pix_val;

    ui->analyse_display->setMinimumSize(image_width,image_height);
    ui->analyse_display->showImage(analyse_image_displayed);
}

void eVBL::set_combo_line_colour()  //create the combo box for line colours on the analyse screen
{
    //set icon sizes
    QPixmap red_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap green_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap blue_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap purple_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap orange_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap pink_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap yellow_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap black_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap white_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    //colour in icons
    red_icon.fill(QColor(red_line[0],red_line[1],red_line[2]));
    green_icon.fill(QColor(green_line[0],green_line[1],green_line[2]));
    blue_icon.fill(QColor(blue_line[0],blue_line[1],blue_line[2]));
    purple_icon.fill(QColor(purple_line[0],purple_line[1],purple_line[2]));
    orange_icon.fill(QColor(orange_line[0],orange_line[1],orange_line[2]));
    pink_icon.fill(QColor(pink_line[0],pink_line[1],pink_line[2]));
    yellow_icon.fill(QColor(yellow_line[0],yellow_line[1],yellow_line[2]));
    black_icon.fill(QColor(black_line[0],black_line[1],black_line[2]));
    white_icon.fill(QColor(white_line[0],white_line[1],white_line[2]));
    //populate combo box with icons and text
    ui->combo_line_colour->addItem(QIcon(red_icon),"cherry red");
    ui->combo_line_colour->addItem(QIcon(green_icon),"frog green");
    ui->combo_line_colour->addItem(QIcon(blue_icon),"smurf blue");
    ui->combo_line_colour->addItem(QIcon(purple_icon),"purple plum");
    ui->combo_line_colour->addItem(QIcon(orange_icon),"orange orange");
    ui->combo_line_colour->addItem(QIcon(pink_icon),"pink hotpants");
    ui->combo_line_colour->addItem(QIcon(yellow_icon),"sunshine yellow");
    ui->combo_line_colour->addItem(QIcon(black_icon),"midnight black");
    ui->combo_line_colour->addItem(QIcon(white_icon),"white snow");
    line_colour = cv::Scalar(red_line[2],red_line[1],red_line[0]);
}

void eVBL::on_combo_line_colour_currentIndexChanged(int index)
{
    switch(index)
    {
    case 0: //red_line
        line_colour = cv::Scalar(red_line[2],red_line[1],red_line[0]);
        break;
    case 1: //green_line
        line_colour = cv::Scalar(green_line[2],green_line[1],green_line[0]);
        break;
    case 2: //blue_line
        line_colour = cv::Scalar(blue_line[2],blue_line[1],blue_line[0]);
        break;
    case 3: //purple_line
        line_colour = cv::Scalar(purple_line[2],purple_line[1],purple_line[0]);
        break;
    case 4: //orange_line
        line_colour = cv::Scalar(orange_line[2],orange_line[1],orange_line[0]);
        break;
    case 5: //pink_line
        line_colour = cv::Scalar(pink_line[2],pink_line[1],pink_line[0]);
        break;
    case 6: //yellow_line
        line_colour = cv::Scalar(yellow_line[2],yellow_line[1],yellow_line[0]);
        break;
    case 7: //black_line
        line_colour = cv::Scalar(black_line[2],black_line[1],black_line[0]);
        break;
    case 8: //white_line
        line_colour = cv::Scalar(white_line[2],white_line[1],white_line[0]);
        break;
    default: //grey line as default
        cv::Scalar(40,40,40);
        break;
    }
    apply_overlay_lines();  //redraw
}


void eVBL::apply_smooth_bg()    //takes the buffered unedited image, applys smoothing functions as analyse_image, then calls apply_manipulations
{
    //this stuff can be slow so it is in a separate function from the colour stuff
    //which can be applied later much quicker.
    //only want the gaussian smooth to be done when it is really needed.

    if(analyse_image_saved.empty())
    {
        return;
    }
    ui->spin_gauss->setEnabled(false);
    this->setCursor(Qt::WaitCursor);

    //apply background subtraction
   if(ui->check_background->isChecked())
   {
      analyse_image = analyse_image_saved - background_image;
   }
   else
   {
       analyse_image_saved.copyTo(analyse_image);
   }

   //apply gaussian smooth

   if(ui->check_gaussian->isChecked())
   {
       analyse_image.copyTo(temp_img);
       int sigma = (ui->spin_gauss->value());
       cv::GaussianBlur(analyse_image,analyse_image,cv::Size(),sigma);
   }

   apply_manipulations();

   this->setCursor(Qt::ArrowCursor);
   ui->spin_gauss->setEnabled(true);
}

void eVBL::apply_manipulations()    //apply the colour enhancement images to the analysed picture- outputs to manipulated_image
{
     //make sure that an image has been opened first
    if(analyse_image.empty())
    {
        return;
    }
    else
    {
        analyse_image.copyTo(manipulated_image);
    }

    //apply black and white
    if(ui->check_bw->isChecked())
    {
        manipulated_image.copyTo(temp_img);
        cv::cvtColor(manipulated_image,temp_img,CV_BGR2GRAY);
        cv::cvtColor(temp_img,manipulated_image,CV_GRAY2BGR);   //****MUST CONVERT BACK TO BGR!!!! or else cvimagewidget will fuck the whole thing
    }

    //apply invert colours
    if(ui->check_invert->isChecked())
    {
        manipulated_image.copyTo(temp_img);
        manipulated_image =cv::Scalar(255,255,255) - temp_img;
    }
    //apply crop


    //output manipulated image to screen
    manipulated_image = apply_threshold(manipulated_image);

    //display logarithm of plot
    if(ui->check_log->isChecked())
    {
        manipulated_image = apply_log(manipulated_image);
    }

    apply_overlay_lines();
    if(ui->anal_type_tab->currentIndex() == 2)
    {
        get_intensity_profile();
    }
}

void eVBL::threshold_high() //check high limit is not lower than low limit, adjust low
{
    //test if values are ok
    float min_pix_val = ui->slider_low_point->value();
    float max_pix_val = ui->slider_high_point->value();
    if(max_pix_val - 10 <= min_pix_val)
    {
        ui->spin_low_point->setValue(max_pix_val - 10);
    }
   apply_manipulations();

}

void eVBL::threshold_low()  //check low limit is not greater than high limit, adjust high
{
    //test if values are ok
    float min_pix_val = ui->slider_low_point->value();
    float max_pix_val = ui->slider_high_point->value();
    if(max_pix_val - 10 <= min_pix_val)
    {
        ui->spin_high_point->setValue(min_pix_val + 10);
    }
    apply_manipulations();
}

cv::Mat eVBL::apply_threshold(cv::Mat display)      //add colour thresholds to the image under analysis
{
    float min_pix_val = ui->slider_low_point->value();
    float max_pix_val = ui->slider_high_point->value();
    float pix_range = max_pix_val - min_pix_val;
    cv::Mat return_img;
    display.copyTo(return_img);
    return_img = (display-min_pix_val)*255/pix_range;
    return(return_img);
}

cv::Mat eVBL::apply_log(cv::Mat display)    // take logarithm of image
{
    cv::Mat return_img;
    cv::Mat log_img;
    display.copyTo(return_img);
    display.copyTo(log_img);
    //return_img = return_img + 1;
    display.convertTo(return_img,CV_32F);
    cv::log(return_img, return_img);
    //cv::cvtColor(return_img,return_img,CV_)
    return_img.convertTo(return_img,CV_8U);
    return_img = return_img/log(255) * 255;
    return(return_img);
}

void eVBL::on_check_log_clicked()
{
  apply_manipulations();
}

void eVBL::on_reset_image_clicked()     //clear all manipulations to the image
{
    //reset drawn lines
    length_line[0] = -1;
    length_line[2] = -1;
    angle_line[0] = -1;
    angle_line[2] = -1;
    angle_line[4] = -1;
    reset_intensity_line();
    reset_crop_box();
    box_grab = 0;

    ui->check_gaussian->setChecked(false);
    ui->check_background->setChecked(false);
    ui->check_bw->setChecked(false);
    ui->check_invert->setChecked(false);
    ui->check_log->setChecked(false);
    ui->slider_low_point->setValue(0);
    ui->slider_high_point->setValue(255);
    threshold_low();

}

void eVBL::on_combo_line_thickness_currentIndexChanged()
{
    apply_overlay_lines();
}

void eVBL::on_anal_type_tab_currentChanged(int index)
{
    apply_overlay_lines();
    if(index == 2)  //if intensity tab selected
    {
        if(intensity_line[0] == -1){return;}
        get_intensity_profile();
    }
    if(index == 3)  //if crop box
    {
        if(analyse_image_saved.empty() == true){return;}   //ignore if no loaded image
        reset_crop_box();
        draw_crop_box();
    }
}

void eVBL::reset_crop_box()
{
    cv::Size a = analyse_image_saved.size();
    float x = a.width;
    float y = a.height;
    if((x < CROP_BOX_SIZE) || (y < CROP_BOX_SIZE))
    {
        ui->crop_button->setEnabled(false);
        ui->crop_info_label->setText("Too small to crop!");
    }else{
        ui->crop_button->setEnabled(true);
        ui->crop_info_label->setText("Save cropped version of image");
        crop_box_line[0] = x/2;
        crop_box_line[1] = y/2;
    }

}

void eVBL::reset_intensity_line()
{
    cv::Size a = analyse_image_saved.size();
    float x = a.width;
    float y = a.height;
    intensity_line[0] = x/2;
    intensity_line[1] = y/2;
    intensity_line[2] = 0.0;
}

void eVBL::mousePressEvent(QMouseEvent *event)   //event when mouse is pressed, return if not left pressed on analyse_display widget
{
    if(ui->analyse_display->underMouse() == false){return;}; //return if not on analyse_display
    if(event->button() == Qt::RightButton){return;};    //return if right mouse button was clicked

    QPoint coord = QCursor::pos();      //coordinates relative to whole screen
    QPoint localcoord = ui->analyse_display->mapFromGlobal(coord);  //coordinates in the actual image widget
    cv::Size a = analyse_image_saved.size();
    cv::Size b = analyse_image_displayed.size();
    float c = a.width;
    float d = b.width;
    float scale = c/d;
    int click_x = localcoord.rx()*scale;    //coords of image ignoring scaling factors of display
    int click_y = localcoord.ry()*scale;
    int x1, x2, y1, y2;

    //test tabs to see what mode
    switch(ui->anal_type_tab->currentIndex())
    {
    case 0:                                                         //length tab currently selected
        //check if no clicks yet
        if(length_line[0] == -1)    //set first point only
        {
            length_line[0] = click_x;
            length_line[1] = click_y;
            draw_length_line();
            return;
        }
         if(length_line[2] == -1)   //set second point
        {
            length_line[2] = click_x;
            length_line[3] = click_y;
            draw_length_line();
            return;
        }
        else                        //check if box clicked or set new line
        {
             if ((qSqrt(qPow(click_x-length_line[0],2))) <= 10 && (qSqrt(qPow(click_y-length_line[1],2)) <= 10))    //box 1 clicked
             {
                 box_grab = 1;
                 this->setCursor(Qt::SizeAllCursor);
                 return;
             }
             if ((qSqrt(qPow(click_x-length_line[2],2))) <= 10 && (qSqrt(qPow(click_y-length_line[3],2)) <= 10))    //box 2 clicked
             {
                 box_grab = 2;
                 this->setCursor(Qt::SizeAllCursor);
                 return;
             }
            length_line[0] = click_x;
            length_line[1] = click_y;
            length_line[2] = -1;
            length_line[3] = -1;
            draw_length_line();
        }
        break;
    case 1:                                                         //angle tab selected
        if(angle_line[0] == -1)     //set first point
        {
            angle_line[0] = click_x;
            angle_line[1] = click_y;
            draw_angle_line();
            return;
        }
        if(angle_line[2] == -1)     //set to second point only
        {
            angle_line[2] = click_x;
            angle_line[3] = click_y;
            draw_angle_line();
            return;
        }
        if(angle_line[4] == -1)     //complete angle line
        {
            angle_line[4] = click_x;
            angle_line[5] = click_y;
            draw_angle_line();
            return;
        }
        else                        //check if box clicked or set new angle line
        {
            if ((qSqrt(qPow(click_x-angle_line[0],2))) <= 10 && (qSqrt(qPow(click_y-angle_line[1],2)) <= 10))    //box 1 clicked
            {
                box_grab = 1;
                this->setCursor(Qt::SizeFDiagCursor);
                return;
            }
            if ((qSqrt(qPow(click_x-angle_line[2],2))) <= 10 && (qSqrt(qPow(click_y-angle_line[3],2)) <= 10))    //circle clicked
            {
                box_grab = 2;
                this->setCursor(Qt::SizeAllCursor);
                return;
            }
            if ((qSqrt(qPow(click_x-angle_line[4],2))) <= 10 && (qSqrt(qPow(click_y-angle_line[5],2)) <= 10))    //box 2 clicked
            {
                box_grab = 3;
                this->setCursor(Qt::SizeBDiagCursor);
                return;
            }
            angle_line[0] = click_x;
            angle_line[1] = click_y;
            angle_line[2] = -1;
            angle_line[3] = -1;
            angle_line[4] = -1;
            angle_line[5] = -1;
            draw_angle_line();
        }
        break;
    case 2:   //intensity tab selected
        x1 = click_x - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        x2 = click_x + INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        y1 = click_y + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        y2 = click_y - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);

        //test if grabbed box
        if ((qSqrt(qPow(click_x-(intensity_line[0]- INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2])),2))) <= 10 && (qSqrt(qPow(click_y-(intensity_line[1]+ INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2])),2)) <= 10))    //box 1 clicked
        {
            box_grab = 1;
            this->setCursor(Qt::SizeFDiagCursor);
            return;
        }
        if ((qSqrt(qPow(click_x-intensity_line[0],2))) <= 10 && (qSqrt(qPow(click_y-intensity_line[1],2)) <= 10))    //circle clicked
        {
            box_grab = 2;
            this->setCursor(Qt::SizeAllCursor);
            return;
        }
        if ((qSqrt(qPow(click_x-(intensity_line[0]+ INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2])),2))) <= 10 && (qSqrt(qPow(click_y-(intensity_line[1]- INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2])),2)) <= 10))    //box 2 clicked
        {
            box_grab = 3;
            this->setCursor(Qt::SizeBDiagCursor);
            return;
        }

        //test extents
        if(x1 < 0)
        {
            click_x = INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        }
        if(x2 > a.width)
        {
            click_x = a.width - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        }
        if(y1 > a.height)
        {
            click_y = a.height - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        }
        if(y2 < 0)
        {
            click_y = INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        }
        if(y2 > a.height)
        {
            click_y = a.height + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        }
        if(y1 < 0)
        {
            click_y = -1*(INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]));
        }

        intensity_line[0] = click_x;
        intensity_line[1] = click_y;
        draw_intensity_line();
        break;
    case 3: //crop tab selected
        x1 = click_x - CROP_BOX_SIZE/2;
        x2 = click_x + CROP_BOX_SIZE/2;
        y1 = click_y - CROP_BOX_SIZE/2;
        y2 = click_y + CROP_BOX_SIZE/2;

        //test if grabbed centre
        if(qSqrt(qPow((click_x-crop_box_line[0]),2)) <= 10 && qSqrt(qPow((click_y-crop_box_line[1]),2)))
        {
            box_grab = 1;
            this->setCursor(Qt::SizeAllCursor);
            return;
        }

        //test extents
        if(x1 < 0)
        {
            click_x = CROP_BOX_SIZE/2;
        }
        if(x2 > a.width)
        {
            click_x = a.width - CROP_BOX_SIZE/2;
        }
        if(y1 < 0)
        {
            click_y = CROP_BOX_SIZE/2;
        }
        if(y2 > a.height)
        {
            click_y = a.height - CROP_BOX_SIZE/2;
        }
        crop_box_line[0] = click_x;
        crop_box_line[1] = click_y;
        draw_crop_box();
        break;
    default:
        //qDebug() << "no tab selected ???";
        break;
    }
}

void eVBL::apply_overlay_lines()   //add lines to analyse overlay
{
    int index = ui->anal_type_tab->currentIndex();

    switch(index)
    {
    case 0: //length
        draw_length_line();
        return;
    case 1: //angle
        draw_angle_line();
        return;
    case 2: //intensity
        draw_intensity_line();
        break;
    case 3: //crop
        draw_crop_box();
        break;
    default:
        //qDebug() << "?";
        break;
    }
}

void eVBL::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton){return;};    //return if right mouse button was released
    box_grab = 0;   //set box to ungrabbed mode when button released
    this->setCursor(Qt::ArrowCursor);    //reset cursor
    if(ui->anal_type_tab->currentIndex() == 2)  //test if intensity line tab selected, and readjust box if out of bounds
    {
        int x1 = intensity_line[0] - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        int x2 = intensity_line[0] + INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
        int y1 = intensity_line[1] + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        int y2 = intensity_line[1] - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
        cv::Size a = analyse_image_saved.size();

        //test extents
        if(x1 < 0)
        {
            intensity_line[0] = intensity_line[0] - x1;
        }
        if(x2 > a.width)
        {
            intensity_line[0] = intensity_line[0] - (x2 - a.width);
        }
        if(y1 > a.height)
        {
            intensity_line[1] = intensity_line[1] - (y1 - a.height);
        }
        if(y2 < 0)
        {
            intensity_line[1] = intensity_line[1] - y2;
        }
        if(y2 > a.height)
        {
            intensity_line[1] = intensity_line[1] - (y2 - a.height);
        }
        if(y1 < 0)
        {
            intensity_line[1] = intensity_line[1] - y1;
        }
    draw_intensity_line();
    }

}

void eVBL::mouseMoveEvent(QMouseEvent *event)
{
    if(ui->analyse_display->underMouse() == false){return;}; //return if not on analyse_display
    if(event->button() == Qt::RightButton){return;};    //return if right mouse button was clicked

    QPoint coord = QCursor::pos();      //coordinates relative to whole screen
    QPoint localcoord = ui->analyse_display->mapFromGlobal(coord);  //coordinates in the actual image widget
    cv::Size a = analyse_image_saved.size();
    cv::Size b = analyse_image_displayed.size();
    float c = a.width;
    float d = b.width;
    float scale = c/d;
    int click_x = localcoord.rx()*scale;
    int click_y = localcoord.ry()*scale;
    float dist, ang;

    //test if at edge boundaries
    if(click_x < 0)
    {
        click_x = 0;
    }
    if(click_x > c)
    {
        click_x = a.width;
    }
    if(click_y < 0)
    {
        click_y = 0;
    }
    if(click_y > a.height)
    {
        click_y = a.height;
    }

    //test tabs to see what mode
    switch(ui->anal_type_tab->currentIndex())
    {
    case 0: //move length line
        if(box_grab == 0)
        {
            return;
        }
        if(box_grab == 1)
        {
            length_line[0] = click_x;
            length_line[1] = click_y;
            draw_length_line();
        }
        if(box_grab == 2)
        {
            length_line[2] = click_x;
            length_line[3] = click_y;
            draw_length_line();
        }
        break;
    case 1: //move angle line
        if(box_grab == 0)
        {
            return;
        }
        if(box_grab == 1)
        {
            angle_line[0] = click_x;
            angle_line[1] = click_y;
            draw_angle_line();
        }
        if(box_grab == 2)
        {
            angle_line[2] = click_x;
            angle_line[3] = click_y;
            draw_angle_line();
        }
        if(box_grab == 3)
        {
            angle_line[4] = click_x;
            angle_line[5] = click_y;
            draw_angle_line();
        }
        break;
    case 2: //move intensity line
        if(box_grab == 0)
        {
            return;
        }
        if(box_grab == 1)   //grabbed left anchor
        {
            dist = qSqrt( qPow((intensity_line[0] - click_x),2) + qPow((intensity_line[1] - click_y),2));
            if(click_x <= intensity_line[0])
            {
                ang = qAsin((click_y - intensity_line[1])/dist);
            }
            else
            {
                ang = -1 * (qAsin((click_y - intensity_line[1])/dist));
            }
                intensity_line[2] = ang;
                ui->rotate_spinbox->setValue(ang * 180 / PI);
                draw_intensity_line();
                return;
        }
        if(box_grab == 3)   //grabbed right anchor
        {
            dist = qSqrt( qPow((intensity_line[0] - click_x),2) + qPow((intensity_line[1] - click_y),2));
            if(click_x <= intensity_line[0])
            {
                ang = qAsin((click_y - intensity_line[1])/dist);
            }
            else
            {
                ang = -1 * (qAsin((click_y - intensity_line[1])/dist));
            }
                intensity_line[2] = ang;
                ui->rotate_spinbox->setValue(ang * 180 / PI);
                draw_intensity_line();
                return;
        }
        if(box_grab == 2)   //grabbed middle
        {
            intensity_line[0] = click_x;
            intensity_line[1] = click_y;
            draw_intensity_line();
        }
        break;
    case 3: //move crop line
        if(box_grab == 0)
        {
            return;
        }
        if(box_grab == 1)
        {
            int x1 = click_x - CROP_BOX_SIZE/2;
            int x2 = click_x + CROP_BOX_SIZE/2;
            int y1 = click_y - CROP_BOX_SIZE/2;
            int y2 = click_y + CROP_BOX_SIZE/2;
           //test extents
            if(x1 < 0)
            {
                click_x = CROP_BOX_SIZE/2;
            }
            if(x2 > a.width)
            {
                click_x = a.width - CROP_BOX_SIZE/2;
            }
            if(y1 < 0)
            {
                click_y = CROP_BOX_SIZE/2;
            }
            if(y2 > a.height)
            {
                click_y = a.height - CROP_BOX_SIZE/2;
            }
            crop_box_line[0] = click_x;
            crop_box_line[1] = click_y;
            draw_crop_box();
        }
        //qDebug() << "mouse tracking";
        break;
    default:
        //qDebug() << "??";
        break;
    }
}

void eVBL::resizeEvent(QResizeEvent *event)
{
    QString str_val = ui->zoom_setting_process->currentText();
    if(str_val == "Fit")
    {
        apply_overlay_lines();
    }

    str_val = ui->zoom_setting->currentText();
    if(str_val == "Fit")
    {
        if(buffered_snapshot.empty() == false)
        {
            display_capture(buffered_snapshot);
        }
    }
}

void eVBL::draw_length_line()
{

    if(length_line[0] == -1)
    {
        display_analyse(manipulated_image);
        ui->measured_distance->setText("--.-- mm");
        return;
    }
    manipulated_image.copyTo(analyse_overlay);
    draw_box(analyse_overlay,length_line[0],length_line[1]);
    //check if second click yet
    if(length_line[2] == -1)
    {
        display_analyse(analyse_overlay);
        ui->measured_distance->setText("--.-- mm");
        return;
    }
    draw_box(analyse_overlay,length_line[2],length_line[3]);
    draw_line(analyse_overlay,length_line[0],length_line[1],length_line[2],length_line[3]);
    float val = qSqrt(qPow((length_line[2]-length_line[0]),2) + qPow((length_line[3]-length_line[1]),2)) * MM_PER_PIXEL;
    QString str = QString::number(val) + " mm";
    ui->measured_distance->setText(str);

    display_analyse(analyse_overlay);
}

void eVBL::draw_angle_line()
{
    if(angle_line[0] == -1)
    {
        display_analyse(manipulated_image);
        ui->angle_measurement->setText("--");
        return;
    }
    manipulated_image.copyTo(analyse_overlay);
    draw_box(analyse_overlay,angle_line[0],angle_line[1]);
    //check if mid point yet
    if(angle_line[2] == -1)
    {
        display_analyse(analyse_overlay);
        ui->angle_measurement->setText("--");
        return;
    }
    draw_circle(analyse_overlay,angle_line[2],angle_line[3]);
    draw_line(analyse_overlay,angle_line[0],angle_line[1],angle_line[2],angle_line[3]);
    if(angle_line[4] == -1)
    {
        display_analyse(analyse_overlay);
        ui->angle_measurement->setText("--");
        return;
    }
    draw_box(analyse_overlay,angle_line[4],angle_line[5]);
    draw_line(analyse_overlay,angle_line[2],angle_line[3],angle_line[4],angle_line[5]);
    show_angle();
    display_analyse(analyse_overlay);
}

void eVBL::show_angle()     //calculate and display angle measurement
{
    if(angle_line[4] == -1)  //return if line not fully defined
    {
        ui->angle_measurement->setText("--");
        return;
    }
    QString str = "--";
    float x1 = angle_line[0] - angle_line[2];
    float y1 = angle_line[1] - angle_line[3];
    float x2 = angle_line[4] - angle_line[2];
    float y2 = angle_line[5] - angle_line[3];
    float cos_ang = ((x1 * x2) + (y1 * y2))/(qSqrt((x1 * x1)+(y1 * y1)) * qSqrt((x2 * x2) + (y2 * y2)));

    if(ui->radio_degrees->isChecked())
    {
       float ang = qAcos(cos_ang) * 180 / PI;
       str = QString::number(ang,'f',2) + "°";
    }
    if(ui->radio_radians->isChecked())
    {
        float ang = qAcos(cos_ang);
        str = QString::number(ang,'f',4) + " rad";
    }
    ui->angle_measurement->setText(str);

}

void eVBL::on_spin_intensity_width_valueChanged()
{
   draw_intensity_line();
}

void eVBL::draw_intensity_line() //draw intensity profile line over top of image
{
    //test if null
    if(intensity_line[0] == -1)
    {
        cv::Size size = manipulated_image.size();
        intensity_line[0] = size.width/2;
        intensity_line[1] = size.height/2;
        intensity_line[2] = 0.0;
    }

    manipulated_image.copyTo(analyse_overlay);
    //calculate end points for line at angle defined by intensity[2]
    int x1 = intensity_line[0] - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    int x2 = intensity_line[0] + INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    int y1 = intensity_line[1] + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
    int y2 = intensity_line[1] - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);


    draw_box(analyse_overlay, intensity_line[0],intensity_line[1]); //draw centre box
    draw_circle(analyse_overlay,x1,y1);
    draw_circle(analyse_overlay,x2,y2);

    int integration_width = ui->spin_intensity_width->value();
    int upper;
    int lower;
    if( integration_width % 2)
    {
        upper = (integration_width - 1) / 2;
        lower = upper;
    }else{
        upper = integration_width / 2;
        lower = upper - 1;
    }
    int intensity_x_upper = intensity_line[0] - upper*qSin(intensity_line[2]);
    int intensity_y_upper = intensity_line[1] - upper*qCos(intensity_line[2]);
    int intensity_x_lower = intensity_line[0] + lower*qSin(intensity_line[2]);
    int intensity_y_lower = intensity_line[1] + lower*qCos(intensity_line[2]);

    //draw upper line
    x1 = intensity_x_upper - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    x2 = intensity_x_upper + INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    y1 = intensity_y_upper + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
    y2 = intensity_y_upper - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);

    draw_line(analyse_overlay,x1,y1,x2,y2);

    //draw lower line
    x1 = intensity_x_lower - INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    x2 = intensity_x_lower + INTENSITY_LINE_LENGTH/2 * qCos(intensity_line[2]);
    y1 = intensity_y_lower + INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);
    y2 = intensity_y_lower - INTENSITY_LINE_LENGTH/2 * qSin(intensity_line[2]);

    draw_line(analyse_overlay,x1,y1,x2,y2);

    display_analyse(analyse_overlay);

    get_intensity_profile();

}

void eVBL::get_intensity_profile()  //get intensity profile along intensity line
{
    //make sure image loaded
    if(manipulated_image.empty())
    {
        return;
    }
    cv::cvtColor(manipulated_image,greyscale_analyse,CV_BGR2GRAY);  //make greyscale version for intensity
    intensity_preview = cv::Mat::zeros(256,INTENSITY_LINE_LENGTH,CV_8UC3);    //create matrix for preview
    cv::Point intensity_polyline[1][INTENSITY_LINE_LENGTH]; //define points

    cv::Size a = greyscale_analyse.size();
    float max_x = a.width;
    float max_y = a.height;

    intensity_profile.clear();
    //loop over all points
    int integration_width = ui->spin_intensity_width->value();
    int start;
    if( integration_width % 2)
    {
        start = (integration_width - 1) / 2;
    }else{
        start = integration_width / 2;
    }

    int intensity;
    int intensity_add = 0;

    for(int i=0; i<=INTENSITY_LINE_LENGTH;i++)
    {
        int mid_x = intensity_line[0] - (INTENSITY_LINE_LENGTH/2 - i) * qCos(intensity_line[2]);
        int mid_y = intensity_line[1] + (INTENSITY_LINE_LENGTH/2 - i) * qSin(intensity_line[2]);

        intensity_add = 0;
        //integrate over selected width
        for(int j=0; j<integration_width;j++)
        {
            float x = mid_x - (start - j)*qSin(intensity_line[2]);
            float y = mid_y - (start - j)*qCos(intensity_line[2]);
            if((x>=max_x)||(y>=max_y)||(x<=0)||(y<=0))
            {
                intensity_add = intensity_add + 0;
            }
            else
            {
            intensity_add = intensity_add + greyscale_analyse.at<uchar>(y,x);
            }
            //qDebug() << "start =" << start << "point " << j << " x =" << x << "y =" << y << "mid x =" << mid_x << "mid y = " << mid_y << "intensity =" << greyscale_analyse.at<uchar>(y,x);

        }
        intensity = intensity_add / integration_width;
        intensity_profile.append(intensity);
        intensity_polyline[0][i] = cv::Point(i,intensity);
        cv::line(intensity_preview,cv::Point(i,256),cv::Point(i,256-intensity),cv::Scalar(200,255,200),1,8,0);
    }
    int image_width = ui->intensity_display->width();
    int image_height = ui->intensity_display->height();
    cv::resize(intensity_preview,intensity_preview_resized,cv::Size(image_width,image_height),0,0,cv::INTER_LINEAR);
    ui->intensity_display->showImage(intensity_preview_resized);
}

void eVBL::draw_crop_box()
{
    if((crop_box_line[0] == -1) || (ui->crop_button->isEnabled() == false))
    {
        display_analyse(manipulated_image);
        return;
    }

    manipulated_image.copyTo(analyse_overlay);
    //get 4 corners
    int x1 = crop_box_line[0] - CROP_BOX_SIZE/2;
    int x2 = crop_box_line[0] + CROP_BOX_SIZE/2;
    int y1 = crop_box_line[1] - CROP_BOX_SIZE/2;
    int y2 = crop_box_line[1] + CROP_BOX_SIZE/2;

    //make outer box
    int line_thickness = ui->combo_line_thickness->currentText().toInt();
    cv::rectangle(analyse_overlay, cv::Point(x1,y1),cv::Point(x2,y2),line_colour,line_thickness,8,0);
    //make cross
    draw_line(analyse_overlay,x1,crop_box_line[1],x2,crop_box_line[1]);
    draw_line(analyse_overlay,crop_box_line[0],y1,crop_box_line[0],y2);
    //make anchor circle
    draw_circle(analyse_overlay,crop_box_line[0],crop_box_line[1]);
    display_analyse(analyse_overlay);
}

void eVBL::draw_box(cv::Mat img, int x_point, int y_point)  //draw box around specified point
{
    int x1 = x_point - 10;
    int x2 = x_point + 10;
    int y1 = y_point - 10;
    int y2 = y_point + 10;
    int line_thickness = ui->combo_line_thickness->currentText().toInt();

    cv::rectangle(img, cv::Point(x1,y1),cv::Point(x2,y2),line_colour,line_thickness,8,0);
}

void eVBL::draw_line(cv::Mat img, int x1, int y1, int x2, int y2)   //draw line between specified coordinates
{
    int line_thickness = ui->combo_line_thickness->currentText().toInt();

    cv::line(img, cv::Point(x1,y1),cv::Point(x2,y2),line_colour,line_thickness,8,0);
}

void eVBL::draw_circle(cv::Mat img, int x_point, int y_point)   //draw circle around specified point
{
    int line_thickness = ui->combo_line_thickness->currentText().toInt();
    int radius = 10;

    cv::circle(img, cv::Point(x_point, y_point), radius, line_colour, line_thickness, 8, 0);
}



void eVBL::on_radio_degrees_toggled()
{
    show_angle();
}


void eVBL::on_clipboard_button_clicked()    //copy intensity profile data to clipboard
{
    //check if any intensity data

    //create clipboard instance and copy data to clipboard
    QClipboard *cb = QApplication::clipboard();
    //create text data string
    QString cb_txt = prepare_intensity_data_string();
    cb->setText(cb_txt);
}

void eVBL::on_file_button_clicked() //
{
    if(analyse_image_saved.empty() == true){return;}    //make sure file is loaded

    QStringList get_name = ui->label_loaded_file->text().split(".");

    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",QDir::currentPath() + "/" + get_name[0] + "-intensity",tr("Text File (*.txt);;All Files (*.*)"));
    QByteArray ba = savefilename.toUtf8();
    if (savefilename.isEmpty())
    {
        //qDebug() << "empty";
    }
    else
    {
        QString file_txt = prepare_intensity_data_string();
        QFile file(savefilename);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        out << file_txt;
        file.close();
    }
}

QString eVBL::prepare_intensity_data_string()  //prepare string of intensity profile data ready for export
{
    QString txt = QString::number(intensity_profile.value(0));

    for(int i=1; i<INTENSITY_LINE_LENGTH; i++)
    {
        txt.append('\n');
        txt.append(QString::number(intensity_profile.value(i)));
    }
    return(txt);
}

void eVBL::on_crop_button_clicked()
{
    if(analyse_image_saved.empty() == true){return;}    //cehck if image loaded
    if(crop_box_line[0] == -1){return;}
    QStringList get_name = ui->label_loaded_file->text().split(".");
    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",QDir::currentPath() + "/" + get_name[0] + "-cropped",tr("Tiff (*.tif);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = savefilename.toUtf8();
    const char *cv_filesave = ba.data();
    if (savefilename.isEmpty()){return;}

    //qDebug() << cv_filesave;
    int x1 = crop_box_line[0] - CROP_BOX_SIZE/2;
    int y1 = crop_box_line[1] - CROP_BOX_SIZE/2;
    cv::Mat croppedImage;
    cv::Rect croparea(x1,y1,CROP_BOX_SIZE,CROP_BOX_SIZE);

    cv::Mat(manipulated_image,croparea).copyTo(croppedImage);
    if(ui->check_bw->isChecked())
    {
        cv::cvtColor(croppedImage,croppedImage,CV_BGR2GRAY);
    }
    cv::imwrite(cv_filesave,croppedImage);


}

//*********************************************************************************************************************************
//
//menu items
//
//*********************************************************************************************************************************

void eVBL::on_actionExit_triggered()
{
    QApplication::quit();
}

void eVBL::on_actionSettings_triggered()
{
    Settings *config = new Settings();
    int reply = config->exec();

    if(reply == 0)
    {
        read_setting_values();

        if(ui->evbl_tabs->currentIndex() == 0)
        {
            if (ui->device_list->currentIndex() != -1)          //ignore if no cameras connected
            {
                preview_timer->stop();
                preview_timer->start(1000/PREVIEW_FPS);
            }
        }
    }
}

void eVBL::on_actionAbout_triggered()
{
    about_display = new about();
    about_display->show();
}

void eVBL::on_actionHelp_triggered()
{
    help_display = new help();
    help_display->show();
}
