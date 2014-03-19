/********************************************************************************
** Form generated from reading UI file 'acercade.ui'
**
** Created: Thu 20. May 12:28:57 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCADE_H
#define UI_ACERCADE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_acercade
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton;
    QFrame *frame;

    void setupUi(QDialog *acercade)
    {
        if (acercade->objectName().isEmpty())
            acercade->setObjectName(QString::fromUtf8("acercade"));
        acercade->resize(350, 179);
        acercade->setMinimumSize(QSize(350, 179));
        acercade->setMaximumSize(QSize(350, 179));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/imagenes/logo.gif"), QSize(), QIcon::Normal, QIcon::Off);
        acercade->setWindowIcon(icon);
        label = new QLabel(acercade);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 10, 221, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(acercade);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 50, 171, 21));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(acercade);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 120, 331, 16));
        label_4 = new QLabel(acercade);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 140, 141, 16));
        commandLinkButton = new QCommandLinkButton(acercade);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 140, 91, 31));
        commandLinkButton->setAutoDefault(true);
        commandLinkButton->setDefault(false);
        frame = new QFrame(acercade);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 101, 101));
        frame->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix1/imagenes/logo.bmp);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        retranslateUi(acercade);

        QMetaObject::connectSlotsByName(acercade);
    } // setupUi

    void retranslateUi(QDialog *acercade)
    {
        acercade->setWindowTitle(QApplication::translate("acercade", "Acerca de QFotoPaint...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("acercade", "PAV QFotoPaint", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("acercade", "Versi\303\263n 4.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("acercade", "(2010) by GinesGM, D.I.S., Universidad de Murcia", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("acercade", "Versi\303\263n extensible", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("acercade", "Salir", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class acercade: public Ui_acercade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCADE_H
