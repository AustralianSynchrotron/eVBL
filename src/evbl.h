#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QFileDialog>


#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

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

    void on_device_list_currentIndexChanged(int index);
    void on_zoom_setting_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::eVBL *ui;

    void display_capture(cv::Mat display, float scale_amount);
    void set_camera(int index);

    cv::VideoCapture videoCapture;
    cv::Mat buffered_snapshot;
    cv::Mat preview_frame;
    cv::Mat output_preview;

protected:
    void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
