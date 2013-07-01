#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <cvimagewidget.h>

#define EVBL_MAX_IMAGE_HEIGHT 1944
#define EVBL_MAX_IMAGE_WIDTH 2592
#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 100


eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    videoCapture.open(0);

    //qDebug() << cv::getTickFrequency();

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
    startTimer(EVBL_PREVIEW_WINDOW_REFRESH);

}

eVBL::~eVBL()
{
    delete ui;
}

void eVBL::timerEvent(QTimerEvent*) {

    videoCapture.read(preview_frame);
    cv::resize(preview_frame,output_preview,cv::Size(EVBL_PREVIEW_WINDOW_WIDTH,EVBL_PREVIEW_WINDOW_HEIGHT),0,0,cv::INTER_AREA);
    ui->previewVideo->showImage(output_preview);
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
