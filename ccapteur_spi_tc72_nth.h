#ifndef CCAPTEUR_SPI_TC72_NTH_H
#define CCAPTEUR_SPI_TC72_NTH_H

#include <QObject>
#include <QThread>

#include "/home/pi/devQt/biblis/cspi.h"

#define ADRESSE 0x80
#define REG_CTRL 0x00
#define REG_LSB 0x01
#define REG_MSB 0x02
#define REG_ID 0x03   // contient 0x54
#define W 0x80
#define RESET 0xfe

typedef enum {
    CONTINUOUS=0,
    ONESHOT=0x11
} T_ETAT;

class CCapteur_Spi_TC72_NTh : public QObject
{
    Q_OBJECT

public:
    explicit CCapteur_Spi_TC72_NTh(QObject *parent = 0, int ce = 0);
    ~CCapteur_Spi_TC72_NTh();
    quint8 getManufacturer();
    float getTemperature();

private:
    CSpi *m_spi;
    int m_ce;
    T_ETAT m_etat;   // état du capteur

    int setMode(T_ETAT etat); // continous ou oneshot
    int reset();
    quint8 getControleRegister();
    int setControleRegister(quint8 val);

signals:
    void sigErreur(QString mess);

private slots:
    void onErreur(QString mess);

};

#endif // CCAPTEURTEMPSPI_NTH_H
