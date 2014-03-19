#include "mediaponderada.h"
#include "ui_mediaponderada.h"

mediaponderada::mediaponderada(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mediaponderada)
{
    ui->setupUi(this);
    nfoto= foto_activa();
    nfoto2= nfoto;
    for (int i= 0, pos= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            ui->listWidget->addItem(QString(foto[i].nombre));
            corresp[pos++]= i;
        }
    }
    imgUno= foto[nfoto].img;
    imgDos= cvCreateImage(cvGetSize(imgUno), imgUno->depth, imgUno->nChannels);
    imgRes= cvCreateImage(cvGetSize(imgUno), imgUno->depth, imgUno->nChannels);
}

mediaponderada::~mediaponderada()
{
    cvDestroyWindow("Media ponderada");
    cvReleaseImage(&imgDos);
    cvReleaseImage(&imgRes);
    delete ui;
}

void mediaponderada::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void mediaponderada::on_horizontalSlider_valueChanged(int value)
{
    if (ui->checkBox->isChecked()) {
        double peso= ui->horizontalSlider->value()/100.0;
        cvAddWeighted(imgUno, peso, imgDos, 1.0-peso, 0, imgRes);
        cvNamedWindow("Media ponderada", 0);
        cvShowImage("Media ponderada", imgRes);
    }
}

void mediaponderada::on_listWidget_currentRowChanged(int currentRow)
{
    nfoto2= corresp[currentRow];
    cvResize(foto[corresp[currentRow]].img, imgDos, CV_INTER_CUBIC);
    on_horizontalSlider_valueChanged(ui->horizontalSlider->value());
}

void mediaponderada::on_buttonBox_accepted()
{
    double peso= ui->horizontalSlider->value()/100.0;
    media_ponderada(nfoto, nfoto2, primera_libre(), peso);
}
