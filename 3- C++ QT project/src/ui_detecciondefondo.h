/********************************************************************************
** Form generated from reading UI file 'detecciondefondo.ui'
**
** Created: Tue 31. Aug 17:25:50 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECCIONDEFONDO_H
#define UI_DETECCIONDEFONDO_H

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

class Ui_detecciondefondo
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_6;
    QLabel *label_5;

    void setupUi(QDialog *detecciondefondo)
    {
        if (detecciondefondo->objectName().isEmpty())
            detecciondefondo->setObjectName(QString::fromUtf8("detecciondefondo"));
        detecciondefondo->resize(499, 301);
        pushButton = new QPushButton(detecciondefondo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 260, 101, 31));
        pushButton_2 = new QPushButton(detecciondefondo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 260, 101, 31));
        label = new QLabel(detecciondefondo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 16));
        label_2 = new QLabel(detecciondefondo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 141, 16));
        lineEdit = new QLineEdit(detecciondefondo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(20, 30, 411, 20));
        lineEdit_2 = new QLineEdit(detecciondefondo);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(20, 90, 411, 20));
        label_3 = new QLabel(detecciondefondo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 130, 151, 16));
        lineEdit_3 = new QLineEdit(detecciondefondo);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        lineEdit_3->setGeometry(QRect(20, 150, 411, 20));
        pushButton_3 = new QPushButton(detecciondefondo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 30, 51, 23));
        pushButton_4 = new QPushButton(detecciondefondo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(440, 90, 51, 23));
        pushButton_5 = new QPushButton(detecciondefondo);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(440, 150, 51, 23));
        label_4 = new QLabel(detecciondefondo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 190, 151, 16));
        lineEdit_4 = new QLineEdit(detecciondefondo);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setGeometry(QRect(20, 210, 411, 20));
        pushButton_6 = new QPushButton(detecciondefondo);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(440, 210, 51, 23));
        label_5 = new QLabel(detecciondefondo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 240, 461, 16));

        retranslateUi(detecciondefondo);

        QMetaObject::connectSlotsByName(detecciondefondo);
    } // setupUi

    void retranslateUi(QDialog *detecciondefondo)
    {
        detecciondefondo->setWindowTitle(QApplication::translate("detecciondefondo", "Detectar fondo de un v\303\255deo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("detecciondefondo", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("detecciondefondo", "Cancelar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("detecciondefondo", "Selecciona la imagen m\303\255nima", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("detecciondefondo", "Selecciona la imagen m\303\241xima", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("detecciondefondo", "Selecciona la imagen activa", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("detecciondefondo", "Cambiar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("detecciondefondo", "Cambiar", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("detecciondefondo", "Cambiar", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("detecciondefondo", "Selecciona el v\303\255deo a modificar", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("detecciondefondo", "Cambiar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("detecciondefondo", "ADVERTENCIA: este proceso es muy lento, visualice el v\303\255deo cuando esta ventana desaparezca", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class detecciondefondo: public Ui_detecciondefondo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECCIONDEFONDO_H
