#ifndef PINCHARESTIRAR_H
#define PINCHARESTIRAR_H

#include <QDialog>

namespace Ui {
    class pincharestirar;
}

class pincharestirar : public QDialog {
    Q_OBJECT
public:
    pincharestirar(QWidget *parent = 0);
    ~pincharestirar();
    void exec(void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::pincharestirar *ui;
    int nfoto;

private slots:
    void on_buttonBox_accepted();
    void on_horizontalSlider_gradodelefecto_valueChanged(int value);
    void on_horizontalSlider_radiodelefecto_valueChanged(int value);
};

#endif // PINCHARESTIRAR_H
