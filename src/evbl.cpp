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
    imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);



    //connection for displaying image when captured
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(showCapturedImage(int,QImage)));
    //connection for capturing image when button clicked
    connect(ui->capture_frame, SIGNAL(clicked()),imageCapture, SLOT(capture()));




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

void eVBL::showCapturedImage(int requestId, const QImage& img)
{
    Q_UNUSED(requestId);
    ui->show_capture->QLabel::setPixmap(QPixmap::fromImage(img));

}
