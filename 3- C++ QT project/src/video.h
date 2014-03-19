#ifndef VIDEO_H
#define VIDEO_H

#include "imagenes.h"
// Se usa el m�dulo de procesamiento de im�genes

extern const char FiltroVideo[];

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE VIDEO       //////////////
///////////////////////////////////////////////////////////////////

void rotar_video (int nfoto, const char *nombre, int modo, int nframes, int codec, double fps= 30.0);
// Crea un v�deo, con el nombre dado (que debe tener extensi�n .avi) de tama�o
// nframes, con una rotaci�n de 360� de la imagen nfoto

int inic_camara (int numero= 0);
// Inicializa la c�mara con el n�mero de �ndice indicado. La imagen se muestra
// en una ventana. Si no se puede abrir la c�mara devuelve 0. En otro caso
// devuelve el n�mero de milisegundos entre cada par de frames

void fin_camara (void);
// Finaliza la captura de c�mara, cerrando la ventana correspondiente

void acumular_media (bool primera= false);
// Captura una imagen de la c�mara y la acumula en una media. La c�mara debe
// estar inicializada. Si primera==true significa que es la primera imagen

void media_a_nueva (int nfoto);
// Almacena la imagen media actual en la entrada nfoto

void mostrar_camara (void);
// Captura una imagen de la c�mara y la muestra en la ventana correspondiente

void dialogo_video (int tipo);
// Abre el cuadro de di�logo de v�deo asociado a la c�mara. La c�mara debe
// estar inicializada. tipo puede ser _DIALOG_FORMAT o _DIALOG_SOURCE

#endif // VIDEO_H
