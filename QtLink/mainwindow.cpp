#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <signal_game_window.h>
#include <QTimer>
#include <QFileDialog>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("颜色连连看");
    this->setFixedSize(1000,1000);
    this->setWindowIcon(QIcon(":/new/prefix1/resourse/window_Icon.jpg"));

    //实例化游戏场景
    gamewindow1=new signal_game_window;
    gamewindow2=new double_game_window;

    //单人模式按钮
    MyPushButton * signalBtn= new MyPushButton(":/new/prefix1/resourse/signalbutton.jpg");
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
            gamewindow1->show();
        });
    });
    //双人模式按钮
    MyPushButton * doubleBtn= new MyPushButton(":/new/prefix1/resourse/doublebutton.jpg");
    doubleBtn->setParent(this);
    doubleBtn->move(this->width()*0.5-signalBtn->width()*0.5,this->height()*0.4);
    connect(doubleBtn,&MyPushButton::clicked,[=]()
    {
        //做弹起特效
        doubleBtn->zoom1();
        //延时进入到游戏场景中
        QTimer::singleShot(100,this,[=]()
        {
            //将自身隐藏
            this->hide();
            //显示游戏场景
            gamewindow2->show();
        });
    });
    //载入按钮
    MyPushButton * lodBtn= new MyPushButton(":/new/prefix1/resourse/lodbutton.jpg");
    lodBtn->setParent(this);
    lodBtn->move(this->width()*0.5-signalBtn->width()*0.5,this->height()*0.6);
    connect(lodBtn,&MyPushButton::clicked,[=]()
    {
        //做弹起特效
        lodBtn->zoom1();
        QTimer::singleShot(100,this,[=]()
        {
            QDialog *dlg=new QDialog(this);
            dlg->resize(100,300);
            dlg->setWindowTitle("载入游戏");
            QPushButton *btn1=new QPushButton(dlg);
            QPushButton *btn2=new QPushButton(dlg);
            btn1->move(30,100);
            btn2->move(30,200);
            btn1->setText("单人模式");
            btn2->setText("双人模式");
            dlg->show();
            qDebug()<<"running";
            connect(btn1,&QPushButton::clicked,[=]()
            {

                QFile file(":/new/prefix2/save/signal_game_mode.txt");
                for (int var=0;var<40;var=var+2) {
                    QString num=file.readLine(var);
                    int number=num.toInt();
                    gamewindow1->p[var/2].ID_x=number;
                }

                QString num=file.readLine(40);
                int number=num.toInt();
                gamewindow1->ones.ID_x=number;
                num=file.readLine(41);
                number=num.toInt();
                gamewindow1->ones.ID_y=number;
                num=file.readLine(42);
                number=num.toInt();
                gamewindow1->hint.ID_x=number;
                num=file.readLine(43);
                number=num.toInt();
                gamewindow1->hint.ID_y=number;
                num=file.readLine(44);
                number=num.toInt();
                gamewindow1->shuffle.ID_x=number;
                num=file.readLine(45);
                number=num.toInt();
                gamewindow1->shuffle.ID_y=number;
                num=file.readLine(46);
                number=num.toInt();
                gamewindow1->flash.ID_x=number;
                num=file.readLine(47);
                number=num.toInt();
                gamewindow1->flash.ID_y=number;
                gamewindow1->show();
                this->hide();
                dlg->hide();
            });
        });
    });
    //退出按钮
    MyPushButton * closeBtn= new MyPushButton(":/new/prefix1/resourse/closebutton.jpg");
    closeBtn->setParent(this);
    closeBtn->move(this->width()*0.5-signalBtn->width()*0.5,this->height()*0.8);
    connect(closeBtn,&MyPushButton::clicked,[=]()
    {
        //做弹起特效
        closeBtn->zoom1();

        QTimer::singleShot(100,this,[=]()
        {
            this->close();
        });
    });

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::cyan);
    p.drawRect(rect());
}



MainWindow::~MainWindow()
{
    delete ui;
}

