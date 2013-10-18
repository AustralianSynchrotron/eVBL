#include "evbl.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eVBL w;
    w.show();
    
    return a.exec();
}
