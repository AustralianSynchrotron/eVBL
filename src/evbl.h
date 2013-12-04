#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>
#include <QtMultimedia/QCamera>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <QScrollArea>
#include <QMouseEvent>
#include <qmath.h>
#include <QSettings>
#include <QResizeEvent>

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <settings.h>
#include <about.h>

#define EVBL_PREVIEW_WINDOW_HEIGHT 240
#define EVBL_PREVIEW_WINDOW_WIDTH 320
#define DEFAULT_PREVIEW_FPS 25
#define COLOUR_ICON_WIDTH 20
#define COLOUR_ICON_HEIGHT 15
#define DEFAULT_MM_PER_PIXEL 0.1376
#define DEFAULT_INTENSITY_LINE_LENGTH 1024
#define DEFAULT_CROP_BOX_SIZE 1024
#define PI 3.14159265358979323846264338327950288419717

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
    void set_combo_line_colour();
    void on_device_list_currentIndexChanged(int index);
    void on_zoom_setting_currentIndexChanged();
    void on_zoom_setting_process_currentIndexChanged();
    void recentre_vertical_capture(int min_bar, int max_bar);
    void recentre_horizontal_capture(int min_bar, int max_bar);
    void recentre_vertical_analyse(int min_bar, int max_bar);
    void recentre_horizontal_analyse(int min_bar, int max_bar);
    void change_rotate_spinbox(int val);
    void change_rotate_slider(double val);
    void on_save_image_button_clicked();
    void update_video();
    void on_evbl_tabs_currentChanged(int index);
    void on_open_analysis_button_clicked();
    void check_background_size();
    void apply_manipulations();
    void apply_smooth_bg();
    void on_background_button_clicked();
    void threshold_high();
    void threshold_low();
    void on_reset_image_clicked();
    void draw_length_line();
    void draw_angle_line();
    void draw_crop_box();
    void show_angle();
    void draw_intensity_line();
    void get_intensity_profile();
    void apply_overlay_lines();
    void reset_crop_box();
    void reset_intensity_line();
    QString prepare_intensity_data_string();
    void read_setting_values();

    void on_combo_line_colour_currentIndexChanged(int index);

    void on_anal_type_tab_currentChanged(int index);

    void on_radio_degrees_toggled();


    void on_combo_line_thickness_currentIndexChanged();

    void on_clipboard_button_clicked();

    void on_file_button_clicked();

    void on_crop_button_clicked();

    void on_capture_frame_button_clicked();

    void on_multi_frame_button_clicked();

    void on_check_log_clicked();

    void on_actionExit_triggered();

    void on_actionSettings_triggered();

    void on_actionAbout_triggered();

    void on_spin_intensity_width_valueChanged();

private:
    Ui::eVBL *ui;

    Settings *settings;
    about* about_display;


    void display_capture(cv::Mat display);
    void display_analyse(cv::Mat display);
    void set_camera(int index);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void draw_box(cv::Mat img, int x_point, int y_point);
    void draw_line(cv::Mat img, int x1, int y1, int x2, int y2);
    void draw_circle(cv::Mat img, int x_point, int y_point);


    cv::Mat apply_threshold(cv::Mat display);
    cv::Mat apply_log(cv::Mat display);

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
    cv::Mat intensity_preview;          //plot of intensity profile
    cv::Mat intensity_preview_resized;  //shrunk version of preview
    cv::Scalar line_colour;             //set colour of the analyse image lines

    int CROP_BOX_SIZE = DEFAULT_CROP_BOX_SIZE;
    int PREVIEW_FPS = DEFAULT_PREVIEW_FPS;
    float MM_PER_PIXEL = DEFAULT_MM_PER_PIXEL;
    int INTENSITY_LINE_LENGTH = DEFAULT_INTENSITY_LINE_LENGTH;



protected:
    //void timerEvent(QTimerEvent*);

};


#endif // EVBL_H
