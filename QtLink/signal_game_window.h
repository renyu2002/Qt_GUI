#ifndef MAIN_GAME_WINDOW_H
#define MAIN_GAME_WINDOW_H

#include <QWidget>
#include <QPoint>
#include <QBrush>
#include <QMouseEvent>

namespace Ui {
class signal_game_window;
}
struct point : public QPoint
{
public:
    int ID_x=0;
    int ID_y=0;
};

class signal_game_window : public QWidget
{
    Q_OBJECT

public:
    explicit signal_game_window(QWidget *parent = nullptr);
    ~signal_game_window();

    void paintEvent (QPaintEvent *ev) override;
    void keyPressEvent(QKeyEvent *event) override;
    int  x ,y ;
    point p[20];//全部的点
    point first;//第一个选中的点
    int FIRST=-1;//第一个选中的号
    point second;//第二个选中的点
    int SECOND=-1;//第二个选中的号
    int s=0,d=0;//奇数号与偶数号
    void choose();//判断选中了哪一个
    void whether_is_same();//判断是否相同
    bool issame;//是否相同
    int t=120;//游戏计时
    point ones;//+1s的位置
    point hint;//hint的位置
    point shuffle;//shuffl的位置
    point flash;//flash的位置
    point highlight1;//一号高光
    point highlight2;//二号高光
    void Tools();//四大道具
    int mark=0;//记录分数
    void mousePressEvent(QMouseEvent *ev) override;
    QMouseEvent *ev;
    point mouse;
    void save();
    void load();
    bool is_loading=false;
    bool straightLinkMatch(int x1, int y1, int x2, int y2);
    bool LinkMatch(int x1, int y1, int x2, int y2, bool flag);


private:
    Ui::signal_game_window *ui;
};


#endif // MAIN_GAME_WINDOW_H
