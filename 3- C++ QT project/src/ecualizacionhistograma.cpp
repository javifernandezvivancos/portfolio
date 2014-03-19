#include "ecualizacionhistograma.h"
#include "ui_ecualizacionhistograma.h"
#include "imagenes.h"



ecualizacionhistograma::ecualizacionhistograma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ecualizacionhistograma)
{
    ui->setupUi(this);
}

ecualizacionhistograma::~ecualizacionhistograma()
{
    delete ui;
}

void ecualizacionhistograma::changeEvent(QEvent *e)
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

void ecualizacionhistograma::on_pushButton_clicked()
{
    int pl= primera_libre();
    if (pl!=-1)
        ecualizarHistograma(0, pl);                                         //la ecualización será conjunta
}

void ecualizacionhistograma::on_pushButton_2_clicked()
{
    int pl= primera_libre();
    if (pl!=-0)
        ecualizarHistograma(1, pl);                                         //la ecualización será por separado
}


void ecualizacionhistograma::calcularFuncionEcualizacion(IplImage *canal, CvMat *dest){
    //Variables
    int celdas= 256;                                                        //número de celdas del histograma
    float acum= 0.0;                                                        //variable acumulación de la ecualización
    CvHistogram* hist= cvCreateHist(1, &celdas, CV_HIST_ARRAY);             //Creamos el histograma de la imagen
    cvCalcHist(&canal, hist);                                               //calculamos el histograma para la imagen deseada
    cvNormalizeHist(hist, 256.0);                                           //lo normalizamos

    //Acciones
    for (int i= 0; i<255; i++) {                                            //vamos obteniendo cada valor...
        cvSet1D(dest, i, cvScalarAll(acum));
        acum+= cvQueryHistValue_1D(hist, i);
    }
    cvSet1D(dest, 255, cvScalarAll(255));                                   //lo asignamos en la función lut

    cvReleaseHist(&hist);                                                   //liberamos memoria
}

// si tipo=0 entonces conjunta, si tipo=1 entonces por separado
void ecualizacionhistograma::ecualizarHistograma(int tipo, int pl){    
    int fa= foto_activa();                                                  //número de foto activa
    if(fa!=-1){        
        //Variables
        IplImage *img = cvCloneImage(foto[fa].img);                         //clonamos la imagen activa (para trabajar con ella)
        IplImage *gris= cvCreateImage(cvGetSize(img), img->depth, 1);       //imagen que contendrá el canal gris
        IplImage *rojo= cvCreateImage(cvGetSize(img), img->depth, 1);       //imagen que contendrá el canal rojo
        IplImage *verde= cvCreateImage(cvGetSize(img), img->depth, 1);      //imagen que contendrá el canal verde
        IplImage *azul= cvCreateImage(cvGetSize(img), img->depth, 1);       //imagen que contendrá el canal azul
        CvMat *lut= cvCreateMat(1, 256, CV_8UC3);                           //creamos la función de ecualización con 3 canales (para la conjunta);                                                         //función de ecualización
        CvMat *lutR= cvCreateMat(1, 256, CV_8UC1);                          //creamos las 3 funciones de ecualización para cada canal (para la separada);
        CvMat *lutG= cvCreateMat(1, 256, CV_8UC1);
        CvMat *lutB= cvCreateMat(1, 256, CV_8UC1);

        //Acciones
        if(tipo==0){
            cvCvtColor(img,gris,CV_RGB2GRAY);                               //convertimos la imagen a escala de grises
            calcularFuncionEcualizacion(gris, lut);                         //calculamos la función de ecualización lut
            cvLUT(img, img, lut);                                           //ecualizamos la imagen
        }
        else if(tipo==1){
            cvSplit(img, azul, verde, rojo, NULL);                          //dividimos la imagen en sus 3 canales
            calcularFuncionEcualizacion(rojo, lutR);                        //calculamos la función de ecualización para el canal rojo
            calcularFuncionEcualizacion(verde, lutG);                       //calculamos la función de ecualización para el canal verde
            calcularFuncionEcualizacion(azul, lutB);                        //calculamos la función de ecualización para el canal azul
            cvLUT(rojo, rojo, lutR);                                        //ecualizamos el canal rojo
            cvLUT(verde, verde, lutG);                                      //ecualizamos el canal verde
            cvLUT(azul, azul, lutB);                                        //ecualizamos el canal azul
            cvMerge(azul, verde, rojo, 0, img);                             //Unimos los canales ecualizados.
        }

        crear_nueva(pl, img);                                               //creamos la imagen ecualizada

        cvReleaseMat(&lut);
        cvReleaseMat(&lutR);
        cvReleaseMat(&lutG);
        cvReleaseMat(&lutB);
        cvReleaseImage(&gris);
        cvReleaseImage(&rojo);
        cvReleaseImage(&verde);
        cvReleaseImage(&azul);
        close();                                                            //cerramos la ventana
    }
}

