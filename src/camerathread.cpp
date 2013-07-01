#include "camerathread.h"
#include <QTimer>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <QDebug>

#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define EVBL_PREVIEW_WINDOW_REFRESH 40

CameraThread::CameraThread(QObject *parent) :
    QThread(parent)
{
    videoCapture.open(0);
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, 100000);
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, 100000);
}

void CameraThread::run() {
    QTimer timer;
    connect(&timer,SIGNAL(timeout()),this,SLOT(update()),Qt::DirectConnection);
    timer.setInterval(EVBL_PREVIEW_WINDOW_REFRESH);
    timer.start();
    exec();
    timer.stop();
}

void CameraThread::update() {
    videoCapture.read(bufferedFrame);
    cv::resize(bufferedFrame,previewFrame,cv::Size(EVBL_PREVIEW_WINDOW_WIDTH,EVBL_PREVIEW_WINDOW_HEIGHT),0,0,cv::INTER_AREA);
    emit sendPreview();
    //ui->previewVideo->showImage(output_preview);
}
