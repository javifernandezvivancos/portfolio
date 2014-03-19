//---------------------------------------------------------------------------

#include "imagenes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui/QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES                        //////////////
///////////////////////////////////////////////////////////////////

ventana foto[MAX_VENTANAS];

tipo_herramienta herr_actual= puntos;

int radio_pincel= 10;

CvScalar color_pincel= CV_RGB(255, 255, 255);

int difum_pincel= 10;

bool preguntar_guardar= true;


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void callback (int event, int x, int y, int flags, void *_nfoto);

void SetStatusBar1 (int masfotos);

//---------------------------------------------------------------------------

void inic_fotos (void)
{
  for (int i= 0; i<MAX_VENTANAS; i++) {
    foto[i].usada= false;
    foto[i].modificada= false;
    foto[i].nombre= NULL;
    foto[i].img= NULL;
    foto[i].roi= cvRect(-1,-1,-1,-1);
  }
}

//---------------------------------------------------------------------------

void fin_fotos (void)
{
  for (int i= 0; i<MAX_VENTANAS; i++) {
    if (foto[i].usada) {
      cvDestroyWindow(foto[i].nombre);
      delete [] foto[i].nombre;
      cvReleaseImage(&foto[i].img);
      foto[i].usada= false;
    }
  }
}

//---------------------------------------------------------------------------

int primera_libre (void)
{
  int libre= -1;
  for (int i= 0; i<MAX_VENTANAS && libre==-1; i++)
    if (!foto[i].usada)
      libre= i;
  return libre;
}

//---------------------------------------------------------------------------

void escribir_barra_estado (void)
{
    int usadas, modificadas;
    num_fotos(usadas, modificadas);
    w->setStatusBarText(QString::number(usadas)+" fotos abiertas, "+
                        QString::number(modificadas)+" modificadas.");
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, int ancho, int alto, CvScalar color)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
  foto[nfoto].nombre= new char[40];
  sprintf(foto[nfoto].nombre, "nueva-%d.bmp", nfoto);
  foto[nfoto].img= cvCreateImage(cvSize(ancho, alto), IPL_DEPTH_8U, 3);
  cvSet(foto[nfoto].img, color);
  cvNamedWindow(foto[nfoto].nombre, 0);
  foto[nfoto].handle= GetActiveWindow();
  cvShowImage(foto[nfoto].nombre, foto[nfoto].img);
  cvResizeWindow(foto[nfoto].nombre, ancho, alto);
  foto[nfoto].usada= true;
  foto[nfoto].modificada= true;
  foto[nfoto].roi= cvRect(-1, -1, -1, -1);
  cvSetMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
  escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, IplImage *img)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada && img);
  foto[nfoto].nombre= new char[40];
  sprintf(foto[nfoto].nombre, "nueva-%d.bmp", nfoto);
  foto[nfoto].img= img;
  cvNamedWindow(foto[nfoto].nombre, 0);
  foto[nfoto].handle= GetActiveWindow();
  cvShowImage(foto[nfoto].nombre, foto[nfoto].img);
  cvResizeWindow(foto[nfoto].nombre, img->width, img->height);
  foto[nfoto].usada= true;
  foto[nfoto].modificada= true;
  foto[nfoto].roi= cvRect(-1, -1, -1, -1);
  cvSetMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
  escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, const char *nombre)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
  foto[nfoto].img= cvLoadImage(nombre, 1);
  if (!foto[nfoto].img)
    return;
  foto[nfoto].nombre= new char[strlen(nombre)+1];
  strcpy(foto[nfoto].nombre, nombre);
  cvNamedWindow(foto[nfoto].nombre, 0);
  foto[nfoto].handle= GetActiveWindow();
  cvShowImage(foto[nfoto].nombre, foto[nfoto].img);
  cvResizeWindow(foto[nfoto].nombre, foto[nfoto].img->width, foto[nfoto].img->height);
  foto[nfoto].usada= true;
  foto[nfoto].modificada= false;
  foto[nfoto].roi= cvRect(-1, -1, -1, -1);
  cvSetMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
  escribir_barra_estado();
}

//---------------------------------------------------------------------------

void guardar_foto (int nfoto, const char *nombre)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
  // 1. Guardar la imagen con el mismo nombre que tiene
  if (!nombre || !strlen(nombre))
    foto[nfoto].modificada= !cvSaveImage(foto[nfoto].nombre, foto[nfoto].img);
  // 2. Guardar la imagen con un nombre distinto al actual
  else {
    foto[nfoto].modificada= !cvSaveImage(nombre, foto[nfoto].img);
    cvDestroyWindow(foto[nfoto].nombre); // Se debe cambiar el nombre de la
    delete [] foto[nfoto].nombre;        // ventana de HighGUI
    foto[nfoto].nombre= new char[strlen(nombre)+1];
    strcpy(foto[nfoto].nombre, nombre);
    cvNamedWindow(foto[nfoto].nombre, 0);
    foto[nfoto].handle= GetActiveWindow();
    cvShowImage(foto[nfoto].nombre, foto[nfoto].img);
    cvResizeWindow(foto[nfoto].nombre, foto[nfoto].img->width,
                   foto[nfoto].img->height);
    cvSetMouseCallback(foto[nfoto].nombre, callback, (void*) nfoto);
  }
  escribir_barra_estado();
}

//---------------------------------------------------------------------------

void cerrar_foto (int nfoto, bool destruir_ventana)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
  if (destruir_ventana)
    cvDestroyWindow(foto[nfoto].nombre);
  cvReleaseImage(&foto[nfoto].img);
  foto[nfoto].usada= false;
  delete [] foto[nfoto].nombre;
  escribir_barra_estado();
}

//---------------------------------------------------------------------------

void mostrar (int nfoto)
{
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
  cvShowImage(foto[nfoto].nombre, foto[nfoto].img);
}

//---------------------------------------------------------------------------

int nombre_a_numero (const char *nombre)
{
  int i;
  for (i= 0; i<MAX_VENTANAS; i++)
    if (foto[i].usada && !strcmp(foto[i].nombre, nombre))
      return i;
  return -1;
}

//---------------------------------------------------------------------------

int foto_activa (void)
{
  int j= 0;
  HWND hijo= GetActiveWindow();
  do {
    for (int i= 0; i<MAX_VENTANAS; i++)
      if (foto[i].usada && hijo==foto[i].handle) {
        return i;
      }
    hijo= GetNextWindow(hijo, GW_HWNDNEXT);
    j++;
  } while (j<100);
  return -1;
}

//---------------------------------------------------------------------------

int num_fotos (int &usadas, int &modificadas)
{
    usadas= 0;
    modificadas= 0;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            usadas++;
            if (foto[i].modificada)
                modificadas++;
        }
    }
    return usadas;
}

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DEL CALLBACK PRINCIPAL          //////////////
///////////////////////////////////////////////////////////////////

int downx, downy;
// Posición inicial del ratón al pinchar sobre la imagen actual

//---------------------------------------------------------------------------

void ninguna_accion (int factual, int x, int y)
{
  IplImage *res= cvCloneImage(foto[factual].img);
  cvCircle(res, cvPoint(x, y), radio_pincel, CV_RGB(255,255,255));
  cvShowImage(foto[factual].nombre, res);
  cvReleaseImage(&res);
}

//---------------------------------------------------------------------------

void cb_close (int factual)
{
    if (foto[factual].img && foto[factual].usada) {
        if (foto[factual].modificada && preguntar_guardar) {
            QString cadena= "El archivo " + QString(foto[factual].nombre) +
                            " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(w, "Archivo modificado", cadena,
                                            QMessageBox::Yes | QMessageBox::No );
            if (resp==QMessageBox::Yes)
                guardar_foto(factual);
        }
        cerrar_foto(factual, false);
    }
}

//---------------------------------------------------------------------------

void cb_punto (int factual, int x, int y)
{
  IplImage *im= foto[factual].img;  // Ojo: esto no es una copia, sino un
                                    // puntero a la misma imagen. No liberar
  // Redibujar la ventana
  RedrawWindow(foto[factual].handle,NULL,NULL,RDW_UPDATENOW);
  if (difum_pincel==0)
    cvCircle(im, cvPoint(x, y), radio_pincel, color_pincel, -1);
  else {
    IplImage *res= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvSet(res, color_pincel);
    IplImage *cop= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvZero(cop);
    cvCircle(cop, cvPoint(x, y), radio_pincel, CV_RGB(255,255,255), -1);
    cvSmooth(cop, cop, CV_BLUR, difum_pincel*2+1, difum_pincel*2+1);
    cvMul(res, cop, res, 1.0/255.0);
    cvNot(cop, cop);
    cvMul(im, cop, im, 1.0/255.0);
    cvAdd(res, im, im);
    cvReleaseImage(&cop);
    cvReleaseImage(&res);
  }
  cvShowImage(foto[factual].nombre, im);
  foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_linea (int factual, int x, int y)
{
  IplImage *im= foto[factual].img;
  if (difum_pincel==0)
    cvLine(im, cvPoint(downx, downy), cvPoint(x,y), color_pincel, radio_pincel);
  else {
    IplImage *res= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvSet(res, color_pincel);
    IplImage *cop= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvZero(cop);
    cvLine(cop, cvPoint(downx, downy), cvPoint(x,y),
           CV_RGB(255,255,255), radio_pincel);
    cvSmooth(cop, cop, CV_BLUR, difum_pincel*2+1, difum_pincel*2+1);
    cvMul(res, cop, res, 1.0/255.0);
    cvNot(cop, cop);
    cvMul(im, cop, im, 1.0/255.0);
    cvAdd(res, im, im);
    cvReleaseImage(&cop);
    cvReleaseImage(&res);
  }
  cvShowImage(foto[factual].nombre, im);
  foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_linea (int factual, int x, int y)
{
  IplImage *res= cvCloneImage(foto[factual].img);
  cvLine(res, cvPoint(downx, downy), cvPoint(x,y), color_pincel, radio_pincel);
  cvShowImage(foto[factual].nombre, res);
  cvReleaseImage(&res);
}

//---------------------------------------------------------------------------

void cb_seleccionar (int factual, int x, int y)
{
  IplImage *im= foto[factual].img;
  CvRect nuevo= cvRect(min(downx, x), min(downy, y),
                 max(downx, x)-min(downx, x)+1, max(downy, y)-min(downy, y)+1);
  if (nuevo.x<0)
    nuevo.x= 0;
  if (nuevo.y<0)
    nuevo.y= 0;
  if (nuevo.x+nuevo.width>im->width)
    nuevo.width= im->width-nuevo.x;
  if (nuevo.y+nuevo.height>im->height)
    nuevo.height= im->height-nuevo.y;
  foto[factual].roi= nuevo;
}

//---------------------------------------------------------------------------

void cb_ver_seleccion (int factual, int x, int y, bool foto_roi)
{
  IplImage *res= cvCloneImage(foto[factual].img);
  CvPoint p1, p2;
  if (foto_roi) {
    p1.x= foto[factual].roi.x;
    p1.y= foto[factual].roi.y;
    p2.x= foto[factual].roi.x+foto[factual].roi.width-1;
    p2.y= foto[factual].roi.y+foto[factual].roi.height-1;
  }
  else {
    p1= cvPoint(downx, downy);
    p2= cvPoint(x,y);
  }
  cvRectangle(res, p1, p2, CV_RGB(255,foto_roi?0:255,0));
  cvShowImage(foto[factual].nombre, res);
  cvReleaseImage(&res);
}

//---------------------------------------------------------------------------

void cb_rectangulo (int factual, int x, int y)
{
  IplImage *im= foto[factual].img;
  if (difum_pincel==0){ //Si no hay que hacer suavizado, se dibuja el rectángulo
      cvRectangle(im, cvPoint(downx, downy), cvPoint(x,y), color_pincel, radio_pincel-1);
  }
  else {//En caso contrario, debemos crear el rectángulo suavizado
    IplImage *res= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvSet(res, color_pincel);
    IplImage *cop= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvZero(cop);
    cvRectangle(cop, cvPoint(downx, downy), cvPoint(x,y), CV_RGB(255,255,255), radio_pincel-1);
    cvSmooth(cop, cop, CV_BLUR, difum_pincel*2+1, difum_pincel*2+1);
    cvMul(res, cop, res, 1.0/255.0);
    cvNot(cop, cop);
    cvMul(im, cop, im, 1.0/255.0);
    cvAdd(res, im, im);
    cvReleaseImage(&cop);
    cvReleaseImage(&res);
  }
  cvShowImage(foto[factual].nombre, im);
  foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_rectangulo (int factual, int x, int y)
{
  IplImage *res= cvCloneImage(foto[factual].img);
  cvRectangle(res, cvPoint(downx, downy), cvPoint(x,y), color_pincel, radio_pincel);
  cvShowImage(foto[factual].nombre, res);
  cvReleaseImage(&res);
}
//---------------------------------------------------------------------------

void cb_elipse (int factual, int x, int y)
{
  IplImage *im= foto[factual].img;
  if (difum_pincel==0){ //Si no hay que hacer suavizado, se dibuja la elipse
      cvEllipse(im, cvPoint(downx+((x-downx)/2), downy+((y-downy)/2)), cvSize(qAbs(x-downx)/2, qAbs(y-downy)/2), 0.0, 0.0, 360.0, color_pincel, radio_pincel-1);
  }
  else {//En caso contrario, debemos crear el rectángulo suavizado
    IplImage *res= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvSet(res, color_pincel);
    IplImage *cop= cvCreateImage(cvGetSize(im), im->depth, im->nChannels);
    cvZero(cop);
    cvEllipse(cop, cvPoint(downx+((x-downx)/2), downy+((y-downy)/2)), cvSize(qAbs(x-downx)/2, qAbs(y-downy)/2), 0.0, 0.0, 360.0, CV_RGB(255,255,255), radio_pincel-1);
    cvSmooth(cop, cop, CV_BLUR, difum_pincel*2+1, difum_pincel*2+1);
    cvMul(res, cop, res, 1.0/255.0);
    cvNot(cop, cop);
    cvMul(im, cop, im, 1.0/255.0);
    cvAdd(res, im, im);
    cvReleaseImage(&cop);
    cvReleaseImage(&res);
  }
  cvShowImage(foto[factual].nombre, im);
  foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_elipse (int factual, int x, int y)
{
  IplImage *res= cvCloneImage(foto[factual].img);
  cvEllipse(res, cvPoint(downx+((x-downx)/2), downy+((y-downy)/2)), cvSize(qAbs(x-downx)/2, qAbs(y-downy)/2), 0.0, 0.0, 360.0, color_pincel, radio_pincel);
  cvShowImage(foto[factual].nombre, res);
  cvReleaseImage(&res);
}

//---------------------------------------------------------------------------

void callback (int event, int x, int y, int flags, void *_nfoto)
{
  int factual= (int) _nfoto;

  // 1. Eventos y casos especiales
  // 1.1. Evento cerrar ventana
  if (event==CV_EVENT_CLOSE) {
    cb_close(factual);
    return;
  }

  // 1.2. El ratón se sale de la ventana
  if (x>=foto[factual].img->width || y>=foto[factual].img->height)
    return;

  // 1.3. Se inicia la pulsación del ratón
  if (event==CV_EVENT_LBUTTONDOWN) {
    downx= x;
    downy= y;
  }

  // 2. Según la herramienta actual
  switch (herr_actual) {

    // 2.1. Herramienta PUNTOS
    case puntos:
       if (flags==CV_EVENT_FLAG_LBUTTON)
         cb_punto(factual, x, y);
       else
         ninguna_accion(factual, x, y);
       break;

    // 2.2. Herramienta LINEAS
    case lineas:
       if (event==CV_EVENT_LBUTTONUP)
         cb_linea(factual, x, y);
       else if (event==CV_EVENT_MOUSEMOVE && flags==CV_EVENT_FLAG_LBUTTON)
         cb_ver_linea(factual, x, y);
       else
         ninguna_accion(factual, x, y);
       break;

    // 2.3. Herramienta SELECCIONAR
    case seleccionar:
       if (event==CV_EVENT_LBUTTONUP)
         cb_seleccionar(factual, x, y);
       else if (event==CV_EVENT_MOUSEMOVE)
         cb_ver_seleccion(factual, x, y, flags!=CV_EVENT_FLAG_LBUTTON);
       break;

    // 2.4 Herramienta RECTANGULO
    case rectangulo:
       if (event==CV_EVENT_LBUTTONUP)
         cb_rectangulo(factual, x, y);
       else if (event==CV_EVENT_MOUSEMOVE && flags==CV_EVENT_FLAG_LBUTTON)
         cb_ver_rectangulo(factual, x, y);
       else
         ninguna_accion(factual, x, y);
       break;

    // 2.5 Herramienta ELIPSE
    case elipse:
       if (event==CV_EVENT_LBUTTONUP)
         cb_elipse(factual, x, y);
       else if (event==CV_EVENT_MOUSEMOVE && flags==CV_EVENT_FLAG_LBUTTON)
         cb_ver_elipse(factual, x, y);
       else
         ninguna_accion(factual, x, y);
        break;
  }
}


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////
void convertir_escala_color(int nfoto, int nres){
    //Variables
    IplImage *gris=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);    //imagen a escala de grises
    IplImage *gris2=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);   //imagen a escala de grises
    IplImage *gris3=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);   //imagen a escala de grises
    IplImage *resultado= cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,3);    //imagen de salida
    CvMat *lut= cvCreateMat(1, 256, CV_8UC3);
    int pincelR= color_pincel.val[2];
    int pincelV= color_pincel.val[1];
    int pincelA= color_pincel.val[0];
    int R, V, A;

    //Acciones
    cvCvtColor(foto[nfoto].img, gris, CV_RGB2GRAY);                             //convertimos la imagen a escala de grises
    cvCvtColor(foto[nfoto].img, gris2, CV_RGB2GRAY);                            //convertimos la imagen a escala de grises
    cvCvtColor(foto[nfoto].img, gris3, CV_RGB2GRAY);                            //convertimos la imagen a escala de grises
    cvMerge(gris,gris2,gris3,0,resultado);                                      //creamos una nueva imagen img con los 3 canales de gris duplicados

    for(int i=0;i<256;i++){
       if (i<128){
            R=pincelR*i/128;
            A=pincelA*i/128;
            V=pincelV*i/128;
            cvSet1D(lut,i,CV_RGB(R,V,A));
        }
        else {
            R= pincelR+(255-pincelR)*(i-128)/128;
            V= pincelV+(255-pincelV)*(i-128)/128;
            A= pincelA+(255-pincelA)*(i-128)/128;
            cvSet1D(lut,i,CV_RGB(R,V,A));
        }
        /*  otros efectos
        R= Valr*i/256;
        A= Vala*i/256;
        V= Valv*i/256;
        cvSet1D(lut,i,CV_RGB(R,V,A));
        */
        /*
        //efecto raro:
        if (i<128){
            R=Valr*i/128;
            A=Vala*i/128;
            V=Valv*i/128;
            cvSet1D(lut,i,CV_RGB(R,V,A));
        }
        else {
            R=Valr*(255-i)/128;
            A=Vala*(255-i)/128;
            V=Valv*(255-i)/128;
            cvSet1D(lut,i,CV_RGB(R,V,A));
       }
        */
    }
    cvLUT(resultado, resultado, lut);
    crear_nueva(nres, resultado);

    cvReleaseImage(&gris);                                                                     //Liberamos memoria
    cvReleaseImage(&gris2);
    cvReleaseImage(&gris3);
    cvReleaseMat(&lut);
}

void balance_blancos(int nfoto, int nres)
{
    //Variables
    IplImage *img= cvCloneImage(foto[nfoto].img);                                           //Creamos una imagen rgb clonando la foto que tenemos
    IplImage *r=cvCreateImage(cvSize(img->width, img->height), img->depth, 1);              //Creamos 3 imagenes r, g, b de 1 canal
    IplImage *g=cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
    IplImage *b=cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
    int mediaR; int mediaG; int mediaB;                                                     //Creamos 3 variables para almacenar la media de cada canal

    //Acciones
    cvSplit(img, b, g, r, NULL);                                                            //Dividimos la imagen en sus 3 canales r, g y b
    mediaR= 128-cvAvg(r, NULL).val[0];                                                      //Obtenemos la media de cada uno de los canales...
    mediaG= 128-cvAvg(g, NULL).val[0];                                                      //... y la modificamos para que sume 128
    mediaB= 128-cvAvg(b, NULL).val[0];

    for (int i=0; i<r->width; i++){                                                         //Vamos obteniendo cada pixel de la imagen resultado
        for(int j=0; j<r->height; j++){
            cvSet2D(r, j, i, cvScalar(mediaR+cvGet2D(r, j, i).val[0]));
            cvSet2D(g, j, i, cvScalar(mediaG+cvGet2D(g, j, i).val[0]));
            cvSet2D(b, j, i, cvScalar(mediaB+cvGet2D(b, j, i).val[0]));
        }
    }

    cvMerge(b, g, r, 0, img);                                                               //Unimos los canales otra vez.

    crear_nueva(nres, img);

    cvReleaseImage(&r);                                                                     //Liberamos memoria
    cvReleaseImage(&g);
    cvReleaseImage(&b);
}

void color_falso(int nfoto, int nres)
{
    //Variables
    int R, G, B;
    CvMat *lut= cvCreateMat(1, 256, CV_8UC3);                                   //tabla de transformación
    IplImage *gris=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);    //imagen a escala de grises
    IplImage *gris2=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);   //imagen a escala de grises
    IplImage *gris3=cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,1);   //imagen a escala de grises
    IplImage *img= cvCreateImage(cvGetSize(foto[nfoto].img),IPL_DEPTH_8U,3);    //imagen de salida

    //Acciones
    cvCvtColor(foto[nfoto].img, gris, CV_RGB2GRAY);                             //convertimos la imagen a escala de grises
    cvCvtColor(foto[nfoto].img, gris2, CV_RGB2GRAY);                            //convertimos la imagen a escala de grises
    cvCvtColor(foto[nfoto].img, gris3, CV_RGB2GRAY);                            //convertimos la imagen a escala de grises

    cvMerge(gris,gris2,gris3,0,img);                                            //creamos una nueva imagen img con los 3 canales de gris duplicados

    for(int i=0;i<43;i++){                                                      //preparamos la tabla de transformación
        R= 255;
        G= 255/42*i;
        B= 0;
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    for(int i=43;i<86;i++){
        R= 255-(255/43*(i-43));
        G= 255;
        B= 0;
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    for(int i=86;i<129;i++){
        R= 0;
        G= 255;
        B= 255/42*(i-86);
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    for(int i=128;i<171;i++){
        R= 0;
        G= 255-(255/42*(i-128));
        B= 255;
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    for(int i=171;i<214;i++){
        R= 255/42*(i-171);
        G= 0;
        B= 255;
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    for(int i=214;i<256;i++){
        R= 255;
        G= 0;
        B= 255-(255/42*(i-213));
        cvSet1D(lut,i,CV_RGB(R,G,B));
    }
    cvLUT(img, img, lut);                                                           //aplicamos la transformación

    crear_nueva(nres, img);
}

void invertir (int nfoto, int nres)
{
  IplImage *img= cvCreateImage(cvGetSize(foto[nfoto].img),
                               foto[nfoto].img->depth,
                               foto[nfoto].img->nChannels);
  cvNot(foto[nfoto].img, img);
  crear_nueva(nres, img);
}

//---------------------------------------------------------------------------

void rotar_angulo (int nfoto, IplImage *imgRes, double grado)
{
    int w= foto[nfoto].img->width/2.0;
    int h= foto[nfoto].img->height/2.0;
    int w2= imgRes->width/2.0;
    int h2= imgRes->height/2.0;
    CvMat *mrotacion= cvCreateMat(2, 3, CV_32FC1);
    cv2DRotationMatrix(cvPoint2D32f(0, 0), grado, 1.0, mrotacion);
    grado*= M_PI*2.0/360.0;
    double dx= w2 - w*cos(grado) - h*sin(grado);
    double dy= h2 + w*sin(grado) - h*cos(grado);
    cvSet2D(mrotacion, 0, 2, cvScalarAll(dx));
    cvSet2D(mrotacion, 1, 2, cvScalarAll(dy));
    cvWarpAffine(foto[nfoto].img, imgRes, mrotacion, CV_INTER_CUBIC);
    cvReleaseMat(&mrotacion);
}

//---------------------------------------------------------------------------

void rotar_exacto (int nfoto, int nres, int grado)
{
    int w= foto[nfoto].img->width;
    int h= foto[nfoto].img->height;
    IplImage *img= cvCreateImage((grado==1 || grado==3)?cvSize(h, w):cvSize(w, h),
                                 foto[nfoto].img->depth,
                                 foto[nfoto].img->nChannels);
    CvMat *mrotacion= cvCreateMat(2, 3, CV_32FC1);
    cv2DRotationMatrix(cvPoint2D32f(0, 0), grado*90.0, 1.0, mrotacion);
    double dx[3]= {0, w, h};
    double dy[3]= {w, h, 0};
    cvSet2D(mrotacion, 0, 2, cvScalarAll(dx[(grado+2)%3]));
    cvSet2D(mrotacion, 1, 2, cvScalarAll(dy[(grado+2)%3]));
    cvWarpAffine(foto[nfoto].img, img, mrotacion);
    crear_nueva(nres, img);
    cvReleaseMat(&mrotacion);
}

//---------------------------------------------------------------------------

void rotar_m90 (int nfoto)
{
  IplImage *img;
  int ant_foto= foto_activa();
  if (ant_foto<0)
    return;
  img= cvCreateImage(cvSize(foto[ant_foto].img->height, foto[ant_foto].img->width),
                     foto[ant_foto].img->depth, foto[ant_foto].img->nChannels);
/*  iplRotate(foto[ant_foto].img, img, -90.0, img->width-1, 0, IPL_INTER_NN); */
  crear_nueva(nfoto, img);
}

//---------------------------------------------------------------------------

void ver_brillo_contraste (int nfoto, int suma, double prod, double gama, bool guardar)
{
  IplImage * imr;   //imagen que usaremos para ajustar la gama.
  IplImage *img;
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
  img= cvCloneImage(foto[nfoto].img);
  cvScale(foto[nfoto].img, img, prod, suma);

  //gama
  imr= cvCreateImage(cvGetSize(foto[nfoto].img), IPL_DEPTH_32F, foto[nfoto].img->nChannels);    //Creamos una nueva imagen imr de profundidad 32 bits
  cvConvertScale(img, imr, 1./255, 0);                                                          //imr es de profundidad 32F
  cvPow(imr, imr, gama);                                                                        //elevamos la imagen
  cvConvertScale(imr, img, 255.0,0);
  cvReleaseImage(&imr);                                                                         //liberamos la memoria de img
  cvShowImage(foto[nfoto].nombre, img);
  if (guardar) {
    cvCopy(img, foto[nfoto].img);
    foto[nfoto].modificada= true;
  }
  cvReleaseImage(&img);
}

//---------------------------------------------------------------------------

void ver_matiz_sat_lumin(int nfoto, int matiz, double saturacion, double luminosidad, bool guardar)
{
    IplImage *img;
    IplImage *H, *L, *S;

    img= cvCloneImage(foto[nfoto].img);         //clonamos la imagen en img
    cvCvtColor(img,img,CV_BGR2HLS);             //la convertimos al espacio HLS

    H =cvCreateImage(cvGetSize(img),8,1);       //creamos el canal H
    L =cvCreateImage(cvGetSize(img),8,1);       //creamos el canal L
    S =cvCreateImage(cvGetSize(img),8,1);       //creamos el canal S
    cvSplit(img,H,L,S,NULL);                    //le damos a cada uno su valor
    //matiz= matiz%180;
    cvAddS(H,cvScalar(matiz),H,NULL);           //ajustamos el matiz

    cvConvertScaleAbs(H, H, 180.0, 0);          //provocamos que el valor del matiz sea modulo 180

    cvScale(L,L,luminosidad);                   //ajustamos la luminosidad
    cvScale(S,S,saturacion);                    //ajustamos la saturacion
    cvMerge(H,L,S,NULL,img);                    //juntamos los canales de nuevo
    cvCvtColor(img,img,CV_HLS2BGR);             //volvemos a convertir la imagen de HLS a RGB
    cvShowImage(foto[nfoto].nombre, img);       //mostramos la imagen
    if (guardar) {                              //la guardamos si es necesario
            cvCopy(img, foto[nfoto].img);
            foto[nfoto].modificada= true;
    }
    cvReleaseImage(&img);                       //liberamos memoria
    cvReleaseImage(&H);
    cvReleaseImage(&L);
    cvReleaseImage(&S);
}

//---------------------------------------------------------------------------

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy, bool guardar)
{
  IplImage *img;
  assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
  img= cvCloneImage(foto[nfoto].img);
  cvSmooth(foto[nfoto].img, img, ntipo, tamx, tamy);
  cvShowImage(foto[nfoto].nombre, img);
  if (guardar) {
    cvCopy(img, foto[nfoto].img);
    foto[nfoto].modificada= true;
  }
  cvReleaseImage(&img);
}

//---------------------------------------------------------------------------

void media_ponderada (int nf1, int nf2, int nueva, double peso)
{
  IplImage *img, *cop;
  img= cvCloneImage(foto[nf1].img);
  cop= cvCloneImage(foto[nf1].img);
  cvResize(foto[nf2].img, cop, CV_INTER_CUBIC);
  cvAddWeighted(img, peso, cop, 1.0-peso, 0, img);
  crear_nueva(nueva, img);
  cvReleaseImage(&cop);
}

//---------------------------------------------------------------------------

void crearcampana(IplImage *img, int cx, int cy, double sigma){
    double valor;
    for(int y=0; y<img->height; y++){
        for(int x=0; x<img->width; x++){
            valor = (x-cx)*(x-cx)+(y-cy)*(y-cy);
            valor = exp(-valor/(sigma*sigma));
            cvSet2D(img, y, x, cvScalarAll(valor));
        }
    }
}

//---------------------------------------------------------------------------

IplImage* crearmapax(IplImage *S, double a){
    IplImage *res = cvCloneImage(S);
    double valor;

    cvSobel(S, res, 1, 0);
    cvMul(S, res, res, a);
    for(int y=0; y<res->height; y++){
        for(int x=0; x<res->width; x++){
            valor = cvGet2D(res, y, x).val[0];
            cvSet2D(res, y, x, cvScalarAll(valor+x));
        }
    }
    return res;
}

//---------------------------------------------------------------------------

IplImage* crearmapay(IplImage *S, double a){
    IplImage *res = cvCloneImage(S);
    double valor;

    cvSobel(S, res, 0, 1);
    cvMul(S, res, res, a);
    for(int y=0; y<res->height; y++){
        for(int x=0; x<res->width; x++){
            valor = cvGet2D(res, y, x).val[0];
            cvSet2D(res, y, x, cvScalarAll(valor+y));
        }
    }
    return res;
}

//---------------------------------------------------------------------------

void f_pincharestirar(IplImage *ent, IplImage *sal, int cx, int cy, double sigma, double a){
    IplImage *S = cvCreateImage(cvGetSize(ent), IPL_DEPTH_32F, 1);
    crearcampana(S, cx, cy, sigma);
    IplImage *mapax = crearmapax(S, a);
    IplImage *mapay = crearmapay(S, a);
    cvRemap(ent, sal, mapax, mapay);
    cvReleaseImage(&S);
    cvReleaseImage(&mapax);
    cvReleaseImage(&mapay);
}

   //---------------------------------------------------------------------------

