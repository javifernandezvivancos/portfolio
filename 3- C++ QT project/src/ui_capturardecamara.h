/********************************************************************************
** Form generated from reading UI file 'capturardecamara.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURARDECAMARA_H
#define UI_CAPTURARDECAMARA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_capturardecamara
{
public:
    QDialogButtonBox *buttonBox_previsualizarcamara;
    QCheckBox *checkBox_previsualizarcamara;
    QLabel *label;

    void setupUi(QDialog *capturardecamara)
    {
        if (capturardecamara->objectName().isEmpty())
            capturardecamara->setObjectName(QString::fromUtf8("capturardecamara"));
        capturardecamara->resize(200, 122);
        buttonBox_previsualizarcamara = new QDialogButtonBox(capturardecamara);
        buttonBox_previsualizarcamara->setObjectName(QString::fromUtf8("buttonBox_previsualizarcamara"));
        buttonBox_previsualizarcamara->setGeometry(QRect(20, 70, 161, 32));
        buttonBox_previsualizarcamara->setOrientation(Qt::Horizontal);
        buttonBox_previsualizarcamara->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox_previsualizarcamara = new QCheckBox(capturardecamara);
        checkBox_previsualizarcamara->setObjectName(QString::fromUtf8("checkBox_previsualizarcamara"));
        checkBox_previsualizarcamara->setGeometry(QRect(40, 20, 121, 18));
        checkBox_previsualizarcamara->setChecked(true);
        label = new QLabel(capturardecamara);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 141, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(capturardecamara);
        QObject::connect(buttonBox_previsualizarcamara, SIGNAL(accepted()), capturardecamara, SLOT(accept()));
        QObject::connect(buttonBox_previsualizarcamara, SIGNAL(rejected()), capturardecamara, SLOT(reject()));

        QMetaObject::connectSlotsByName(capturardecamara);
    } // setupUi

    void retranslateUi(QDialog *capturardecamara)
    {
        capturardecamara->setWindowTitle(QApplication::translate("capturardecamara", "Capturar desde C\303\241mara...", 0, QApplication::UnicodeUTF8));
        checkBox_previsualizarcamara->setText(QApplication::translate("capturardecamara", "Previsualizar C\303\241mara", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("capturardecamara", "Para capturar pulsa 'F'", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class capturardecamara: public Ui_capturardecamara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURARDECAMARA_H
