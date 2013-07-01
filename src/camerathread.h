#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

class CameraThread : public QThread
{
    Q_OBJECT
public:
    explicit CameraThread(QObject *parent = 0);
    
private:
    void run();

    cv::VideoCapture videoCapture;
    cv::Mat bufferedFrame;
    cv::Mat previewFrame;

signals:
    void sendPreview();

public slots:

private slots:
    void update();
    
};

#endif // CAMERATHREAD_H
