#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"teacher.h"
#include"student.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Teacher *te;
    Student *st;

    void classisover1();
    void classisover2();
};
#endif // WIDGET_H
