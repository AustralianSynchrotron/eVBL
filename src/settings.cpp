#include "settings.h"
#include "ui_settings.h"

#include <QSettings>



Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon("./logo-blue.ico"));
    QString settings_file = "./settings.ini";
    QSettings settings(settings_file, QSettings::IniFormat);
    CROP_BOX_SIZE = settings.value("General/crop_box_size",DEFAULT_CROP_BOX_SIZE).toInt();
    PREVIEW_FPS = settings.value("General/preview_fps",DEFAULT_PREVIEW_FPS).toInt();
    MM_PER_PIXEL = settings.value("General/mm_per_pixel",DEFAULT_MM_PER_PIXEL).toFloat();
    INTENSITY_LINE_LENGTH = settings.value("General/intensity_line_length",DEFAULT_INTENSITY_LINE_LENGTH).toInt();

    ui->spin_crop_box_size->setValue(CROP_BOX_SIZE);
    ui->spin_fps->setValue(PREVIEW_FPS);
    ui->spin_mm_per_pixel->setValue(MM_PER_PIXEL);
    ui->spin_intensity_line_length->setValue(INTENSITY_LINE_LENGTH);


}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_button_default_clicked()
{
    CROP_BOX_SIZE = DEFAULT_CROP_BOX_SIZE;
    PREVIEW_FPS = DEFAULT_PREVIEW_FPS;
    MM_PER_PIXEL = DEFAULT_MM_PER_PIXEL;
    INTENSITY_LINE_LENGTH = DEFAULT_INTENSITY_LINE_LENGTH;

    ui->spin_crop_box_size->setValue(CROP_BOX_SIZE);
    ui->spin_fps->setValue(PREVIEW_FPS);
    ui->spin_mm_per_pixel->setValue(MM_PER_PIXEL);
    ui->spin_intensity_line_length->setValue(INTENSITY_LINE_LENGTH);
}

void Settings::on_button_cancel_clicked()
{
    this->close();
}

void Settings::on_button_save_clicked()
{
    QString settings_file = "./settings.ini";
    QSettings settings(settings_file, QSettings::IniFormat);
    settings.setValue("General/crop_box_size",ui->spin_crop_box_size->value());
    settings.setValue("General/preview_fps",ui->spin_fps->value());
    settings.setValue("General/mm_per_pixel",ui->spin_mm_per_pixel->value());
    settings.setValue("General/intensity_line_length",ui->spin_intensity_line_length->value());
    settings.sync();
    this->close();
}
