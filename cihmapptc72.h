#ifndef CIHMAPPTC72_H
#define CIHMAPPTC72_H

#include <QMainWindow>
#include <QDebug>
#include "/home/pi/devQt/biblis/cspi.h"
#include "ccapteur_spi_tc72_nth.h"

namespace Ui {
class CIhmAppTC72;
}

class CIhmAppTC72 : public QMainWindow
{
    Q_OBJECT

public:
    explicit CIhmAppTC72(QWidget *parent = 0);
    ~CIhmAppTC72();

private slots:
    void on_pbId_clicked();
    void on_pbMesure_clicked();
    void onErreur(QString mess);

private:
    Ui::CIhmAppTC72 *ui;
    CCapteur_Spi_TC72_NTh *m_tc72;
};

#endif // CIHMAPPTC72_H
