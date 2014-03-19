/********************************************************************************
** Form generated from reading UI file 'inpaint.ui'
**
** Created: Fri 20. Aug 22:38:05 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPAINT_H
#define UI_INPAINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_inpaint
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *inpaint)
    {
        if (inpaint->objectName().isEmpty())
            inpaint->setObjectName(QString::fromUtf8("inpaint"));
        inpaint->resize(148, 232);
        buttonBox = new QDialogButtonBox(inpaint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 10, 111, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(inpaint);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 46, 13));
        horizontalSlider = new QSlider(inpaint);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 100, 121, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(5);
        horizontalSlider->setOrientation(Qt::Horizontal);
        checkBox = new QCheckBox(inpaint);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 140, 81, 17));
        checkBox_2 = new QCheckBox(inpaint);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(20, 160, 81, 17));
        checkBox_2->setChecked(true);
        pushButton = new QPushButton(inpaint);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 190, 91, 31));

        retranslateUi(inpaint);

        QMetaObject::connectSlotsByName(inpaint);
    } // setupUi

    void retranslateUi(QDialog *inpaint)
    {
        inpaint->setWindowTitle(QApplication::translate("inpaint", "InPaint", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("inpaint", "Radio", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("inpaint", "Crear nueva", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("inpaint", "Pintar/Borrar", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("inpaint", "Previsualizar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class inpaint: public Ui_inpaint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPAINT_H
