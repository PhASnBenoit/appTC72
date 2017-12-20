#include "cihmapptc72.h"
#include "ui_cihmapptc72.h"

CIhmAppTC72::CIhmAppTC72(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmAppTC72)
{
    ui->setupUi(this);
    m_tc72 = new CCapteur_Spi_TC72_NTh(this, '0');
    connect(m_tc72, SIGNAL(sigErreur(QString)), this, SLOT(onErreur(QString)));
}

CIhmAppTC72::~CIhmAppTC72()
{
    delete m_tc72;
    delete ui;
}

void CIhmAppTC72::on_pbId_clicked()
{
    quint8 ref;

    ref  = m_tc72->getManufacturer();
    onErreur("Id fabricant (hex) : "+QString::number(ref,16));
}

void CIhmAppTC72::on_pbMesure_clicked()
{
    float mesure;

    mesure = m_tc72->getTemperature();
    onErreur("Mesure : "+QString::number(mesure,'f',1)+" °C");
}

void CIhmAppTC72::onErreur(QString mess)
{
 ui->textEdit->append(mess);
}
