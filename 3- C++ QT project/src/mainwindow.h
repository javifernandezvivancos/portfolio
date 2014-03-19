#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

extern QString FiltroImagen;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setStatusBarText(QString cadena);
    int comprobar_primera_libre (void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionBajorrelieve_triggered();
    void on_actionVer_informaci_n_triggered();
    void on_actionConvertir_a_escala_de_color_triggered();
    void on_actionMediana_triggered();
    void on_actionTransformaci_n_de_malla_triggered();
    void on_actionDetecci_n_de_fondo_triggered();
    void on_actionImagenes_m_nima_y_m_xima_triggered();
    void on_actionTransicion_entre_imagenes_triggered();
    void on_actionPerfilado_triggered();
    void on_actionBalance_de_blancos_triggered();
    void on_actionConvertir_a_color_falso_triggered();
    void on_actionAjuste_lineal_del_histograma_triggered();
    void on_actionInPaint_triggered();
    void on_actionEcualizaci_n_del_histograma_triggered();
    void on_actionMatiz_Saturacion_Luminosidad_triggered();
    void on_actionElipse_triggered();
    void on_toolButton_Elipse_clicked();
    void on_actionRect_ngulo_triggered();
    void on_toolButton_Rectangulo_clicked();
    void on_actionVer_histograma_2D_triggered();
    void on_actionVer_histograma_triggered();
    void on_actionCopiar_a_nueva_triggered();
    void on_actionCapturar_de_Video_triggered();
    void on_actionCapturar_de_C_mara_triggered();
    void on_actionPinchar_Estirar_triggered();
    void on_actionImagen_media_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionRotar_imagen_triggered();
    void on_actionMedia_ponderada_triggered();
    void on_actionMedia_triggered();
    void on_actionGausiano_triggered();
    void on_actionBrillo_contraste_triggered();
    void on_actionRotar_91_triggered();
    void on_actionRotar_180_triggered();
    void on_actionRotar_90_triggered();
    void on_actionInvertir_triggered();
    void on_toolButton_6_clicked();
    void on_toolButton_5_clicked();
    void on_toolButton_4_clicked();
    void on_actionSeleccionar_todo_triggered();
    void on_actionColor_del_pincel_triggered();
    void on_actionPreguntar_si_guardar_triggered();
    void on_actionCerrar_triggered();
    void on_actionGuardar_como_triggered();
    void on_actionGuardar_triggered();
    void on_toolButton_clicked();
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_clicked();
    void on_toolButton_2_clicked();
    void on_actionSeleccionar_triggered();
    void on_actionLinea_triggered();
    void on_actionPunto_triggered();
    void on_actionAbrir_imagen_triggered();
    void on_actionNueva_imagen_triggered();
    void on_actionSalir_triggered();
};

extern MainWindow *w;
extern QApplication *a;

#endif // MAINWINDOW_H
