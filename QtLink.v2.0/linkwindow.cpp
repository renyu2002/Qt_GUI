#include "linkwindow.h"

#include <QGridLayout>

LinkWindow::LinkWindow(QWidget *parent)
    : QWidget(parent)
{
    map = new LinkMap;
    msgLabel = new QLabel(tr("QLink"));
    timeLabel = new QLabel(tr("时间："));
    scoreLabel = new QLabel(tr("玩家一分数"));
    score2Label = new QLabel(tr("玩家二分数"));
    timeLcd = new QLCDNumber(3);
    scoreLcd = new QLCDNumber(3);
    score2Lcd = new QLCDNumber(3);
    pauseButton = new QPushButton(tr("暂停/继续"));
    saveButton = new QPushButton(tr("保存游戏"));
    readButton = new QPushButton(tr("读取存档"));
    restartButton = new QPushButton(tr("重新开始"));
    backButton = new QPushButton(tr("返回主菜单"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(map, 0, 0, 9, 5);
    layout->addWidget(msgLabel, 0, 5, 1, 3);
    layout->addWidget(timeLabel, 1, 5);
    layout->addWidget(timeLcd, 1, 6, 1, 2);
    layout->addWidget(scoreLabel, 2, 5);
    layout->addWidget(scoreLcd, 2, 6, 1, 2);
    layout->addWidget(score2Label, 3, 5);
    layout->addWidget(score2Lcd, 3, 6, 1, 2);
    layout->addWidget(pauseButton, 4, 5, 1, 3);
    layout->addWidget(saveButton, 5, 5, 1, 3);
    layout->addWidget(readButton, 6, 5, 1, 3);
    layout->addWidget(restartButton, 7, 5, 1, 3);
    layout->addWidget(backButton, 8, 5, 1, 3);
    setLayout(layout);

    connect(map, SIGNAL(sendMsg(const QString &)), msgLabel, SLOT(setText(const QString &)));
    connect(map, SIGNAL(timeChanged(int)), timeLcd, SLOT(display(int)));
    connect(map, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(map, SIGNAL(score2Changed(int)), score2Lcd, SLOT(display(int)));
    connect(pauseButton, SIGNAL(clicked()), map, SLOT(pause()));
    connect(saveButton, SIGNAL(clicked()), map, SLOT(save()));
    connect(readButton, SIGNAL(clicked()), map, SLOT(read()));
    connect(restartButton, SIGNAL(clicked()), map, SLOT(restart()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(backButton, SIGNAL(clicked()), this, SIGNAL(back()));
    connect(this, SIGNAL(startGame()), map, SLOT(start()));
    connect(this, SIGNAL(start2Game()), map, SLOT(start2()));
    connect(this, SIGNAL(readGame()), map, SLOT(read()));

    msgLabel->setAlignment(Qt::AlignCenter);
    msgLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    msgLabel->setStyleSheet("QLabel{border:1px solid}");
    timeLcd->display(100);

    QSizePolicy sp = map->sizePolicy();
    sp.setVerticalPolicy(QSizePolicy::Fixed);
    sp.setHorizontalPolicy(QSizePolicy::Fixed);
    map->setSizePolicy(sp);
    setStyleSheet("QWidget{background: rgb(240, 240, 240)}");
    setWindowTitle(tr("QLink"));
    resize(530, 400);
}

LinkWindow::~LinkWindow()
{
    delete map;
}


