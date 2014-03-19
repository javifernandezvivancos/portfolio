/********************************************************************************
** Form generated from reading UI file 'bajorrelieve.ui'
**
** Created: Thu 16. Sep 03:52:50 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAJORRELIEVE_H
#define UI_BAJORRELIEVE_H

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

class Ui_bajorrelieve
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *bajorrelieve)
    {
        if (bajorrelieve->objectName().isEmpty())
            bajorrelieve->setObjectName(QString::fromUtf8("bajorrelieve"));
        bajorrelieve->resize(257, 192);
        pushButton = new QPushButton(bajorrelieve);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(26, 150, 81, 31));
        pushButton_2 = new QPushButton(bajorrelieve);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 150, 81, 31));
        checkBox = new QCheckBox(bajorrelieve);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);
        checkBox->setGeometry(QRect(110, 110, 101, 17));
        checkBox->setChecked(true);
        horizontalSlider = new QSlider(bajorrelieve);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 30, 191, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(4);
        horizontalSlider->setValue(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(bajorrelieve);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(30, 80, 191, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(4);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(bajorrelieve);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 46, 13));
        label_2 = new QLabel(bajorrelieve);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 16));

        retranslateUi(bajorrelieve);

        QMetaObject::connectSlotsByName(bajorrelieve);
    } // setupUi

    void retranslateUi(QDialog *bajorrelieve)
    {
        bajorrelieve->setWindowTitle(QApplication::translate("bajorrelieve", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("bajorrelieve", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("bajorrelieve", "Cancelar", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("bajorrelieve", "Previsualizar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("bajorrelieve", "Cantidad", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("bajorrelieve", "Direcci\303\263n", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class bajorrelieve: public Ui_bajorrelieve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAJORRELIEVE_H
