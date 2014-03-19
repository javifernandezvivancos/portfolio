/********************************************************************************
** Form generated from reading UI file 'mediaponderada.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPONDERADA_H
#define UI_MEDIAPONDERADA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_mediaponderada
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;

    void setupUi(QDialog *mediaponderada)
    {
        if (mediaponderada->objectName().isEmpty())
            mediaponderada->setObjectName(QString::fromUtf8("mediaponderada"));
        mediaponderada->resize(301, 225);
        mediaponderada->setMinimumSize(QSize(301, 225));
        mediaponderada->setMaximumSize(QSize(301, 225));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        mediaponderada->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(mediaponderada);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 190, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(mediaponderada);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 80, 281, 111));
        listWidget->setAlternatingRowColors(false);
        listWidget->setViewMode(QListView::ListMode);
        checkBox = new QCheckBox(mediaponderada);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(180, 200, 101, 17));
        checkBox->setChecked(true);
        label = new QLabel(mediaponderada);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 60, 91, 16));
        label_2 = new QLabel(mediaponderada);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 281, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(mediaponderada);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 281, 21));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);

        retranslateUi(mediaponderada);
        QObject::connect(buttonBox, SIGNAL(accepted()), mediaponderada, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), mediaponderada, SLOT(reject()));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(mediaponderada);
    } // setupUi

    void retranslateUi(QDialog *mediaponderada)
    {
        mediaponderada->setWindowTitle(QApplication::translate("mediaponderada", "Media ponderada...", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("mediaponderada", "Previsualizar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mediaponderada", "Segunda imagen", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mediaponderada", "Porcentaje", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mediaponderada: public Ui_mediaponderada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPONDERADA_H
