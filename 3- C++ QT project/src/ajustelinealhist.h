#ifndef AJUSTELINEALHIST_H
#define AJUSTELINEALHIST_H

#include <QDialog>

namespace Ui {
    class ajustelinealhist;
}

class ajustelinealhist : public QDialog {
    Q_OBJECT
public:
    ajustelinealhist(QWidget *parent = 0);

    ~ajustelinealhist();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ajustelinealhist *ui;    
    int nfoto;

private slots:
    void ajustarLinealmente(bool guardar);
    void on_pushButton_2_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void on_pushButton_clicked();
};

#endif // AJUSTELINEALHIST_H
