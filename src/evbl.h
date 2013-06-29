#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QtMultimediaWidgets/QCameraViewfinder>
#include <QtMultimedia/QCameraImageCapture>

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
    void showCapturedImage(int requestId, const QImage& img);
    
private:
    Ui::eVBL *ui;

    QCamera *camera;
    QCameraImageCapture *imageCapture;
};

#endif // EVBL_H
