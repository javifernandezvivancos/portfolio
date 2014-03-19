#ifndef BAJORRELIEVE_H
#define BAJORRELIEVE_H

#include <QDialog>

namespace Ui {
    class bajorrelieve;
}

class bajorrelieve : public QDialog {
    Q_OBJECT
public:
    bajorrelieve(QWidget *parent = 0);
    ~bajorrelieve();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::bajorrelieve *ui;

private slots:
    void mostrarBR(bool guardar);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
};

#endif // BAJORRELIEVE_H
