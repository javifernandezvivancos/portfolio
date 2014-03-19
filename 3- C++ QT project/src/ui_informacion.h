/********************************************************************************
** Form generated from reading UI file 'informacion.ui'
**
** Created: Thu 16. Sep 01:53:33 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMACION_H
#define UI_INFORMACION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Informacion
{
public:
    QLabel *label;

    void setupUi(QDialog *Informacion)
    {
        if (Informacion->objectName().isEmpty())
            Informacion->setObjectName(QString::fromUtf8("Informacion"));
        Informacion->resize(230, 170);
        label = new QLabel(Informacion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 201, 121));

        retranslateUi(Informacion);

        QMetaObject::connectSlotsByName(Informacion);
    } // setupUi

    void retranslateUi(QDialog *Informacion)
    {
        Informacion->setWindowTitle(QApplication::translate("Informacion", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Informacion", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Informacion: public Ui_Informacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMACION_H
