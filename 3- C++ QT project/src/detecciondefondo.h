#ifndef DETECCIONDEFONDO_H
#define DETECCIONDEFONDO_H

#include <QDialog>
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

namespace Ui {
    class detecciondefondo;
}

class detecciondefondo : public QDialog {
    Q_OBJECT
public:
    detecciondefondo(QWidget *parent = 0);
    ~detecciondefondo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::detecciondefondo *ui;

private slots:
    int compararPixeles(CvScalar pixel1, CvScalar pixel2);
    CvScalar obtenerPixelCorrecto(CvScalar pixelMinimo, CvScalar pixelMaximo, CvScalar pixelEntrada, CvScalar pixelActivo);
    void obtenerFrameResultado(IplImage *frameResultado, IplImage *frameEntrada, IplImage *imgMinima, IplImage *imgMaxima, IplImage *imgActiva);
    void detectarFondo(QString nombreVideoSalida, QString nombreVideoEntrada, QString nombreImgMinima, QString nombreImgMaxima, QString nombreImgActiva);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
};

#endif // DETECCIONDEFONDO_H
