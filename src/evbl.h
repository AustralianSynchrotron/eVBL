#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimedia/QCameraImageCapture>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include "camerathread.h"

namespace Ui {
class eVBL;
}

class eVBL : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit eVBL(QWidget *parent = 0);
    ~eVBL();

private slots:
    void take_shot();
    void updatePreview();

private:
    Ui::eVBL *ui;

    void display_capture(cv::Mat display);

    cv::VideoCapture videoCapture;
    cv::Mat buffered_snapshot;
    cv::Mat preview_frame;
    cv::Mat output_preview;
    CameraThread camera_thread;

protected:
    void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
