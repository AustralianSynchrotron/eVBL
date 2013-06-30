#include "evbl.h"
#include "ui_evbl.h"

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <cvimagewidget.h>

eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    videoCapture.open(0);

    //set up the video preview screen and start it running
    /*
    camera = new QCamera;
    camera->setViewfinder(ui->viewFinder);
    camera->start();

    */
    connect(ui->capture_frame, SIGNAL(clicked()),this, SLOT(take_shot()));




/*
    //set up the process for capturing still images for the main display
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);



    //connection for displaying image when captured
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(showCapturedImage(int,QImage)));
    //connection for capturing image when button clicked
    connect(ui->capture_frame, SIGNAL(clicked()),imageCapture, SLOT(capture()));


   */

    //combo box showing the attached camera devices
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = camera->deviceDescription(deviceName);
        ui->device_list->addItem(description);
        qDebug() << description;
    }

    startTimer(100);

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
    /*
    camera->stop();
    cv::VideoCapture cap(0);
    cv::Mat frame;

       //cap >> frame; // get a new frame from camera

    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(CV_CAP_PROP_BRIGHTNESS,128);
    cap.set(CV_CAP_PROP_CONTRAST,32);
    cap.set(CV_CAP_PROP_SATURATION,32);

    cap.open(0);
    */
    cv::Mat frame;
    videoCapture.read(frame);
    ui->cvwidget_test->showImage(frame);
}
