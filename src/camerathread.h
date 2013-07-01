#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include <opencv2/core/core.hpp>

class CameraThread : public QThread
{
    Q_OBJECT
public:
    explicit CameraThread(QObject *parent = 0);
    
private:
    void run();

    cv::Mat bufferedFrame;

signals:
    void sendPreview(cv::Mat previewFrame);

public slots:

private slots:
    void update();
    
};

#endif // CAMERATHREAD_H
