#include "detecciondefondo.h"
#include "ui_detecciondefondo.h"

#include "imagenes.h"
#include "video.h"
#include "mainwindow.h"

#include <QFileDialog>


detecciondefondo::detecciondefondo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detecciondefondo)
{
    ui->setupUi(this);
}

detecciondefondo::~detecciondefondo()
{
    delete ui;
}

void detecciondefondo::changeEvent(QEvent *e)
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

//función que compara 2 píxeles, devuelve 1 si el pixel1 es mayor que el segundo, 2 si es menor, 0 si son iguales y -1 en otro caso
int detecciondefondo::compararPixeles(CvScalar pixel1, CvScalar pixel2){
    if(pixel1.val[0]==pixel2.val[0] && pixel1.val[1]==pixel2.val[1] && pixel1.val[2]==pixel2.val[2]){
        return 0;
    }
    if(pixel1.val[0]>=pixel2.val[0] && pixel1.val[1]>=pixel2.val[1] && pixel1.val[2]>=pixel2.val[2]){
        return 1;
    }
    if(pixel1.val[0]<=pixel2.val[0] && pixel1.val[1]<=pixel2.val[1] && pixel1.val[2]<=pixel2.val[2]){
        return 2;
    }
    return -1;
}

CvScalar detecciondefondo::obtenerPixelCorrecto(CvScalar pixelMinimo, CvScalar pixelMaximo, CvScalar pixelEntrada, CvScalar pixelActivo){
    if(compararPixeles(pixelEntrada, pixelMinimo)==1 && compararPixeles(pixelEntrada, pixelMaximo)==2){//si el pixel del frame del vídeo de entrada es mayor que el pixel de la imagen mínima...
        return pixelActivo;                                                          //...y también es menor que el píxel de la imagen máxima...
    }                                                                                //...entonces debemos sustituirlo por el píxel activo
    if(compararPixeles(pixelEntrada, pixelMinimo)==0 || compararPixeles(pixelEntrada, pixelMaximo)==0){
        return pixelActivo;
    }
    return pixelEntrada;                                                            //En otro caso devolvemos el píxel del frame de entrada.

}

void detecciondefondo::obtenerFrameResultado(IplImage *frameResultado, IplImage *frameEntrada, IplImage *imgMinima, IplImage *imgMaxima, IplImage *imgActiva){
    //Variables
    CvScalar pixelEntrada, pixelResultado, pixelMinimo, pixelMaximo, pixelActivo;

    //Acciones
    for(int i=0; i<frameEntrada->width; i++){                                       //recorremos cada píxel del frame
        for(int j=0; j<frameEntrada->height; j++){
            pixelMinimo= cvGet2D(imgMinima, j, i);                                  //obtenemos el píxel del frame
            pixelMaximo= cvGet2D(imgMaxima, j, i);                                  //obtenemos el píxel de la imagenMinima
            pixelEntrada= cvGet2D(frameEntrada, j, i);
            pixelActivo= cvGet2D(imgActiva, j, i);
            pixelResultado= obtenerPixelCorrecto(pixelMinimo, pixelMaximo, pixelEntrada, pixelActivo);//obtenemos el píxel resultado
            cvSet2D(frameResultado, j, i, pixelResultado);                          //guardamos el pixel resultado en el frame de salida
        }
    }
}

void detecciondefondo::detectarFondo(QString nombreVideoResultado, QString nombreVideoEntrada, QString nombreImgMinima, QString nombreImgMaxima, QString nombreImgActiva){
    //Variables
    IplImage *imgMinima= cvLoadImage(nombreImgMinima.toAscii());                    //cargamos la imagen minima
    IplImage *imgMaxima= cvLoadImage(nombreImgMaxima.toAscii());                    //cargamos la imagen máxima;
    IplImage *imgActiva= cvLoadImage(nombreImgActiva.toAscii());                    //cargamos la Imagen activa
    IplImage *imgActivaEscalada= cvCloneImage(imgMinima);                           //imagen activa para escalar
    IplImage *frameEntrada= cvCloneImage(imgMinima);                                //Frame del vídeo de entrada
    IplImage *frameResultado= cvCloneImage(imgMinima);                              //Frame del vídeo de salida
    CvCapture *videoEntrada= cvCaptureFromFile(nombreVideoEntrada.toAscii());       //asignamos el capturador al archivo de vídeo
    CvVideoWriter* videoResultado= cvCreateVideoWriter(nombreVideoResultado.toAscii(), CV_FOURCC('M','J','P','G'), 20, cvGetSize(frameEntrada));//Creamos el video de salida.

    //Acciones
    if(!videoEntrada) return;                                                       //si no hay ningún error continuamos
    //cvResize(imgActiva, imgActivaEscalada, CV_INTER_CUBIC);                         //Escalamos la imagen activa al tamaño del vídeo
    frameEntrada= cvQueryFrame(videoEntrada);                                       //obtenemos el primer frame del vídeo de entrada

    while(frameEntrada!=NULL){                                                      //vamos obteniendo cada uno de los frames del vídeo
        obtenerFrameResultado(frameResultado, frameEntrada, imgMinima, imgMaxima, imgActiva);//obtenemos el frame resultado
        cvWriteFrame(videoResultado, frameResultado);                               //escribimos el frame obtenido en el vídeo de salida

        frameEntrada= cvQueryFrame(videoEntrada);                                   //frame del vídeo de entrada
    }

    cvReleaseImage(&imgMinima);
    cvReleaseImage(&imgMaxima);
    cvReleaseImage(&imgActiva);
    cvReleaseImage(&imgActivaEscalada);
    cvReleaseImage(&frameEntrada);
    cvReleaseImage(&frameResultado);
    cvReleaseVideoWriter(&videoResultado);
    cvReleaseCapture(&videoEntrada);

}
void detecciondefondo::on_pushButton_3_clicked()
{
    QString nombre= QFileDialog::getOpenFileName();                         //Obtenemos el nombre del archivo a abrir
    if (!nombre.isEmpty())
        ui->lineEdit->setText(nombre.toAscii());                            //lo almacenamos en el lineEdit de la GUI
}

void detecciondefondo::on_pushButton_4_clicked()
{
    QString nombre= QFileDialog::getOpenFileName();                         //Obtenemos el nombre del archivo a abrir
    if (!nombre.isEmpty())
        ui->lineEdit_2->setText(nombre.toAscii());                          //lo almacenamos en el lineEdit de la GUI
}


void detecciondefondo::on_pushButton_5_clicked()
{
    QString nombre= QFileDialog::getOpenFileName();                         //Obtenemos el nombre del archivo a abrir
    if (!nombre.isEmpty())
        ui->lineEdit_3->setText(nombre.toAscii());                          //lo almacenamos en el lineEdit de la GUI
}

void detecciondefondo::on_pushButton_6_clicked()
{
    QString nombre= QFileDialog::getOpenFileName();                         //Obtenemos el nombre del archivo a abrir
    if (!nombre.isEmpty())
        ui->lineEdit_4->setText(nombre.toAscii());                          //lo almacenamos en el lineEdit de la GUI
}

void detecciondefondo::on_pushButton_clicked()
{
    //Variables
    QString nombreImgMinima= ui->lineEdit->text().toAscii();
    QString nombreImgMaxima= ui->lineEdit_2->text().toAscii();
    QString nombreImgActiva= ui->lineEdit_3->text().toAscii();
    QString nombreVideoEntrada= ui->lineEdit_4->text().toAscii();
    QString nombreVideoSalida;

    //Acciones
    if(nombreImgMinima!=NULL && nombreImgMaxima!=NULL && nombreImgActiva!=NULL && nombreVideoEntrada!=NULL){
        nombreVideoSalida= QFileDialog::getSaveFileName(w, "Guardar vídeo", ".", FiltroVideo);    //obtenemos el nombre del vídeo
        detectarFondo(nombreVideoSalida, nombreVideoEntrada, nombreImgMinima, nombreImgMaxima, nombreImgActiva);
        close();
    }
}

void detecciondefondo::on_pushButton_2_clicked()
{
    close();
}
