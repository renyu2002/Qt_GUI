#include "linkstartmenu.h"
#include <QGridLayout>

LinkStartmenu::LinkStartmenu(QWidget *parent) : QWidget(parent)
{
    window = new LinkWindow;
    titleLabel = new QLabel(tr("QLink"));
    startButton = new QPushButton(tr("单人游戏"));
    start2Button = new QPushButton(tr("双人游戏"));
    readButton = new QPushButton(tr("读取存档"));
    exitButton = new QPushButton(tr("退出游戏"));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(titleLabel, 0, 0, 1, 3);
    layout->addWidget(startButton, 1, 1, 1, 1);
    layout->addWidget(start2Button, 2, 1, 1, 1);
    layout->addWidget(readButton, 3, 1, 1, 1);
    layout->addWidget(exitButton, 4, 1, 1, 1);
    layout->setContentsMargins(0, 0, 0, 50);
    layout->setSpacing(20);
    setLayout(layout);

    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(startButton, SIGNAL(clicked()), window, SIGNAL(startGame()));
    connect(start2Button, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(start2Button, SIGNAL(clicked()), window, SIGNAL(start2Game()));
    connect(readButton, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(readButton, SIGNAL(clicked()), window, SIGNAL(readGame()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(window, SIGNAL(back()), this, SLOT(show()));

    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(QFont("Times", 32));

    setWindowTitle(tr("QLink"));
    resize(500, 400);
}

LinkStartmenu::~LinkStartmenu()
{
    delete window;
}

void LinkStartmenu::startGame()
{
    this->hide();
    window->show();
}
