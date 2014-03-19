/********************************************************************************
** Form generated from reading UI file 'histograma2d.ui'
**
** Created: Thu 20. May 14:03:25 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMA2D_H
#define UI_HISTOGRAMA2D_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_histograma2D
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *histograma2D)
    {
        if (histograma2D->objectName().isEmpty())
            histograma2D->setObjectName(QString::fromUtf8("histograma2D"));
        histograma2D->resize(280, 47);
        pushButton = new QPushButton(histograma2D);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));
        pushButton_2 = new QPushButton(histograma2D);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 10, 75, 23));
        pushButton_3 = new QPushButton(histograma2D);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 10, 75, 23));

        retranslateUi(histograma2D);

        QMetaObject::connectSlotsByName(histograma2D);
    } // setupUi

    void retranslateUi(QDialog *histograma2D)
    {
        histograma2D->setWindowTitle(QApplication::translate("histograma2D", "Histograma 2D", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("histograma2D", "Rojo/Verde", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("histograma2D", "Rojo/Azul", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("histograma2D", "Verde/Azul", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class histograma2D: public Ui_histograma2D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMA2D_H
