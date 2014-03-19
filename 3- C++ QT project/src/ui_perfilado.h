/********************************************************************************
** Form generated from reading UI file 'perfilado.ui'
**
** Created: Fri 20. Aug 22:38:05 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERFILADO_H
#define UI_PERFILADO_H

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

class Ui_perfilado
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;

    void setupUi(QDialog *perfilado)
    {
        if (perfilado->objectName().isEmpty())
            perfilado->setObjectName(QString::fromUtf8("perfilado"));
        perfilado->resize(201, 186);
        pushButton = new QPushButton(perfilado);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 150, 75, 23));
        pushButton_2 = new QPushButton(perfilado);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 150, 75, 23));
        horizontalSlider = new QSlider(perfilado);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 30, 160, 21));
        horizontalSlider->setMinimum(3);
        horizontalSlider->setMaximum(7);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(perfilado);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(20, 90, 160, 21));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(perfilado);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 46, 13));
        label_2 = new QLabel(perfilado);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 16));
        checkBox = new QCheckBox(perfilado);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(40, 120, 81, 17));
        checkBox->setChecked(true);

        retranslateUi(perfilado);

        QMetaObject::connectSlotsByName(perfilado);
    } // setupUi

    void retranslateUi(QDialog *perfilado)
    {
        perfilado->setWindowTitle(QApplication::translate("perfilado", "Perfilar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("perfilado", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("perfilado", "Cancelar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("perfilado", "Radio", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("perfilado", "Porcentaje de perfilado", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("perfilado", "Previsualizar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class perfilado: public Ui_perfilado {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERFILADO_H
