#include "informacion.h"
#include "ui_informacion.h"
#include "imagenes.h"

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
#include <qfiledialog.h>

QString toString(int numero){
    QString resultado="";
    int resto;
    while(numero>9){
        resto= numero%10;
        numero= numero/10;
        resultado= resultado+""+(resto+48);
    }
    resultado= resultado+""+(numero+48);    

    QString resultadoI= resultado;

    for(int i=0;i<resultadoI.length();i++){
        resultadoI[i]= resultado[resultado.length()-i-1];
    }    
    return resultadoI;
}

Informacion::Informacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Informacion)
{
    ui->setupUi(this);
    ver_informacion(foto_activa());
}

Informacion::~Informacion()
{
    delete ui;
}

void Informacion::changeEvent(QEvent *e)
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

void Informacion::ver_informacion(int nfoto){
    //Variables
    QString informacion= "";

    //Acciones
    informacion= informacion+"Dimensiones:\n";
    informacion= informacion+"-   Anchura= " + toString(foto[nfoto].img->width) + "\n";
    informacion= informacion+"-   Altura= " + toString(foto[nfoto].img->height) + "\n\n";
    informacion= informacion+"Canales: " + toString(foto[nfoto].img->nChannels) + "\n\n";
    informacion= informacion+"Profundidad: " + toString(foto[nfoto].img->depth) + "\n\n";
    informacion= informacion+"Memoria utilizada: " + toString(foto[nfoto].img->height*foto[nfoto].img->width*foto[nfoto].img->nChannels*foto[nfoto].img->depth/1024/8)+" KBytes";
    //"Tamaño= " + foto[fa].img->nSize + "\n" + "Memoria ocupada= " + foto[fa].img->height*foto[fa].img->width*foto[fa].img->nChannels);
    ui->label->setText(informacion);

    //cadena=(Tamaño= " + foto[fa].img->nSize + "\n" + "Canales= " + foto[fa].img->nChannels + "\n" + "Profundidad en pixels= " + foto[fa].img->depth + "\n" + "Memoria ocupada= " + foto[fa].img->height*foto[fa].img->width*foto[fa].img->nChannels);
}

