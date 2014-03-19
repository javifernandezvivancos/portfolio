#include "capturardecamara.h"
#include "ui_capturardecamara.h"
#include "imagenes.h"
#include <QFileDialog>
#include <QAbstractButton>

QString FiltroImagen = "Todos los formatos (*.bmp *.dib *.jpg *.jpeg *.jpe *.tif *.tiff *.png *.gif);;Archivos BMP (*.bmp *.dib);;Archivos JPG (*.jpg *.jpeg *.jpe);;Archivos TIF (*.tif *.tiff);;Archivos GIF (*.gif);;Otros (*.*)";

capturardecamara::capturardecamara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capturardecamara)
{
    ui->setupUi(this);
}

capturardecamara::~capturardecamara()
{
    delete ui;
}

void capturardecamara::changeEvent(QEvent *e)
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

void capturardecamara::exec(void){
    QDialog::exec();
}

void capturardecamara::on_buttonBox_previsualizarcamara_accepted()
{

    CvCapture *cap = cvCaptureFromCAM(0);           //lo convertimos en capturador desde CAM
    if(!cap) return;                                //si no hay ning�n error continuamos

    IplImage *frame = cvQueryFrame(cap);            //frame de cada captura
    cvNamedWindow("Pulse una tecla para capturar...", 0);//Creamos la ventana que contendr� el v�deo

    int tecla= cvWaitKey(10);                       //variable tecla que esperar� recibir una tecla
    while (frame && tecla==-1) {                    //Mientras no recibamos ninguna tecla...
        if(ui->checkBox_previsualizarcamara->isChecked()) cvShowImage("Pulse una tecla para capturar...", frame); //...vamos mostrando las im�genes que vamos capturando
        frame= cvQueryFrame(cap);                   //capturamos una nueva imagen
        tecla= cvWaitKey(10);                       //esperamos a recibir una pulsaci�n de tecla
    }
    frame= cvCloneImage(frame);                     //Guardamos el �ltimo frame capturado

    cvReleaseCapture(&cap);                         //liberamos el buffer de captura
    cvDestroyWindow("Pulse una tecla para capturar...");

    //Ponemos la imagen (frame) en la lista de imagenes, la memoria de esta imagen ser� liberada cuando el usuario la cierre desde el programa principal.
    int nuevacap = primera_libre();                 //buscamos la primera posici�n libre
    if (nuevacap!=-1) {                             //cuando la tengamos...
        crear_nueva(nuevacap, frame);               //...guardamos el frame en esa posici�n
    }
}
