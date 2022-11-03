#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QBrush>
#include <QMainWindow>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   QTimer *timer = new QTimer(this);

    timer->start(200);

    connect(timer,&QTimer::timeout,this,QOverload<>::of(&Widget::repaint));

    setWindowIcon(QIcon(":/ /075e760aeff8b7c2af7003a1d9b9eaa7.jpeg"));
    setWindowTitle("推箱子");
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W)
    {
        y=y-50;
    }
    if(event->key()==Qt::Key_A)
    {
        x=x-50;
    }
    if(event->key()==Qt::Key_S)
    {
        y=y+50;
    }
    if(event->key()==Qt::Key_D)
    {
        x=x+50;
    }

}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush brush1(QColor(0,0,255));
    painter.setBrush(brush1);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(x,y),50,50);
    painter.drawEllipse(QPoint(x+800,y),50,50);
    painter.drawEllipse(QPoint(x-800,y),50,50);
    painter.drawEllipse(QPoint(x,y+600),50,50);
    painter.drawEllipse(QPoint(x,y-600),50,50);
    QBrush brush2(QColor(0,255,0));
    painter.setBrush(brush2);
    painter.drawRect(QRect(a,b,100,100));
    painter.drawRect(QRect(a+800,b,100,100));
    painter.drawRect(QRect(a-800,b,100,100));
    painter.drawRect(QRect(a,b+600,100,100));
    painter.drawRect(QRect(a,b-600,100,100));
    if(x==a+100&&y==b+50)
    {
        a=x-150,b=y-50;
    }
    if(x==a+50&&y==b)
    {
        a=x-50,b=y+50;
    }
    if(x==a&&y==b+50)
    {
        a=x+50,b=y-50;
    }
    if(x==a+50&&y==b+100)
    {
        a=x-50,b=y-150;
    }
}

Widget::~Widget()
{
    delete ui;
}

