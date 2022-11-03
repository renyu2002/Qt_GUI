#include "widget.h"
#include"teacher.h"
#include"student.h"
#include<QPushButton>

//Teacher 类   老师类
//Student 类   学生类
//下课后，老师会发送一个信号：hungry，学生响应：请老师吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个老师对象
    this->te =new Teacher(this);

    //创建一个学生对象
    this->st =new Student(this);

    //connect(te,&Teacher::hungry,st,&Student::treat);



    //指针->地址
    //函数指针->函数地址

    void (Teacher::*teachersignal1)(QString)=&Teacher::hungry;
    void (Student::*studentslot1)(QString)=&Student::treat;

    //将信号与槽链接起来
    connect(te,teachersignal1,st,studentslot1);
    //classisover();

    //点击一个“下课”的按钮，再触发下课
    QPushButton *button1=new QPushButton("下课1",this);
    QPushButton *button2=new QPushButton("下课2",this);
    button2->move(500,500);
    resize(1000,1000);

    //点击按钮触发下课
    connect(button1,&QPushButton::clicked,this,&Widget::classisover1);
    //无参信号和槽链接
    void (Teacher::*teachersignal2)(void)=&Teacher::hungry;
    void (Student::*studentslot2)(void)=&Student::treat;
    connect(te,teachersignal2,st,studentslot2);

    //信号连接信号
    connect(button2,&QPushButton::clicked,te,teachersignal2);

    //断开信号
    disconnect(te,teachersignal2,st,studentslot2);

    //拓展
    //1、信号可以连接信号
    //2、一个信号可以连接多个槽函数
    //3、多个信号可以连接一个槽函数
    //4、信号和槽函数参数类型必须一一对应
    //5、信号和槽的参数的个数，可以不一致
    //6、信号的参数需要多于槽函数，且至少包含槽函数的参数类型
    //7、信号与信号连接，前一个的信号参数个数和类型需要多于或等于后一个


    //Qt4版本以前的信号和槽的连接方式
    //利用Qt4信号槽 连接无参版本
    //Qt4版本 底层SIGNAL("hungry") SLOT("treat")
    connect(te,SIGNAL(hungry()),st,SLOT(treat()));
    //优点：参数直观
    //缺点：类型不做检测，bug不容易发现
    //Qt5以上 支持 Qt4的版本写法，反之不支持

}

void Widget::classisover1()
{
    emit te->hungry("宫保鸡丁");
}
void Widget::classisover2()
{
    emit te->hungry();
}

Widget::~Widget()
{
}

