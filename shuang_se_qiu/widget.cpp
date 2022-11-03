#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QPushButton>
#include <mypushbutton.h>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("双色球");
    this->setFixedSize(1000,1000);
    this->setWindowIcon(QIcon(":/new/prefix1/resource/src=http___pic.51yuansu.com_pic3_cover_00_89_45_58dbb170ddb56_610.jpg&refer=http___pic.51yuansu.jfif"));

    //实例化游戏场景
    gamewindow=new game_window;
    //单人模式按钮
    MyPushButton * signalBtn= new MyPushButton(":/new/prefix1/resource/button.jpg");
    signalBtn->setParent(this);
    signalBtn->move(this->width()*0.5-signalBtn->width()*0.5,this->height()*0.2);
    connect(signalBtn,&MyPushButton::clicked,[=]()
    {
        //做弹起特效
        signalBtn->zoom1();

        //延时进入到游戏场景中
        QTimer::singleShot(100,this,[=]()
        {
            //将自身隐藏
            this->hide();
            //显示游戏场景
            gamewindow->show();
        });
    });
}

Widget::~Widget()
{
    delete ui;
}

