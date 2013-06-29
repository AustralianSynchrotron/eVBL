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
    //imageCapture->setCaptureDestination(ui->imageCap);

    imageCapture->capture();

    //combo box showing the attached camera devices
    foreach(const QByteArray &deviceName, QCamera::availableDevices())
    {
        QString description = camera->deviceDescription(deviceName);
        ui->device_list->addItem(description);
        qDebug() << description;
    }
}

eVBL::~eVBL()
{
    delete ui;
}
