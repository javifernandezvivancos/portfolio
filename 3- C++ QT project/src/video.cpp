//---------------------------------------------------------------------------

#include "video.h"
#include <math.h>

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES PRIVADAS               //////////////
///////////////////////////////////////////////////////////////////

CvCapture *camara= NULL;
// Capturador de cámara usado actualmente

IplImage *img_media= NULL;
// Imagen media acumulada de la cámara

IplImage *frame_float= NULL;
// Suma de los frames acumulados en la cámara

int frames_img_media;
// Número de frames que se han acumulado en la media frame_float

const char FiltroVideo[]= "Todos los formatos (*.avi *.mpg *.wmv *.mov);;Archivos AVI (*.avi);;Archivos MPG (*.mpg *.mpeg);;Archivos WMV (*.wmv);;Archivos MOV (*.mov);;Otros (*.*)";

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE VIDEO       //////////////
///////////////////////////////////////////////////////////////////

void rotar_video (int nfoto, const char *nombre, int modo, int nframes, int codec, double fps)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada && nombre && nframes>0);
    int w= foto[nfoto].img->width;
    int h= foto[nfoto].img->height;
    CvSize sres;
    if (modo==0) {
        sres.width= w;
        sres.height= h;
    }
    else if (modo==1)
        sres.width= sres.height= sqrt(w*w + h*h);
    else
        sres.width= sres.height= min(w, h)/sqrt(2.0);
    IplImage* res= cvCreateImage(sres, foto[nfoto].img->depth, foto[nfoto].img->nChannels);
    CvVideoWriter* aw= cvCreateVideoWriter(nombre, codec, fps, sres);
    if (aw) {
        for (int i= 0; i<nframes; i++) {
            cvSet(res, color_pincel);
            rotar_angulo(nfoto, res, i*360.0/nframes);
            cvNamedWindow("Imagen a vídeo - Rotación", 1);
            cvShowImage("Imagen a vídeo - Rotación", res);
            cvWaitKey(1);
            cvWriteFrame(aw, res);
        }
        cvReleaseVideoWriter(&aw);
        cvDestroyWindow("Imagen a vídeo - Rotación");
    }
    cvReleaseImage(&res);
}

//---------------------------------------------------------------------------

int inic_camara (int numero)
{
    assert(!camara);
    camara= cvCaptureFromCAM(numero);
    if (camara) {
        IplImage *img;
        cvNamedWindow("Imagen de cámara", 0);
        img= cvQueryFrame(camara);
        cvResizeWindow("Imagen de cámara", img->width, img->height);
        cvShowImage("Imagen de cámara", img);
        return 1000.0/30;
    }
    else
        return 0;
}

//---------------------------------------------------------------------------

void fin_camara (void)
{
    if (camara) {
        cvReleaseCapture(&camara);
        cvDestroyWindow("Imagen de cámara");
    }
    if (img_media) {
        cvReleaseImage(&img_media);
        cvDestroyWindow("Imagen media");
    }
}

//---------------------------------------------------------------------------

void acumular_media (bool primera)
{
    assert(camara);
    IplImage *frame= cvQueryFrame(camara);
    if (frame->origin) {
        cvFlip(frame);
        frame->origin= 0;
    }
    cvNamedWindow("Imagen de cámara", 0);
    cvShowImage("Imagen de cámara", frame);
    if (primera) {
        cvReleaseImage(&img_media);
        cvReleaseImage(&frame_float);
    }
    if (!img_media) {
        img_media= cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_32F, frame->nChannels);
        frame_float= cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_32F, frame->nChannels);
        cvConvert(frame, img_media);
        cvNamedWindow("Imagen media", 1);
        frames_img_media= 1;
        cvShowImage("Imagen media", frame);
    }
    else {
        frames_img_media++;
        cvScale(frame, frame_float);
        cvAdd(img_media, frame_float, img_media);
        cvConvertScale(img_media, frame, 1.0/frames_img_media);
        cvShowImage("Imagen media", frame);
    }
}

//---------------------------------------------------------------------------

void media_a_nueva (int nfoto)
{
    IplImage *res= cvCreateImage(cvSize(img_media->width, img_media->height),
                                 IPL_DEPTH_8U, img_media->nChannels);
    cvConvertScale(img_media, res, 1.0/frames_img_media);
    crear_nueva (nfoto, res);
}

//---------------------------------------------------------------------------

void mostrar_camara (void)
{
    cvNamedWindow("Imagen de cámara", 0);
    IplImage *img= cvQueryFrame(camara);
    cvShowImage("Imagen de cámara", img);
}

//---------------------------------------------------------------------------

void dialogo_video (int tipo)
{
    cvSetCaptureProperty(camara, tipo, CV_CAP_PROP_SOURCE);
}

//---------------------------------------------------------------------------
