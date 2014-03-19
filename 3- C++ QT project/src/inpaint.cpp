#include "inpaint.h"
#include "ui_inpaint.h"
#include "imagenes.h"

IplImage *imagen = NULL;
IplImage *mascara = NULL;
IplImage *resultado = NULL;
int radio_actual = 5;
int pintar = 255;

void on_mouse(int event, int x, int y, int flags, void *)
{
    if (flags == CV_EVENT_FLAG_LBUTTON){
        cvCircle(imagen, cvPoint(x, y), radio_actual, CV_RGB(255,255,255),-1);
        cvCircle(mascara, cvPoint(x, y), radio_actual, CV_RGB(pintar,pintar,pintar),-1);

        cvCopy(resultado, imagen);
        cvSet(imagen, CV_RGB(255,255,255), mascara);

        cvShowImage("Efecto InPaint", imagen);
    }
}

inpaint::inpaint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inpaint)
{
    ui->setupUi(this);
    nfoto = foto_activa();
}

inpaint::~inpaint()
{
    cvReleaseImage(&imagen);
    cvReleaseImage(&resultado);
    cvReleaseImage(&mascara);

    cvDestroyWindow("Efecto InPaint");
    cvDestroyWindow("Resultado InPaint");
    delete ui;
}

void inpaint::changeEvent(QEvent *e)
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

int inpaint::exec()
{
    imagen = cvCloneImage(foto[nfoto].img);
    resultado = cvCloneImage(foto[nfoto].img);
    mascara = cvCreateImage(cvGetSize(imagen), IPL_DEPTH_8U, 1);

    cvZero(mascara);
    cvNamedWindow("Efecto InPaint", 0);
    cvShowImage("Efecto InPaint", imagen);
    cvSetMouseCallback("Efecto InPaint", on_mouse);
    return QDialog::exec();
}

void inpaint::on_buttonBox_accepted()
{
    cvInpaint(foto[nfoto].img, mascara, resultado, 3, CV_INPAINT_TELEA);

    if (ui->checkBox->isChecked()){
        crear_nueva(primera_libre(), resultado);
        resultado = NULL;
    }
    else {
        cvCopy(resultado, foto[nfoto].img);
        cvReleaseImage(&resultado);
    }

    cvReleaseImage(&imagen);
    cvReleaseImage(&mascara);

    cvDestroyWindow("Efecto InPaint");
    cvDestroyWindow("Resultado InPaint");

    radio_actual = 5;
    pintar = 255;
    close();
}

void inpaint::on_buttonBox_rejected()
{
    cvReleaseImage(&imagen);
    cvReleaseImage(&resultado);
    cvReleaseImage(&mascara);

    cvDestroyWindow("Efecto InPaint");
    cvDestroyWindow("Resultado InPaint");
    radio_actual = 5;
    pintar = 255;
    close();
}

void inpaint::on_horizontalSlider_valueChanged(int value)
{
    radio_actual = value;
}

void inpaint::on_pushButton_clicked()
{
    cvInpaint(foto[nfoto].img, mascara, resultado, 3, CV_INPAINT_TELEA);
    cvNamedWindow("Resultado InPaint", 0);
    cvShowImage("Resultado InPaint", resultado);
}

void inpaint::on_inpaint_destroyed()
{
    cvReleaseImage(&imagen);
    cvReleaseImage(&resultado);
    cvReleaseImage(&mascara);


    cvDestroyWindow("Efecto InPaint");
    cvDestroyWindow("Resultado InPaint");
}

void inpaint::on_checkBox_2_clicked(bool checked)
{
    pintar = (checked?255:0);
}
