#ifndef OPEN_H
#define OPEN_H

#include <QWidget>

class open : public QWidget
{
    Q_OBJECT
public:
    explicit open(QWidget *parent = nullptr);
    void  openwindow();
signals:

};

#endif // OPEN_H
