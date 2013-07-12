#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QFileDialog>
#include <QTimer>

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
    void multi_shot();
    void on_device_list_currentIndexChanged(int index);
    void on_zoom_setting_currentIndexChanged();
    void on_zoom_setting_process_currentIndexChanged();
    void recentre_vertical_capture(int min_bar, int max_bar);
    void recentre_horizontal_capture(int min_bar, int max_bar);
    void recentre_vertical_analyse(int min_bar, int max_bar);
    void recentre_horizontal_analyse(int min_bar, int max_bar);
    void on_save_image_button_clicked();
    void update_video();
    void on_evbl_tabs_currentChanged(int index);

    void on_open_analysis_button_clicked();

private:
    Ui::eVBL *ui;

    void display_capture(cv::Mat display);
    void display_analyse(cv::Mat display);
    void set_camera(int index);

    QTimer *preview_timer;
    cv::VideoCapture videoCapture;
    cv::Mat buffered_snapshot;
    cv::Mat preview_frame;
    cv::Mat output_preview;
    cv::Mat analyse_image;              //loaded image altered for editing
    cv::Mat manipulated_image;          //loaded image sitting fresh in buffer ready for resetting
    cv::Mat analyse_image_displayed;    //resised version of analyse_image for display in widget

protected:
    //void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
