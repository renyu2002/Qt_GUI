#include "widget.h"
#include "ui_widget.h"
#include <QTime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    getavector();

    for (int var=0;var<27;var++) {
        qDebug () <<a[var];
    }
}

void Widget::getavector()
{
//    qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
    for (int i = 0; i < 27; ++i) {
        qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
         a[i]=qrand()%27;
         for (int j = 0; j < 27; ++j) {
             if (a[j]==a[i]) {
                 i--;
                 break;
             }
         }
    };

//    for (int var=0;var<27;var++) {
//        qDebug () <<a[var];
//    }


}

Widget::~Widget()
{
    delete ui;
}

