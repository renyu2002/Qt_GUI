#ifndef LINKPLAYER_H
#define LINKPLAYER_H

#include <QVector>
#include "linkbox.h"

class LinkPlayer
{
public:
    QVector<LinkBox*> selectedBox;
    int selectedBoxNum;
    bool isPlayer2;

    LinkPlayer();
    ~LinkPlayer();
    int x() const { return playerX; }
    int y() const { return playerY; }
    int getScore() const { return score; }
    void setX(int xx) { playerX = xx; }
    void setY(int yy) { playerY = yy; }
    void move(int xx, int yy) { playerX = xx, playerY = yy; }
    void moveUp() { --playerY; }
    void moveDown() { ++playerY; }
    void moveLeft() { --playerX; }
    void moveRight() { ++playerX; }
    void addScore() { score += 10; }
    void setScore(int ss) { score = ss; }
    void clear();

private:
    int playerX;
    int playerY;
    int score;
};

#endif // LINKPLAYER_H
