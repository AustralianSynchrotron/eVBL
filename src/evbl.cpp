#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo/photo.hpp>

#include <cvimagewidget.h>

#include <QScrollBar>
#include <QThread>

#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 100


eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    preview_timer = new QTimer(this);

    connect(preview_timer, SIGNAL(timeout()), this, SLOT(update_video()));
    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));
    connect(ui->multi_button, SIGNAL(clicked()),this, SLOT(multi_shot()));
    connect(ui->scrollArea_Capture->verticalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_vertical_capture(int,int)));
    connect(ui->scrollArea_Capture->horizontalScrollBar(), SIGNAL(rangeChanged(int,int)), this, SLOT(recentre_horizontal_capture(int,int)));



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

    set_camera(ui->device_list->currentIndex());  //use selected camera in list
    preview_timer->start(EVBL_PREVIEW_WINDOW_REFRESH);  //gets the preview video working

    int index = ui->zoom_setting->findText("Fit");  //set default zoom to 'fit to window'
    ui->zoom_setting->setCurrentIndex(index);




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
    //qDebug() << videoCapture.get(CV_CAP_PROP_EXPOSURE);
    //qDebug() << videoCapture.get(CV_CAP_PROP_GAIN);
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
    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",auto_name,tr("Bitmap (*.bmp);;JPEG (*.jpg)"));
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


