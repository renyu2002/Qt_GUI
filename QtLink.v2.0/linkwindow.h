#ifndef LINKWINDOW_H
#define LINKWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include "linkmap.h"

class LinkWindow : public QWidget
{
    Q_OBJECT

public:
    LinkWindow(QWidget *parent = nullptr);
    ~LinkWindow();

signals:
    void startGame();
    void start2Game();
    void readGame();
    void back();

private:
    LinkMap *map;
    QLabel *msgLabel;
    QLabel *timeLabel;
    QLabel *scoreLabel;
    QLabel *score2Label;
    QLCDNumber *timeLcd;
    QLCDNumber *scoreLcd;
    QLCDNumber *score2Lcd;
    QPushButton *pauseButton;
    QPushButton *saveButton;
    QPushButton *readButton;
    QPushButton *restartButton;
    QPushButton *backButton;
};

#endif // LINKWINDOW_H
