/********************************************************************************
** Form generated from reading UI file 'capturardevideo.ui'
**
** Created: Thu 16. Sep 11:53:52 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURARDEVIDEO_H
#define UI_CAPTURARDEVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_capturardevideo
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QDialog *capturardevideo)
    {
        if (capturardevideo->objectName().isEmpty())
            capturardevideo->setObjectName(QString::fromUtf8("capturardevideo"));
        capturardevideo->resize(221, 93);
        buttonBox = new QDialogButtonBox(capturardevideo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 50, 161, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(capturardevideo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(120, 10, 81, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(100000);
        label = new QLabel(capturardevideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 91, 21));

        retranslateUi(capturardevideo);
        QObject::connect(buttonBox, SIGNAL(accepted()), capturardevideo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), capturardevideo, SLOT(reject()));

        QMetaObject::connectSlotsByName(capturardevideo);
    } // setupUi

    void retranslateUi(QDialog *capturardevideo)
    {
        capturardevideo->setWindowTitle(QApplication::translate("capturardevideo", "Capturar desde v\303\255deo...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("capturardevideo", "N\303\272mero de frame:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class capturardevideo: public Ui_capturardevideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURARDEVIDEO_H
