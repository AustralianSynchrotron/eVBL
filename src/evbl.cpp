#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <cvimagewidget.h>
#include "camerathread.h"

#define EVBL_MAX_IMAGE_HEIGHT 1944
#define EVBL_MAX_IMAGE_WIDTH 2592
#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 40


eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    //qRegisterMetaType(cv::Mat);

    connect(&camera_thread, SIGNAL(sendPreview()), this, SLOT(updatePreview()), Qt::QueuedConnection);
    camera_thread.start();

    /*
    videoCapture.open(0);

    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 100000);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 100000);
    qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
    qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));




    //combo box showing the attached camera devices
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = QCamera::deviceDescription(deviceName);
        ui->device_list->addItem(description);
    }



    //set up the video preview screen and start it running
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, EVBL_MAX_IMAGE_HEIGHT);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, EVBL_MAX_IMAGE_WIDTH);
    //startTimer(EVBL_PREVIEW_WINDOW_REFRESH);
    */

}

void eVBL::updatePreview() {
    qDebug() << "update preview";
}

eVBL::~eVBL()
{
    camera_thread.quit();
    camera_thread.wait();
    delete ui;

}

void eVBL::timerEvent(QTimerEvent*) {


}


void eVBL::take_shot()
{

    preview_frame.copyTo(buffered_snapshot);

    display_capture(buffered_snapshot);

    //videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, EVBL_PREVIEW_WINDOW_HEIGHT);
    //videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, EVBL_PREVIEW_WINDOW_WIDTH);
    //ui->capture_frame->setEnabled(true);

}

void eVBL::display_capture(cv::Mat display)
{
    cv::Mat output_display;
    cv::resize(display,output_display,cv::Size(),0.25,0.25,cv::INTER_CUBIC);
    ui->display_capture_frame->showImage(output_display);

}
