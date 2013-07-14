#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo/photo.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <cvimagewidget.h>

#include <QScrollBar>
#include <QThread>

#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 100
#define COLOUR_ICON_WIDTH 20
#define COLOUR_ICON_HEIGHT 15
static QColor red_line = QColor("#DC143C");
static QColor green_line = QColor("#32CD32");
static QColor blue_line = QColor("#4169E1");
static QColor purple_line = QColor("#800080");
static QColor orange_line = QColor("#FFA500");
static QColor pink_line = QColor("#FF69B4");
static QColor yellow_line = QColor("#FFFF00");
static QColor black_line = QColor("#000000");
static QColor white_line = QColor("#FFFFFF");

eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    preview_timer = new QTimer(this);

    set_combo_line_colour();        //set icon and entries for combo_line_colour on process tab

    connect(preview_timer, SIGNAL(timeout()), this, SLOT(update_video()));
    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));
    connect(ui->multi_button, SIGNAL(clicked()),this, SLOT(multi_shot()));
    //set scrollbars to centre captured image when zoom level changes
    connect(ui->scrollArea_Capture->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_vertical_capture(int,int)));
    connect(ui->scrollArea_Capture->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_horizontal_capture(int,int)));
    //set scrollbars to centre process image when zoom level changes
    connect(ui->scrollArea_Analyse->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_vertical_analyse(int,int)));
    connect(ui->scrollArea_Analyse->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_horizontal_analyse(int,int)));
    //set image manipulation slots
    connect(ui->check_background, SIGNAL(stateChanged(int)),this, SLOT(apply_manipulations()));


    //populate combo box showing the attached camera devices
    int cam_no = 0;
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = QCamera::deviceDescription(deviceName);  //for reading in actual camera type
        cam_no = cam_no + 1;
        QString cam_no_str = QString::number(cam_no);
        ui->device_list->addItem("Detector " + cam_no_str);
        //ui->device_list->addItem(description);//used to fill combo box with actual camera type
    }

    set_camera(ui->device_list->currentIndex());            //use selected camera in list
    preview_timer->start(EVBL_PREVIEW_WINDOW_REFRESH);      //gets the preview video working

    int index_c = ui->zoom_setting->findText("Fit");          //set default zoom to 'fit to window'
    int index_p = ui->zoom_setting_process->findText("Fit");  //same for the process tab window
    ui->zoom_setting->setCurrentIndex(index_c);
    ui->zoom_setting_process->setCurrentIndex(index_p);




}

eVBL::~eVBL()
{
    delete ui;
}

void eVBL::on_evbl_tabs_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        //start camera preview
        preview_timer->start(EVBL_PREVIEW_WINDOW_REFRESH);  //gets the preview video working
        break;
    case 1:
        //stop preview camera
        preview_timer->stop();
        break;
    default:
        break;
    }


}


void eVBL::update_video() {

    videoCapture.read(preview_frame);
    cv::resize(preview_frame,output_preview,cv::Size(EVBL_PREVIEW_WINDOW_WIDTH,EVBL_PREVIEW_WINDOW_HEIGHT),0,0,cv::INTER_LINEAR);
    ui->previewVideo->showImage(output_preview);
}


void eVBL::take_shot()
{

    preview_frame.copyTo(buffered_snapshot);

    display_capture(buffered_snapshot);

}

void eVBL::multi_shot()
{

    int frames = 3;

    cv::Mat *array_of_mats = new cv::Mat[frames];
    for(int i = 0; i < frames; i++)
    {
        qDebug() << i;
        preview_frame.copyTo(array_of_mats[i]);
        QThread::sleep(1);
    }

    cv::fastNlMeansDenoisingColoredMulti(*array_of_mats, buffered_snapshot, frames/2, frames/2);
    //cv::fastNlMeansDenoisingColoredMulti(*array_of_mats, averaged_image, 5, 5, 3, 3, 6, 21);

    display_capture(buffered_snapshot);

    qDebug() << "pew pew...";
}

void eVBL::display_capture(cv::Mat display)
{
    if (display.empty() == true)
    {
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
    ui->captured_display->showImage(output_display);


}

void eVBL::set_camera(int index)
{
    videoCapture.open(index);//(ui->device_list->currentIndex());
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 10000);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 10000);

    //initialise exposure and gain settings
    //qDebug() << "auto" << videoCapture.get(CV_CAP_PROP_AUTO_EXPOSURE);
    //videoCapture.set(CV_CAP_PROP_AUTO_EXPOSURE,0.0);
    //qDebug() << "auto" << videoCapture.get(CV_CAP_PROP_AUTO_EXPOSURE);
    //set_exposure = videoCapture.get(CV_CAP_PROP_EXPOSURE);
    //set_gain = videoCapture.get(CV_CAP_PROP_GAIN);
    qDebug() << videoCapture.get(CV_CAP_PROP_EXPOSURE);
    qDebug() << videoCapture.get(CV_CAP_PROP_GAIN);
    QString image_height = QString::number(videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT));
    QString image_width = QString::number(videoCapture.get(CV_CAP_PROP_FRAME_WIDTH));
    ui->label_resolution->setText("Size: " + image_width + " x " + image_height + " pixels");

}

void eVBL::on_device_list_currentIndexChanged(int index)
{
    videoCapture.release();
    set_camera(index);

}

void eVBL::on_zoom_setting_currentIndexChanged()
{
    display_capture(buffered_snapshot);
}

void eVBL::on_zoom_setting_process_currentIndexChanged()
{
    display_analyse(manipulated_image);
}

void eVBL::on_save_image_button_clicked()
{
    //get text to create auto filename
    QString initials = ui->info_initials->text();
    QString school = ui->info_school->text();
    QString distance = ui->info_distance->text();
    QString object = ui->combo_object->currentText();
    QString object_number = ui->combo_objectnumber->currentText();
    QString wavelength = ui->combo_wavelength->currentText();

    QString auto_name = school + "_" + initials + "_" + object + "_" + wavelength + "_" + distance + "_" + object_number;
    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",auto_name,tr("Tiff (*.tif);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = savefilename.toUtf8();
    const char *cv_filesave = ba.data();
    if (savefilename.isEmpty())
    {
        qDebug() << "empty";
    }
    else
    {
        qDebug() << cv_filesave;
        cv::imwrite(cv_filesave,buffered_snapshot);
    }
    //cv::imwrite(savefilename,buffered_snapshot);

}

void eVBL::recentre_vertical_capture(int min_bar, int max_bar)
{
    Q_UNUSED(min_bar);
    //set scroll bar to centre
    ui->scrollArea_Capture->verticalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_horizontal_capture(int min_bar, int max_bar)
{
    Q_UNUSED(min_bar);
    //set scrollbar to centre
    ui->scrollArea_Capture->horizontalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_vertical_analyse(int min_bar, int max_bar)
{
    Q_UNUSED(min_bar);
    //set scroll bar to centre
    ui->scrollArea_Analyse->verticalScrollBar()->setValue(max_bar/2);

}

void eVBL::recentre_horizontal_analyse(int min_bar, int max_bar)
{
    Q_UNUSED(min_bar);
    //set scrollbar to centre
    ui->scrollArea_Analyse->horizontalScrollBar()->setValue(max_bar/2);

}


void eVBL::on_open_analysis_button_clicked()
{
    QString loadfilename = QFileDialog::getOpenFileName(this,"Open Image","",tr("Tiff (*.tif *.tiff);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = loadfilename.toUtf8();
    const char *cv_fileload = ba.data();
    if (loadfilename.isEmpty())
    {
        qDebug() << "empty";
    }
    else
    {
        qDebug() << cv_fileload;
        //set file as analyse_image
        analyse_image = cv::imread(cv_fileload,CV_LOAD_IMAGE_COLOR);
        //push to manipulated_image for editing and display
            //analyse_image.copyTo(manipulated_image);
            //display_analyse(manipulated_image);
        apply_manipulations();
    }


}

void eVBL::on_background_button_clicked()
{
    QString loadfilename = QFileDialog::getOpenFileName(this,"Load Background","",tr("Tiff (*.tif *.tiff);;Bitmap (*.bmp);;JPEG (*.jpg);;All Files (*.*)"));
    QByteArray ba = loadfilename.toUtf8();
    const char *cv_fileload = ba.data();
    if (loadfilename.isEmpty())
    {
        qDebug() << "empty";
    }
    else
    {
        qDebug() << cv_fileload;
        //set file as analyse_image
        background_image = cv::imread(cv_fileload,CV_LOAD_IMAGE_COLOR);
        // if box already checked apply the manipulation
        if(ui->check_background->isChecked())
        {
            apply_manipulations();
        }
    }


}

void eVBL::display_analyse(cv::Mat display)
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

    ui->analyse_display->setMinimumSize(image_width,image_height);
    ui->analyse_display->showImage(analyse_image_displayed);


}

void eVBL::set_combo_line_colour()
{
    QPixmap red_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap green_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap blue_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap purple_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap orange_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap pink_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap yellow_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap black_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    QPixmap white_icon(COLOUR_ICON_WIDTH,COLOUR_ICON_HEIGHT);
    red_icon.fill(red_line);
    green_icon.fill(green_line);
    blue_icon.fill(blue_line);
    purple_icon.fill(purple_line);
    orange_icon.fill(orange_line);
    pink_icon.fill(pink_line);
    yellow_icon.fill(yellow_line);
    black_icon.fill(black_line);
    white_icon.fill(white_line);
    ui->combo_line_colour->addItem(QIcon(red_icon),"cherry red");
    ui->combo_line_colour->addItem(QIcon(green_icon),"frog green");
    ui->combo_line_colour->addItem(QIcon(blue_icon),"smurf blue");
    ui->combo_line_colour->addItem(QIcon(purple_icon),"purple plum");
    ui->combo_line_colour->addItem(QIcon(orange_icon),"orange orange");
    ui->combo_line_colour->addItem(QIcon(pink_icon),"pink hotpants");
    ui->combo_line_colour->addItem(QIcon(yellow_icon),"sunshine yellow");
    ui->combo_line_colour->addItem(QIcon(black_icon),"midnight black");
    ui->combo_line_colour->addItem(QIcon(white_icon),"white snow");

}

void eVBL::apply_manipulations()
{
    //apply manipulations to the displayed process image

    //make sure that an image has been opened first
    if(analyse_image.empty())
    {
        return;
    }

     //apply background subtraction
    if(ui->check_background->isChecked())
    {
       manipulated_image = analyse_image - background_image;
    }
    else
    {
        analyse_image.copyTo(manipulated_image);
    }

    //apply invert

    //apply black and white
    if(ui->check_bw->isChecked())
    {
        //manipulated_image.copyTo(temp_img);
        cv::cvtColor(temp_img,manipulated_image,CV_RGB2GRAY);
    }
    //apply crop

    //apply gaussian smooth


    //output manipulated image to screen

    display_analyse(manipulated_image);

}
