#ifndef LINKSTARTMENU_H
#define LINKSTARTMENU_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "linkwindow.h"

class LinkStartmenu : public QWidget
{
    Q_OBJECT
public:
    explicit LinkStartmenu(QWidget *parent = nullptr);
    ~LinkStartmenu();

private:
    LinkWindow *window;
    QLabel *titleLabel;
    QPushButton *startButton;
    QPushButton *start2Button;
    QPushButton *readButton;
    QPushButton *exitButton;

private slots:
    void startGame();
};

#endif // LINKSTARTMENU_H
