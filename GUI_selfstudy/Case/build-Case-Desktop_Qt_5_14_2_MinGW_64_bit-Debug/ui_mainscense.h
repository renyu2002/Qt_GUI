/********************************************************************************
** Form generated from reading UI file 'mainscense.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENSE_H
#define UI_MAINSCENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainScense
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainScense)
    {
        if (MainScense->objectName().isEmpty())
            MainScense->setObjectName(QString::fromUtf8("MainScense"));
        MainScense->resize(800, 600);
        centralwidget = new QWidget(MainScense);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainScense->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainScense);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainScense->setMenuBar(menubar);
        statusbar = new QStatusBar(MainScense);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainScense->setStatusBar(statusbar);

        retranslateUi(MainScense);

        QMetaObject::connectSlotsByName(MainScense);
    } // setupUi

    void retranslateUi(QMainWindow *MainScense)
    {
        MainScense->setWindowTitle(QCoreApplication::translate("MainScense", "MainScense", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainScense: public Ui_MainScense {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENSE_H
