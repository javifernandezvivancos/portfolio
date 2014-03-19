#ifndef INFORMACION_H
#define INFORMACION_H

#include <QDialog>

namespace Ui {
    class Informacion;
}

class Informacion : public QDialog {
    Q_OBJECT
public:
    Informacion(QWidget *parent = 0);    
    ~Informacion();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Informacion *ui;

private slots:
    void ver_informacion(int nfoto);
};

#endif // INFORMACION_H
