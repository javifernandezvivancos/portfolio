#ifndef PERFILADO_H
#define PERFILADO_H

#include <QDialog>

namespace Ui {
    class perfilado;
}

class perfilado : public QDialog {
    Q_OBJECT
public:
    perfilado(QWidget *parent = 0);
    ~perfilado();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::perfilado *ui;    
    int nfoto;

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void perfilar(bool guardar);
};

#endif // PERFILADO_H
