#include "transicionvideo.h"
#include "ui_transicionvideo.h"


#include "mainwindow.h"
#include "video.h"
#include "imagenes.h"

#include <QFileDialog>

transicionvideo::transicionvideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transicionvideo)
{
    ui->setupUi(this);
}

transicionvideo::~transicionvideo()
{
    delete ui;
}

void transicionvideo::changeEvent(QEvent *e)
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
void transicionvideo::crearTransicion(IplImage *imgOrigen, IplImage *imgDestino, QString nombreVideo, int codec, int nFrames, double fps)
{    
    IplImage *imgDestinoEscalada= cvCreateImage(cvGetSize(imgOrigen),imgDestino->depth, imgDestino->nChannels);
    cvResize(imgDestino,imgDestinoEscalada,CV_INTER_CUBIC);                                                     //ajustamos el tamaño de la imagen de destino (la dejamos igual que la de origen)

    IplImage *frame= cvCreateImage(cvGetSize(imgOrigen),imgOrigen->depth, imgOrigen->nChannels);                //creamos el frame y establecemos su tamaño
    CvSize tamanoFrame;
    tamanoFrame.width= frame->width;
    tamanoFrame.height= frame->height;

    CvVideoWriter* video= cvCreateVideoWriter(nombreVideo.toAscii(), codec, fps, tamanoFrame);                  //Creamos el video.
    int cantidadSuavizado;                                                                                      //variable que indicará la cantidad de suavizado en cada momento.
    double cantidadEscalado;

    for(int i=0; i<nFrames; i++){
        if(i<nFrames/2){
            cantidadSuavizado= (i*i*i)/nFrames+1;//1+i*i;
            cantidadEscalado= ((5*i)/nFrames)+1;//(5*i)/nFrames;
            cvSmooth(imgOrigen, frame, CV_BLUR, cantidadSuavizado, cantidadSuavizado);                          //suavizamos la imagen de origen de menos a más
            cvScale(frame, frame, cantidadEscalado, 0);                                                                        //aumentamos el brillo de la imgOrigen de menos a más
        }
        else{
            cantidadSuavizado= (nFrames-i)*(nFrames-i)*(nFrames-i)/nFrames+1;//(nFrames-i)*(nFrames-i)+1;
            cantidadEscalado= ((5*(nFrames-i))/nFrames)+1;//(5*(nFrames-i+1))/nFrames;
            cvSmooth(imgDestinoEscalada, frame, CV_BLUR, cantidadSuavizado, cantidadSuavizado);                 //suavizamos la imagen de destino de más a menos
            cvScale(frame, frame, cantidadEscalado, 0);                                                        //aumentamos el brillo de la imgDestino de más a menos
        }

        cvShowImage("img", frame);                                                                              //mostramos cada frame creado
        cvWriteFrame(video, frame);                                                                             //lo escribimos en el vídeo
        cvWaitKey(1);
    }

    cvReleaseImage(&frame);                                                                                     //liberamos memoria
    cvReleaseVideoWriter(&video);

}
void transicionvideo::on_pushButton_3_clicked()
{
    QString nombre= QFileDialog::getOpenFileName(this, "Abrir imagen", ".", FiltroImagen);
    if (!nombre.isEmpty())
        ui->lineEdit->setText(nombre.toAscii());
}

void transicionvideo::on_pushButton_4_clicked()
{
    QString nombre= QFileDialog::getOpenFileName(this, "Abrir imagen", ".", FiltroImagen);
    if (!nombre.isEmpty())
        ui->lineEdit_2->setText(nombre.toAscii());
}

void transicionvideo::on_pushButton_clicked()
{
    //Variables
    QString nombreImgOrigen= ui->lineEdit->text().toAscii();
    QString nombreImgDestino= ui->lineEdit_2->text().toAscii();
    QString nombreVideo;
    QString codecCB= ui->comboBox->currentText();
    int codec= CV_FOURCC(codecCB.toAscii().at(0), codecCB.toAscii().at(1),
                        codecCB.toAscii().at(2), codecCB.toAscii().at(3));
    IplImage *imgOrigen;
    IplImage *imgDestino;

    //Acciones
    if(!nombreImgOrigen.isEmpty() && !nombreImgDestino.isEmpty()){                          //si se han seleccionado dos imágenes continuamos
        nombreVideo= QFileDialog::getSaveFileName(w, "Guardar vídeo", ".", FiltroVideo);    //obtenemos el nombre del vídeo
        imgOrigen= cvLoadImage(nombreImgOrigen.toAscii());                                  //cargamos la imagen de origen
        imgDestino= cvLoadImage(nombreImgDestino.toAscii());                                //cargamos la imagen de destino

        crearTransicion(imgOrigen, imgDestino, nombreVideo, codec, ui->spinBox->value(), ui->doubleSpinBox->value());   //creamos la transición
        cvReleaseImage(&imgOrigen);                                                         //liberamos memoria
        cvReleaseImage(&imgDestino);
        close();
    }
}

void transicionvideo::on_pushButton_2_clicked()
{
    close();
}
