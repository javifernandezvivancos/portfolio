#include "minimamaximadevideo.h"
#include "ui_minimamaximadevideo.h"

#include "imagenes.h"

#include <QFileDialog>

minimamaximadevideo::minimamaximadevideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::minimamaximadevideo)
{
    ui->setupUi(this);
}

minimamaximadevideo::~minimamaximadevideo()
{
    delete ui;
}

void minimamaximadevideo::changeEvent(QEvent *e)
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

CvScalar minimamaximadevideo::pixelMenor(CvScalar pixel1, CvScalar pixel2){
    //Variables
    CvScalar pixelResultado;

    //Acciones
    for(int i=0;i<3;i++){
        if(pixel1.val[i] < pixel2.val[i]){                                  //comparamos el canal rojo
            pixelResultado.val[i]= pixel1.val[i];
        }
        else{
            pixelResultado.val[i]= pixel2.val[i];
        }
    }

    return pixelResultado;
}

CvScalar minimamaximadevideo::pixelMayor(CvScalar pixel1, CvScalar pixel2){
    //Variables
    CvScalar pixelResultado;

    //Acciones
    for(int i=0;i<3;i++){
        if(pixel1.val[i] < pixel2.val[i]){                                  //comparamos el canal rojo
            pixelResultado.val[i]= pixel2.val[i];
        }
        else{
            pixelResultado.val[i]= pixel1.val[i];
        }
    }

    return pixelResultado;
}

void minimamaximadevideo::obtenerImagenesMinMax(QString nombreVideo){
    //Variables
    IplImage *imgMinima;                                                    //Imagen mínima
    IplImage *imgMaxima;                                                    //Imagen máxima
    IplImage *frame;                                                        //Frame del vídeo
    CvCapture *cap;                                                         //Capturador
    //CvScalar pixelFrame, pixelImg;                                          //Valor de un píxel

    //Acciones
    cap= cvCaptureFromFile(nombreVideo.toAscii());                          //asignamos el capturador al archivo de vídeo
    if(!cap) return;                                                        //si no hay ningún error continuamos
    frame= cvQueryFrame(cap);                                               //obtenemos el primer frame del vídeo
    imgMinima= cvCloneImage(frame);                                         //inicialmente la imgMinima será el primer frame
    imgMaxima= cvCloneImage(frame);                                         //inicialmente la imgMaxima será el primer frame
    frame= cvQueryFrame(cap);                                               //obtenemos el segundo frame

    while(frame!=NULL){                                                     //vamos obteniendo cada uno de los frames del vídeo

        cvMin(frame, imgMinima, imgMinima);
        cvMax(frame, imgMaxima, imgMaxima);
        /*
        for(int i=0; i<frame->width; i++){                                  //recorremos cada píxel del frame
            for(int j=0; j<frame->height; j++){
                pixelFrame= cvGet2D(frame, j, i);                           //obtenemos el píxel del frame
                pixelImg= cvGet2D(imgMinima, j, i);                         //obtenemos el píxel de la imagenMinima
                cvSet2D(imgMinima, j, i, pixelMenor(pixelFrame, pixelImg)); //asignamos el pixel menor a la imagen mínima

                pixelImg= cvGet2D(imgMaxima, j, i);                         //obtenemos el píxel de la imagenMaxima
                cvSet2D(imgMaxima, j, i, pixelMayor(pixelFrame, pixelImg)); //asignamos el píxel mayor a la imagen máxima
            }
        }*/
        frame= cvQueryFrame(cap);                                           //frame de la captura
    }

    crear_nueva(primera_libre(), imgMinima);                                //creamos las imágenes calculadas
    crear_nueva(primera_libre(), imgMaxima);

    cvReleaseImage(&frame);                                                 //liberamos la memoria usada
    close();
}
void minimamaximadevideo::on_pushButton_clicked()
{
    QString nombre= QFileDialog::getOpenFileName();                         //Obtenemos el nombre del archivo a abrir
    if (!nombre.isEmpty())
        ui->lineEdit->setText(nombre.toAscii());
}

void minimamaximadevideo::on_pushButton_2_clicked()
{
    //Variables
    QString nombreVideo= ui->lineEdit->text().toAscii();

    //Acciones
        if(!nombreVideo.isEmpty()){                                         //si se han seleccionado dos imágenes continuamos
        obtenerImagenesMinMax(nombreVideo);
        close();
    }
}

void minimamaximadevideo::on_pushButton_3_clicked()
{
    close();
}
