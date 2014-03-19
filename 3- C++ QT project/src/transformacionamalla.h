#ifndef TRANSFORMACIONAMALLA_H
#define TRANSFORMACIONAMALLA_H

#include <QDialog>

#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
namespace Ui {
    class transformacionamalla;
}

class transformacionamalla : public QDialog {
    Q_OBJECT
public:
    transformacionamalla(QWidget *parent = 0);
    ~transformacionamalla();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::transformacionamalla *ui;
    int nfoto;

private slots:
    bool lineditCorrectos();
    void transformarRectangulo(IplImage *src, IplImage *dst, CvPoint2D32f psrc[4], CvPoint2D32f pdst[4]);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // TRANSFORMACIONAMALLA_H
