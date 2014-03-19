#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

#include "acercade.h"
#include "brillocontraste.h"
#include "dialognueva.h"
#include "imagenes.h"
#include "mediadevideo.h"
#include "mediaponderada.h"
#include "rotaravideo.h"
#include "suavizados.h"
#include "capturardecamara.h"
#include "capturardevideo.h"
#include "pincharestirar.h"
#include "histograma.h"
#include "histograma2d.h"
#include "matizsaturacionluminosidad.h"
#include "ecualizacionhistograma.h"
#include "inpaint.h"
#include "ajustelinealhist.h"
#include "perfilado.h"
#include "transicionvideo.h"
#include "minimamaximadevideo.h"
#include "detecciondefondo.h"
#include "transformacionamalla.h"
#include "Informacion.h"
#include "bajorrelieve.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inic_fotos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStatusBarText(QString cadena)
{
    ui->statusBar->showMessage(cadena, 0);
}

int MainWindow::comprobar_primera_libre (void)
{
    int pl= primera_libre();
    if (pl==-1)
        QMessageBox::warning(this, "Error al crear imagen",
                             "Lo siento. No se pueden crear más ventanas.");
    return pl;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionNueva_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl!=-1) {
        DialogNueva nueva;
        if (nueva.exec()) {
            CvScalar color= CV_RGB(nueva.red(), nueva.green(), nueva.blue());
            crear_nueva(pl, nueva.getWidth(), nueva.getHeight(), color);
        }
    }
}

void MainWindow::on_actionAbrir_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl!=-1) {
        QString nombre= QFileDialog::getOpenFileName(this, "Abrir imagen", ".", FiltroImagen);
        if (!nombre.isEmpty())
            crear_nueva(pl, nombre.toAscii());
    }
}

void MainWindow::on_actionPunto_triggered()
{
    herr_actual= puntos;
    ui->toolButton_4->setChecked(true);
}

void MainWindow::on_actionLinea_triggered()
{
    herr_actual= lineas;
    ui->toolButton_5->setChecked(true);
}

void MainWindow::on_actionSeleccionar_triggered()
{
    herr_actual= seleccionar;
    ui->toolButton_6->setChecked(true);
}

void MainWindow::on_toolButton_2_clicked()
{
    on_actionNueva_imagen_triggered();
}

void MainWindow::on_pushButton_clicked()
{
    QColor color= QColorDialog::getColor();
    if (color.isValid()) {
        QString estilo= "background-color: rgb(";
        estilo+= QString::number(color.red())+",";
        estilo+= QString::number(color.green())+",";
        estilo+= QString::number(color.blue())+")";
        ui->pushButton->setStyleSheet(estilo);
        color_pincel= CV_RGB(color.red(), color.green(), color.blue());
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    radio_pincel= value;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    difum_pincel= value;
}

void MainWindow::on_toolButton_clicked()
{
    on_actionAbrir_imagen_triggered();
}

void MainWindow::on_actionGuardar_triggered()
{
    int fa= foto_activa();
    if (fa!=-1)
        guardar_foto(fa);
}

void MainWindow::on_actionGuardar_como_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        QString nombre= QFileDialog::getSaveFileName(this, "Guardar imagen", foto[fa].nombre, FiltroImagen);
        if (!nombre.isEmpty())
            guardar_foto(fa, nombre.toAscii());
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        if (foto[fa].modificada && preguntar_guardar) {
            QString nombre= foto[fa].nombre;
            nombre= "El archivo " + nombre + " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(this, "Archivo modificado", nombre,
                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if (resp==QMessageBox::Yes)
                guardar_foto(fa);
            else if (resp==QMessageBox::Cancel)
                return;
        }
        cerrar_foto(fa);
    }
}

void MainWindow::on_actionPreguntar_si_guardar_triggered()
{
    preguntar_guardar= ui->actionPreguntar_si_guardar->isChecked();
}

void MainWindow::on_actionColor_del_pincel_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionSeleccionar_todo_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        foto[fa].roi= cvRect(-1, -1, -1, -1);
        mostrar(fa);
    }
}

void MainWindow::on_toolButton_4_clicked()
{
    herr_actual= puntos;
}

void MainWindow::on_toolButton_5_clicked()
{
    herr_actual= lineas;
}

void MainWindow::on_toolButton_6_clicked()
{
    herr_actual= seleccionar;
}

void MainWindow::on_actionInvertir_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            invertir(fa, pl);
    }
}

void MainWindow::on_actionRotar_90_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            rotar_exacto(fa, pl, 1);
    }
}

void MainWindow::on_actionRotar_180_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            rotar_exacto(fa, pl, 1);
    }
}

void MainWindow::on_actionRotar_91_triggered()
{
    int fa= foto_activa();
    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            rotar_exacto(fa, pl, 1);
    }
}

void MainWindow::on_actionBrillo_contraste_triggered()
{
    if (foto_activa()!=-1) {
        brillocontraste bc;
        bc.exec();
    }
}

void MainWindow::on_actionGausiano_triggered()
{
    if (foto_activa()!=-1) {
        suavizados sg(CV_GAUSSIAN);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_triggered()
{
    if (foto_activa()!=-1) {
        suavizados sg(CV_BLUR);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_ponderada_triggered()
{
    if (foto_activa()!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1) {
            mediaponderada mp;
            mp.exec();
        }
    }
}

void MainWindow::on_actionRotar_imagen_triggered()
{
    if (foto_activa()!=-1) {
        rotaravideo rv;
        rv.exec();
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    acercade ad;
    ad.exec();
}

void MainWindow::on_actionImagen_media_triggered()
{
    mediadevideo mv;
    mv.exec();
}

void MainWindow::on_actionPinchar_Estirar_triggered()
{
    if(foto_activa() != -1){
        pincharestirar dpe;
        dpe.exec();
    }
}

void MainWindow::on_actionCapturar_de_C_mara_triggered()
{
    capturardecamara cdc;
    cdc.exec();
}

void MainWindow::on_actionCapturar_de_Video_triggered()
{
    capturardevideo cdv;
    cdv.exec();
}

void MainWindow::on_actionCopiar_a_nueva_triggered()
{
    IplImage *recorte;                                          //imagen que contendrá el recorte

    int fa= foto_activa();                                      //obtenemos el número de foto activa
    int pl= comprobar_primera_libre();                          //obtenemos la primera posición libre
    if(fa!=-1 && pl!=-1){                                       //si todo es correcto proseguimos
        if(foto[fa].roi.width <= 0 || foto[fa].roi.height <= 0){//si no hay roi seleccionado...
            recorte= cvCloneImage(foto[fa].img);                //copiamos la imagen
            crear_nueva(pl, recorte);
        }
        else{                                                   //si sí que hay roi seleccionado...
            cvSetImageROI(foto[fa].img, foto[fa].roi);          //se lo establecemos a la imagen
            recorte= cvCreateImage(cvSize(foto[fa].roi.width, foto[fa].roi.height),foto[fa].img->depth, foto[fa].img->nChannels); //creamos la imagen que contendrá el recorte
            cvCopy(foto[fa].img, recorte);                      //copiamos el recorte a la imagen
            cvResetImageROI(foto[fa].img);                      //Dejamos la roi como estaba
            crear_nueva(pl,recorte);                            //introducimos la imagen en la lista de imágenes
        }
    }
}

void MainWindow::on_actionVer_histograma_triggered()
{
    histograma h;
    h.exec();
}

void MainWindow::on_actionVer_histograma_2D_triggered()
{
    histograma2D h2D;
    h2D.exec();
}

void MainWindow::on_toolButton_Rectangulo_clicked()
{
    herr_actual = rectangulo;                       //Selección de herramienta
}

void MainWindow::on_actionRect_ngulo_triggered()
{
    herr_actual = rectangulo;                       //Selección de herramienta
    ui->toolButton_Rectangulo->setChecked(true);    //Para el botón de la ui
}

void MainWindow::on_toolButton_Elipse_clicked()
{
    herr_actual = elipse;                            //Selección de herramienta
}

void MainWindow::on_actionElipse_triggered()
{
    herr_actual = elipse;                           //Selección de herramienta
    ui->toolButton_Elipse->setChecked(true);        //Para el botón de la ui
}

void MainWindow::on_actionMatiz_Saturacion_Luminosidad_triggered()
{
    if (foto_activa()!=-1) {
        matizsaturacionluminosidad msl;
        msl.exec();
    }
}

void MainWindow::on_actionEcualizaci_n_del_histograma_triggered()
{
    if (foto_activa()!=-1) {
        ecualizacionhistograma eh;
        eh.exec();
    }
}

void MainWindow::on_actionInPaint_triggered()
{
    if (foto_activa()!=-1) {
        inpaint di;
        di.exec();
    }
}

void MainWindow::on_actionAjuste_lineal_del_histograma_triggered()
{
    if (foto_activa()!=-1) {
        ajustelinealhist alh;
        alh.exec();
    }
}

void MainWindow::on_actionConvertir_a_color_falso_triggered()
{
    int fa= foto_activa();

    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            color_falso(fa, pl);
    }
}

void MainWindow::on_actionBalance_de_blancos_triggered()
{
    int fa= foto_activa();

    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            balance_blancos(fa, pl);
    }
}

void MainWindow::on_actionPerfilado_triggered()
{
    if (foto_activa()!=-1) {
        perfilado p;
        p.exec();
    }
}

void MainWindow::on_actionTransicion_entre_imagenes_triggered()
{
    transicionvideo tv;
    tv.exec();
}

void MainWindow::on_actionImagenes_m_nima_y_m_xima_triggered()
{
    minimamaximadevideo mmv;
    mmv.exec();
}

void MainWindow::on_actionDetecci_n_de_fondo_triggered()
{
    detecciondefondo ddf;
    ddf.exec();
}

void MainWindow::on_actionTransformaci_n_de_malla_triggered()
{
    transformacionamalla tdm;
    tdm.exec();
}

void MainWindow::on_actionMediana_triggered()
{
    if (foto_activa()!=-1) {
        suavizados sg(CV_MEDIAN);
        sg.exec();
    }
}

void MainWindow::on_actionConvertir_a_escala_de_color_triggered()
{
    int fa= foto_activa();

    if (fa!=-1) {
        int pl= comprobar_primera_libre();
        if (pl!=-1)
            convertir_escala_color(fa, pl);
    }
}

void MainWindow::on_actionVer_informaci_n_triggered()
{
    int fa= foto_activa();

    if (fa!=-1) {
        Informacion inf;
        inf.exec();
    }
}

void MainWindow::on_actionBajorrelieve_triggered()
{
    int fa= foto_activa();

    if (fa!=-1) {
        bajorrelieve br;
        br.exec();
    }
}
