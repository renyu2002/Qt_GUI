/********************************************************************************
** Form generated from reading UI file 'double_game_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOUBLE_GAME_WINDOW_H
#define UI_DOUBLE_GAME_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_double_game_window
{
public:
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *score1;
    QLabel *scores1;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pause;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *time;
    QLabel *minute;
    QLabel *label;
    QLabel *second;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *help;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *score2;
    QLabel *scores2;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *double_game_window)
    {
        if (double_game_window->objectName().isEmpty())
            double_game_window->setObjectName(QString::fromUtf8("double_game_window"));
        double_game_window->resize(1000, 1000);
        widget_2 = new QWidget(double_game_window);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 981, 61));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        score1 = new QLabel(widget_3);
        score1->setObjectName(QString::fromUtf8("score1"));

        horizontalLayout_3->addWidget(score1);

        scores1 = new QLabel(widget_3);
        scores1->setObjectName(QString::fromUtf8("scores1"));

        horizontalLayout_3->addWidget(scores1);


        horizontalLayout_4->addWidget(widget_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pause = new QPushButton(widget_2);
        pause->setObjectName(QString::fromUtf8("pause"));

        horizontalLayout_4->addWidget(pause);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        time = new QLabel(widget_4);
        time->setObjectName(QString::fromUtf8("time"));

        horizontalLayout_2->addWidget(time);

        minute = new QLabel(widget_4);
        minute->setObjectName(QString::fromUtf8("minute"));

        horizontalLayout_2->addWidget(minute);

        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        second = new QLabel(widget_4);
        second->setObjectName(QString::fromUtf8("second"));

        horizontalLayout_2->addWidget(second);


        horizontalLayout_4->addWidget(widget_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        help = new QPushButton(widget_2);
        help->setObjectName(QString::fromUtf8("help"));

        horizontalLayout_4->addWidget(help);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        score2 = new QLabel(widget);
        score2->setObjectName(QString::fromUtf8("score2"));

        horizontalLayout->addWidget(score2);

        scores2 = new QLabel(widget);
        scores2->setObjectName(QString::fromUtf8("scores2"));

        horizontalLayout->addWidget(scores2);


        horizontalLayout_4->addWidget(widget);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        retranslateUi(double_game_window);

        QMetaObject::connectSlotsByName(double_game_window);
    } // setupUi

    void retranslateUi(QWidget *double_game_window)
    {
        double_game_window->setWindowTitle(QCoreApplication::translate("double_game_window", "Form", nullptr));
        score1->setText(QCoreApplication::translate("double_game_window", "player1\345\276\227\345\210\206\357\274\232", nullptr));
        scores1->setText(QCoreApplication::translate("double_game_window", "0", nullptr));
        pause->setText(QCoreApplication::translate("double_game_window", "\346\232\202\345\201\234", nullptr));
        time->setText(QCoreApplication::translate("double_game_window", "\346\227\266\351\227\264\357\274\232", nullptr));
        minute->setText(QCoreApplication::translate("double_game_window", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("double_game_window", ":", nullptr));
        second->setText(QCoreApplication::translate("double_game_window", "TextLabel", nullptr));
        help->setText(QCoreApplication::translate("double_game_window", "\345\270\256\345\212\251", nullptr));
        score2->setText(QCoreApplication::translate("double_game_window", "player2\345\276\227\345\210\206\357\274\232", nullptr));
        scores2->setText(QCoreApplication::translate("double_game_window", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class double_game_window: public Ui_double_game_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOUBLE_GAME_WINDOW_H
