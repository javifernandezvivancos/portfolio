/********************************************************************************
** Form generated from reading UI file 'suavizados.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUAVIZADOS_H
#define UI_SUAVIZADOS_H

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

class Ui_suavizados
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_2;

    void setupUi(QDialog *suavizados)
    {
        if (suavizados->objectName().isEmpty())
            suavizados->setObjectName(QString::fromUtf8("suavizados"));
        suavizados->resize(358, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(suavizados->sizePolicy().hasHeightForWidth());
        suavizados->setSizePolicy(sizePolicy);
        suavizados->setMinimumSize(QSize(358, 150));
        suavizados->setMaximumSize(QSize(358, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        suavizados->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(suavizados);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 110, 161, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox = new QCheckBox(suavizados);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(190, 118, 101, 17));
        checkBox->setChecked(true);
        horizontalSlider_2 = new QSlider(suavizados);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(10, 80, 271, 21));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(20);
        label = new QLabel(suavizados);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        spinBox_2 = new QSpinBox(suavizados);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(290, 60, 61, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(400);
        spinBox = new QSpinBox(suavizados);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(290, 10, 61, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(400);
        horizontalSlider = new QSlider(suavizados);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(20);
        label_2 = new QLabel(suavizados);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(suavizados);
        QObject::connect(buttonBox, SIGNAL(accepted()), suavizados, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), suavizados, SLOT(reject()));

        QMetaObject::connectSlotsByName(suavizados);
    } // setupUi

    void retranslateUi(QDialog *suavizados)
    {
        suavizados->setWindowTitle(QApplication::translate("suavizados", "Suavizado...", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("suavizados", "Previsualizar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("suavizados", "Suavizado en X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("suavizados", "Suavizado en Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class suavizados: public Ui_suavizados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUAVIZADOS_H
