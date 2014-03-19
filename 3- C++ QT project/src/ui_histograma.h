/********************************************************************************
** Form generated from reading UI file 'histograma.ui'
**
** Created: Thu 20. May 14:03:25 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMA_H
#define UI_HISTOGRAMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_histograma
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *histograma)
    {
        if (histograma->objectName().isEmpty())
            histograma->setObjectName(QString::fromUtf8("histograma"));
        histograma->resize(303, 97);
        pushButton = new QPushButton(histograma);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 75, 23));
        pushButton_2 = new QPushButton(histograma);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 20, 75, 23));
        pushButton_3 = new QPushButton(histograma);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 20, 75, 23));
        pushButton_4 = new QPushButton(histograma);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 60, 75, 23));

        retranslateUi(histograma);

        QMetaObject::connectSlotsByName(histograma);
    } // setupUi

    void retranslateUi(QDialog *histograma)
    {
        histograma->setWindowTitle(QApplication::translate("histograma", "Histograma", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("histograma", "Rojo", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("histograma", "Verde", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("histograma", "Azul", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("histograma", "Gris", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class histograma: public Ui_histograma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMA_H
