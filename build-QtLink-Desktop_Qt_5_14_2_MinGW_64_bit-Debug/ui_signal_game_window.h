/********************************************************************************
** Form generated from reading UI file 'signal_game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNAL_GAME_WINDOW_H
#define UI_SIGNAL_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signal_game_window
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *score;
    QLabel *scores;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *time;
    QLabel *minute;
    QLabel *label;
    QLabel *second;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pause;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *help;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *signal_game_window)
    {
        if (signal_game_window->objectName().isEmpty())
            signal_game_window->setObjectName(QString::fromUtf8("signal_game_window"));
        signal_game_window->resize(1000, 1000);
        widget_2 = new QWidget(signal_game_window);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(9, 9, 981, 71));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        score = new QLabel(widget_3);
        score->setObjectName(QString::fromUtf8("score"));

        horizontalLayout_3->addWidget(score);

        scores = new QLabel(widget_3);
        scores->setObjectName(QString::fromUtf8("scores"));

        horizontalLayout_3->addWidget(scores);


        horizontalLayout_4->addWidget(widget_3);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
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

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_4->addWidget(widget);

        pause = new QPushButton(widget_2);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout_4->addWidget(pause);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        help = new QPushButton(widget_2);
        help->setObjectName(QString::fromUtf8("help"));

        horizontalLayout_4->addWidget(help);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        retranslateUi(signal_game_window);

        QMetaObject::connectSlotsByName(signal_game_window);
    } // setupUi

    void retranslateUi(QWidget *signal_game_window)
    {
        signal_game_window->setWindowTitle(QCoreApplication::translate("signal_game_window", "Form", nullptr));
        score->setText(QCoreApplication::translate("signal_game_window", "\345\276\227\345\210\206\357\274\232", nullptr));
        scores->setText(QCoreApplication::translate("signal_game_window", "0", nullptr));
        time->setText(QCoreApplication::translate("signal_game_window", "\346\227\266\351\227\264\357\274\232", nullptr));
        minute->setText(QCoreApplication::translate("signal_game_window", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("signal_game_window", ":", nullptr));
        second->setText(QCoreApplication::translate("signal_game_window", "TextLabel", nullptr));
        pause->setText(QCoreApplication::translate("signal_game_window", "\346\232\202\345\201\234", nullptr));
        help->setText(QCoreApplication::translate("signal_game_window", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signal_game_window: public Ui_signal_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNAL_GAME_WINDOW_H
