#include "transformacionamalla.h"
#include "ui_transformacionamalla.h"
#include "imagenes.h"

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

transformacionamalla::transformacionamalla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transformacionamalla)
{
    ui->setupUi(this);
    nfoto = foto_activa();
}

transformacionamalla::~transformacionamalla()
{
    delete ui;
}

void transformacionamalla::changeEvent(QEvent *e)
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
void transformacionamalla::transformarRectangulo(IplImage *src, IplImage *dst, CvPoint2D32f psrc[4], CvPoint2D32f pdst[4]){

    //Variables
    CvMat *c= cvCreateMat(3, 3, CV_32FC1);
    cvSet(dst, cvScalarAll(255));

    //Acciones
    cvGetPerspectiveTransform(psrc, pdst, c);
    cvWarpPerspective(src, dst, c, CV_INTER_CUBIC);
    cvReleaseMat(&c);
}
bool transformacionamalla::lineditCorrectos(){
    QString v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18;

    v1= ui->lineEdit->text().toAscii();
    v2= ui->lineEdit_2->text().toAscii();
    v3= ui->lineEdit_3->text().toAscii();
    v4= ui->lineEdit_4->text().toAscii();
    v5= ui->lineEdit_5->text().toAscii();
    v6= ui->lineEdit_6->text().toAscii();
    v7= ui->lineEdit_7->text().toAscii();
    v8= ui->lineEdit_8->text().toAscii();
    v9= ui->lineEdit_9->text().toAscii();
    v10= ui->lineEdit_10->text().toAscii();
    v11= ui->lineEdit_11->text().toAscii();
    v12= ui->lineEdit_12->text().toAscii();
    v13= ui->lineEdit_13->text().toAscii();
    v14= ui->lineEdit_14->text().toAscii();
    v15= ui->lineEdit_15->text().toAscii();
    v16= ui->lineEdit_16->text().toAscii();
    v17= ui->lineEdit_17->text().toAscii();
    v18= ui->lineEdit_18->text().toAscii();

    if(v1.isEmpty() || v2.isEmpty() || v3.isEmpty() || v4.isEmpty() || v5.isEmpty() || v6.isEmpty() || v7.isEmpty() || v8.isEmpty() || v9.isEmpty() || v10.isEmpty() || v11.isEmpty() || v12.isEmpty() || v13.isEmpty() || v14.isEmpty() || v15.isEmpty() || v16.isEmpty() || v17.isEmpty() || v18.isEmpty()){
        return false;
    }
    return true;

}
/*
void transformacionamalla::crearArrayLineEdits(QString lineEdits[3][3][2]){
    lineEdits[0][0][0]= ui->lineEdit->text().toAscii();
    lineEdits[0][0][1]= ui->lineEdit_2->text().toAscii();
    lineEdits[1][0][0]= ui->lineEdit_3->text().toAscii();
    lineEdits[1][0][1]= ui->lineEdit_4->text().toAscii();
    lineEdits[2][0][0]= ui->lineEdit_5->text().toAscii();
    lineEdits[2][0][1]= ui->lineEdit_6->text().toAscii();
    lineEdits[0][1][0]= ui->lineEdit_7->text().toAscii();
    lineEdits[0][1][1]= ui->lineEdit_8->text().toAscii();
    lineEdits[1][1][0]= ui->lineEdit_9->text().toAscii();
    lineEdits[1][1][1]= ui->lineEdit_10->text().toAscii();
    lineEdits[2][1][0]= ui->lineEdit_11->text().toAscii();
    lineEdits[2][1][1]= ui->lineEdit_12->text().toAscii();
    lineEdits[0][2][0]= ui->lineEdit_13->text().toAscii();
    lineEdits[0][2][1]= ui->lineEdit_14->text().toAscii();
    lineEdits[1][2][0]= ui->lineEdit_15->text().toAscii();
    lineEdits[1][2][1]= ui->lineEdit_16->text().toAscii();
    lineEdits[2][2][0]= ui->lineEdit_17->text().toAscii();
    lineEdits[2][2][1]= ui->lineEdit_18->text().toAscii();
}
*/

void transformacionamalla::on_pushButton_clicked()
{
    /*
    if(!lineditCorrectos()){
        return;
    }

    //Variables
    IplImage *src= cvCloneImage(foto[nfoto].img);
    IplImage *dst= cvCloneImage(foto[nfoto].img);
    int anchuraMalla= foto[nfoto].img->width/4;
    int alturaMalla= foto[nfoto].img->height/4;
    CvPoint2D32f psrc[4]= // Cuatro puntos en el origen
    {{0,0}, {100,0}, {100,100}, {0,100}};
    CvPoint2D32f pdst[4]= // Cuatro puntos en el destino
    {{0,0}, {100,0}, {150,150}, {0,100}};
    QString lineEdits[3][3][2]={{{"0", "0"}, {"0", "0"}, {"0", "0"}}, {{"0", "0"}, {"0", "0"}, {"0", "0"}}, {{"0", "0"}, {"0", "0"}, {"0", "0"}}};

    //Acciones
    crearArrayLineEdits(lineEdits);
    for(int j=0; j<4; j++){
        for(int i=0; i<4; i++){
            psrc[0].x= i*anchuraMalla;      psrc[0].y= j*alturaMalla;
            psrc[1].x= (i+1)*anchuraMalla;  psrc[1].y= j*alturaMalla;
            psrc[2].x= (i+1)*anchuraMalla;  psrc[2].y= (j+1)*alturaMalla;
            psrc[3].x= i*anchuraMalla;      psrc[3].y= (j+1)*alturaMalla;

            v2= ui->lineEdit_2->text().toAscii();

            transformarRectangulo(src, dst, psrc, pdst);
        }
    }

    //Acciones
    transformarRectangulo(src, dst, psrc, pdst);
    crear_nueva(primera_libre(), dst);
    close();
    */
}

void transformacionamalla::on_pushButton_2_clicked()
{
    close();
}
