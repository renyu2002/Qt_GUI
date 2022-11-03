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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_game_window
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *time;
    QLabel *minute;
    QLabel *label;
    QLabel *second;

    void setupUi(QWidget *main_game_window)
    {
        if (main_game_window->objectName().isEmpty())
            main_game_window->setObjectName(QString::fromUtf8("main_game_window"));
        main_game_window->resize(1000, 1000);
        widget = new QWidget(main_game_window);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 30, 324, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        time = new QLabel(widget);
        time->setObjectName(QString::fromUtf8("time"));

        horizontalLayout->addWidget(time);

        minute = new QLabel(widget);
        minute->setObjectName(QString::fromUtf8("minute"));

        horizontalLayout->addWidget(minute);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        second = new QLabel(widget);
        second->setObjectName(QString::fromUtf8("second"));

        horizontalLayout->addWidget(second);


        retranslateUi(main_game_window);

        QMetaObject::connectSlotsByName(main_game_window);
    } // setupUi

    void retranslateUi(QWidget *main_game_window)
    {
        main_game_window->setWindowTitle(QCoreApplication::translate("main_game_window", "Form", nullptr));
        time->setText(QCoreApplication::translate("main_game_window", "\346\227\266\351\227\264\357\274\232", nullptr));
        minute->setText(QCoreApplication::translate("main_game_window", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("main_game_window", ":", nullptr));
        second->setText(QCoreApplication::translate("main_game_window", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_game_window: public Ui_main_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_GAME_WINDOW_H
