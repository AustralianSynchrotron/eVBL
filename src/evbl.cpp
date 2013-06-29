#include "evbl.h"
#include "ui_evbl.h"

eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);

    //set up the video preview screen and start it running
    camera = new QCamera;
    camera->setViewfinder(ui->viewFinder);
    camera->start();

    //set up the process for capturing still images for the main display
    imageCapture = new QCameraImageCapture(camera);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToBuffer);

    //imageCapture->capture();


    //combo box showing the attached camera devices
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = camera->deviceDescription(deviceName);
        ui->device_list->addItem(description);
        qDebug() << description;
    }

    //here is all the debugging shit
    qDebug() << imageCapture->supportedBufferFormats().count();
    foreach(const QVideoFrame::PixelFormat &bufferformat, imageCapture->supportedBufferFormats())
    {
        qDebug() << bufferformat;
    }

}

eVBL::~eVBL()
{
    delete ui;
}
