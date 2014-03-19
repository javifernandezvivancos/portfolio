#ifndef MATIZSATURACIONLUMINOSIDAD_H
#define MATIZSATURACIONLUMINOSIDAD_H

#include <QDialog>

namespace Ui {
    class matizsaturacionluminosidad;
}

class matizsaturacionluminosidad : public QDialog {
    Q_OBJECT
public:
    matizsaturacionluminosidad(QWidget *parent = 0);
    ~matizsaturacionluminosidad();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::matizsaturacionluminosidad *ui;
    int nfoto;
    double saturacion;
    double luminosidad;
    int matiz;
    void actualiza_matiz_sat_lumin();

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_3_valueChanged(int value);
    void on_spinBox_3_valueChanged(int );
    void on_spinBox_2_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // MATIZSATURACIONLUMINOSIDAD_H
