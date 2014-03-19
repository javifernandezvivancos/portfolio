#include "histograma.h"
#include "ui_histograma.h"
#include "imagenes.h"
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

int nPosiciones=256;          //número de posiciones a mostrar (generalmente serán 256)

histograma::histograma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::histograma)
{
    ui->setupUi(this);
}

histograma::~histograma()
{
    delete ui;
}

void histograma::changeEvent(QEvent *e)
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

void histograma::on_pushButton_clicked()
{
    mostrarHistograma('R');
}
void histograma::on_pushButton_2_clicked()
{
    mostrarHistograma('V');
}

void histograma::on_pushButton_3_clicked()
{
    mostrarHistograma('A');
}

void histograma::on_pushButton_4_clicked()
{
    mostrarHistograma('G');
}

void histograma::mostrarHistograma(char tipo){
    CvHistogram* histograma;            //histograma
    IplImage *imagen;                   //imagen modificada
    IplImage *imgnHistograma;           //histograma en forma de imagen
    int i;                              //iterador
    float max_value = 0;                //valor máximo de color
    float valorHistograma;              //valor del histograma en una posición dada
    int fa= foto_activa();              //número de foto activa
    if(fa!=-1){
        histograma= cvCreateHist(1,&nPosiciones,CV_HIST_ARRAY);                     //creamos el histograma
        imagen= cvCreateImage(cvGetSize(foto[fa].img),8,1);                         //creamos la imagen sobre la que trabajaremos
        if(tipo=='R')       cvSplit(foto[fa].img, NULL, NULL, imagen, NULL);        //convertimos la imagen a rojos
        else if(tipo=='V')  cvSplit(foto[fa].img, NULL, imagen, NULL, NULL);        //convertimos la imagen a verdes
        else if(tipo=='A')  cvSplit(foto[fa].img, imagen, NULL, NULL, NULL);        //convertimos la imagen a azules
        else if(tipo=='G')  cvCvtColor(foto[fa].img,imagen,CV_RGB2GRAY);            //convertimos la imagen a escala de grises

        cvCalcHist(&imagen,histograma,0);                                           //calculamos el histograma
        cvGetMinMaxHistValue( histograma, 0, &max_value, 0, 0 );                    //calculamos el valor máximo
        imgnHistograma = cvCreateImage( cvSize(nPosiciones-1,nPosiciones-1), 8, 3 );//creamos la imagen sobre la que mostraremos el histograma
        cvSet(imgnHistograma, CV_RGB(nPosiciones-1,nPosiciones-1,nPosiciones-1));
        for( i = 0; i <= nPosiciones-1; i++ )                                       //vamos dibujando las líneas verticales del histograma
        {
            valorHistograma = cvQueryHistValue_1D( histograma, i);
            cvLine(imgnHistograma,cvPoint(i,nPosiciones-1),cvPoint(i,(nPosiciones-1)-((nPosiciones-1)*valorHistograma/max_value)),CV_RGB(0,0,0),1);
        }

        cvNamedWindow("Histograma",1);
        cvShowImage("Histograma",imgnHistograma);                                   //mostramos el histograma en una ventana
        cvReleaseImage(&imgnHistograma);                                            //liberamos la memoria usada
        cvReleaseHist(&histograma);
        cvReleaseImage(&imagen);
    }
}



