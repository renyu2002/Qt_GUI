#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>


class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    //鼠标进入事件
    void  enterEvent(QEvent *event);

    //鼠标离开事件
    void leaveEvent(QEvent *event);

    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);

    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *event);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent *ev);

signals:

};

#endif // MYLABEL_H
