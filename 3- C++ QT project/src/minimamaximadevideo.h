#ifndef MINIMAMAXIMADEVIDEO_H
#define MINIMAMAXIMADEVIDEO_H

#include <QDialog>

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

namespace Ui {
    class minimamaximadevideo;
}

class minimamaximadevideo : public QDialog {
    Q_OBJECT
public:
    minimamaximadevideo(QWidget *parent = 0);
    ~minimamaximadevideo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::minimamaximadevideo *ui;

private slots:
    void on_pushButton_3_clicked();
    CvScalar pixelMenor(CvScalar pixel1, CvScalar pixel2);
    CvScalar pixelMayor(CvScalar pixel1, CvScalar pixel2);
    void obtenerImagenesMinMax(QString nombreVideo);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // MINIMAMAXIMADEVIDEO_H
