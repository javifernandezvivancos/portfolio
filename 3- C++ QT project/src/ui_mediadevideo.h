/********************************************************************************
** Form generated from reading UI file 'mediadevideo.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIADEVIDEO_H
#define UI_MEDIADEVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_mediadevideo
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *mediadevideo)
    {
        if (mediadevideo->objectName().isEmpty())
            mediadevideo->setObjectName(QString::fromUtf8("mediadevideo"));
        mediadevideo->resize(257, 194);
        mediadevideo->setMinimumSize(QSize(257, 194));
        mediadevideo->setMaximumSize(QSize(257, 194));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        mediadevideo->setWindowIcon(icon);
        pushButton = new QPushButton(mediadevideo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 50, 111, 31));
        label = new QLabel(mediadevideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 22, 131, 16));
        spinBox = new QSpinBox(mediadevideo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(160, 20, 71, 22));
        spinBox->setMaximum(10000);
        pushButton_2 = new QPushButton(mediadevideo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(130, 50, 111, 31));
        groupBox = new QGroupBox(mediadevideo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 231, 61));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(10, 20, 101, 31));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(120, 20, 101, 31));
        pushButton_5 = new QPushButton(mediadevideo);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(90, 160, 75, 31));
        pushButton_5->setDefault(true);

        retranslateUi(mediadevideo);

        QMetaObject::connectSlotsByName(mediadevideo);
    } // setupUi

    void retranslateUi(QDialog *mediadevideo)
    {
        mediadevideo->setWindowTitle(QApplication::translate("mediadevideo", "V\303\255deo a imagen media...", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("mediadevideo", "Conectar c\303\241mara", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mediadevideo", "Indice de la c\303\241mara:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("mediadevideo", "Desconectar c\303\241mara", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("mediadevideo", "Media", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("mediadevideo", "Empezar", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("mediadevideo", "Obtener", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("mediadevideo", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mediadevideo: public Ui_mediadevideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIADEVIDEO_H
