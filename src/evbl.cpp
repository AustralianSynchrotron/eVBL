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
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = QCamera::deviceDescription(deviceName);
        ui->device_list->addItem(description);
    }

    set_camera(0);

    startTimer(EVBL_PREVIEW_WINDOW_REFRESH);

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

    display_capture(buffered_snapshot,0.1);

}

void eVBL::display_capture(cv::Mat display, float scale_amount )
{
    cv::Mat output_display;
    cv::resize(display,output_display,cv::Size(),scale_amount,scale_amount,cv::INTER_LINEAR);
    ui->display_capture_frame->showImage(output_display);

}

void eVBL::set_camera(int index)
{
    qDebug() << index;//ui->device_list->currentIndex();
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

void eVBL::on_zoom_setting_currentIndexChanged(const QString &arg1)
{
    QString str_val = arg1;
    qDebug() << str_val;

    if (str_val == "Fit")
    {
        qDebug() << "fit set";
    }
    else
    {
        QString strip_val = str_val.replace("%","");
        float val = strip_val.toFloat() / 100.0 ;
        display_capture(buffered_snapshot,val);
    }

}

void eVBL::on_pushButton_clicked()
{
    //get text to create auto filename
    QString initials = ui->info_initials->text();
    QString school = ui->info_school->text();
    QString distance = ui->info_distance->text();
    QString object = ui->combo_object->currentText();
    QString object_number = ui->combo_objectnumber->currentText();
    QString wavelength = ui->combo_wavelength->currentText();

    QString auto_name = school + "_" + initials + "_" + object + "_" + wavelength + "_" + object_number;
    QFileDialog::getSaveFileName();
}
