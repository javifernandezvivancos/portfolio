#include "pincharestirar.h"
#include "ui_pincharestirar.h"
#include "imagenes.h"

IplImage *img = NULL;
IplImage *res = NULL;
int cx, cy;
double radio = 50;
double grado = 0.0;

void callback2 (int event, int x, int y, int flags, void *_nfoto){
    if(event == CV_EVENT_LBUTTONDOWN){
        cx = x;
        cy = y;
        f_pincharestirar(img, res, cx, cy, radio, grado);
        cvShowImage("Pinchar/Estirar", res);
    }
}

pincharestirar::pincharestirar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pincharestirar)
{
    ui->setupUi(this);
    nfoto = foto_activa();
}

pincharestirar::~pincharestirar()
{
    delete ui;
    cvReleaseImage(&img);
    cvReleaseImage(&res);
    cvDestroyWindow("Pinchar/Estirar");
}

void pincharestirar::changeEvent(QEvent *e)
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

void pincharestirar::exec(void){
    img = cvCloneImage(foto[nfoto].img);
    res = cvCloneImage(foto[nfoto].img);
    cvNamedWindow("Pinchar/Estirar", 0);
    cvShowImage("Pinchar/Estirar", res);
    cvSetMouseCallback("Pinchar/Estirar", callback2);
    QDialog::exec();
}

void pincharestirar::on_horizontalSlider_radiodelefecto_valueChanged(int value)
{
    radio = value;
}

void pincharestirar::on_horizontalSlider_gradodelefecto_valueChanged(int value)
{
    grado = value;
}

void pincharestirar::on_buttonBox_accepted()
{
    f_pincharestirar(img, foto[nfoto].img, cx, cy, radio, grado);
    mostrar(nfoto);
}
