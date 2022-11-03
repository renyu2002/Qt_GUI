#include "signal_game_window.h"
#include "ui_signal_game_window.h"
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include <QDebug>
#include <QBrush>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QPen>
#include <QFileDialog>


signal_game_window::signal_game_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signal_game_window)
{
    ui->setupUi(this);
    this->setFixedSize(1000,1000);
    this->setWindowTitle("单人模式");
    this->setWindowIcon(QIcon(":/new/prefix1/resourse/window_Icon.jpg"));

    QTimer *timer=new QTimer (this);
    QTimer *tim=new QTimer (this);
    timer->start(1000);
    /////////////////////////////////暂停按钮///////////////////////////////////
    connect(ui->pause,&QPushButton::clicked,[=]()
    {
        timer->stop();
        QDialog *dlg2=new QDialog(this);
        dlg2->setFixedSize(200,400);
        dlg2->setWindowTitle("暂停");
        ///////////////////////////////保存按钮////////////////////////////////////
        QPushButton *button1=new QPushButton(dlg2);
        button1->setText("保存");
        button1->move(30,100);
        connect(button1,&QPushButton::clicked,[=]()
        {
            save();
            dlg2->close();
            timer->start(1000);
        });
        /////////////////////////////////////载入按钮/////////////////////////////
        QPushButton *button2=new QPushButton(dlg2);
        button2->setText("载入");
        button2->move(30,200);
        connect(button2,&QPushButton::clicked,[=]()
        {
            load();
            dlg2->close();
            timer->start(1000);
        });
        //////////////////////////////////返回按钮////////////////////////////
        QPushButton *button3=new QPushButton(dlg2);
        button3->setText("返回游戏");
        button3->move(30,300);
        connect(button3,&QPushButton::clicked,[=]()
        {
            timer->start(1000);
            dlg2->close();
        });
        dlg2->exec();
    });
    tim->start(100);
    connect(timer,&QTimer::timeout,[=]()
    {
        /////////////////////////倒计时//////////////////////////////
        if(t>=0){
            QString num1 = QString::number(t/60);
            ui->minute->setText(num1);
            QString num2 = QString::number(t%60);
            ui->second->setText(num2);
            t=t-1;
        }
        else{
            timer->stop();
        }
        //////////////////////////////超时结束////////////////////////////////////
        if (t==0){
            QDialog *dlg3=new QDialog(this);
            dlg3->setWindowTitle("Timeout");
            QPushButton *button=new QPushButton(dlg3);
            button->setText("Timeout,close");
            connect(button,&QPushButton::clicked,dlg3,&QDialog::close);
            connect(button,&QPushButton::clicked,this,&QWidget::close);
            dlg3->exec();
        }
        ////////////////////////////判断是否全被消完/////////////////////////////////////
        int i=0;
        for (int var = 0; var < 20; ++var) {
            if(p[var].ID_x!=0||p[var].ID_y!=0){
                i=i+1;
            }
        }
        if(i==0){
            QDialog *dlg1=new QDialog(this);
            dlg1->setWindowTitle("game over");
            dlg1->resize(100,100);
            QLabel *label=new QLabel(dlg1);
            label->setText("You win.");
            label->move(30,30);
            QPushButton *button=new QPushButton(dlg1);
            button->setText("close");
            button->move(30,50);
            connect(button,&QPushButton::clicked,dlg1,&QDialog::close);
            connect(button,&QPushButton::clicked,this,&QWidget::close);
            dlg1->exec();
        }
    });
    /////////////////////////////////游戏的刷新频率：0.1s/////////////////////////////////////////////
    connect(tim,&QTimer::timeout,this,QOverload<>::of(&QWidget::repaint));
    connect(tim,&QTimer::timeout,[=](){
        choose();
        Tools();
        whether_is_same();
        if(FIRST!=-1&&SECOND!=-1){
            if(issame==true)
            {
                p[FIRST].ID_x=0;
                p[FIRST].ID_y=0;
                p[SECOND].ID_x=0;
                p[SECOND].ID_y=0;
                first.ID_x=0;
                first.ID_y=0;
                second.ID_x=0;
                second.ID_y=0;
                s=0;
                d=0;
                FIRST=-1;
                SECOND=-1;
//                qDebug()<<"true";
                mark++;
                QString num = QString::number(mark);
                ui->scores->setText(num);
            }
            else
            {
                first.ID_x=0;
                first.ID_y=0;
                second.ID_x=0;
                second.ID_y=0;
                s=0;
                d=0;
                FIRST=-1;
                SECOND=-1;
//                qDebug()<<"false";
            }
        }
    });
    if(is_loading==false){
        ////////////////////////////////////设置素材数组//////////////////////////////////
        qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
        for (int var = 0; var < 20; ++var) {
            int j=0;
            int x = qrand()%10;
            int y = qrand()%9;
            for (int i=0;i<var;i++){
                if(x+1==p[i].ID_x&&y+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(j==0){
                p[var].ID_x=x+1;
                p[var].ID_y=y+2;}
            else var=var-1;
        };
//        for (int var = 0; var < 20; ++var)
//        {
//            //qDebug()<<p[var].ID_x<<"   "<<p[var].ID_y<<endl;
//        }
        ////////////////////////////////hint的坐标/////////////////////////
        for (int var = 0; var < 20; ++var) {
            int j=0;
            int a = qrand()%10;
            int b = qrand()%9;
            for (int i=0;i<20;i++){
                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(j==0){
                hint.ID_x=a+1;
                hint.ID_y=b+2;
            }
        }
        ////////////////////////////ones的坐标//////////////////////////////////////
        for (int var = 0; var < 20; ++var) {
            int j=0;
            int a = qrand()%10;
            int b = qrand()%9;
            for (int i=0;i<20;i++){
                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
            if(j==0){
                ones.ID_x=a+1;
                ones.ID_y=b+2;
            }
        }
        //////////////////////////shuffle的坐标///////////////////////////////////////
        for (int var = 0; var < 20; ++var) {
            int j=0;
            int a = qrand()%10;
            int b = qrand()%9;
            for (int i=0;i<20;i++){
                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
            if(a+1==ones.ID_x&&b+2==ones.ID_y) j++;
            if(j==0){
                shuffle.ID_x=a+1;
                shuffle.ID_y=b+2;
            }
        }
        ///////////////////////////flash的坐标////////////////////////////////////////
        for (int var = 0; var < 20; ++var) {
            int j=0;
            int a = qrand()%10;
            int b = qrand()%9;
            for (int i=0;i<20;i++){
                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
            if(a+1==ones.ID_x&&b+2==ones.ID_y) j++;
            if(a+1==shuffle.ID_x&&b+2==shuffle.ID_y) j++;
            if(j==0){
                flash.ID_x=a+1;
                flash.ID_y=b+2;
            }
        }
        /////////////////////////帮助按钮////////////////////////////////////////////////
        connect(ui->help,&QPushButton::clicked,[=]()
        {
            QDialog *dlg=new QDialog(this);
            dlg->setFixedSize(584,617);
            dlg->setWindowTitle("帮助");
            dlg->setWindowIcon(QIcon(":/new/prefix1/resourse/window_Icon.jpg"));
            QLabel *label=new QLabel(dlg);
            label->setPixmap(QPixmap(":/new/prefix1/resourse/signal_game_mode_help.jpg"));
            dlg->exec();
        });
        /////////////////////////////生成RPG角色坐标//////////////////////////////////////////////
        bool ok=false;
        while (ok==false) {
            qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
            int j=0;
            int a = qrand()%10;
            int b = qrand()%9;
            for (int i=0;i<20;i++){
                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
            if(a+1==ones.ID_x&&b+2==ones.ID_y) j++;
            if(a+1==shuffle.ID_x&&b+2==shuffle.ID_y) j++;
            if(a+1==flash.ID_x&&b+2==flash.ID_y) j++;
            if(j==0){
                x=a+1;
                y=b+2;
                ok=true;
            }
        }
    }
}
//判断是否相同
void signal_game_window ::whether_is_same()
{
    if(FIRST%2==0&&SECOND%2==1)
    {
        d=FIRST,s=SECOND;
    }
    else issame=false;
    if(FIRST%2==1&&SECOND%2==0)
    {
        s=FIRST,d=SECOND;
    }
    else issame=false;

    if( s==d+1){
        issame=true;
    }
    else{
        issame=false;
    }
//    qDebug() <<"is running"<<endl;
//    qDebug()<<"signal="<<s<<endl;
//    qDebug()<<"double="<<d<<endl;
}

//上下左右移动
void signal_game_window::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W)
    {
        y=y-1;
    }
    if(event->key()==Qt::Key_A)
    {
        x=x-1;
    }
    if(event->key()==Qt::Key_S)
    {
        y=y+1;
    }
    if(event->key()==Qt::Key_D)
    {
        x=x+1;
    }

}
//判断选中了哪个圆
void signal_game_window :: choose()
{
    if (first.ID_x==0&&first.ID_y==0){
        for (int var=0;var<20;var++) {
            if(x==p[var].ID_x){
                if(y==p[var].ID_y){
                    first.ID_x=x;
                    first.ID_y=y;
                    FIRST=var;
                    qDebug() <<"first.x:"<<first.ID_x<<endl<<"first.y:"<<first.ID_y<<endl;
                };
            };
        };
    }
    else {
        if(first.ID_x!=x||first.ID_y!=y){
            if(second.ID_x==0&&second.ID_y==0){
                for (int var=0;var<20;var++) {
                    if(x==p[var].ID_x){
                        if(y==p[var].ID_y){
                            second.ID_x=x;
                            second.ID_y=y;
                            SECOND=var;
                            qDebug() <<"second.x:"<<second.ID_x<<endl<<"second.y:"<<second.ID_y<<endl;
                        };
                    };
                };
            };
        };
    }
}

//画图
void signal_game_window :: paintEvent(QPaintEvent *ev)
{
    QPainter player(this);
    QPen pen(QColor(255,0,0));
    player.setPen(pen);
//    画RPG角色
    player.drawEllipse(QPoint(x*100-50,y*100-50),50,50);
    pen.setColor(QColor(255,255,255));
    player.setPen(pen);
    for (int var=0;var<=20;var=var+2) {
        qsrand(var);
        int r=qrand()%25*10;
        int g=qrand()%25*10;
        int y=qrand()%25*10;
//        设置画刷
        QBrush brush (QColor(r,g,y));
//        让画家使用这根画刷
        player.setBrush(brush);
//        画出圆形
        player.drawEllipse(QPoint((p[var].ID_x*100-50),(p[var].ID_y*100-50)),50,50);
        player.drawEllipse(QPoint((p[var+1].ID_x*100-50),(p[var+1].ID_y*100-50)),50,50);
    }
//    画4个技能
    QBrush brush(QColor(0,0,0));
    brush.setStyle(Qt::BDiagPattern);
    player.setBrush(brush);
    player.drawEllipse(QPoint((ones.ID_x*100-50),(ones.ID_y*100-50)),50,50);
    brush.setStyle(Qt::FDiagPattern);
    player.setBrush(brush);
    player.drawEllipse(QPoint((hint.ID_x*100-50),(hint.ID_y*100-50)),50,50);
    brush.setStyle(Qt::DiagCrossPattern);
    player.setBrush(brush);
    player.drawEllipse(QPoint((shuffle.ID_x*100-50),(shuffle.ID_y*100-50)),50,50);
    brush.setStyle(Qt::CrossPattern);
    player.setBrush(brush);
    player.drawEllipse(QPoint((flash.ID_x*100-50),(flash.ID_y*100-50)),50,50);
    QBrush brush1(QColor(30,144,255));
    player.setBrush(brush1);
    player.drawEllipse(QPoint((highlight1.ID_x*100-50),(highlight1.ID_y*100-50)),50,50);
    player.drawEllipse(QPoint((highlight2.ID_x*100-50),(highlight2.ID_y*100-50)),50,50);
}

void signal_game_window::Tools( )
{
//        +1s的实现
    if(x==ones.ID_x&&y==ones.ID_y)
    {
        t=t+30;
        ones.ID_x=0;
        ones.ID_y=0;
    }
//        hint的实现
    if(x==hint.ID_x&&y==hint.ID_y)
    {
        hint.ID_x=0;
        hint.ID_y=0;

        QTimer *time =new QTimer(this);
        time ->start(100);
        static int  ti=0;
        connect(time ,&QTimer::timeout,[=]()
        {
            ti=ti+1;
            if (ti<=100) {
                for (int var=0;var<=20;var=var+2) {
                    if(p[var].ID_x!=0||p[var].ID_y!=0){
                        highlight1.ID_x=p[var].ID_x;
                        highlight1.ID_y=p[var].ID_y;
                        highlight2.ID_x=p[var+1].ID_x;
                        highlight2.ID_y=p[var+1].ID_y;
                        break;
                    }
                }
            }
            else
            {
                time->stop();
                highlight1.ID_x=0;
                highlight1.ID_y=0;
                highlight2.ID_x=0;
                highlight2.ID_y=0;
            }
        });
    }
//        shuffle的实现
    if(x==shuffle.ID_x&&y==shuffle.ID_y)
    {
        for (int var=0;var<20-mark*2;var++) {
            qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
            int j=0;
            int x = qrand()%10;
            int y = qrand()%9;
            for (int i=0;i<var;i++){
                if(x+1==p[i].ID_x&&y+2==p[i].ID_y){
                    j=j+1;
                }
            }
            if(j==0){
                p[var].ID_x=x+1;
                p[var].ID_y=y+2;}
            else var=var-1;
        }
        for (int var=20-mark*2;var<20;var++) {
            p[var].ID_x=0;
            p[var].ID_y=0;}
        shuffle.ID_x=0;
        shuffle.ID_y=0;
        //////////////////hint的坐标/////////////////////////
        if(hint.ID_x!=0||hint.ID_y!=0){
            for (int var = 0; var < 20; ++var) {
                int j=0;
                int a = qrand()%10;
                int b = qrand()%9;
                for (int i=0;i<20;i++){
                    if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                        j=j+1;
                    }
                }
                if(j==0){
                    hint.ID_x=a+1;
                    hint.ID_y=b+2;
                }
            }
        }
        ///////////////ones的坐标/////////////
        if(ones.ID_x!=0||ones.ID_y!=0){
            for (int var = 0; var < 20; ++var) {
                int j=0;
                int a = qrand()%10;
                int b = qrand()%9;
                for (int i=0;i<20;i++){
                    if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                        j=j+1;
                    }
                }
                if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
                if(j==0){
                    ones.ID_x=a+1;
                    ones.ID_y=b+2;
                }
            }
        }
        //////////flash的坐标////////
        if(flash.ID_x!=0||flash.ID_y!=0){
            for (int var = 0; var < 20; ++var) {
                int j=0;
                int a = qrand()%10;
                int b = qrand()%9;
                for (int i=0;i<20;i++){
                    if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
                        j=j+1;
                    }
                }
                if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
                if(a+1==ones.ID_x&&b+2==ones.ID_y) j++;
                if(a+1==shuffle.ID_x&&b+2==shuffle.ID_y) j++;
                if(j==0){
                    flash.ID_x=a+1;
                    flash.ID_y=b+2;
                }
            }
        }
    }
//    flash的实现
    if(x==flash.ID_x&&flash.ID_y)
    {
        QTimer *timers =new QTimer(this);
        timers ->start(100);
        static int  it=0;
        connect(timers,&QTimer::timeout,[=]()
        {
            it=it+1;
            if (it<=50) {
                x=mouse.ID_x;
                y=mouse.ID_y;
            }
        });
        flash.ID_x=0;
        flash.ID_y=0;
    }
}
void signal_game_window::mousePressEvent(QMouseEvent *ev)
{
    mouse.ID_x=(ev->x()+50)/100;
    mouse.ID_y=(ev->y()+50)/100;
//    qDebug() <<"is running";
//    qDebug() <<mouse.ID_x<<"  "<<mouse.ID_y<<endl;
}

void signal_game_window::save()
{

    QFile file("C:/Users/DELL/Desktop/GUI/QtLink/save/signal_game_mode.txt");
    if (file.open(QIODevice::ReadWrite)) //QIODevice::ReadWrite支持读写
    {
        QTextStream stream(&file);
        QString num_x,num_y;
        for (int var=0;var<20;var++) {
            num_x=QString::number(p[var].ID_x);
            stream << num_x << endl;
            num_y=QString::number(p[var].ID_y);
            stream << num_y << endl;
        }
        num_x=QString::number(ones.ID_x);
        stream << num_x << endl;
        num_y=QString::number(ones.ID_y);
        stream << num_y << endl;
        num_x=QString::number(hint.ID_x);
        stream << num_x << endl;
        num_y=QString::number(hint.ID_y);
        stream << num_y << endl;
        num_x=QString::number(shuffle.ID_x);
        stream << num_x << endl;
        num_y=QString::number(shuffle.ID_y);
        stream << num_y << endl;
        num_x=QString::number(flash.ID_x);
        stream << num_x << endl;
        num_y=QString::number(flash.ID_y);
        stream << num_y << endl;
        num_x=QString::number(mark);
        stream << num_x << endl;
        num_y=QString::number(t);
        stream << num_y << endl;
        num_x=QString::number(x);
        stream << num_x << endl;
        num_y=QString::number(y);
        stream << num_y << endl;
    }
    file.close();
}

void signal_game_window::load()
{
    QFile file("C:/Users/DELL/Desktop/GUI/QtLink/save/signal_game_mode.txt");
    if (file.open(QIODevice::ReadWrite)) //QIODevice::ReadWrite支持读写
    {for (int var=0;var<=40;var=var+2) {
            QString num=file.readLine(var);
            int number=num.toInt();
            p[var/2].ID_x=number;
//            qDebug() <<var<<"   "<<number<<endl;
            num=file.readLine(var+1);
            number=num.toInt();
            p[var/2].ID_y=number;
//            qDebug() <<var+1<<""<<number<<endl;
        }

        QString num=file.readLine(41);
        int number=num.toInt();
        ones.ID_x=number;
//        qDebug() <<"41  "<<number<<endl;
        num=file.readLine(42);
        number=num.toInt();
        ones.ID_y=number;
//        qDebug() <<"42  "<<number<<endl;
        num=file.readLine(43);
        number=num.toInt();
        hint.ID_x=number;
//        qDebug() <<"43  "<<number<<endl;
        num=file.readLine(44);
        number=num.toInt();
        hint.ID_y=number;
//        qDebug() <<"44  "<<number<<endl;
        num=file.readLine(45);
        number=num.toInt();
        shuffle.ID_x=number;
//        qDebug() <<"45  "<<number<<endl;
        num=file.readLine(46);
        number=num.toInt();
        shuffle.ID_y=number;
//        qDebug() <<"46  "<<number<<endl;
        num=file.readLine(47);
        number=num.toInt();
        flash.ID_x=number;
//        qDebug() <<"47  "<<number<<endl;
        num=file.readLine(48);
        number=num.toInt();
        flash.ID_y=number;
//        qDebug() <<"48  "<<number<<endl;
        num=file.readLine(49);
        number=num.toInt();
        mark=number;
//        qDebug() <<"49  "<<number<<endl;
        num=file.readLine(50);
        number=num.toInt();
        t=number;
//        qDebug() <<"50  "<<number<<endl;
        num=file.readLine(51);
        number=num.toInt();
        x=number;
//        qDebug() <<"51  "<<number<<endl;
        num=file.readLine(52);
        number=num.toInt();
        y=number;
//        qDebug() <<"52  "<<number<<endl;
    }
    is_loading=true;
}

//
//判断是否可以不经过折线连接
//
bool signal_game_window::straightLinkMatch(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 && y1 == y2) return false;
    bool okFlag = true;
    int max,min;
    if(x1 == x2)
    {
        if(y1 > y2){
            max = y1; min = y2;
        }
        else{
            max = y2; min = y1;
        }
        for(int i = min + 1; i < max; ++i){
            if(p[i].ID_x> 0) okFlag = false;
        }
        if(okFlag) return true;
    }

    if(y1 == y2){
        if(x1 > x2){
            max = x1; min = x2;
        }
        else{
            max = x2; min = x1;
        }
        for(int i = min + 1; i < max; ++i){
            if(p[i].ID_x> 0) okFlag = false;
        }
        if(okFlag) return true;
    }

    return false;
}

bool signal_game_window::LinkMatch(int x1, int y1, int x2, int y2, bool flag)
{
    //判断能否直线连接
    bool okFlag;
    okFlag = straightLinkMatch(x1,y1,x2,y2);
    int numOfImportantPoints;
    point ImportantPoints[3];
    if(okFlag)
    {
        if(flag){
            numOfImportantPoints = 2;
            //std::cout<<"ImportantPoints in map.cpp "<<numOfImportantPoints<<std::endl;
            ImportantPoints[0] = first;
            ImportantPoints[1] = second;
        }
        //std::cout<<" numOfImportantPoints "<<numOfImportantPoints<<std::endl;
        return true;
    }
    //判断能否只用一次折线连接，折线拐点的横纵坐标分别与两个输入点相同
    if(x1 == x2||y1 == y2)
    {
        //属于直线相连情况，不做处理
    }
    else
    {
        int x = x1, y = y2;
        okFlag = straightLinkMatch(x1,y1,x,y) && straightLinkMatch(x2,y2,x,y) ;
        if(okFlag)
        {
            if(flag)
            {
                numOfImportantPoints = 3;
                //std::cout<<"ImportantPoints in map.cpp "<<numOfImportantPoints<<std::endl;
                ImportantPoints[0] = first;
                ImportantPoints[1].ID_x =first.ID_x ;
                ImportantPoints[1].ID_y =second.ID_y ;
                ImportantPoints[2] = second;
            }
            //std::cout<<" numOfImportantPoints "<<numOfImportantPoints<<std::endl;
        }
    }
}

signal_game_window::~signal_game_window()
{
    delete ui;
}
