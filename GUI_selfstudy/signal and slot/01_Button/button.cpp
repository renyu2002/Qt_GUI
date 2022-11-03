#include "button.h"
#include <QPushButton>//按钮控制的头文件
#include "mypushbutton.h"
#include <qdebug.h>

Button::Button(QWidget *parent)
    : QMainWindow(parent)
{
    //创建一个按钮(方法一）
    QPushButton *button=new QPushButton;
    button->show();//show以一个新窗口的方式进行显示
    //让button对象 依赖于button窗口上
    button->setParent(this);//把其父类定义为this，也就是这个窗口
    //看来this在这种情况下会代表这个Button函数
    //显示文本
    button->setText("这是一个按钮");
    //重置按钮大小
    button->resize(100,25 );


    //创建一个按钮（方法二）
    QPushButton *button2=new QPushButton ("这是另一个按钮",this);
    //缺点：按照控件的大小创建窗口，导致窗口过小

    //重置窗口大小
    resize (1000,1000);

    //移动按钮位置
    button->move(900,900);

    //设置窗口标题
    setWindowTitle("按钮");

    //设置固定的窗口大小
    setFixedSize(1000,1000);

    //创建一个自己的按钮
    Mypushbutton *newbutton=new Mypushbutton;
    newbutton->setParent(this);
    newbutton->setText("我的按钮");
    newbutton->move(500,500);
    newbutton->resize(100,25);


    //需求：点击这是一个按钮，关闭窗口
    //参数1，信号的发送者；参数2，信号;参数3，信号的接收者；参数4，执行函数
    connect(button,&QPushButton::clicked,this,&QWidget::close);
    connect(button2,&Mypushbutton::clicked,this,QWidget::close);
    connect(newbutton,&Mypushbutton::clicked,this,QWidget::close);





}

Button::~Button()
{
    qDebug() <<"按钮类析构调用";
}

