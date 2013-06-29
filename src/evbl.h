#ifndef EVBL_H
#define EVBL_H

#include <QMainWindow>

namespace Ui {
class eVBL;
}

class eVBL : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit eVBL(QWidget *parent = 0);
    ~eVBL();
    
private:
    Ui::eVBL *ui;
};

#endif // EVBL_H
