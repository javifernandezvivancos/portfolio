/********************************************************************************
** Form generated from reading UI file 'pincharestirar.ui'
**
** Created: Thu 20. May 14:03:25 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINCHARESTIRAR_H
#define UI_PINCHARESTIRAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_pincharestirar
{
public:
    QDialogButtonBox *buttonBox;
    QSlider *horizontalSlider_radiodelefecto;
    QSlider *horizontalSlider_gradodelefecto;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *pincharestirar)
    {
        if (pincharestirar->objectName().isEmpty())
            pincharestirar->setObjectName(QString::fromUtf8("pincharestirar"));
        pincharestirar->resize(202, 173);
        buttonBox = new QDialogButtonBox(pincharestirar);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 130, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalSlider_radiodelefecto = new QSlider(pincharestirar);
        horizontalSlider_radiodelefecto->setObjectName(QString::fromUtf8("horizontalSlider_radiodelefecto"));
        horizontalSlider_radiodelefecto->setGeometry(QRect(20, 40, 160, 16));
        horizontalSlider_radiodelefecto->setMinimum(5);
        horizontalSlider_radiodelefecto->setMaximum(300);
        horizontalSlider_radiodelefecto->setValue(50);
        horizontalSlider_radiodelefecto->setOrientation(Qt::Horizontal);
        horizontalSlider_radiodelefecto->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_radiodelefecto->setTickInterval(10);
        horizontalSlider_gradodelefecto = new QSlider(pincharestirar);
        horizontalSlider_gradodelefecto->setObjectName(QString::fromUtf8("horizontalSlider_gradodelefecto"));
        horizontalSlider_gradodelefecto->setGeometry(QRect(20, 90, 160, 16));
        horizontalSlider_gradodelefecto->setMinimum(-100);
        horizontalSlider_gradodelefecto->setMaximum(100);
        horizontalSlider_gradodelefecto->setOrientation(Qt::Horizontal);
        horizontalSlider_gradodelefecto->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_gradodelefecto->setTickInterval(10);
        label = new QLabel(pincharestirar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 121, 16));
        label_2 = new QLabel(pincharestirar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 111, 16));

        retranslateUi(pincharestirar);
        QObject::connect(buttonBox, SIGNAL(accepted()), pincharestirar, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pincharestirar, SLOT(reject()));

        QMetaObject::connectSlotsByName(pincharestirar);
    } // setupUi

    void retranslateUi(QDialog *pincharestirar)
    {
        pincharestirar->setWindowTitle(QApplication::translate("pincharestirar", "Pinchar/Estirar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("pincharestirar", "Radio del efecto", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("pincharestirar", "Grado del efecto", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class pincharestirar: public Ui_pincharestirar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINCHARESTIRAR_H
