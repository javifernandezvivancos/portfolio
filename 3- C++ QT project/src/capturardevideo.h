#ifndef CAPTURARDEVIDEO_H
#define CAPTURARDEVIDEO_H

#include <QDialog>

namespace Ui {
    class capturardevideo;
}

class capturardevideo : public QDialog {
    Q_OBJECT
public:
    capturardevideo(QWidget *parent = 0);
    ~capturardevideo();
    void exec(void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::capturardevideo *ui;

private slots:
    void on_buttonBox_accepted();
    void on_spinBox_valueChanged(int );
};

#endif // CAPTURARDEVIDEO_H
