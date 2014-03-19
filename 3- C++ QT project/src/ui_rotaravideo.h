/********************************************************************************
** Form generated from reading UI file 'rotaravideo.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROTARAVIDEO_H
#define UI_ROTARAVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_rotaravideo
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *spinBox;
    QGroupBox *groupBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QDialog *rotaravideo)
    {
        if (rotaravideo->objectName().isEmpty())
            rotaravideo->setObjectName(QString::fromUtf8("rotaravideo"));
        rotaravideo->resize(316, 182);
        rotaravideo->setMinimumSize(QSize(316, 182));
        rotaravideo->setMaximumSize(QSize(316, 182));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        rotaravideo->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(rotaravideo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 10, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(rotaravideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 181, 16));
        spinBox = new QSpinBox(rotaravideo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 30, 161, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000);
        spinBox->setValue(30);
        groupBox = new QGroupBox(rotaravideo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 191, 101));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 20, 181, 17));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 50, 141, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 80, 141, 17));
        comboBox = new QComboBox(rotaravideo);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(210, 90, 91, 21));
        comboBox->setEditable(true);
        label_2 = new QLabel(rotaravideo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 70, 101, 16));
        label_3 = new QLabel(rotaravideo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 120, 101, 16));
        doubleSpinBox = new QDoubleSpinBox(rotaravideo);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(210, 140, 91, 22));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMaximum(200);
        doubleSpinBox->setValue(30);

        retranslateUi(rotaravideo);
        QObject::connect(buttonBox, SIGNAL(accepted()), rotaravideo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), rotaravideo, SLOT(reject()));

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(rotaravideo);
    } // setupUi

    void retranslateUi(QDialog *rotaravideo)
    {
        rotaravideo->setWindowTitle(QApplication::translate("rotaravideo", "Rotar imagen a v\303\255deo...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("rotaravideo", "N\303\272mero de frames del v\303\255deo:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("rotaravideo", "Tama\303\261o del video", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("rotaravideo", "Igual que imagen original", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("rotaravideo", "M\303\241ximo, caber todo", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("rotaravideo", "M\303\255nimo, sin bordes", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("rotaravideo", "MJPG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("rotaravideo", "PIM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("rotaravideo", "DIVX", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("rotaravideo", "XVID", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("rotaravideo", "C\303\263dec de v\303\255deo", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("rotaravideo", "Frames por seg.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class rotaravideo: public Ui_rotaravideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROTARAVIDEO_H
