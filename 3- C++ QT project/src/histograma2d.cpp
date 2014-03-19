#include "histograma2d.h"
#include "ui_histograma2d.h"
#include "imagenes.h"
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>



histograma2D::histograma2D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::histograma2D)
{
    ui->setupUi(this);
}

histograma2D::~histograma2D()
{
    delete ui;
}

void histograma2D::changeEvent(QEvent *e)
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

void histograma2D::mostrarHistograma(char tipo[]){
    int nCeldas[2]= {64,64};          //número de posiciones a mostrar (generalmente serán 256, pero pueden ser menos)

    CvHistogram* histograma;            //histograma
    IplImage *planos[2];                //Atray de 3 imágenes que serán la imagen en rojo, verde y azul.
    IplImage *imgnHistograma;           //histograma en forma de imagen
    int i, j;                           //iterador
    float bin_val;                      //valor que usaremos para recorrer cada posición del histograma
    int fa= foto_activa();              //número de foto activa
    if(fa!=-1){
        histograma= cvCreateHist(2,nCeldas,CV_HIST_ARRAY);                         //creamos el histograma
        planos[0]= cvCreateImage(cvGetSize(foto[fa].img), 8, 1);                   //creamos las imágenes sobre las que trabajaremos
        planos[1]= cvCreateImage(cvGetSize(foto[fa].img), 8, 1);
        imgnHistograma= cvCreateImage( cvSize(nCeldas[0]-1,nCeldas[1]-1), 8, 3 );  //creamos la imagen sobre la que mostraremos el histograma

        if(tipo[0]=='R' && tipo[1]=='V')        cvSplit(foto[fa].img, NULL, planos[1], planos[0], NULL);    //dependiendo del histograma que estemos calculando...
        else if(tipo[0]=='R' && tipo[1]=='A')   cvSplit(foto[fa].img, planos[1], NULL, planos[0], NULL);    //...llenaremos el array de 2 imágenes con los valores...
        else if(tipo[0]=='V' && tipo[1]=='A')   cvSplit(foto[fa].img, planos[1], planos[0], NULL, NULL);    //...de azul, verde o rojo de la imagen

        cvCalcHist(planos,histograma,0);                                            //calculamos el histograma

        for( i = 0; i < nCeldas[0]; i++ ){                                          //vamos dibujando el histograma
            for(j=0;j<nCeldas[1];j++){
                bin_val = cvQueryHistValue_2D( histograma, i, j);
                cvCircle(imgnHistograma, cvPoint(i, j), 1, CV_RGB(255-(bin_val),255-(bin_val),255-(bin_val)), -1);
            }
        }

        cvNamedWindow("Histograma",1);
        cvShowImage("Histograma",imgnHistograma);                                   //mostramos el histograma en una ventana
        cvReleaseImage(&imgnHistograma);                                            //liberamos la memoria usada
        cvReleaseHist(&histograma);
        for(i=0;i<3;i++){
            cvReleaseImage(&planos[i]);
        }
    }
}
void histograma2D::on_pushButton_clicked()
{
    char cadena[]= "RV";
    mostrarHistograma(cadena);
}

void histograma2D::on_pushButton_2_clicked()
{
    char cadena[]= "RA";
    mostrarHistograma(cadena);
}

void histograma2D::on_pushButton_3_clicked()
{
    char cadena[]= "VA";
    mostrarHistograma(cadena);
}
