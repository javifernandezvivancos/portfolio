#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include <QDialog>
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
namespace Ui {
    class histograma;
}

class histograma : public QDialog {
    Q_OBJECT
public:
    histograma(QWidget *parent = 0);
    ~histograma();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::histograma *ui;

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void mostrarHistograma(char tipo);
};

#endif // HISTOGRAMA_H
