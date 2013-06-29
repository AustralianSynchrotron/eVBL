#include "evbl.h"
#include "ui_evbl.h"

eVBL::eVBL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eVBL)
{
    ui->setupUi(this);
}

eVBL::~eVBL()
{
    delete ui;
}
