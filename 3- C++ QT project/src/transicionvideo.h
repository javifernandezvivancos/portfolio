#ifndef TRANSICIONVIDEO_H
#define TRANSICIONVIDEO_H

#include <QDialog>

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>

namespace Ui {
    class transicionvideo;
}

class transicionvideo : public QDialog {
    Q_OBJECT
public:
    transicionvideo(QWidget *parent = 0);
    ~transicionvideo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::transicionvideo *ui;

private slots:
    void crearTransicion(IplImage *imgOrigen, IplImage *imgDestino, QString nombreVideo, int codec, int nFrames, double fps);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
};

#endif // TRANSICIONVIDEO_H
