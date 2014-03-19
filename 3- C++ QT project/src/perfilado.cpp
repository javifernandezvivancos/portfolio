#include "perfilado.h"
#include "ui_perfilado.h"
#include "imagenes.h"

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

perfilado::perfilado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::perfilado)
{
    ui->setupUi(this);
    nfoto = foto_activa();
}

perfilado::~perfilado()
{
    cvDestroyWindow("previsualizacion");
    delete ui;
}

void perfilado::changeEvent(QEvent *e)
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
void perfilado::perfilar(bool guardar){
    //Variables
    IplImage *img= cvCloneImage(foto[nfoto].img);
    int radio= ui->horizontalSlider->value();
    CvMat *mask= cvCreateMatHeader(radio, radio, CV_32FC1);
    float porcentaje= ui->horizontalSlider_2->value();

    float coef[3*3]= {0,-porcentaje,0, -porcentaje,4*porcentaje+1,-porcentaje, 0,-porcentaje,0};// matriz identidad donde irán los pesos
    //float coef2[3*3]= {-1,-1,-1, -1,9,-1, -1,-1,-1}; //valores por defecto

    //Acciones
    cvSetData(mask, coef, radio*sizeof(float));
    cvFilter2D(img, img, mask);

    cvReleaseMat(&mask);

    if(guardar){
        crear_nueva(primera_libre(), img);
    }
    else{
        cvShowImage("previsualizacion", img);
        cvReleaseImage(&img);
    }
}
void perfilado::on_pushButton_clicked()
{
    perfilar(true);
    close();
}

void perfilado::on_pushButton_2_clicked()
{
    close();
}

void perfilado::on_horizontalSlider_2_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        perfilar(false);
    }
}

void perfilado::on_horizontalSlider_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        perfilar(false);
    }
}
