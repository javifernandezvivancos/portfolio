/********************************************************************************
** Form generated from reading UI file 'dialognueva.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNUEVA_H
#define UI_DIALOGNUEVA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogNueva
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogNueva)
    {
        if (DialogNueva->objectName().isEmpty())
            DialogNueva->setObjectName(QString::fromUtf8("DialogNueva"));
        DialogNueva->setWindowModality(Qt::NonModal);
        DialogNueva->resize(302, 188);
        DialogNueva->setMinimumSize(QSize(302, 188));
        DialogNueva->setMaximumSize(QSize(302, 188));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        DialogNueva->setWindowIcon(icon);
        DialogNueva->setModal(false);
        buttonBox = new QDialogButtonBox(DialogNueva);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 150, 261, 32));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(DialogNueva);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 261, 81));
        groupBox->setFlat(false);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 46, 13));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 46, 13));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(80, 20, 101, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000);
        spinBox->setValue(640);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(80, 50, 101, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(10000);
        spinBox_2->setValue(480);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 20, 46, 13));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 50, 46, 13));
        label_5 = new QLabel(DialogNueva);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 120, 91, 16));
        pushButton = new QPushButton(DialogNueva);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 110, 71, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton->setDefault(false);
        pushButton->setFlat(false);

        retranslateUi(DialogNueva);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNueva, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNueva, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogNueva);
    } // setupUi

    void retranslateUi(QDialog *DialogNueva)
    {
        DialogNueva->setWindowTitle(QApplication::translate("DialogNueva", "Nueva imagen...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DialogNueva", "Tama\303\261o de la imagen", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNueva", "Anchura:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DialogNueva", "Altura:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DialogNueva", "p\303\255xeles", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DialogNueva", "p\303\255xeles", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DialogNueva", "Color del fondo:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogNueva: public Ui_DialogNueva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNUEVA_H
