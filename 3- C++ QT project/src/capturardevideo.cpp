#include "capturardevideo.h"
#include "ui_capturardevideo.h"
#include "imagenes.h"
#include <QFileDialog>

int num_frame = 0;

capturardevideo::capturardevideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::capturardevideo)
{
    ui->setupUi(this);
}

capturardevideo::~capturardevideo()
{
    delete ui;
}

void capturardevideo::changeEvent(QEvent *e)
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

void capturardevideo::exec(void){
    QDialog::exec();
}

void capturardevideo::on_spinBox_valueChanged(int value)
{
    num_frame = value;
}

void capturardevideo::on_buttonBox_accepted()
{
    CvCapture *cap;                                     //Capturador
    QString nombre = QFileDialog::getOpenFileName();    //Obtenemos el nombre del archivo a abrir
    cap= cvCaptureFromFile(nombre.toAscii());           //asignamos el capturador al archivo de vídeo
    if(!cap) return;                                    //si no hay ningún error continuamos

    cvSetCaptureProperty(cap, CV_CAP_PROP_POS_FRAMES, num_frame);

    IplImage *frame= cvQueryFrame(cap);                 //frame de la captura
    frame= cvCloneImage(frame);                         //Guardamos el último frame capturado
    cvReleaseCapture(&cap);                             //liberamos el buffer de captura


    int nuevacap = primera_libre();                     //Incorporamos el frame a las fotos abiertas
    if (nuevacap!=-1) {                                 //por el programa.
        crear_nueva(nuevacap, frame);
    }
}
