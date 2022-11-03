#include "mypushbutton.h"
#include <QDebug>

Mypushbutton::Mypushbutton(QPushButton *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮类构造调用";


}

Mypushbutton::~Mypushbutton()
{
    qDebug()<<"我的按钮类析构";
}
