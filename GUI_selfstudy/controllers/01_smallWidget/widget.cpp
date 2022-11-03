#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //点击获取，获取当前值
    connect(ui->btn_get,&QPushButton::clicked,[=](){
        qDebug() << ui->widget->getNum();
    });

    //设置到一半
    connect(ui->btn_set,&QPushButton::clicked,[=](){
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

