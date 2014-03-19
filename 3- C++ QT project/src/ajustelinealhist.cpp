#include "ajustelinealhist.h"
#include "ui_ajustelinealhist.h"
#include "imagenes.h"
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

//utilidades
//Función que nos calcula el número total de píxeles con color de un histograma
int numTotalPixeles(CvHistogram *hist){
    //Variables
    int totalPixeles= 0;

    //Acciones
    for(int i=0;i<256;i++){
        totalPixeles= totalPixeles + cvQueryHistValue_1D(hist,i);
    }
    return totalPixeles;
}

//Calcula la posición a la izquierda del histograma ignorando un porcentaje de píxeles
double calculaPosMin(int porcentaje, CvHistogram *hist){
    //Variables
    int numPixelesIgnorados= numTotalPixeles(hist)*porcentaje/100;
    int numPixeles= 0;

    //Acciones
    for(int i=0;i<256;i++){
        numPixeles= numPixeles + cvQueryHistValue_1D(hist,i);
        if(numPixeles>=numPixelesIgnorados){
            return i+0.0;
        }
    }
    return 255.0;
}

//Calcula la posición a la derecha del histograma ignorando un porcentaje de píxeles a la izquierda
double calculaPosMax(int porcentaje, CvHistogram *hist){
    //Variables
    int numPixelesIgnorados= numTotalPixeles(hist)*porcentaje/100;
    int numPixeles= 0;

    //Acciones
    for(int i=255;i>=0;i--){
        numPixeles= numPixeles + cvQueryHistValue_1D(hist,i);
        if(numPixeles>=numPixelesIgnorados){
            return i+0.0;
        }
    }
    return 0.0;
}

ajustelinealhist::ajustelinealhist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajustelinealhist)
{
    ui->setupUi(this);
    nfoto = foto_activa();
}

ajustelinealhist::~ajustelinealhist()
{    
    cvDestroyWindow("previsualizacion");
    delete ui;
}

void ajustelinealhist::changeEvent(QEvent *e)
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

//procedimiento que nos ajusta linealmente la imagen, si le pasamos true la guarda, si no no
void ajustelinealhist::ajustarLinealmente(bool guardar){
    //Variables
    int celdas=256;
    double posMin;
    double posMax;
    CvHistogram *hist= cvCreateHist(1,&celdas,CV_HIST_ARRAY);                               //histograma
    IplImage *gris=cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,1);      //canal gris
    IplImage *rojo= cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,1);     //canal rojo
    IplImage *verde= cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,1);    //canal verde
    IplImage *azul= cvCreateImage(cvGetSize(foto[nfoto].img),foto[nfoto].img->depth,1);     //canal azul
    IplImage *resultado= cvCreateImage(cvGetSize(foto[nfoto].img), foto[nfoto].img->depth, 3);//imagen resultado

    //Acciones
    cvCvtColor(foto[nfoto].img, gris, CV_RGB2GRAY);                                           //convertimos la imagen a grises
    cvCalcHist(&gris, hist);                                                                 //calculamos su histograma
    cvNormalizeHist(hist, 1000.0);                                                           //lo normalizamos

    cvSplit(foto[nfoto].img, azul, verde, rojo, 0);                                         //obtenemos los canales rgb de la imagen

    posMin= calculaPosMin(ui->horizontalSlider_2->value(), hist);                           //calculamos la posición mínima a tener en cuenta del histograma
    posMax= calculaPosMax(ui->horizontalSlider->value(), hist);                             //calculamos la posición máxima a tener en cuenta del histograma

    cvScale(azul, azul,255.0/(posMax-posMin), -posMin*255.0/(posMax-posMin));
    cvScale(verde, verde,255.0/(posMax-posMin), -posMin*255.0/(posMax-posMin));
    cvScale(rojo, rojo,255.0/(posMax-posMin), -posMin*255.0/(posMax-posMin));
    //cvNormalize(azul, azul, posMin, posMax, CV_MINMAX);                                     //ajustamos linealmente cada uno de los canales de la imagen
    //cvNormalize(verde, verde, posMin, posMax, CV_MINMAX);
    //cvNormalize(rojo, rojo, posMin, posMax, CV_MINMAX);

    cvMerge(azul, verde, rojo, 0, resultado);                                               //creamos la imagen resultado

    if(guardar){
        crear_nueva(primera_libre(), resultado);                                            //almacenamos la imagen en el array
    }
    else{
        cvShowImage("previsualizacion", resultado);                                         //la previsualizamos
        cvReleaseImage(&resultado);
    }

    cvReleaseHist(&hist);                                                                   //liberamos memoria
    cvReleaseImage(&gris);
    cvReleaseImage(&rojo);
    cvReleaseImage(&verde);
    cvReleaseImage(&azul);    
}

void ajustelinealhist::on_pushButton_clicked()
{
    ajustarLinealmente(true);
    close();
}

void ajustelinealhist::on_horizontalSlider_2_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        ajustarLinealmente(false);
    }
}

void ajustelinealhist::on_horizontalSlider_valueChanged(int value)
{
    if(ui->checkBox->isChecked()){
        ajustarLinealmente(false);
    }
}

void ajustelinealhist::on_pushButton_2_clicked()
{
    close();
}


