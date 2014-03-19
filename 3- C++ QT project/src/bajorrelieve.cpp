#include "bajorrelieve.h"
#include "ui_bajorrelieve.h"

#include <imagenes.h>

bajorrelieve::bajorrelieve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bajorrelieve)
{
    ui->setupUi(this);
}

bajorrelieve::~bajorrelieve()
{
    cvDestroyWindow("previsualizacion");
    delete ui;
}

void bajorrelieve::changeEvent(QEvent *e)
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

void bajorrelieve::mostrarBR(bool guardar){
        //Variables
        int nfoto = foto_activa();
        int cantidad= ui->horizontalSlider->value();
        int direccion= ui->horizontalSlider_2->value();
        IplImage *gris= cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,1);
        IplImage *img16S=cvCreateImage(cvGetSize(foto[nfoto].img), IPL_DEPTH_16S, 1);
        IplImage *resultado=cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,3);

        //Acciones
        cvCvtColor(foto[nfoto].img,gris,CV_RGB2GRAY);                   //guardamos la imagen a escala de grises
        cvSobel (gris, img16S, direccion, cantidad, 5);                                   //aplicamos el bajorrelieve
        cvConvertScale(img16S, gris, 1, 0);//direccion, cantidad);                         //convertimos el resultado a gris
        cvCvtColor(gris,resultado,CV_GRAY2RGB);                         //convertimos la imagen resultado al espacio rgb

        if(guardar){                                                    //la guardamos si es necesario
            crear_nueva(primera_libre(),resultado);
        }
        else{
            cvShowImage("previsualizacion", resultado);
            cvReleaseImage(&resultado);
        }

        cvReleaseImage(&img16S);                                           //liberamos memoria
        cvReleaseImage(&gris);

}

void bajorrelieve::on_horizontalSlider_2_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        mostrarBR(false);
    }
}

void bajorrelieve::on_horizontalSlider_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        mostrarBR(false);
    }
}

void bajorrelieve::on_pushButton_clicked()
{
    mostrarBR(true);
    close();
}

void bajorrelieve::on_pushButton_2_clicked()
{
    close();
}
