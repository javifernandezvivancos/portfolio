#ifndef INPAINT_H
#define INPAINT_H

#include <QDialog>

namespace Ui {
    class inpaint;
}

class inpaint : public QDialog {
    Q_OBJECT
public:
    inpaint(QWidget *parent = 0);
    ~inpaint();
    int exec();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::inpaint *ui;
    int nfoto;

private slots:
    void on_checkBox_2_clicked(bool checked);
    void on_inpaint_destroyed();
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // INPAINT_H
