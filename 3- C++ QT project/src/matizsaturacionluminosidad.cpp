#include "matizsaturacionluminosidad.h"
#include "ui_matizsaturacionluminosidad.h"

#include "imagenes.h"

matizsaturacionluminosidad::matizsaturacionluminosidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matizsaturacionluminosidad)
{
    ui->setupUi(this);
    nfoto= foto_activa();
    matiz= 1.0;
    saturacion= 1.0;
    luminosidad= 1;
}

matizsaturacionluminosidad::~matizsaturacionluminosidad()
{
    delete ui;
}

void matizsaturacionluminosidad::changeEvent(QEvent *e)
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

void matizsaturacionluminosidad::actualiza_matiz_sat_lumin()
{
    matiz= ui->horizontalSlider->value();
    saturacion=  ui->horizontalSlider_2->value()/10.0;
    luminosidad=  ui->horizontalSlider_3->value()/10.0;
}

void matizsaturacionluminosidad::on_spinBox_3_valueChanged(int valor)
{
    ui->horizontalSlider_3->setValue(valor);
}

void matizsaturacionluminosidad::on_spinBox_2_valueChanged(int valor)
{
    ui->horizontalSlider_2->setValue(valor);
}

void matizsaturacionluminosidad::on_spinBox_valueChanged(int valor)
{
    ui->horizontalSlider->setValue(valor);
}


void matizsaturacionluminosidad::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
    actualiza_matiz_sat_lumin();
    if (ui->checkBox->isChecked())
        ver_matiz_sat_lumin(nfoto, matiz, saturacion, luminosidad);
}

void matizsaturacionluminosidad::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
    actualiza_matiz_sat_lumin();
    if (ui->checkBox->isChecked())
        ver_matiz_sat_lumin(nfoto, matiz, saturacion, luminosidad);
}

void matizsaturacionluminosidad::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
    actualiza_matiz_sat_lumin();
    if (ui->checkBox->isChecked())
        ver_matiz_sat_lumin(nfoto, matiz, saturacion, luminosidad);
}

void matizsaturacionluminosidad::on_buttonBox_rejected()
{
    mostrar(nfoto);
}

void matizsaturacionluminosidad::on_buttonBox_accepted()
{
    actualiza_matiz_sat_lumin();
    ver_matiz_sat_lumin(nfoto, matiz, saturacion, luminosidad, true);
}
