/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QPushButton *singlePlayerBtn;
    QPushButton *multiplayerBtn;
    QLineEdit *gameStringTxt;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QString::fromUtf8("Start"));
        Start->resize(486, 537);
        singlePlayerBtn = new QPushButton(Start);
        singlePlayerBtn->setObjectName(QString::fromUtf8("singlePlayerBtn"));
        singlePlayerBtn->setGeometry(QRect(160, 80, 75, 23));
        multiplayerBtn = new QPushButton(Start);
        multiplayerBtn->setObjectName(QString::fromUtf8("multiplayerBtn"));
        multiplayerBtn->setGeometry(QRect(160, 130, 75, 23));
        gameStringTxt = new QLineEdit(Start);
        gameStringTxt->setObjectName(QString::fromUtf8("gameStringTxt"));
        gameStringTxt->setGeometry(QRect(140, 180, 113, 20));

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Form", nullptr));
        singlePlayerBtn->setText(QApplication::translate("Start", "Single Player", nullptr));
        multiplayerBtn->setText(QApplication::translate("Start", "Multiplayer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
