/********************************************************************************
** Form generated from reading UI file 'ajustelinealhist.ui'
**
** Created: Fri 20. Aug 22:38:05 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJUSTELINEALHIST_H
#define UI_AJUSTELINEALHIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_ajustelinealhist
{
public:
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *ajustelinealhist)
    {
        if (ajustelinealhist->objectName().isEmpty())
            ajustelinealhist->setObjectName(QString::fromUtf8("ajustelinealhist"));
        ajustelinealhist->resize(194, 180);
        horizontalSlider = new QSlider(ajustelinealhist);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 80, 160, 21));
        horizontalSlider->setMaximum(50);
        horizontalSlider->setValue(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(ajustelinealhist);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(20, 30, 160, 21));
        horizontalSlider_2->setMaximum(50);
        horizontalSlider_2->setValue(5);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(ajustelinealhist);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 81, 16));
        label_2 = new QLabel(ajustelinealhist);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 81, 16));
        pushButton = new QPushButton(ajustelinealhist);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 140, 75, 23));
        pushButton_2 = new QPushButton(ajustelinealhist);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 140, 75, 23));
        checkBox = new QCheckBox(ajustelinealhist);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 110, 81, 17));
        checkBox->setChecked(true);

        retranslateUi(ajustelinealhist);

        QMetaObject::connectSlotsByName(ajustelinealhist);
    } // setupUi

    void retranslateUi(QDialog *ajustelinealhist)
    {
        ajustelinealhist->setWindowTitle(QApplication::translate("ajustelinealhist", "Ajustar linealmente el histograma", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ajustelinealhist", "% a la derecha", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ajustelinealhist", "% a la izquierda", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ajustelinealhist", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ajustelinealhist", "Cancelar", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ajustelinealhist", "Previsualizar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ajustelinealhist: public Ui_ajustelinealhist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJUSTELINEALHIST_H
