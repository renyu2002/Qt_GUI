#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    timer->start(1000);


    connect(timer,&QTimer::timeout,[=]()
    {
        x=x+20;
        repaint();
        qDebug()<<"+1s";
    });
}

void Widget::paintEvent(QPaintEvent *)
{

//    //实例化一个画家对象 this指定的是绘图的设备
//    QPainter painter(this);
//    //设置画笔
//    QPen pen(QColor(255,0,0));
//    //设置画笔的宽度
//    pen.setWidth(3);
//    //设置画笔的风格
//    pen.setStyle(Qt::DotLine);

//    //设置画刷
//    QBrush brush(Qt::cyan);
//    brush.setStyle(Qt::Dense7Pattern);
//    //让画家使用这根画刷
//    painter.setBrush(brush);
//    //让画家使用这根画笔
//    painter.setPen(pen);
//    //画一条直线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    //画一个圆
//    painter.drawEllipse( QPoint(100,100),50,100);
//    //画一个矩形
//    painter.drawRect(QRect(20,20,50,50));
//    //画文字
//    painter.drawText(QRect(10,200,100,50),"好好学习，天天向上");



    //////////////////////////高级设置/////////////////////////

    QPainter painter(this);
    painter.drawEllipse(QPoint(100,50),50,50);
    //设置抗锯齿 效率较低
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(200,50),50,50);
    //画矩形
    painter.drawRect(QRect(500,500,50,50));
    //移动画家
    painter .translate(100,0);
    //保存画家状态
    painter.save();
    painter.drawRect(QRect(500,500,50,50));
    //还原画家状态
    painter.restore();
    painter.drawRect(QRect(500,500,50,50));

//    ///////////////////////////////利用画家画资源图片//////////////////////
//    QPainter painter(this);

//    //如果超出了屏幕，从0开始

//    if(x>this->width()){
//        x=0;
//    }
//    painter.drawPixmap(x,20,QPixmap(":/new/prefix1/mysource/a.jpg"));
}

Widget::~Widget()
{
    delete ui;
}

