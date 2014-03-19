/********************************************************************************
** Form generated from reading UI file 'transicionvideo.ui'
**
** Created: Tue 24. Aug 19:12:49 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSICIONVIDEO_H
#define UI_TRANSICIONVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_transicionvideo
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QLabel *label_3;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *transicionvideo)
    {
        if (transicionvideo->objectName().isEmpty())
            transicionvideo->setObjectName(QString::fromUtf8("transicionvideo"));
        transicionvideo->resize(379, 236);
        pushButton = new QPushButton(transicionvideo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 200, 75, 23));
        pushButton_2 = new QPushButton(transicionvideo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 200, 75, 23));
        label = new QLabel(transicionvideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 121, 16));
        lineEdit = new QLineEdit(transicionvideo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(20, 30, 291, 20));
        QFont font;
        font.setPointSize(7);
        lineEdit->setFont(font);
        pushButton_3 = new QPushButton(transicionvideo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(320, 30, 51, 23));
        label_2 = new QLabel(transicionvideo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 16));
        lineEdit_2 = new QLineEdit(transicionvideo);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(20, 90, 291, 20));
        lineEdit_2->setFont(font);
        pushButton_4 = new QPushButton(transicionvideo);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 90, 51, 23));
        comboBox = new QComboBox(transicionvideo);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 150, 71, 22));
        label_3 = new QLabel(transicionvideo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 130, 81, 16));
        spinBox = new QSpinBox(transicionvideo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 150, 91, 22));
        spinBox->setMinimum(4);
        spinBox->setMaximum(100);
        spinBox->setValue(25);
        doubleSpinBox = new QDoubleSpinBox(transicionvideo);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(140, 150, 101, 22));
        doubleSpinBox->setValue(25);
        label_4 = new QLabel(transicionvideo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 130, 101, 16));
        label_5 = new QLabel(transicionvideo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(140, 130, 101, 16));

        retranslateUi(transicionvideo);

        QMetaObject::connectSlotsByName(transicionvideo);
    } // setupUi

    void retranslateUi(QDialog *transicionvideo)
    {
        transicionvideo->setWindowTitle(QApplication::translate("transicionvideo", "Transicion", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("transicionvideo", "Aceptar", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("transicionvideo", "Cancelar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("transicionvideo", "Selecciona la foto Inicial:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        pushButton_3->setText(QApplication::translate("transicionvideo", "Cambiar", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("transicionvideo", "Selecciona la foto Final:", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("transicionvideo", "Cambiar", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("transicionvideo", "MJPG", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("transicionvideo", "PIM1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("transicionvideo", "DIVX", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("transicionvideo", "XVID", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("transicionvideo", "C\303\263dec de v\303\255deo:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("transicionvideo", "n\302\272 frames del v\303\255deo", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("transicionvideo", "Frames por segundo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class transicionvideo: public Ui_transicionvideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSICIONVIDEO_H
