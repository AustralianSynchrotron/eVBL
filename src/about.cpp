#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowTitleHint);
}

about::~about()
{
    delete ui;
}

void about::on_about_close_button_clicked()
{
    this->close();
}
