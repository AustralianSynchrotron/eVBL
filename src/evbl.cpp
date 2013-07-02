#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <cvimagewidget.h>

#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 100


eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);



    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));


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

    set_camera(0);  //use first camera in list
    startTimer(EVBL_PREVIEW_WINDOW_REFRESH);  //gets the preview video working

    int index = ui->zoom_setting->findText("Fit");  //set default zoom to 'fit to window'
    ui->zoom_setting->setCurrentIndex(index);




}

eVBL::~eVBL()
{
    delete ui;
}

void eVBL::timerEvent(QTimerEvent*) {

    videoCapture.read(preview_frame);
    cv::resize(preview_frame,output_preview,cv::Size(EVBL_PREVIEW_WINDOW_WIDTH,EVBL_PREVIEW_WINDOW_HEIGHT),0,0,cv::INTER_LINEAR);
    ui->previewVideo->showImage(output_preview);
}


void eVBL::take_shot()
{

    preview_frame.copyTo(buffered_snapshot);

    display_capture(buffered_snapshot);

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
        float width_scale = ui->captured_display->width() / videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
        float height_scale = ui->captured_display->height() / videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);

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
    ui->captured_display->showImage(output_display);

}

void eVBL::set_camera(int index)
{
    videoCapture.open(index);//(ui->device_list->currentIndex());
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 10000);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 10000);
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

    QString auto_name = school + "_" + initials + "_" + object + "_" + wavelength + "_" + object_number;
    QString savefilename = QFileDialog::getSaveFileName(this,"Save Image",auto_name,tr("Bitmap (*.bmp);;JPEG (*.jpg)"));

    if (savefilename.isEmpty())
    {
        qDebug() << "empty";
    }
    else
    {
        qDebug() << savefilename;
    }
    //cv::imwrite(savefilename,buffered_snapshot);

}
