#ifndef CAPTURARDECAMARA_H
#define CAPTURARDECAMARA_H

#include <QDialog>

namespace Ui {
    class capturardecamara;
}

class capturardecamara : public QDialog {
    Q_OBJECT
public:
    capturardecamara(QWidget *parent = 0);
    ~capturardecamara();
    void exec(void);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::capturardecamara *ui;

private slots:
    void on_buttonBox_previsualizarcamara_accepted();
};

#endif // CAPTURARDECAMARA_H
