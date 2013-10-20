#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

#define DEFAULT_PREVIEW_FPS 25
#define DEFAULT_MM_PER_PIXEL 0.1376
#define DEFAULT_INTENSITY_LINE_LENGTH 1024
#define DEFAULT_CROP_BOX_SIZE 1024



namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    
private slots:

    void on_button_default_clicked();

    void on_button_cancel_clicked();

    void on_button_save_clicked();

private:
    Ui::Settings *ui;

    int CROP_BOX_SIZE = DEFAULT_CROP_BOX_SIZE;
    int PREVIEW_FPS = DEFAULT_PREVIEW_FPS;
    float MM_PER_PIXEL = DEFAULT_MM_PER_PIXEL;
    int INTENSITY_LINE_LENGTH = DEFAULT_INTENSITY_LINE_LENGTH;



};

#endif // SETTINGS_H
