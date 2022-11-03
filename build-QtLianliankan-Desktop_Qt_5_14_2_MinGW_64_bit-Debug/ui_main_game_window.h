/********************************************************************************
** Form generated from reading UI file 'main_game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_GAME_WINDOW_H
#define UI_MAIN_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainGameWindow
{
public:
    QAction *actionsignal;
    QAction *actionMedium;
    QAction *actionHard;
    QAction *actiondouble;
    QAction *actionlogin;
    QAction *actionclose;
    QAction *actionpause;
    QWidget *centralWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *timeBar;
    QPushButton *hintBtn;
    QMenuBar *menuBar;
    QMenu *menuGame;

    void setupUi(QMainWindow *MainGameWindow)
    {
        if (MainGameWindow->objectName().isEmpty())
            MainGameWindow->setObjectName(QString::fromUtf8("MainGameWindow"));
        MainGameWindow->resize(1411, 1000);
        MainGameWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 249, 255);"));
        actionsignal = new QAction(MainGameWindow);
        actionsignal->setObjectName(QString::fromUtf8("actionsignal"));
        actionMedium = new QAction(MainGameWindow);
        actionMedium->setObjectName(QString::fromUtf8("actionMedium"));
        actionHard = new QAction(MainGameWindow);
        actionHard->setObjectName(QString::fromUtf8("actionHard"));
        actiondouble = new QAction(MainGameWindow);
        actiondouble->setObjectName(QString::fromUtf8("actiondouble"));
        actionlogin = new QAction(MainGameWindow);
        actionlogin->setObjectName(QString::fromUtf8("actionlogin"));
        actionclose = new QAction(MainGameWindow);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        actionpause = new QAction(MainGameWindow);
        actionpause->setObjectName(QString::fromUtf8("actionpause"));
        centralWidget = new QWidget(MainGameWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1171, 46));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        timeBar = new QProgressBar(widget);
        timeBar->setObjectName(QString::fromUtf8("timeBar"));
        timeBar->setValue(24);

        horizontalLayout->addWidget(timeBar);

        hintBtn = new QPushButton(widget);
        hintBtn->setObjectName(QString::fromUtf8("hintBtn"));
        hintBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(11, 255, 36, 161);"));

        horizontalLayout->addWidget(hintBtn);

        MainGameWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainGameWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1411, 26));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        MainGameWindow->setMenuBar(menuBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionsignal);
        menuGame->addAction(actiondouble);
        menuGame->addSeparator();
        menuGame->addAction(actionpause);
        menuGame->addAction(actionlogin);
        menuGame->addAction(actionclose);

        retranslateUi(MainGameWindow);

        QMetaObject::connectSlotsByName(MainGameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainGameWindow)
    {
        MainGameWindow->setWindowTitle(QCoreApplication::translate("MainGameWindow", "MainGameWindow", nullptr));
        actionsignal->setText(QCoreApplication::translate("MainGameWindow", "\345\215\225\344\272\272\346\250\241\345\274\217", nullptr));
        actionMedium->setText(QCoreApplication::translate("MainGameWindow", "medium", nullptr));
        actionHard->setText(QCoreApplication::translate("MainGameWindow", "hard", nullptr));
        actiondouble->setText(QCoreApplication::translate("MainGameWindow", "\345\217\214\344\272\272\346\250\241\345\274\217", nullptr));
        actionlogin->setText(QCoreApplication::translate("MainGameWindow", "\350\275\275\345\205\245", nullptr));
        actionclose->setText(QCoreApplication::translate("MainGameWindow", "\345\205\263\351\227\255", nullptr));
        actionpause->setText(QCoreApplication::translate("MainGameWindow", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("MainGameWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        hintBtn->setText(QCoreApplication::translate("MainGameWindow", "hints", nullptr));
        menuGame->setTitle(QCoreApplication::translate("MainGameWindow", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainGameWindow: public Ui_MainGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_GAME_WINDOW_H
