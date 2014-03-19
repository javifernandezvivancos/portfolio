/********************************************************************************
** Form generated from reading UI file 'matizsaturacionluminosidad.ui'
**
** Created: Tue 1. Jun 21:18:30 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATIZSATURACIONLUMINOSIDAD_H
#define UI_MATIZSATURACIONLUMINOSIDAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_matizsaturacionluminosidad
{
public:
    QSlider *horizontalSlider_3;
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox_3;
    QSlider *horizontalSlider;
    QSpinBox *spinBox_2;
    QLabel *label_2;
    QCheckBox *checkBox;
    QSpinBox *spinBox;
    QLabel *label;
    QSlider *horizontalSlider_2;
    QLabel *label_3;

    void setupUi(QDialog *matizsaturacionluminosidad)
    {
        if (matizsaturacionluminosidad->objectName().isEmpty())
            matizsaturacionluminosidad->setObjectName(QString::fromUtf8("matizsaturacionluminosidad"));
        matizsaturacionluminosidad->resize(355, 196);
        horizontalSlider_3 = new QSlider(matizsaturacionluminosidad);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(10, 130, 271, 21));
        horizontalSlider_3->setMinimum(0);
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setSingleStep(1);
        horizontalSlider_3->setValue(10);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_3->setTickInterval(10);
        buttonBox = new QDialogButtonBox(matizsaturacionluminosidad);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 162, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox_3 = new QSpinBox(matizsaturacionluminosidad);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(290, 110, 61, 22));
        spinBox_3->setMinimum(-100);
        spinBox_3->setMaximum(100);
        horizontalSlider = new QSlider(matizsaturacionluminosidad);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(-128);
        horizontalSlider->setMaximum(128);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        spinBox_2 = new QSpinBox(matizsaturacionluminosidad);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(290, 60, 61, 22));
        spinBox_2->setMinimum(-100);
        spinBox_2->setMaximum(100);
        label_2 = new QLabel(matizsaturacionluminosidad);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        checkBox = new QCheckBox(matizsaturacionluminosidad);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(190, 170, 101, 17));
        checkBox->setChecked(true);
        spinBox = new QSpinBox(matizsaturacionluminosidad);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 10, 61, 22));
        spinBox->setMinimum(-200);
        spinBox->setMaximum(200);
        label = new QLabel(matizsaturacionluminosidad);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider_2 = new QSlider(matizsaturacionluminosidad);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 80, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        label_3 = new QLabel(matizsaturacionluminosidad);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(matizsaturacionluminosidad);

        QMetaObject::connectSlotsByName(matizsaturacionluminosidad);
    } // setupUi

    void retranslateUi(QDialog *matizsaturacionluminosidad)
    {
        matizsaturacionluminosidad->setWindowTitle(QApplication::translate("matizsaturacionluminosidad", "Ajustar matiz/saturaci\303\263n/luminosidad", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("matizsaturacionluminosidad", "Saturaci\303\263n", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("matizsaturacionluminosidad", "Previsualizar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("matizsaturacionluminosidad", "Matiz", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("matizsaturacionluminosidad", "Luminosidad", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class matizsaturacionluminosidad: public Ui_matizsaturacionluminosidad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATIZSATURACIONLUMINOSIDAD_H
