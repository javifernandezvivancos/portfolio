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
    if(!cap) return;                                //si no hay ningún error continuamos

    IplImage *frame = cvQueryFrame(cap);            //frame de cada captura
    cvNamedWindow("Pulse una tecla para capturar...", 0);//Creamos la ventana que contendrá el vídeo

    int tecla= cvWaitKey(10);                       //variable tecla que esperará recibir una tecla
    while (frame && tecla==-1) {                    //Mientras no recibamos ninguna tecla...
        if(ui->checkBox_previsualizarcamara->isChecked()) cvShowImage("Pulse una tecla para capturar...", frame); //...vamos mostrando las imágenes que vamos capturando
        frame= cvQueryFrame(cap);                   //capturamos una nueva imagen
        tecla= cvWaitKey(10);                       //esperamos a recibir una pulsación de tecla
    }
    frame= cvCloneImage(frame);                     //Guardamos el último frame capturado

    cvReleaseCapture(&cap);                         //liberamos el buffer de captura
    cvDestroyWindow("Pulse una tecla para capturar...");

    //Ponemos la imagen (frame) en la lista de imagenes, la memoria de esta imagen será liberada cuando el usuario la cierre desde el programa principal.
    int nuevacap = primera_libre();                 //buscamos la primera posición libre
    if (nuevacap!=-1) {                             //cuando la tengamos...
        crear_nueva(nuevacap, frame);               //...guardamos el frame en esa posición
    }
}
