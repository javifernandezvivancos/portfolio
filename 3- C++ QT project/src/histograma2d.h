#ifndef HISTOGRAMA2D_H
#define HISTOGRAMA2D_H

#include <QDialog>

namespace Ui {
    class histograma2D;
}

class histograma2D : public QDialog {
    Q_OBJECT
public:
    histograma2D(QWidget *parent = 0);
    ~histograma2D();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::histograma2D *ui;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void mostrarHistograma(char tipo[]);
    void on_pushButton_clicked();
};

#endif // HISTOGRAMA2D_H
