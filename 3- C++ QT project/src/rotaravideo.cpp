#include "rotaravideo.h"
#include "ui_rotaravideo.h"
#include <QFileDialog>
#include "mainwindow.h"

#include "video.h"

rotaravideo::rotaravideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rotaravideo)
{
    ui->setupUi(this);
    nfoto= foto_activa();
}

rotaravideo::~rotaravideo()
{
    delete ui;
}

void rotaravideo::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void rotaravideo::on_buttonBox_accepted()
{
    QString nombre= QFileDialog::getSaveFileName(w, "Guardar vídeo", ".", FiltroVideo);
    if (!nombre.isEmpty()) {
        int modo= ui->radioButton->isChecked() ? 0 :
                  (ui->radioButton_2->isChecked() ? 1 : 2);
        int codigocc;
        QString cad= ui->comboBox->currentText();
        codigocc= CV_FOURCC(cad.toAscii().at(0), cad.toAscii().at(1),
                            cad.toAscii().at(2), cad.toAscii().at(3));
        rotar_video(nfoto, nombre.toAscii(), modo, ui->spinBox->value(),
                    codigocc, ui->doubleSpinBox->value());
    }
}
