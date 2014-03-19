#ifndef ECUALIZACIONHISTOGRAMA_H
#define ECUALIZACIONHISTOGRAMA_H

#include <QDialog>
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
namespace Ui {
    class ecualizacionhistograma;
}

class ecualizacionhistograma : public QDialog {
    Q_OBJECT
public:
    ecualizacionhistograma(QWidget *parent = 0);
    ~ecualizacionhistograma();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ecualizacionhistograma *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void calcularFuncionEcualizacion(IplImage *canal, CvMat *dest);
    void ecualizarHistograma(int tipo, int pl);
};

#endif // ECUALIZACIONHISTOGRAMA_H
