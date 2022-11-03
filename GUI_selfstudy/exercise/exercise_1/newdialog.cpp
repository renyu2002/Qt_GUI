#include "newdialog.h"

newdialog::newdialog(QWidget *parent) : QWidget(parent)
{

}

void newdialog::openwindow()
{
    newwindow.show();
}

void newdialog::closewindow()
{
    newwindow.close();
}
