#include "camerathread.h"
#include <QDebug>

CameraThread::CameraThread(QObject *parent) :
    QThread(parent)
{

}

void CameraThread::run() {
    qDebug() << "CameraThread::run()";
}

void CameraThread::update() {
    qDebug() << "CameraThread::run()";
}
