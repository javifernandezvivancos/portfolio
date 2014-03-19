/********************************************************************************
** Form generated from reading UI file 'ecualizacionhistograma.ui'
**
** Created: Mon 30. Aug 23:52:01 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECUALIZACIONHISTOGRAMA_H
#define UI_ECUALIZACIONHISTOGRAMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ecualizacionhistograma
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *ecualizacionhistograma)
    {
        if (ecualizacionhistograma->objectName().isEmpty())
            ecualizacionhistograma->setObjectName(QString::fromUtf8("ecualizacionhistograma"));
        ecualizacionhistograma->resize(358, 95);
        pushButton = new QPushButton(ecualizacionhistograma);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 40, 111, 31));
        pushButton_2 = new QPushButton(ecualizacionhistograma);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 40, 111, 31));
        label = new QLabel(ecualizacionhistograma);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 111, 16));

        retranslateUi(ecualizacionhistograma);

        QMetaObject::connectSlotsByName(ecualizacionhistograma);
    } // setupUi

    void retranslateUi(QDialog *ecualizacionhistograma)
    {
        ecualizacionhistograma->setWindowTitle(QApplication::translate("ecualizacionhistograma", "Ecualizaci\303\263n del histograma", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ecualizacionhistograma", "Conjuntamente", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ecualizacionhistograma", "Por separado", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ecualizacionhistograma", "Ecualizar histograma...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ecualizacionhistograma: public Ui_ecualizacionhistograma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECUALIZACIONHISTOGRAMA_H
