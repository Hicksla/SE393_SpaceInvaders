/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *scoreLcd;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *livesLcd;
    QLabel *label_3;
    QLCDNumber *levelLcd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scoreLcd = new QLCDNumber(centralwidget);
        scoreLcd->setObjectName(QString::fromUtf8("scoreLcd"));
        scoreLcd->setGeometry(QRect(100, 0, 131, 41));
        scoreLcd->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 101, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: white;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 0, 71, 41));
        label_2->setFont(font);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background-color: white;"));
        livesLcd = new QLCDNumber(centralwidget);
        livesLcd->setObjectName(QString::fromUtf8("livesLcd"));
        livesLcd->setGeometry(QRect(300, 0, 131, 41));
        livesLcd->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0. 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 0, 81, 41));
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("background-color: white;"));
        levelLcd = new QLCDNumber(centralwidget);
        levelLcd->setObjectName(QString::fromUtf8("levelLcd"));
        levelLcd->setGeometry(QRect(510, 0, 131, 41));
        levelLcd->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0. 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " SCORE:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", " LIVES", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "  LEVEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
