#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QFileDialog>
#include <QTimer>
#include <QPixmap>
#include <QScrollArea>
#include <QMouseEvent>
#include <qmath.h>

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
    void set_combo_line_colour();
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
    void apply_manipulations();
    void apply_smooth_bg();
    void on_background_button_clicked();
    void threshold_high();
    void threshold_low();
    void on_reset_image_clicked();
    void draw_length_line();
    void draw_angle_line();
    void show_angle();
    void draw_intensity_line();
    void get_intensity_profile();

    void on_combo_line_colour_currentIndexChanged(int index);

    void on_anal_type_tab_currentChanged(int index);

    void on_radio_degrees_toggled(bool checked);

private:
    Ui::eVBL *ui;

    void display_capture(cv::Mat display);
    void display_analyse(cv::Mat display);
    void set_camera(int index);

    void mousePressEvent(QMouseEvent *event);
    void draw_box(cv::Mat img, int x_point, int y_point);
    void draw_line(cv::Mat img, int x1, int y1, int x2, int y2);
    void draw_circle(cv::Mat img, int x_point, int y_point);

    cv::Mat apply_threshold(cv::Mat display);

    QTimer *preview_timer;
    cv::VideoCapture videoCapture;
    cv::Mat buffered_snapshot;
    cv::Mat preview_frame;
    cv::Mat output_preview;
    cv::Mat analyse_image_saved;        //loaded image sitting fresh in buffer ready for resetting
    cv::Mat analyse_image;              //loaded image with processor intensive smoothing functions applied
    cv::Mat manipulated_image;          //loaded image altered for editing
    cv::Mat analyse_image_displayed;    //resised version of analyse_image for display in widget
    cv::Mat background_image;           //background image for subtraction
    cv::Mat analyse_overlay;             //overlay for analyse measurments
    cv::Mat temp_img;                   //temp Mat for immediate fucking about with
    cv::Mat greyscale_analyse;         //greyscale version for intensity profile
    cv::Scalar line_colour;             //set colour of the analyse image lines

protected:
    //void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
