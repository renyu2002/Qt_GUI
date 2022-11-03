#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{


}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入了";
}

//鼠标离开事件
void myLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开了";
}

//鼠标按下事件
void myLabel::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标按下了"<<event->x();
}

//鼠标松开事件
void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标松开了";
}

//鼠标移动事件
void myLabel::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标移动了";
}

//
bool myLabel::event(QEvent *ev)
{
    QMouseEvent *event=static_cast<QMouseEvent*>(ev);
    //如果是鼠标按下，在event事件分发中做拦截操作
    if(ev->type()==QEvent::MouseButtonPress){
        QString str=QString("Event 函数中，鼠标按下了x=%1，y=%2，globalX=%3，globalY=%4").arg(event->x(),event->y(),event->globalX(),event->globalY());
        qDebug()<<str;

        return true;//true代表用户自己处理这个事件，不向下分发
    }

    //其他事件交给父类处理
    return QLabel::event(ev);
}

