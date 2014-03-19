/********************************************************************************
** Form generated from reading UI file 'minimamaximadevideo.ui'
**
** Created: Sat 28. Aug 01:03:46 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIMAMAXIMADEVIDEO_H
#define UI_MINIMAMAXIMADEVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_minimamaximadevideo
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_2;

    void setupUi(QDialog *minimamaximadevideo)
    {
        if (minimamaximadevideo->objectName().isEmpty())
            minimamaximadevideo->setObjectName(QString::fromUtf8("minimamaximadevideo"));
        minimamaximadevideo->resize(485, 121);
        label = new QLabel(minimamaximadevideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 251, 16));
        pushButton = new QPushButton(minimamaximadevideo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 30, 51, 23));
        lineEdit = new QLineEdit(minimamaximadevideo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(20, 30, 401, 20));
        pushButton_2 = new QPushButton(minimamaximadevideo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 80, 101, 31));
        pushButton_3 = new QPushButton(minimamaximadevideo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 80, 101, 31));
        label_2 = new QLabel(minimamaximadevideo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 441, 20));

        retranslateUi(minimamaximadevideo);

        QMetaObject::connectSlotsByName(minimamaximadevideo);
    } // setupUi

    void retranslateUi(QDialog *minimamaximadevideo)
    {
        minimamaximadevideo->setWindowTitle(QApplication::translate("minimamaximadevideo", "Obtener imagen m\303\255nima y m\303\241xima de un v\303\255deo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("minimamaximadevideo", "Selecciona el v\303\255deo para crear el modelo de fondo:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("minimamaximadevideo", "cambiar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("minimamaximadevideo", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("minimamaximadevideo", "Cancelar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("minimamaximadevideo", "ATENCION: Se aconseja un v\303\255deo corto, de 2 a 4 segundos aproximadamente.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class minimamaximadevideo: public Ui_minimamaximadevideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIMAMAXIMADEVIDEO_H
