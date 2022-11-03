#include "double_game_window.h"
#include "ui_double_game_window.h"
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

double_game_window::double_game_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::double_game_window)
{
    ui->setupUi(this);
    this->setFixedSize(1000,1000);
    this->setWindowTitle("双人模式");
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
            if (mark1>mark2){
                label->setText("player1 win.");
                label->move(30,30);}
            if (mark1<mark2){
                label->setText("player2 win.");
                label->move(30,30);}
            if (mark1==mark2){
                label->setText("draw");
                label->move(30,30);}
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
        choose1();
        Tools();
        whether_is_same1();
        if(FIRST1!=-1&&SECOND1!=-1){
            if(issame1==true)
            {
                p[FIRST1].ID_x=0;
                p[FIRST1].ID_y=0;
                p[SECOND1].ID_x=0;
                p[SECOND1].ID_y=0;
                first1.ID_x=0;
                first1.ID_y=0;
                second1.ID_x=0;
                second1.ID_y=0;
                s1=0;
                d1=0;
                FIRST1=-1;
                SECOND1=-1;
//                qDebug()<<"true";
                mark1++;
                QString num1 = QString::number(mark1);
                ui->scores1->setText(num1);
            }
            else
            {
                first1.ID_x=0;
                first1.ID_y=0;
                second1.ID_x=0;
                second1.ID_y=0;
                s1=0;
                d1=0;
                FIRST1=-1;
                SECOND1=-1;
//                qDebug()<<"false";
            }
        }
        choose2();
        Tools();
        whether_is_same2();
        if(FIRST2!=-1&&SECOND2!=-1){
            if(issame2==true)
            {
                p[FIRST2].ID_x=0;
                p[FIRST2].ID_y=0;
                p[SECOND2].ID_x=0;
                p[SECOND2].ID_y=0;
                first2.ID_x=0;
                first2.ID_y=0;
                second2.ID_x=0;
                second2.ID_y=0;
                s2=0;
                d2=0;
                FIRST2=-1;
                SECOND2=-1;
//                qDebug()<<"true";
                mark2++;
                QString num2 = QString::number(mark2);
                ui->scores2->setText(num2);
            }
            else
            {
                first2.ID_x=0;
                first2.ID_y=0;
                second2.ID_x=0;
                second2.ID_y=0;
                s2=0;
                d2=0;
                FIRST2=-1;
                SECOND2=-1;
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
        /////////////////////////////freeze的坐标//////////////////////////////////////////
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
                freeze.ID_x=a+1;
                freeze.ID_y=b+2;
            }
        }
        /////////////////////////////dizzy的坐标////////////////////////////////////////////
        {//    for (int var = 0; var < 20; ++var) {
        //            int j=0;
        //            int a = qrand()%10;
        //            int b = qrand()%9;
        //            for (int i=0;i<20;i++){
        //                if(a+1==p[i].ID_x&&b+2==p[i].ID_y){
        //                    j=j+1;
        //                }
        //            }
        //            if(a+1==hint.ID_x&&b+2==hint.ID_y) j++;
        //            if(a+1==ones.ID_x&&b+2==ones.ID_y) j++;
        //            if(a+1==shuffle.ID_x&&b+2==shuffle.ID_y) j++;
        //            if(a+1==freeze.ID_x&&b+2==freeze.ID_y) j++;
        //            if(j==0){
        //                dizzy.ID_x=a+1;
        //                dizzy.ID_y=b+2;
        //            }
        //        }
        }
        /////////////////////////帮助按钮////////////////////////////////////////////////
        connect(ui->help,&QPushButton::clicked,[=]()
        {
            QDialog *dlg=new QDialog(this);
            dlg->setFixedSize(584,617);
            dlg->setWindowTitle("帮助");
            dlg->setWindowIcon(QIcon(":/new/prefix1/resourse/window_Icon.jpg"));
            QLabel *label=new QLabel(dlg);
            label->setPixmap(QPixmap(":/new/prefix1/resourse/double_game_mode_help.jpg"));
            dlg->exec();
        });
        /////////////////////////////生成RPG角色坐标//////////////////////////////////////////////

        {
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
                if(a+1==freeze.ID_x&&b+2==freeze.ID_y) j++;
                //        if(a+1==dizzy.ID_x&&b+2==dizzy.ID_y) j++;
                if(j==0){
                    x1=a+1;
                    y1=b+2;
                    ok=true;
                }
            }
            ok=false;
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
                if(a+1==freeze.ID_x&&b+2==freeze.ID_y) j++;
                //                    if(a+1==dizzy.ID_x&&b+2==dizzy.ID_y) j++;
                if(a+1==x1&&b+2==y1) j++;
                if(j==0){
                    x2=a+1;
                    y2=b+2;
                    ok=true;
                }
            }
        }
    }
}
//判断player1选中的是否相同
void double_game_window ::whether_is_same1()
{
    if(FIRST1%2==0&&SECOND1%2==1)
    {
        d1=FIRST1,s1=SECOND1;
    }
    else issame1=false;
    if(FIRST1%2==1&&SECOND1%2==0)
    {
        s1=FIRST1,d1=SECOND1;
    }
    else issame1=false;

    if( s1==d1+1){
        issame1=true;
    }
    else{
        issame1=false;
    }
//    qDebug() <<"is running"<<endl;
//    qDebug()<<"signal="<<s<<endl;
//    qDebug()<<"double="<<d<<endl;
}

//判断player2选中的是否相同
void double_game_window ::whether_is_same2()
{
    if(FIRST2%2==0&&SECOND2%2==1)
    {
        d2=FIRST2,s2=SECOND2;
    }
    else issame2=false;
    if(FIRST2%2==1&&SECOND2%2==0)
    {
        s2=FIRST2,d2=SECOND2;
    }
    else issame2=false;

    if( s2==d2+1){
        issame2=true;
    }
    else{
        issame2=false;
    }
//    qDebug() <<"is running"<<endl;
//    qDebug()<<"signal="<<s<<endl;
//    qDebug()<<"double="<<d<<endl;
}

//上下左右移动
void double_game_window::keyPressEvent(QKeyEvent *event)
{
    if(can_be_move1==true)
    {
        if(event->key()==Qt::Key_W)
        {
            y1=y1-1;
        }
        if(event->key()==Qt::Key_A)
        {
            x1=x1-1;
        }
        if(event->key()==Qt::Key_S)
        {
            y1=y1+1;
        }
        if(event->key()==Qt::Key_D)
        {
            x1=x1+1;
        }
    }
    if(can_be_move2==true)
    {
        if(event->key()==Qt::Key_I)
        {
            y2=y2-1;
        }
        if(event->key()==Qt::Key_J)
        {
            x2=x2-1;
        }
        if(event->key()==Qt::Key_K)
        {
            y2=y2+1;
        }
        if(event->key()==Qt::Key_L)
        {
            x2=x2+1;
        }
    }
}

//判断player1选中了哪个圆
void double_game_window :: choose1()
{
    if (first1.ID_x==0&&first1.ID_y==0){
        for (int var=0;var<20;var++) {
            if(x1==p[var].ID_x){
                if(y1==p[var].ID_y){
                    first1.ID_x=x2;
                    first1.ID_y=y2;
                    FIRST1=var;
//                    qDebug() <<"first:"<<FIRST<<endl;
                };
            };
        };
    }
    else {
        if(first1.ID_x!=x1||first1.ID_y!=y1){
            if(second1.ID_x==0&&second1.ID_y==0){
                for (int var=0;var<20;var++) {
                    if(x1==p[var].ID_x){
                        if(y1==p[var].ID_y){
                            second1.ID_x=x2;
                            second1.ID_y=y2;
                            SECOND1=var;
//                            qDebug() <<"second:"<<SECOND<<endl;
                        };
                    };
                };
            };
        };
    }
}

//判断player2选中了哪个圆
void double_game_window :: choose2()
{
    if (first2.ID_x==0&&first2.ID_y==0){
        for (int var=0;var<20;var++) {
            if(x2==p[var].ID_x){
                if(y2==p[var].ID_y){
                    first2.ID_x=x2;
                    first2.ID_y=y2;
                    FIRST2=var;
//                    qDebug() <<"first:"<<FIRST<<endl;
                };
            };
        };
    }
    else {
        if(first2.ID_x!=x2||first2.ID_y!=y2){
            if(second2.ID_x==0&&second2.ID_y==0){
                for (int var=0;var<20;var++) {
                    if(x2==p[var].ID_x){
                        if(y2==p[var].ID_y){
                            second2.ID_x=x2;
                            second2.ID_y=y2;
                            SECOND2=var;
//                            qDebug() <<"second:"<<SECOND<<endl;
                        };
                    };
                };
            };
        };
    }
}

//画图
void double_game_window :: paintEvent(QPaintEvent *ev)
{
    QPainter player(this);
    QPen pen(QColor(255,0,0));
    player.setPen(pen);
    //画RPG角色
    player.drawEllipse(QPoint(x1*100-50,y1*100-50),50,50);
    pen.setColor(QColor(0,0,255));
    player.setPen(pen);
    player.drawEllipse(QPoint(x2*100-50,y2*100-50),50,50);
    pen.setColor(QColor(255,255,255));
    player.setPen(pen);
    for (int var=0;var<=20;var=var+2) {
        qsrand(var);
        int r=qrand()%25*10;
        int g=qrand()%25*10;
        int y=qrand()%25*10;
        //设置画刷
        QBrush brush (QColor(r,g,y));
        //让画家使用这根画刷
        player.setBrush(brush);
        //画出圆形
        player.drawEllipse(QPoint((p[var].ID_x*100-50),(p[var].ID_y*100-50)),50,50);
        player.drawEllipse(QPoint((p[var+1].ID_x*100-50),(p[var+1].ID_y*100-50)),50,50);
    }
    //画5个技能
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
    brush.setStyle(Qt::HorPattern);
    player.setBrush(brush);
    player.drawEllipse(QPoint((freeze.ID_x*100-50),(freeze.ID_y*100-50)),50,50);
//    brush.setStyle(Qt::VerPattern);
//    player.setBrush(brush);
//    player.drawEllipse(QPoint((dizzy.ID_x*100-50),(dizzy.ID_y*100-50)),50,50);
    QBrush brush1(QColor(30,144,255));
    player.setBrush(brush1);
    player.drawEllipse(QPoint((highlight1.ID_x*100-50),(highlight1.ID_y*100-50)),50,50);
    player.drawEllipse(QPoint((highlight2.ID_x*100-50),(highlight2.ID_y*100-50)),50,50);
}
//四个道具的实现
void double_game_window::Tools( )
{
//    +1s的实现
    if((x1==ones.ID_x&&y1==ones.ID_y)||(x2==ones.ID_x&&y2==ones.ID_y))
    {
        t=t+30;
        ones.ID_x=0;
        ones.ID_y=0;
    }
//    hint的实现
    if((x1==hint.ID_x&&y1==hint.ID_y)||(x2==hint.ID_x&&y2==hint.ID_y))
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
//    shuffle的实现
    if((x1==shuffle.ID_x&&y1==shuffle.ID_y)||(x2==shuffle.ID_x&&y2==shuffle.ID_y))
    {
        for (int var=0;var<20-(mark1+mark2)*2;var++) {
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
        for (int var=20-(mark1+mark2)*2;var<20;var++) {
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
    }
//    freeze的实现
    if(x1==freeze.ID_x&&y1==freeze.ID_y){
        QTimer *timerss=new QTimer(this);
        timerss->start(100);
        static int ms=0;
        connect(timerss,&QTimer::timeout,[=]()
        {
            ms=ms+1;
            if (ms<=30)
            {
                can_be_move2=false;
//                qDebug() <<"false";
            }
            else
            {
                can_be_move2=true;
                timerss->stop();
            }
        });
        freeze.ID_x=0;
        freeze.ID_y=0;
    }
    if(x2==freeze.ID_x&&y2==freeze.ID_y){
        QTimer *timersss=new QTimer(this);
        timersss->start(100);
        static int sm=0;
        connect(timersss,&QTimer::timeout,[=]()
        {
            sm= sm+1;
            if (sm<=30)
            {
                can_be_move1=false;
            }
            else
            {
                can_be_move1=true;
                timersss->stop();
            }
        });
        freeze.ID_x=0;
        freeze.ID_y=0;
    }
}
//保存
void double_game_window::save()
{

    QFile file("C:/Users/DELL/Desktop/GUI/QtLink/save/double_game_mode.txt");
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
        num_x=QString::number(freeze.ID_x);
        stream << num_x << endl;
        num_y=QString::number(freeze.ID_y);
        stream << num_y << endl;
        num_x=QString::number(mark1);
        stream << num_x << endl;
        num_x=QString::number(mark2);
        stream << num_x << endl;
        num_y=QString::number(t);
        stream << num_y << endl;
        num_x=QString::number(x1);
        stream << num_x << endl;
        num_y=QString::number(y1);
        stream << num_y << endl;
        num_x=QString::number(x2);
        stream << num_x << endl;
        num_y=QString::number(y2);
        stream << num_y << endl;
    }
    file.close();
}

//载入
void double_game_window::load()
{
    QFile file("C:/Users/DELL/Desktop/GUI/QtLink/save/double_game_mode.txt");
    if (file.open(QIODevice::ReadWrite)) //QIODevice::ReadWrite支持读写
    {for (int var=0;var<=40;var=var+2) {
            QString num=file.readLine(var);
            int number=num.toInt();
            p[var/2].ID_x=number;
//            qDebug() <<var<<"  "<<number<<endl;
            num=file.readLine(var+1);
            number=num.toInt();
            p[var/2].ID_y=number;
//            qDebug() <<var+1<<"  "<<number<<endl;
        }

        QString num=file.readLine(41);
        int number=num.toInt();
        ones.ID_x=number;
//            qDebug() <<"41  "<<number<<endl;
        num=file.readLine(42);
        number=num.toInt();
        ones.ID_y=number;
//            qDebug() <<"42  "<<number<<endl;
        num=file.readLine(43);
        number=num.toInt();
        hint.ID_x=number;
//            qDebug() <<"43  "<<number<<endl;
        num=file.readLine(44);
        number=num.toInt();
        hint.ID_y=number;
//            qDebug() <<"44  "<<number<<endl;
        num=file.readLine(45);
        number=num.toInt();
        shuffle.ID_x=number;
//            qDebug() <<"45  "<<number<<endl;
        num=file.readLine(46);
        number=num.toInt();
        shuffle.ID_y=number;
//            qDebug() <<"46  "<<number<<endl;
        num=file.readLine(47);
        number=num.toInt();
        freeze.ID_x=number;
//            qDebug() <<"47  "<<number<<endl;
        num=file.readLine(48);
        number=num.toInt();
        freeze.ID_y=number;
//            qDebug() <<"48  "<<number<<endl;
        num=file.readLine(49);
        number=num.toInt();
        mark1=number;
//            qDebug() <<"49  "<<number<<endl;
        num=file.readLine(50);
        number=num.toInt();
        mark2=number;
//            qDebug() <<"50  "<<number<<endl;
        num=file.readLine(51);
        number=num.toInt();
        t=number;
//            qDebug() <<"51  "<<number<<endl;
        num=file.readLine(52);
        number=num.toInt();
        x1=number;
//            qDebug() <<"52  "<<number<<endl;
        num=file.readLine(53);
        number=num.toInt();
        y1=number;
//            qDebug() <<"53  "<<number<<endl;
        num=file.readLine(54);
        number=num.toInt();
        x2=number;
//            qDebug() <<"54  "<<number<<endl;
        num=file.readLine(55);
        number=num.toInt();
        x2=number;
//            qDebug() <<"55  "<<number<<endl;
    }
    is_loading=true;
}

double_game_window::~double_game_window()
{
    delete ui;
}
