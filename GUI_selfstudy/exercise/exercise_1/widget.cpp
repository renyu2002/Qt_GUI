#include "widget.h"
#include<QPushButton>
//#include "newdialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QWidget *n =new QWidget();
    resize(500,500);
    setWindowTitle("作业1");
    QPushButton *button2=new QPushButton;
    button2->setParent(this);
    button2->setText("关闭");
    button2->show();
    button2->move(200,200);
    QPushButton *button1=new QPushButton;
    button1->setParent(this);
    button1->setText("打开");
    button1->show();
    button1->move(200,200);


    connect(button1,&QPushButton::clicked,button1,&QWidget::close);
    connect(button2,&QPushButton::clicked,button1,&QWidget::show);
    connect(button1,&QPushButton::clicked,n,&QWidget::show);
    connect(button2,&QPushButton::clicked,n,&QWidget::close);


}

Widget::~Widget()
{
}

