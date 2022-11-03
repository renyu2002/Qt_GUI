#ifndef DOUBLE_GAME_WINDOW_H
#define DOUBLE_GAME_WINDOW_H

#include <QWidget>
#include <QPoint>
#include <QBrush>
#include <QMouseEvent>

namespace Ui {
class double_game_window;
}
struct point2 : public QPoint
{
public:
    int ID_x=0;
    int ID_y=0;
};


class double_game_window : public QWidget
{
    Q_OBJECT

public:
    explicit double_game_window(QWidget *parent = nullptr);
    ~double_game_window();

    void paintEvent (QPaintEvent *ev) override;
    void keyPressEvent(QKeyEvent *event) override;
    int  x1 ,y1 ,x2 ,y2 ;
    point2 p[20];//全部的点
    point2 first1;//p1第一个选中的点
    int FIRST1=-1;//p1第一个选中的号
    point2 second1;//p1第二个选中的点
    int SECOND1=-1;//p1第二个选中的号
    int s1=0,d1=0;//p1选中的奇数号与偶数号
    void choose1();//判断p1选中了哪一个
    void whether_is_same1();//判断p1是否相同
    bool issame1;//p1是否相同
    point2 first2;//p2第一个选中的点
    int FIRST2=-1;//p2第一个选中的号
    point2 second2;//p2第二个选中的点
    int SECOND2=-1;//p2第二个选中的号
    int s2=0,d2=0;//p2选中的奇数号与偶数号
    void choose2();//判断p2选中了哪一个
    void whether_is_same2();//判断p2是否相同
    bool issame2;//p2是否相同
    int t=120;//游戏计时
    point2 ones;//+1s的位置
    point2 hint;//hint的位置
    point2 shuffle;//shuffl的位置
    point2 highlight1;//一号高光
    point2 highlight2;//二号高光
    point2 freeze;
    //    point2 dizzy;
    bool can_be_move1=true;
    bool can_be_move2=true;
    void Tools();//五大道具
    int mark1=0;//记录分数
    int mark2=0;//记录分数
    void save();
    void load();
    bool is_loading=false;

private:
    Ui::double_game_window *ui;
};

#endif // DOUBLE_GAME_WINDOW_H
