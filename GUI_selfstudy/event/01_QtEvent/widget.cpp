#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动计时器
     id1=startTimer(1000);

    //启动第二个计时器
     id2=startTimer(2000);

     //定时器第二种方式
     QTimer *timer=new QTimer(this);
     //启动定时器
     timer->start(500);
     static int a;
     connect(timer,&QTimer::timeout,[=]()
     {
         ui->label_4->setText(QString::number(a++));
     });

//     connect(ui->btn,QPushButton::clicked,[=]()
//     {
//         timer->stop();
//     });

     //给label_1安装事件过滤器
     ui->label_1->installEventFilter(this);
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    if(obj==ui->label_1)
    {
        QMouseEvent *event=static_cast<QMouseEvent*>(e);
        //如果是鼠标按下，在event事件分发中做拦截操作
        if(e->type()==QEvent::MouseButtonPress){
            QString str=QString("Event 函数中，鼠标按下了x=%1，y=%2，globalX=%3，globalY=%4").arg(event->x()).arg(event->y());
            qDebug()<<str;

            return true;//true代表用户自己处理这个事件，不向下分发
        }
    }
}

//重写定时器事件
void Widget::timerEvent (QTimerEvent *event)
{
    if(event->timerId()==id1)
    {
        static int num1=1;
        ui->label_2->setText( QString::number(num1++));
    }
    if(event->timerId()==id2)
    {
        static int num2=1;
        ui->label_3->setText( QString::number(num2++));
    }

}

Widget::~Widget()
{
    delete ui;
}

