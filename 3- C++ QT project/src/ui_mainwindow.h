/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 16. Sep 03:01:12 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNueva_imagen;
    QAction *actionAbrir_imagen;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionCerrar;
    QAction *actionSalir;
    QAction *actionPunto;
    QAction *actionLinea;
    QAction *actionSeleccionar;
    QAction *actionSeleccionar_todo;
    QAction *actionColor_del_pincel;
    QAction *actionPreguntar_si_guardar;
    QAction *actionBrillo_contraste;
    QAction *actionInvertir;
    QAction *actionRotar_90;
    QAction *actionRotar_91;
    QAction *actionMedia_ponderada;
    QAction *actionRotar_180;
    QAction *actionGausiano;
    QAction *actionMedia;
    QAction *actionRotar_imagen;
    QAction *actionAcerca_de;
    QAction *actionImagen_media;
    QAction *actionPinchar_Estirar;
    QAction *actionCapturar_de_C_mara;
    QAction *actionCapturar_de_Video;
    QAction *actionCopiar_a_nueva;
    QAction *actionVer_histograma;
    QAction *actionVer_histograma_2D;
    QAction *actionRect_ngulo;
    QAction *actionElipse;
    QAction *actionMatiz_Saturacion_Luminosidad;
    QAction *actionEcualizaci_n_del_histograma;
    QAction *actionInPaint;
    QAction *actionAjuste_lineal_del_histograma;
    QAction *actionConvertir_a_color_falso;
    QAction *actionBalance_de_blancos;
    QAction *actionPerfilado;
    QAction *actionTransicion_entre_imagenes;
    QAction *actionImagenes_m_nima_y_m_xima;
    QAction *actionDetecci_n_de_fondo;
    QAction *actionTransformaci_n_de_malla;
    QAction *actionMediana;
    QAction *actionConvertir_a_escala_de_color;
    QAction *actionVer_informaci_n;
    QAction *actionBajorrelieve;
    QWidget *centralWidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QPushButton *pushButton;
    QToolButton *toolButton_Rectangulo;
    QToolButton *toolButton_Elipse;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEdici_n;
    QMenu *menuOpciones;
    QMenu *menuHerramientas;
    QMenu *menuTransformar;
    QMenu *menuRotar;
    QMenu *menuEfectos;
    QMenu *menuSuavizado;
    QMenu *menuV_deo;
    QMenu *menuImagen_a_v_deo;
    QMenu *menuV_deo_a_imagen;
    QMenu *menuV_deo_a_video;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(544, 140);
        MainWindow->setMinimumSize(QSize(544, 140));
        MainWindow->setMaximumSize(QSize(544, 140));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNueva_imagen = new QAction(MainWindow);
        actionNueva_imagen->setObjectName(QString::fromUtf8("actionNueva_imagen"));
        actionAbrir_imagen = new QAction(MainWindow);
        actionAbrir_imagen->setObjectName(QString::fromUtf8("actionAbrir_imagen"));
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName(QString::fromUtf8("actionGuardar"));
        actionGuardar_como = new QAction(MainWindow);
        actionGuardar_como->setObjectName(QString::fromUtf8("actionGuardar_como"));
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QString::fromUtf8("actionCerrar"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        actionPunto = new QAction(MainWindow);
        actionPunto->setObjectName(QString::fromUtf8("actionPunto"));
        actionLinea = new QAction(MainWindow);
        actionLinea->setObjectName(QString::fromUtf8("actionLinea"));
        actionSeleccionar = new QAction(MainWindow);
        actionSeleccionar->setObjectName(QString::fromUtf8("actionSeleccionar"));
        actionSeleccionar_todo = new QAction(MainWindow);
        actionSeleccionar_todo->setObjectName(QString::fromUtf8("actionSeleccionar_todo"));
        actionColor_del_pincel = new QAction(MainWindow);
        actionColor_del_pincel->setObjectName(QString::fromUtf8("actionColor_del_pincel"));
        actionPreguntar_si_guardar = new QAction(MainWindow);
        actionPreguntar_si_guardar->setObjectName(QString::fromUtf8("actionPreguntar_si_guardar"));
        actionPreguntar_si_guardar->setCheckable(true);
        actionPreguntar_si_guardar->setChecked(true);
        actionBrillo_contraste = new QAction(MainWindow);
        actionBrillo_contraste->setObjectName(QString::fromUtf8("actionBrillo_contraste"));
        actionInvertir = new QAction(MainWindow);
        actionInvertir->setObjectName(QString::fromUtf8("actionInvertir"));
        actionRotar_90 = new QAction(MainWindow);
        actionRotar_90->setObjectName(QString::fromUtf8("actionRotar_90"));
        actionRotar_91 = new QAction(MainWindow);
        actionRotar_91->setObjectName(QString::fromUtf8("actionRotar_91"));
        actionMedia_ponderada = new QAction(MainWindow);
        actionMedia_ponderada->setObjectName(QString::fromUtf8("actionMedia_ponderada"));
        actionRotar_180 = new QAction(MainWindow);
        actionRotar_180->setObjectName(QString::fromUtf8("actionRotar_180"));
        actionGausiano = new QAction(MainWindow);
        actionGausiano->setObjectName(QString::fromUtf8("actionGausiano"));
        actionMedia = new QAction(MainWindow);
        actionMedia->setObjectName(QString::fromUtf8("actionMedia"));
        actionRotar_imagen = new QAction(MainWindow);
        actionRotar_imagen->setObjectName(QString::fromUtf8("actionRotar_imagen"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
        actionImagen_media = new QAction(MainWindow);
        actionImagen_media->setObjectName(QString::fromUtf8("actionImagen_media"));
        actionPinchar_Estirar = new QAction(MainWindow);
        actionPinchar_Estirar->setObjectName(QString::fromUtf8("actionPinchar_Estirar"));
        actionCapturar_de_C_mara = new QAction(MainWindow);
        actionCapturar_de_C_mara->setObjectName(QString::fromUtf8("actionCapturar_de_C_mara"));
        actionCapturar_de_Video = new QAction(MainWindow);
        actionCapturar_de_Video->setObjectName(QString::fromUtf8("actionCapturar_de_Video"));
        actionCopiar_a_nueva = new QAction(MainWindow);
        actionCopiar_a_nueva->setObjectName(QString::fromUtf8("actionCopiar_a_nueva"));
        actionVer_histograma = new QAction(MainWindow);
        actionVer_histograma->setObjectName(QString::fromUtf8("actionVer_histograma"));
        actionVer_histograma_2D = new QAction(MainWindow);
        actionVer_histograma_2D->setObjectName(QString::fromUtf8("actionVer_histograma_2D"));
        actionRect_ngulo = new QAction(MainWindow);
        actionRect_ngulo->setObjectName(QString::fromUtf8("actionRect_ngulo"));
        actionElipse = new QAction(MainWindow);
        actionElipse->setObjectName(QString::fromUtf8("actionElipse"));
        actionMatiz_Saturacion_Luminosidad = new QAction(MainWindow);
        actionMatiz_Saturacion_Luminosidad->setObjectName(QString::fromUtf8("actionMatiz_Saturacion_Luminosidad"));
        actionEcualizaci_n_del_histograma = new QAction(MainWindow);
        actionEcualizaci_n_del_histograma->setObjectName(QString::fromUtf8("actionEcualizaci_n_del_histograma"));
        actionInPaint = new QAction(MainWindow);
        actionInPaint->setObjectName(QString::fromUtf8("actionInPaint"));
        actionAjuste_lineal_del_histograma = new QAction(MainWindow);
        actionAjuste_lineal_del_histograma->setObjectName(QString::fromUtf8("actionAjuste_lineal_del_histograma"));
        actionConvertir_a_color_falso = new QAction(MainWindow);
        actionConvertir_a_color_falso->setObjectName(QString::fromUtf8("actionConvertir_a_color_falso"));
        actionBalance_de_blancos = new QAction(MainWindow);
        actionBalance_de_blancos->setObjectName(QString::fromUtf8("actionBalance_de_blancos"));
        actionPerfilado = new QAction(MainWindow);
        actionPerfilado->setObjectName(QString::fromUtf8("actionPerfilado"));
        actionTransicion_entre_imagenes = new QAction(MainWindow);
        actionTransicion_entre_imagenes->setObjectName(QString::fromUtf8("actionTransicion_entre_imagenes"));
        actionImagenes_m_nima_y_m_xima = new QAction(MainWindow);
        actionImagenes_m_nima_y_m_xima->setObjectName(QString::fromUtf8("actionImagenes_m_nima_y_m_xima"));
        actionDetecci_n_de_fondo = new QAction(MainWindow);
        actionDetecci_n_de_fondo->setObjectName(QString::fromUtf8("actionDetecci_n_de_fondo"));
        actionTransformaci_n_de_malla = new QAction(MainWindow);
        actionTransformaci_n_de_malla->setObjectName(QString::fromUtf8("actionTransformaci_n_de_malla"));
        actionMediana = new QAction(MainWindow);
        actionMediana->setObjectName(QString::fromUtf8("actionMediana"));
        actionConvertir_a_escala_de_color = new QAction(MainWindow);
        actionConvertir_a_escala_de_color->setObjectName(QString::fromUtf8("actionConvertir_a_escala_de_color"));
        actionVer_informaci_n = new QAction(MainWindow);
        actionVer_informaci_n->setObjectName(QString::fromUtf8("actionVer_informaci_n"));
        actionBajorrelieve = new QAction(MainWindow);
        actionBajorrelieve->setObjectName(QString::fromUtf8("actionBajorrelieve"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(40, 0, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/imagenes/abrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(0, 0, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/imagenes/nuevo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setAutoRaise(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 241, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 70, 241, 21));
        horizontalSlider->setMaximum(120);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 50, 241, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(260, 70, 241, 21));
        horizontalSlider_2->setMaximum(120);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(80, 0, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/imagenes/guardar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setAutoRaise(true);
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(130, 0, 41, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/imagenes/punto.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setCheckable(true);
        toolButton_4->setChecked(true);
        toolButton_4->setAutoExclusive(true);
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setGeometry(QRect(170, 0, 41, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/imagenes/linea.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(32, 32));
        toolButton_5->setCheckable(true);
        toolButton_5->setAutoExclusive(true);
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setGeometry(QRect(290, 0, 41, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/imagenes/seleccionar.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setCheckable(true);
        toolButton_6->setAutoExclusive(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        toolButton_Rectangulo = new QToolButton(centralWidget);
        toolButton_Rectangulo->setObjectName(QString::fromUtf8("toolButton_Rectangulo"));
        toolButton_Rectangulo->setGeometry(QRect(210, 0, 41, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/imagenes/rectangulo.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Rectangulo->setIcon(icon7);
        toolButton_Rectangulo->setIconSize(QSize(32, 32));
        toolButton_Rectangulo->setCheckable(true);
        toolButton_Rectangulo->setAutoExclusive(true);
        toolButton_Elipse = new QToolButton(centralWidget);
        toolButton_Elipse->setObjectName(QString::fromUtf8("toolButton_Elipse"));
        toolButton_Elipse->setGeometry(QRect(250, 0, 41, 41));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/imagenes/elipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Elipse->setIcon(icon8);
        toolButton_Elipse->setIconSize(QSize(32, 32));
        toolButton_Elipse->setCheckable(true);
        toolButton_Elipse->setAutoExclusive(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 544, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        menuEdici_n = new QMenu(menuBar);
        menuEdici_n->setObjectName(QString::fromUtf8("menuEdici_n"));
        menuOpciones = new QMenu(menuEdici_n);
        menuOpciones->setObjectName(QString::fromUtf8("menuOpciones"));
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName(QString::fromUtf8("menuHerramientas"));
        menuTransformar = new QMenu(menuBar);
        menuTransformar->setObjectName(QString::fromUtf8("menuTransformar"));
        menuRotar = new QMenu(menuTransformar);
        menuRotar->setObjectName(QString::fromUtf8("menuRotar"));
        menuEfectos = new QMenu(menuBar);
        menuEfectos->setObjectName(QString::fromUtf8("menuEfectos"));
        menuSuavizado = new QMenu(menuEfectos);
        menuSuavizado->setObjectName(QString::fromUtf8("menuSuavizado"));
        menuV_deo = new QMenu(menuBar);
        menuV_deo->setObjectName(QString::fromUtf8("menuV_deo"));
        menuImagen_a_v_deo = new QMenu(menuV_deo);
        menuImagen_a_v_deo->setObjectName(QString::fromUtf8("menuImagen_a_v_deo"));
        menuV_deo_a_imagen = new QMenu(menuV_deo);
        menuV_deo_a_imagen->setObjectName(QString::fromUtf8("menuV_deo_a_imagen"));
        menuV_deo_a_video = new QMenu(menuV_deo);
        menuV_deo_a_video->setObjectName(QString::fromUtf8("menuV_deo_a_video"));
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdici_n->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuBar->addAction(menuTransformar->menuAction());
        menuBar->addAction(menuEfectos->menuAction());
        menuBar->addAction(menuV_deo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNueva_imagen);
        menuArchivo->addAction(actionAbrir_imagen);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCapturar_de_C_mara);
        menuArchivo->addAction(actionCapturar_de_Video);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionGuardar_como);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addAction(actionSalir);
        menuEdici_n->addAction(actionSeleccionar_todo);
        menuEdici_n->addAction(actionCopiar_a_nueva);
        menuEdici_n->addSeparator();
        menuEdici_n->addAction(menuOpciones->menuAction());
        menuEdici_n->addAction(actionVer_histograma);
        menuEdici_n->addAction(actionVer_histograma_2D);
        menuEdici_n->addAction(actionVer_informaci_n);
        menuOpciones->addAction(actionColor_del_pincel);
        menuOpciones->addAction(actionPreguntar_si_guardar);
        menuHerramientas->addAction(actionPunto);
        menuHerramientas->addAction(actionLinea);
        menuHerramientas->addAction(actionRect_ngulo);
        menuHerramientas->addAction(actionElipse);
        menuHerramientas->addAction(actionSeleccionar);
        menuTransformar->addAction(actionBrillo_contraste);
        menuTransformar->addAction(actionMatiz_Saturacion_Luminosidad);
        menuTransformar->addAction(actionInvertir);
        menuTransformar->addAction(menuRotar->menuAction());
        menuTransformar->addAction(actionMedia_ponderada);
        menuTransformar->addAction(actionEcualizaci_n_del_histograma);
        menuTransformar->addAction(actionAjuste_lineal_del_histograma);
        menuTransformar->addAction(actionConvertir_a_color_falso);
        menuTransformar->addAction(actionTransformaci_n_de_malla);
        menuTransformar->addAction(actionConvertir_a_escala_de_color);
        menuRotar->addAction(actionRotar_90);
        menuRotar->addAction(actionRotar_180);
        menuRotar->addAction(actionRotar_91);
        menuEfectos->addAction(menuSuavizado->menuAction());
        menuEfectos->addAction(actionPerfilado);
        menuEfectos->addAction(actionPinchar_Estirar);
        menuEfectos->addAction(actionInPaint);
        menuEfectos->addAction(actionBalance_de_blancos);
        menuEfectos->addAction(actionBajorrelieve);
        menuSuavizado->addAction(actionGausiano);
        menuSuavizado->addAction(actionMedia);
        menuSuavizado->addAction(actionMediana);
        menuV_deo->addAction(menuImagen_a_v_deo->menuAction());
        menuV_deo->addAction(menuV_deo_a_imagen->menuAction());
        menuV_deo->addAction(menuV_deo_a_video->menuAction());
        menuImagen_a_v_deo->addAction(actionRotar_imagen);
        menuImagen_a_v_deo->addAction(actionTransicion_entre_imagenes);
        menuV_deo_a_imagen->addAction(actionImagen_media);
        menuV_deo_a_imagen->addAction(actionImagenes_m_nima_y_m_xima);
        menuV_deo_a_video->addAction(actionDetecci_n_de_fondo);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QFotoPaint", 0, QApplication::UnicodeUTF8));
        actionNueva_imagen->setText(QApplication::translate("MainWindow", "Nueva imagen...", 0, QApplication::UnicodeUTF8));
        actionAbrir_imagen->setText(QApplication::translate("MainWindow", "Abrir imagen...", 0, QApplication::UnicodeUTF8));
        actionGuardar->setText(QApplication::translate("MainWindow", "Guardar", 0, QApplication::UnicodeUTF8));
        actionGuardar_como->setText(QApplication::translate("MainWindow", "Guardar como...", 0, QApplication::UnicodeUTF8));
        actionCerrar->setText(QApplication::translate("MainWindow", "Cerrar", 0, QApplication::UnicodeUTF8));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
        actionPunto->setText(QApplication::translate("MainWindow", "Punto", 0, QApplication::UnicodeUTF8));
        actionLinea->setText(QApplication::translate("MainWindow", "L\303\255nea", 0, QApplication::UnicodeUTF8));
        actionSeleccionar->setText(QApplication::translate("MainWindow", "Seleccionar", 0, QApplication::UnicodeUTF8));
        actionSeleccionar_todo->setText(QApplication::translate("MainWindow", "Seleccionar todo", 0, QApplication::UnicodeUTF8));
        actionColor_del_pincel->setText(QApplication::translate("MainWindow", "Color del pincel...", 0, QApplication::UnicodeUTF8));
        actionPreguntar_si_guardar->setText(QApplication::translate("MainWindow", "Preguntar si guardar", 0, QApplication::UnicodeUTF8));
        actionBrillo_contraste->setText(QApplication::translate("MainWindow", "Brillo/Contraste/Gamma...", 0, QApplication::UnicodeUTF8));
        actionInvertir->setText(QApplication::translate("MainWindow", "Invertir", 0, QApplication::UnicodeUTF8));
        actionRotar_90->setText(QApplication::translate("MainWindow", "Rotar 90\302\272", 0, QApplication::UnicodeUTF8));
        actionRotar_91->setText(QApplication::translate("MainWindow", "Rotar 270\302\272", 0, QApplication::UnicodeUTF8));
        actionMedia_ponderada->setText(QApplication::translate("MainWindow", "Media ponderada...", 0, QApplication::UnicodeUTF8));
        actionRotar_180->setText(QApplication::translate("MainWindow", "Rotar 180\302\272", 0, QApplication::UnicodeUTF8));
        actionGausiano->setText(QApplication::translate("MainWindow", "Gausiano...", 0, QApplication::UnicodeUTF8));
        actionMedia->setText(QApplication::translate("MainWindow", "Media...", 0, QApplication::UnicodeUTF8));
        actionRotar_imagen->setText(QApplication::translate("MainWindow", "Rotar imagen...", 0, QApplication::UnicodeUTF8));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de...", 0, QApplication::UnicodeUTF8));
        actionImagen_media->setText(QApplication::translate("MainWindow", "Imagen media...", 0, QApplication::UnicodeUTF8));
        actionPinchar_Estirar->setText(QApplication::translate("MainWindow", "Pinchar/Estirar", 0, QApplication::UnicodeUTF8));
        actionCapturar_de_C_mara->setText(QApplication::translate("MainWindow", "Capturar de C\303\241mara...", 0, QApplication::UnicodeUTF8));
        actionCapturar_de_Video->setText(QApplication::translate("MainWindow", "Capturar de V\303\255deo...", 0, QApplication::UnicodeUTF8));
        actionCopiar_a_nueva->setText(QApplication::translate("MainWindow", "Copiar a nueva", 0, QApplication::UnicodeUTF8));
        actionVer_histograma->setText(QApplication::translate("MainWindow", "Ver histograma", 0, QApplication::UnicodeUTF8));
        actionVer_histograma_2D->setText(QApplication::translate("MainWindow", "Ver histograma 2D", 0, QApplication::UnicodeUTF8));
        actionRect_ngulo->setText(QApplication::translate("MainWindow", "Rect\303\241ngulo", 0, QApplication::UnicodeUTF8));
        actionElipse->setText(QApplication::translate("MainWindow", "Elipse", 0, QApplication::UnicodeUTF8));
        actionMatiz_Saturacion_Luminosidad->setText(QApplication::translate("MainWindow", "Matiz/Saturacion/Luminosidad", 0, QApplication::UnicodeUTF8));
        actionEcualizaci_n_del_histograma->setText(QApplication::translate("MainWindow", "Ecualizaci\303\263n del histograma", 0, QApplication::UnicodeUTF8));
        actionInPaint->setText(QApplication::translate("MainWindow", "InPaint", 0, QApplication::UnicodeUTF8));
        actionAjuste_lineal_del_histograma->setText(QApplication::translate("MainWindow", "Ajuste lineal del histograma", 0, QApplication::UnicodeUTF8));
        actionConvertir_a_color_falso->setText(QApplication::translate("MainWindow", "Convertir a color falso", 0, QApplication::UnicodeUTF8));
        actionBalance_de_blancos->setText(QApplication::translate("MainWindow", "Balance de blancos", 0, QApplication::UnicodeUTF8));
        actionPerfilado->setText(QApplication::translate("MainWindow", "Perfilado", 0, QApplication::UnicodeUTF8));
        actionTransicion_entre_imagenes->setText(QApplication::translate("MainWindow", "Transicion entre imagenes...", 0, QApplication::UnicodeUTF8));
        actionImagenes_m_nima_y_m_xima->setText(QApplication::translate("MainWindow", "Imagenes m\303\255nima y m\303\241xima...", 0, QApplication::UnicodeUTF8));
        actionDetecci_n_de_fondo->setText(QApplication::translate("MainWindow", "Detecci\303\263n de fondo...", 0, QApplication::UnicodeUTF8));
        actionTransformaci_n_de_malla->setText(QApplication::translate("MainWindow", "Transformaci\303\263n de malla", 0, QApplication::UnicodeUTF8));
        actionMediana->setText(QApplication::translate("MainWindow", "Mediana...", 0, QApplication::UnicodeUTF8));
        actionConvertir_a_escala_de_color->setText(QApplication::translate("MainWindow", "Convertir a escala de color", 0, QApplication::UnicodeUTF8));
        actionVer_informaci_n->setText(QApplication::translate("MainWindow", "Ver informaci\303\263n", 0, QApplication::UnicodeUTF8));
        actionBajorrelieve->setText(QApplication::translate("MainWindow", "Bajorrelieve", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Radio del pincel</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Suavizado del pincel</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
        pushButton->setText(QString());
        toolButton_Rectangulo->setText(QApplication::translate("MainWindow", "RECTA", 0, QApplication::UnicodeUTF8));
        toolButton_Elipse->setText(QApplication::translate("MainWindow", "ELIPSE", 0, QApplication::UnicodeUTF8));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0, QApplication::UnicodeUTF8));
        menuEdici_n->setTitle(QApplication::translate("MainWindow", "Edici\303\263n", 0, QApplication::UnicodeUTF8));
        menuOpciones->setTitle(QApplication::translate("MainWindow", "Opciones", 0, QApplication::UnicodeUTF8));
        menuHerramientas->setTitle(QApplication::translate("MainWindow", "Herramientas", 0, QApplication::UnicodeUTF8));
        menuTransformar->setTitle(QApplication::translate("MainWindow", "Transformar", 0, QApplication::UnicodeUTF8));
        menuRotar->setTitle(QApplication::translate("MainWindow", "Rotar", 0, QApplication::UnicodeUTF8));
        menuEfectos->setTitle(QApplication::translate("MainWindow", "Efectos", 0, QApplication::UnicodeUTF8));
        menuSuavizado->setTitle(QApplication::translate("MainWindow", "Suavizado", 0, QApplication::UnicodeUTF8));
        menuV_deo->setTitle(QApplication::translate("MainWindow", "V\303\255deo", 0, QApplication::UnicodeUTF8));
        menuImagen_a_v_deo->setTitle(QApplication::translate("MainWindow", "Imagen a v\303\255deo", 0, QApplication::UnicodeUTF8));
        menuV_deo_a_imagen->setTitle(QApplication::translate("MainWindow", "V\303\255deo a imagen", 0, QApplication::UnicodeUTF8));
        menuV_deo_a_video->setTitle(QApplication::translate("MainWindow", "V\303\255deo a video", 0, QApplication::UnicodeUTF8));
        menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
