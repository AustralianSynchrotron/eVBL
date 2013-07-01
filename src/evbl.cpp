#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <cvimagewidget.h>

#define EVBL_MAX_IMAGE_HEIGHT 1944
#define EVBL_MAX_IMAGE_WIDTH 2592
#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320

eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    videoCapture.open(0);

    //qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
    //qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);
    //set up the video preview screen and start it running

    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));



    //combo box showing the attached camera devices
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = QCamera::deviceDescription(deviceName);
        ui->device_list->addItem(description);
        qDebug() << description;
    }
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, EVBL_PREVIEW_WINDOW_HEIGHT);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, EVBL_PREVIEW_WINDOW_WIDTH);


    //set up the video preview screen and start it running
    startTimer(40);

}

eVBL::~eVBL()
{
    delete ui;
}

void eVBL::timerEvent(QTimerEvent*) {
    cv::Mat frame;
    videoCapture.read(frame);
    //qDebug() << frame.size().width;
    ui->previewVideo->showImage(frame);
    //QImage* image = new QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    //ui->show_capture->QLabel::setPixmap(QPixmap::fromImage(image));
}


void eVBL::take_shot()
{

    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 3888);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 5184);

    //videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 720);
    //videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 960);
    //cap.set(CV_CAP_PROP_BRIGHTNESS,128);
    //cap.set(CV_CAP_PROP_CONTRAST,32);
    //cap.set(CV_CAP_PROP_SATURATION,32);
    qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_HEIGHT);
    qDebug() << videoCapture.get(CV_CAP_PROP_FRAME_WIDTH);


    cv::Mat buffered_snapshot;
    videoCapture.read(buffered_snapshot);
    ui->cvwidget_test->showImage(buffered_snapshot);

    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, EVBL_PREVIEW_WINDOW_HEIGHT);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, EVBL_PREVIEW_WINDOW_WIDTH);
}
