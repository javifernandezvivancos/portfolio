#ifndef IMAGENES_H
#define IMAGENES_H

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

///////////////////////////////////////////////////////////////////
/////////  DEFINICIONES PUBLICAS                     //////////////
///////////////////////////////////////////////////////////////////

#define MAX_VENTANAS 50

#define min(a, b)      (((a) < (b)) ? (a) : (b))
#define max(a, b)      (((a) > (b)) ? (a) : (b))
#define mod(a)         ((a) >= 0 ? (a) : (a*(-1)))


///////////////////////////////////////////////////////////////////
/////////  TIPOS DE DATOS PROPIOS                    //////////////
///////////////////////////////////////////////////////////////////

// STRUCT ventana
//    Representa la información asociada a una imagen que está siendo
//    editada actualmente en la aplicación

struct ventana {
  bool usada;          // Indica si se está usando actualmente esta posición
  bool modificada;     // Imagen modificada después de abrirla o crearla
  char *nombre;        // Nombre del fichero que contiene la imagen
  HWND handle;         // Manejador de Windows de la ventana de HighGUI
  CvRect roi;          // Región de interés seleccionada (-1 si no hay ninguna)
  IplImage *img;       // La imagen en sí
};

// ENUM tipo_herramienta
//    Enumerado con los distintos tipos posibles de herramientas
//    que se pueden usar. Añadir nuevas aquí

enum tipo_herramienta {puntos, lineas, seleccionar, rectangulo, elipse};


///////////////////////////////////////////////////////////////////
/////////  VARIABLES PÚBLICAS                        //////////////
///////////////////////////////////////////////////////////////////

extern ventana foto[MAX_VENTANAS];
// El array foto guarda la información de todas las imágenes abiertas
// actualmente o que pueden ser abiertas, hasta un máximo de MAX_VENTANAS

extern tipo_herramienta herr_actual;
// Herramienta que se ha seleccionado actualmente

extern int radio_pincel;
// Radio actual para pintar puntos y líneas

extern CvScalar color_pincel;
// Color actual del pincel

extern int difum_pincel;
// Difuminado actual del pincel

extern bool preguntar_guardar;
// Al cerrar una imagen modificada, preguntar si se guarda o no

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void inic_fotos (void);
// Inicializa el array foto, de imágenes abiertas actualmente

void fin_fotos (void);
// Libera las imágenes del array foto

int primera_libre (void);
// Busca la primera entrada libre del array foto

void crear_nueva (int nfoto, int ancho, int alto, CvScalar color);
// Crea una nueva entrada, en la posición nfoto, con el ancho y el alto dados,
// de profundidad IPL_DEPTH_8U y 3 canales. color indica el color de fondo

void crear_nueva (int nfoto, IplImage *img);
// Crea una nueva entrada, en la posición nfoto, usando la imagen dada en img

void crear_nueva (int nfoto, const char *nombre);
// Crea una nueva entrada, en la posición nfoto, leyéndola del archivo nombre.
// Si no se puede leer, no hace nada

void mostrar (int nfoto);
// Muestra la imagen de la entrada nfoto en la ventana correspondiente

void guardar_foto (int nfoto, const char *nombre= NULL);
// Guarda en disco la imagen de nfoto, con el nombre dado. Si el nombre
// es NULL, usa el nombre de la imagen en el array foto. Si cerrar es false,
// se cierra la ventana con la imagen (modo "guardar y cerrar")

void cerrar_foto (int nfoto, bool destruir_ventana= true);
// Elimina la entrada en la posición nfoto. destruir_ventana indica si debe
// destruirse la ventana de HighGUI (ya que si lo ha hecho el usuario, no
// debe volver a hacerse)

int nombre_a_numero (const char *nombre);
// Dado un nombre de ventana, busca su número en el array foto.
// Si no lo encuentra devuelve -1

int foto_activa (void);
// Devuelve el número de la ventana de imagen activa (la que esté en primer
// lugar). Si no hay ninguna devuelve -1

int num_fotos (int &usadas, int &modificadas);
// Devuelve el número de fotos que hay abiertas actualmente

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////
void convertir_escala_color(int nfoto, int nres);
// Convierte la imagen a escala de color

void balance_blancos(int nfoto, int nres);
// Ajusta automaticamente el balance de blancos de una imagen y la almacena en nres

void color_falso(int nfoto, int nres);
// Convierte una imagen en escala de grises a color falso y la almacena en nres

void invertir (int nfoto, int nres);
// Invierte la imagen contenida en nfoto y la almacena en nres

void rotar_angulo (int nfoto, IplImage *imgRes, double grado);
// Rota la imagen contenida en nfoto, en la cantidad grado
// y la almacena el resultado en imgRes. La imagen de salida
// siempre está centrada

void rotar_exacto (int nfoto, int nres, int grado);
// Rota la imagen contenida en nfoto, en la cantidad 90*grado
// y la almacena en nres. Se trata siempre de una rotación exacta

void ver_brillo_contraste (int nfoto, int suma, double prod, double gama,
                           bool guardar= false);
// Modifica la imagen en nfoto, tomando para cada píxel A(x,y) el valor:
// A(x,y)*prod + suma. Si guardar==true se guarda la imagen, y en otro caso
// sólo se visualiza el resultado, pero sin guardar

void ver_matiz_sat_lumin (int nfoto, int matiz, double saturacion, double luminosidad,
                          bool guardar= false);
// Modifica la imagen en nfoto, ajustando cada píxel según los valores de matiz,
// saturacion y luminosidad dados como parametro. Si guardar==true se guarda la imagen,
// y en otro caso sólo se visualiza el resultado, pero sin guardar.

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy,
                    bool guardar= false);
// Modifica la imagen en nfoto, aplicando un suavizado de tamaño dado. ntipo
// puede ser CV_GAUSSIAN o CV_BLUR. Si guardar==true se guarda la imagen, y
// en otro caso sólo se visualiza el resultado, pero sin guardar

void media_ponderada (int nf1, int nf2, int nueva, double peso);
// Calcula la media ponderada entre la imagen nf1 y la nf2, según el peso dado,
// y almacena el resultado en la posición nueva. Se aplica la fórmula:
// nueva(x,y):= peso*nf1(x,y)+(1-peso)*nf2(x,y). La imagen nf2 se reescala al
// tamaño de nf1

void crearcampana(IplImage *img, int cx, int cy, double sigma);
//

IplImage* crearmapax(IplImage *S, double a);
//

IplImage* crearmapay(IplImage *S, double a);
//

void f_pincharestirar(IplImage *ent, IplImage *sal, int cx, int cy, double sigma, double a);
//



#endif // IMAGENES_H
