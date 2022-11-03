#include "linkmap.h"

#include <QRandomGenerator>
#include <QPen>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QDataStream>

QSize LinkMap::sizeHint() const
{
    return QSize(50 * M + 100, 50 * N + 100);
}

LinkMap::LinkMap(QWidget *parent)
    : QFrame(parent), M(5), N(4), countdownTime(100),
      isStarted(false), isPaused(false), isGameOver(false), isHinting(false), isFlashing(false)
{
    setStyleSheet("QWidget{background:rgb(245, 245, 245)}");
    setFrameStyle(QFrame::Panel | QFrame::Sunken);
    setFocusPolicy(Qt::StrongFocus);

    boxes = new LinkBox* [M];
    boxNum = M * N;
    for(int i = 0; i < M; ++i){
        boxes[i] = new LinkBox[N];
        for(int j = 0; j < N; ++j){
            boxes[i][j].setLocation(i, j);
        }
    }

    highlightBoxes.resize(2);
    player = new LinkPlayer;
    player2 = new LinkPlayer;
    player2->isPlayer2 = true;
    isDoublePlayerMode = false;
    timer = new QTimer;
    timer->setInterval(1000);
    hintTimer = new QTimer(this);
    hintTimer->setSingleShot(true);
    flashTimer = new QTimer(this);
    flashTimer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(hintTimer, SIGNAL(timeout()), this, SLOT(hintOver()));
    connect(flashTimer, SIGNAL(timeout()), this, SLOT(flashOver()));
}

LinkMap::~LinkMap()
{
    for(int i = 0; i < M; ++i)
        delete [] boxes[i];
    delete [] boxes;
    delete player;
    delete player2;
}

bool LinkMap::linkJudgement(int **a, int x1, int y1, int x2, int y2)            // 测试用
{
    LinkBox boxes_test[5][4];
    if(a != nullptr){
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 4; ++j){
                boxes_test[i][j].type = a[i][j];
                if(a[i][j] == -1)  boxes_test[i][j].isActive = false;
                else boxes_test[i][j].isActive = true;
                boxes_test[i][j].toolType = 0;
                boxes_test[i][j].isSelected = false;
            }
        }
    }

    if(boxes_test[x1][y1].type != boxes_test[x2][y2].type)    return false;
                                                // 一次折线情况
    int tmpX = x1, tmpY = y1;
    do{                                         // x方向
        if(tmpX < x2) ++tmpX;
        else if(tmpX > x2) --tmpX;
        else if(tmpY < y2) ++tmpY;
        else if(tmpY > y2) --tmpY;
    }
    while(!boxes_test[tmpX][tmpY].isActive);
    if(tmpX == x2 && tmpY == y2){
        return true;
    }

    tmpX = x1, tmpY = y1;
    do{                                         // y方向
        if(tmpY < y2) ++tmpY;
        else if(tmpY > y2) --tmpY;
        else if(tmpX < x2) ++tmpX;
        else if(tmpX > x2) --tmpX;
    }
    while(!boxes_test[tmpX][tmpY].isActive);
    if(tmpX == x2 && tmpY == y2){
        return true;
    }
                                                // 两次折线情况
    for(int i = x1 - 1; i >= -1; --i){          // 向左
        if(i == -1){
            tmpX = 0;
            while(tmpX != x2 && !boxes_test[tmpX][y2].isActive)  ++tmpX;
            if(tmpX == x2){
                return true;
            }
        }
        else {
            if(boxes_test[i][y1].isActive)   break;
            tmpX = i, tmpY = y1;
            while(!boxes_test[tmpX][tmpY].isActive){
                if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
                else if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
            }
            if(tmpX == x2 && tmpY == y2){
                return true;
            }
        }
    }
    for(int i = x1 + 1; i <= 5; ++i){               // 向右
        if(i == 5){
            tmpX = 5 - 1;
            while(tmpX != x2 && !boxes_test[tmpX][y2].isActive)  --tmpX;
            if(tmpX == x2){
                return true;
            }
        }
        else {
            if(boxes_test[i][y1].isActive)   break;
            tmpX = i, tmpY = y1;
            while(!boxes_test[tmpX][tmpY].isActive){
                if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
                else if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
            }
            if(tmpX == x2 && tmpY == y2){
                return true;
            }
        }
    }
    for(int j = y1 - 1; j >= -1; --j){              // 向上
        if(j == -1){
            tmpY = 0;
            while(tmpY != y2 && !boxes_test[x2][tmpY].isActive)  ++tmpY;
            if(tmpY == y2){
                return true;
            }
        }
        else{
            if(boxes_test[x1][j].isActive)   break;
            tmpX = x1, tmpY = j;
            while(!boxes_test[tmpX][tmpY].isActive){
                if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
                else if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
            }
            if(tmpX == x2 && tmpY == y2){
                return true;
            }
        }
    }
    for(int j = y1 + 1; j <= 4; ++j){                   // 向下
        if(j == 4){
            tmpY = 4 - 1;
            while(tmpY != y2 && !boxes_test[x2][tmpY].isActive)  --tmpY;
            if(tmpY == y2){
                return true;
            }
        }
        else{
            if(boxes_test[x1][j].isActive)   break;
            tmpX = x1, tmpY = j;
            while(!boxes_test[tmpX][tmpY].isActive){
                if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
                else if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
            }
            if(tmpX == x2 && tmpY == y2){
                return true;
            }
        }
    }
    return false;
}

void LinkMap::start()
{
    initialize(false);
    while(!isSolvable(player))  shuffle();    // 打乱地图，保证初始状况可解

    setFocus();
    emit sendMsg(tr("开始游戏"));
    emit timeChanged(countdownTime);
    emit scoreChanged(player->getScore());
    timer->start();
    update();
}

void LinkMap::start2()
{
    do{
        initialize(true);
    }
    while(!isSolvable(player) && !isSolvable(player2));

    setFocus();
    emit sendMsg(tr("开始游戏"));
    emit timeChanged(countdownTime);
    emit scoreChanged(player->getScore());
    emit score2Changed(player2->getScore());
    timer->start();
    update();
}

void LinkMap::pause()
{
    if(!isStarted || isGameOver)  return;
    if(isPaused == false){
        isPaused = true;
        timer->stop();
        remainHintTime = hintTimer->remainingTime();
        remainFlashTime = flashTimer->remainingTime();
        hintTimer->stop();
        flashTimer->stop();
        emit sendMsg(tr("游戏暂停"));
    }
    else{
        isPaused = false;
        timer->start();
        if(remainHintTime != -1){
            hintTimer->start(remainHintTime);
            remainHintTime = -1;
        }
        if(remainFlashTime != -1){
            flashTimer->start(remainFlashTime);
            remainFlashTime = -1;
        }
        setFocus();
        emit sendMsg(tr("游戏继续"));
    }
    update();
}

void LinkMap::save()
{
    if(!isStarted || isGameOver) return;
    remainHintTime = hintTimer->remainingTime();
    remainFlashTime = flashTimer->remainingTime();

    QFile saveFile(tr("saveFile"));
    if(!saveFile.open(QIODevice::WriteOnly)){
        qDebug() << "Open file failed!";
        return;
    }
    QDataStream out(&saveFile);

    out << boxNum << countdownTime << isDoublePlayerMode;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            out << boxes[i][j].type << boxes[i][j].toolType << boxes[i][j].isActive << boxes[i][j].isSelected;
        }
    }
    out << player->x() << player->y() << player->getScore()<< player->selectedBoxNum;
    if(player->selectedBoxNum)  out << player->selectedBox[0]->x() << player->selectedBox[0]->y();
    else out << -1 << -1;
    out << isHinting << remainHintTime;
    out << isFlashing << remainFlashTime;

    if(isDoublePlayerMode){
        out << player2->x() << player2->y() << player2->getScore()<< player2->selectedBoxNum;
        if(player2->selectedBoxNum)  out << player2->selectedBox[0]->x() << player2->selectedBox[0]->y();
        else out << -1 << -1;
    }

    saveFile.close();
    sendMsg(tr("保存成功"));
    setFocus();
}

void LinkMap::read()
{
    int tmpX, tmpY, tmp;
    QFile saveFile(tr("saveFile"));
    if(!saveFile.open(QIODevice::ReadOnly)){
        sendMsg(tr("无存档"));
        return;
    }
    QDataStream in(&saveFile);

    in >> boxNum >> countdownTime >> isDoublePlayerMode;
    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            in >> boxes[i][j].type >> boxes[i][j].toolType >> boxes[i][j].isActive >> boxes[i][j].isSelected;
        }
    }

    in >> tmpX >> tmpY >> tmp;
    player->move(tmpX, tmpY);
    player->setScore(tmp);
    in >> player->selectedBoxNum;
    in >> tmpX >> tmpY;
    if(player->selectedBoxNum)  player->selectedBox[0] = &boxes[tmpX][tmpY];
    else player->selectedBox[0] = nullptr;

    in >> isHinting >> remainHintTime;
    in >> isFlashing >> remainFlashTime;

    if(isDoublePlayerMode){
        in >> tmpX >> tmpY >> tmp;
        player2->move(tmpX, tmpY);
        player2->setScore(tmp);
        in >> player2->selectedBoxNum;
        in >> tmpX >> tmpY;
        if(player2->selectedBoxNum)  player2->selectedBox[0] = &boxes[tmpX][tmpY];
        else player2->selectedBox[0] = nullptr;
    }

    saveFile.close();
    setFocus();
    emit sendMsg(tr("读取成功"));
    highlightBoxes[0] = highlightBoxes[1] = nullptr;
    isStarted = true;
    isPaused = false;
    isGameOver = false;
    emit timeChanged(countdownTime);
    emit scoreChanged(player->getScore());
    emit score2Changed(player2->getScore());
    timer->start();
    if(isHinting)  hintTimer->start(remainHintTime);
    if(isFlashing)  flashTimer->start(remainFlashTime);
    update();
}

void LinkMap::restart()
{
    if(isDoublePlayerMode)  start2();
    else start();
}

void LinkMap::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    painter.setWindow(0, 0, 50 * M + 100, 50 * N + 100);
    painter.translate(50, 50);
    QImage apple(":/images/apple.png");
    QImage banana(":/images/banana.png");
    QImage orange(":/images/orange.png");

    for(int i = 0; i < M + 1; ++i){                             // 画网格线
        painter.drawLine(50 * i, 0, 50 * i, 50 * N);
    }
    for(int i = 0; i < N + 1; ++i){
        painter.drawLine(0, 50 * i, 50 * M, 50 * i);
    }
    if(player->x() != -1 && player->y() != -1){                 // 画玩家一
        painter.save();
        painter.setBrush(QColor(235, 0, 0));
        painter.drawEllipse(50 * player->x(), 50 * player->y(), 50, 50);
        painter.restore();
    }
    if(isDoublePlayerMode && player2->x() != -1 && player2->y() != -1){         // 画玩家二
        painter.save();
        painter.setBrush(QColor(45, 95, 255));
        painter.drawEllipse(50 * player2->x(), 50 * player2->y(), 50, 50);
        painter.restore();
    }

    if(!isStarted)  return;

    for(int i = 0; i < M; ++i){                             // 画方块与道具
        for(int j = 0; j < N; ++j){
            if(boxes[i][j].toolType)   drawTool(&boxes[i][j], painter);
            if(!boxes[i][j].isActive)   continue;

            switch(boxes[i][j].type){
            case 0: painter.drawImage(50 * i, 50 * j, apple); break;
            case 1: painter.drawImage(50 * i, 50 * j, banana); break;
            case 2: painter.drawImage(50 * i, 50 * j, orange); break;
            default: qDebug() << "bad type number of box";
            }
        }
    }

    if(isPaused || isGameOver)    return;

    if(highlightBoxes[0] != nullptr && highlightBoxes[1] != nullptr){           // 画高亮方块
        if(highlightBoxes[0]->isActive && highlightBoxes[1]->isActive)
            drawHighlignt(highlightBoxes[0], highlightBoxes[1], painter);
        else highlightBoxes[0] = highlightBoxes[1] = nullptr;
    }

    if(player->selectedBoxNum == 2){                // 判定方块能否消除
        removeBox(player, painter);
        emit scoreChanged(player->getScore());
    }
    else if(player->selectedBoxNum == 1)    drawSelectedBox(player->selectedBox[0], false, painter);
    if(isDoublePlayerMode){
        if(player2->selectedBoxNum == 2){
            removeBox(player2, painter);
            emit score2Changed(player2->getScore());
        }
        else if(player2->selectedBoxNum == 1)    drawSelectedBox(player2->selectedBox[0], true, painter);
    }

    if(boxNum == 0){                // 若地图上无方块或地图无解，游戏结束
        timer->stop();
        hintTimer->stop();
        flashTimer->stop();
        isGameOver = true;
        if(isDoublePlayerMode){
            if(player->getScore() > player2->getScore())  emit sendMsg(tr("玩家一获胜"));
            else if(player->getScore() < player2->getScore())  emit sendMsg(tr("玩家二获胜"));
            else emit sendMsg(tr("平局"));
        }
        else emit sendMsg(tr("你胜利了"));
        return;
    }
    if(isDoublePlayerMode){
        if(!isSolvable(player) && !isSolvable(player2)){
            timer->stop();
            hintTimer->stop();
            isGameOver = true;
            emit sendMsg(tr("无解，游戏结束"));
        }
    }
    else if(!isSolvable(player)){
        timer->stop();
        hintTimer->stop();
        flashTimer->stop();
        isGameOver = true;
        emit sendMsg(tr("无解，游戏结束"));
    }
}

void LinkMap::keyPressEvent(QKeyEvent *event)
{
    if(!isStarted || isPaused || isGameOver){
        QFrame::keyPressEvent(event);
        return;
    }

    switch(event->key()){
    case Qt::Key_W:
        if(player->y() == 0)  break;
        if(havePlayer(&boxes[player->x()][player->y() - 1]))  break;
        if(boxes[player->x()][player->y() - 1].isActive){
            select(&boxes[player->x()][player->y() - 1], player);
            break;
        }
        player->moveUp();
        break;
    case Qt::Key_A:
        if(player->x() == 0)  break;
        if(havePlayer(&boxes[player->x() - 1][player->y()]))  break;
        if(boxes[player->x() - 1][player->y()].isActive){
            select(&boxes[player->x() - 1][player->y()], player);
            break;
        }
        player->moveLeft();
        break;
    case Qt::Key_S:
        if(player->y() == N - 1)  break;
        if(havePlayer(&boxes[player->x()][player->y() + 1]))  break;
        if(boxes[player->x()][player->y() + 1].isActive){
            select(&boxes[player->x()][player->y() + 1], player);
            break;
        }
        player->moveDown();
        break;
    case Qt::Key_D:
        if(player->x() == M - 1)  break;
        if(havePlayer(&boxes[player->x() + 1][player->y()]))  break;
        if(boxes[player->x() + 1][player->y()].isActive){
            select(&boxes[player->x() + 1][player->y()], player);
            break;
        }
        player->moveRight();
        break;

    case Qt::Key_Up:
        if(!isDoublePlayerMode)  break;
        if(player2->y() == 0)  break;
        if(havePlayer(&boxes[player2->x()][player2->y() - 1]))  break;
        if(boxes[player2->x()][player2->y() - 1].isActive){
            select(&boxes[player2->x()][player2->y() - 1], player2);
            break;
        }
        player2->moveUp();
        break;
    case Qt::Key_Left:
        if(!isDoublePlayerMode)  break;
        if(player2->x() == 0)  break;
        if(havePlayer(&boxes[player2->x() - 1][player2->y()]))  break;
        if(boxes[player2->x() - 1][player2->y()].isActive){
            select(&boxes[player2->x() - 1][player2->y()], player2);
            break;
        }
        player2->moveLeft();
        break;
    case Qt::Key_Down:
        if(!isDoublePlayerMode)  break;
        if(player2->y() == N - 1)  break;
        if(havePlayer(&boxes[player2->x()][player2->y() + 1]))  break;
        if(boxes[player2->x()][player2->y() + 1].isActive){
            select(&boxes[player2->x()][player2->y() + 1], player2);
            break;
        }
        player2->moveDown();
        break;
    case Qt::Key_Right:
        if(!isDoublePlayerMode)  break;
        if(player2->x() == M - 1)  break;
        if(havePlayer(&boxes[player2->x() + 1][player2->y()]))  break;
        if(boxes[player2->x() + 1][player2->y()].isActive){
            select(&boxes[player2->x() + 1][player2->y()], player2);
            break;
        }
        player2->moveRight();
        break;

    default: QFrame::keyPressEvent(event);
    }

    if(boxes[player->x()][player->y()].toolType){                   // 触发道具
        int tmp = boxes[player->x()][player->y()].toolType;
        boxes[player->x()][player->y()].toolType = 0;
        useTool(tmp);
    }
    if(isDoublePlayerMode && boxes[player2->x()][player2->y()].toolType){
        int tmp = boxes[player2->x()][player2->y()].toolType;
        boxes[player2->x()][player2->y()].toolType = 0;
        useTool(tmp);
    }
    update();
}

void LinkMap::mousePressEvent(QMouseEvent *event)
{
    if(isDoublePlayerMode)  return;
    if(isStarted && isFlashing && !isPaused && !isGameOver){
        int xx = event->x() / 50 - 1;
        int yy = event->y() / 50 - 1;
        int type;
        if(xx >= 0 && xx < M && yy >= 0 && yy < N && isAccessible(&boxes[player->x()][player->y()], &boxes[xx][yy], type)){
            if(boxes[xx][yy].isActive){
                switch(type){
                case 1:player->move(xx + 1, yy);
                    select(&boxes[xx][yy], player);
                    break;
                case 2:player->move(xx - 1, yy);
                    select(&boxes[xx][yy], player);
                    break;
                case 3:player->move(xx, yy + 1);
                    select(&boxes[xx][yy], player);
                    break;
                case 4:player->move(xx, yy - 1);
                    select(&boxes[xx][yy], player);
                    break;
                }
            }
            else player->move(xx, yy);

            if(boxes[player->x()][player->y()].toolType){                   // 触发道具
                int tmp = boxes[player->x()][player->y()].toolType;
                boxes[player->x()][player->y()].toolType = 0;
                useTool(tmp);
            }
            update();
        }
    }
}

void LinkMap::initialize(bool isDouble)
{
    countdownTime = 100;
    remainHintTime = -1;
    remainFlashTime = -1;
    isStarted = true;
    isPaused = false;
    isGameOver = false;
    isHinting = false;
    isFlashing = false;
    isDoublePlayerMode = false;
    boxNum = M * N;
    highlightBoxes[0] = highlightBoxes[1] = nullptr;
    isDoublePlayerMode = isDouble;

    int tmp;
    for(int i = 0; i < M; ++i){                     // 随机生成方块
        for(int j = 0; j < N; ++j){
            if(j % 2 == 0){
                boxes[i][j].type = boxes[i][j + 1].type = QRandomGenerator::global()->bounded(3);
                tmp = boxes[i][j].isActive = boxes[i][j + 1].isActive = QRandomGenerator::global()->bounded(3);
                if(tmp == 0)    boxNum -= 2;
                boxes[i][j].toolType = boxes[i][j + 1].toolType = 0;
                boxes[i][j].isSelected = boxes[i][j + 1].isSelected = false;
            }
        }
    }
    if(boxNum == M * N)  boxes[0][0].isActive = boxes[0][1].isActive = false;
    shuffle();

    int rx = QRandomGenerator::global()->bounded(M), ry = QRandomGenerator::global()->bounded(N);       // 随机人物初始位置
    player->clear();
    while(boxes[rx][ry].isActive){
        ++ry;
        if(ry >= N) { ry = 0; ++rx; }
        if(rx >= M) rx = 0;
    }
    player->move(rx, ry);
    if(isDouble){
        player2->clear();
        while(boxes[rx][ry].isActive || (rx == player->x() && ry == player->y())){
            ++ry;
            if(ry >= N) { ry = 0; ++rx; }
            if(rx >= M) rx = 0;
        }
        player2->move(rx, ry);
    }

    for(int i = 0; i < 3; ++i){                 // 随机生成道具
        rx = QRandomGenerator::global()->bounded(M), ry = QRandomGenerator::global()->bounded(N);
        if(boxes[rx][ry].isActive || havePlayer(&boxes[rx][ry]))  continue;
        else boxes[rx][ry].toolType = QRandomGenerator::global()->bounded(1, 5);
    }
}

void LinkMap::shuffle()
{
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j){
            boxes[i][j].isSelected = false;
            if(havePlayer(&boxes[i][j]))    continue;
            int rx = QRandomGenerator::global()->bounded(M);
            int ry = QRandomGenerator::global()->bounded(N);
            if(havePlayer(&boxes[rx][ry]))  continue;
            boxes[i][j].swap(boxes[rx][ry]);
        }

    player->selectedBox[0] = player->selectedBox[1] = nullptr;
    player->selectedBoxNum = 0;
    if(isDoublePlayerMode){
        player2->selectedBox[0] = player2->selectedBox[1] = nullptr;
        player2->selectedBoxNum = 0;
    }
    highlightBoxes[0] = highlightBoxes[1] = nullptr;
}

void LinkMap::select(LinkBox *box, LinkPlayer *player)
{
    if(box->isSelected)  return;
    if(player->selectedBoxNum){
        player->selectedBox[1] = box;
    }
    else{
        player->selectedBox[0] = box;
    }
    ++player->selectedBoxNum;
    box->isSelected = true;
}

void LinkMap::drawSelectedBox(LinkBox *box, bool isPlayer2, QPainter &painter)
{
    QColor selectedColor;
    if(isPlayer2)   selectedColor.setRgb(0, 0, 255);
    else    selectedColor.setRgb(225, 0, 0);
    QBrush selectedBrush(selectedColor, Qt::Dense3Pattern);
    QPen selectedPen(selectedColor);
    selectedPen.setWidth(2);

    painter.save();
    painter.setPen(selectedPen);
    painter.setBrush(selectedBrush);
    painter.drawRect(50 * box->x(), 50 * box->y(), 50, 50);
    painter.restore();
}

void LinkMap::drawLines(LinkBox *box1, LinkBox *box2, int x0, int y0, bool isPlayer2, QPainter &painter)        // 画方块消除时的连接线
{
    QColor selectedColor;
    if(isPlayer2)   selectedColor.setRgb(0, 0, 255);
    else    selectedColor.setRgb(225, 0, 0);
    QPen selectedPen(selectedColor);
    selectedPen.setWidth(3);

    painter.save();
    painter.setPen(selectedPen);
    if(y0 == -2){
        painter.drawLine(50 * box1->x() + 25, 50 * box1->y() + 25, 50 * x0 + 25, 50 * box1->y() + 25);
        painter.drawLine(50 * x0 + 25, 50 * box1->y() + 25, 50 * x0 + 25, 50 * box2->y() + 25);
        painter.drawLine(50 * x0 + 25, 50 * box2->y() + 25, 50 * box2->x() + 25, 50 * box2->y() + 25);
    }
    else{
        painter.drawLine(50 * box1->x() + 25, 50 * box1->y() + 25, 50 * box1->x() + 25, 50 * y0 + 25);
        painter.drawLine(50 * box1->x() + 25, 50 * y0 + 25, 50 * box2->x() + 25, 50 * y0 + 25);
        painter.drawLine(50 * box2->x() + 25, 50 * y0 + 25, 50 * box2->x() + 25, 50 * box2->y() + 25);
    }
    painter.restore();

    QTimer::singleShot(200, this, SLOT(update()));
}

void LinkMap::removeBox(LinkPlayer *player, QPainter &painter)
{
    int x0 = -1, y0 = -1;

    if(linkJudgement(player->selectedBox[0], player->selectedBox[1], x0, y0)){
        player->selectedBox[0]->isActive = false;
        player->selectedBox[1]->isActive = false;
        player->selectedBoxNum = 0;
        drawSelectedBox(player->selectedBox[0], player->isPlayer2, painter);
        drawSelectedBox(player->selectedBox[1], player->isPlayer2, painter);
        drawLines(player->selectedBox[0], player->selectedBox[1], x0, y0, player->isPlayer2, painter);
        player->selectedBox[0] = player->selectedBox[1] = nullptr;
        boxNum -= 2;
        player->addScore();
        if(isDoublePlayerMode){
            if(player->isPlayer2)  emit sendMsg(tr("玩家二消除"));
            else emit sendMsg(tr("玩家一消除"));
        }
        else emit sendMsg(tr("消除"));
    }
    else{
        player->selectedBox[0]->isSelected = player->selectedBox[1]->isSelected = false;
        player->selectedBox[0] = player->selectedBox[1] = nullptr;
        player->selectedBoxNum = 0;
        emit sendMsg(tr("不可消除"));
    }
}

void LinkMap::drawTool(LinkBox *box, QPainter &painter)
{
    switch(box->toolType){
    case 0: break;
    case 1: painter.drawText(50 * box->x(), 50 * box->y(), 50, 50, Qt::AlignCenter, tr("+1s")); break;
    case 2: painter.drawText(50 * box->x(), 50 * box->y(), 50, 50, Qt::AlignCenter, tr("shuffle")); break;
    case 3: painter.drawText(50 * box->x(), 50 * box->y(), 50, 50, Qt::AlignCenter, tr("hint")); break;
    case 4: painter.drawText(50 * box->x(), 50 * box->y(), 50, 50, Qt::AlignCenter, tr("flash")); break;
    }
}

void LinkMap::drawHighlignt(LinkBox *box1, LinkBox *box2, QPainter &painter)
{
    QPen highlightPen;
    highlightPen.setColor(QColor(150, 22, 230));
    highlightPen.setWidth(3);
    painter.save();
    painter.setPen(highlightPen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(50 * box1->x(), 50 * box1->y(), 50, 50);
    painter.drawRect(50 * box2->x(), 50 * box2->y(), 50, 50);
    painter.restore();
}

void LinkMap::useTool(int type)
{
    switch(type){
    case 0: break;
    case 1: countdownTime += 30;
        emit timeChanged(countdownTime);
        emit sendMsg(tr("获得道具，+1s"));
        break;
    case 2: shuffle();
        emit sendMsg(tr("获得道具shuffle"));
        break;
    case 3: isHinting = true;
        hintTimer->start(10000);
        emit sendMsg(tr("获得道具hint"));
        break;
    case 4: isFlashing = true;
        flashTimer->start(5000);
        emit sendMsg(tr("获得道具flash"));
        break;
    }
}

bool LinkMap::havePlayer(LinkBox *box)
{
    if(box->x() == player->x() && box->y() == player->y()) return true;
    if(isDoublePlayerMode && box->x() == player2->x() && box->y() == player2->y()) return true;
    else return false;
}

bool LinkMap::linkJudgement(LinkBox *box1, LinkBox *box2) const
{
    int tmp;
    return linkJudgement(box1, box2 , tmp, tmp);
}

bool LinkMap::linkJudgement(LinkBox *box1, LinkBox *box2, int &x0, int &y0) const
{
    int x1 = box1->x();
    int y1 = box1->y();
    int x2 = box2->x();
    int y2 = box2->y();

    if(boxes[x1][y1].type != boxes[x2][y2].type)    return false;
                                                //一次折线情况
    int tmpX = x1, tmpY = y1;
    do{
        if(tmpX < x2) ++tmpX;
        else if(tmpX > x2) --tmpX;
        else if(tmpY < y2) ++tmpY;
        else if(tmpY > y2) --tmpY;
    }
    while(!boxes[tmpX][tmpY].isActive);
    if(tmpX == x2 && tmpY == y2){
        x0 = x2, y0 = -2;
        return true;
    }

    tmpX = x1, tmpY = y1;
    do{
        if(tmpY < y2) ++tmpY;
        else if(tmpY > y2) --tmpY;
        else if(tmpX < x2) ++tmpX;
        else if(tmpX > x2) --tmpX;
    }
    while(!boxes[tmpX][tmpY].isActive);
    if(tmpX == x2 && tmpY == y2){
        x0 = -2, y0 = y2;
        return true;
    }
                                                //两次折线情况
    for(int i = x1 - 1; i >= -1; --i){
        if(i == -1){
            tmpX = 0;
            while(tmpX != x2 && !boxes[tmpX][y2].isActive)  ++tmpX;
            if(tmpX == x2){
                x0 = -1, y0 = -2;
                return true;
            }
        }
        else{
            if(boxes[i][y1].isActive)   break;
            tmpX = i, tmpY = y1;
            while(!boxes[tmpX][tmpY].isActive){
                if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
                else if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
            }
            if(tmpX == x2 && tmpY == y2){
                x0 = i, y0 = -2;
                return true;
            }
        }
    }
    for(int i = x1 + 1; i <= M; ++i){
        if(i == M){
            tmpX = M - 1;
            while(tmpX != x2 && !boxes[tmpX][y2].isActive)  --tmpX;
            if(tmpX == x2){
                x0 = M, y0 = -2;
                return true;
            }
        }
        else{
            if(boxes[i][y1].isActive)   break;
            tmpX = i, tmpY = y1;
            while(!boxes[tmpX][tmpY].isActive){
                if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
                else if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
            }
            if(tmpX == x2 && tmpY == y2){
                x0 = i, y0 = -2;
                return true;
            }
        }
    }
    for(int j = y1 - 1; j >= -1; --j){
        if(j == -1){
            tmpY = 0;
            while(tmpY != y2 && !boxes[x2][tmpY].isActive)  ++tmpY;
            if(tmpY == y2){
                x0 = -2, y0 = -1;
                return true;
            }
        }
        else{
            if(boxes[x1][j].isActive)   break;
            tmpX = x1, tmpY = j;
            while(!boxes[tmpX][tmpY].isActive){
                if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
                else if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
            }
            if(tmpX == x2 && tmpY == y2){
                x0 = -2, y0 = j;
                return true;
            }
        }
    }
    for(int j = y1 + 1; j <= N; ++j){
        if(j == N){
            tmpY = N - 1;
            while(tmpY != y2 && !boxes[x2][tmpY].isActive)  --tmpY;
            if(tmpY == y2){
                x0 = -2, y0 = N;
                return true;
            }
        }
        else{
            if(boxes[x1][j].isActive)   break;
            tmpX = x1, tmpY = j;
            while(!boxes[tmpX][tmpY].isActive){
                if(tmpX < x2) ++tmpX;
                else if(tmpX > x2) --tmpX;
                else if(tmpY < y2) ++tmpY;
                else if(tmpY > y2) --tmpY;
            }
            if(tmpX == x2 && tmpY == y2){
                x0 = -2, y0 = j;
                return true;
            }
        }
    }
    return false;
}

bool LinkMap::isAccessible(LinkBox *startBox, LinkBox *endBox, int &type)           // type: 1 -- 右侧， 2 -- 左侧， 3 -- 下侧， 4 -- 上侧
{
    if(startBox->x() == endBox->x() && startBox->y() == endBox->y())    return true;

    QVector<LinkBox *> vector;
    vector.append(startBox);
    LinkBox *tmp;
    int x0 = endBox->x(), y0 = endBox->y();
    int **visit;
    visit = new int*[M];
    for(int i = 0; i < M; ++i){
        visit[i] = new int [N];
        for(int j = 0; j < N; ++j)
            if(havePlayer(&boxes[i][j]))  visit[i][j] = 1;
            else visit[i][j] = 0;
    }

    while(!vector.isEmpty()){
        tmp = vector.takeLast();
        int x = tmp->x(), y = tmp->y();

        if(x != 0 && visit[x - 1][y] == 0){
            if(x - 1 == x0 && y == y0){
                type = 1;
                return true;
            }
            if(!boxes[x - 1][y].isActive)
                vector.append(&boxes[x - 1][y]);
            visit[x - 1][y] = 1;
        }
        if(x != M - 1 && visit[x + 1][y] == 0){
            if(x + 1 == x0 && y == y0){
                type = 2;
                return true;}
            if(!boxes[x + 1][y].isActive)
                vector.append(&boxes[x + 1][y]);
            visit[x + 1][y] = 1;
        }
        if(y != 0 && visit[x][y - 1] == 0){
            if(x == x0 && y - 1 == y0){
                type = 3;
                return true;}
            if(!boxes[x][y - 1].isActive)
                vector.append(&boxes[x][y - 1]);
            visit[x][y - 1] = 1;
        }
        if(y != N - 1 && visit[x][y + 1] == 0){
            if(x == x0 && y + 1 == y0){
                type = 4;
                return true;}
            if(!boxes[x][y + 1].isActive)
                vector.append(&boxes[x][y + 1]);
            visit[x][y + 1] = 1;
        }
    }
    return false;
}

bool LinkMap::isSolvable(LinkPlayer *player)
{
    if(!boxNum) return true;
    QVector<LinkBox *> accessibleBox;

    QList<LinkBox *> list;
    list.append(&boxes[player->x()][player->y()]);
    LinkBox *tmp;
    int **visit;
    visit = new int*[M];
    for(int i = 0; i < M; ++i){
        visit[i] = new int [N];
        for(int j = 0; j < N; ++j)
            if(havePlayer(&boxes[i][j]))  visit[i][j] = 1;
            else visit[i][j] = 0;
    }

    while(!list.isEmpty()){
        tmp = list.takeFirst();
        if(tmp->toolType == 2 && !isHinting)  return true;
        int x = tmp->x(), y = tmp->y();

        if(x != 0 && visit[x - 1][y] == 0){
            if(boxes[x - 1][y].isActive)
                accessibleBox.append(&boxes[x - 1][y]);
            else list.append(&boxes[x - 1][y]);
            visit[x - 1][y] = 1;
        }
        if(x != M - 1 && visit[x + 1][y] == 0){
            if(boxes[x + 1][y].isActive)
                accessibleBox.append(&boxes[x + 1][y]);
            else list.append(&boxes[x + 1][y]);
            visit[x + 1][y] = 1;
        }
        if(y != 0 && visit[x][y - 1] == 0){
            if(boxes[x][y - 1].isActive)
                accessibleBox.append(&boxes[x][y - 1]);
            else list.append(&boxes[x][y - 1]);
            visit[x][y - 1] = 1;
        }
        if(y != N - 1 && visit[x][y + 1] == 0){
            if(boxes[x][y + 1].isActive)
                accessibleBox.append(&boxes[x][y + 1]);
            else list.append(&boxes[x][y + 1]);
            visit[x][y + 1] = 1;
        }
    }

    while(!accessibleBox.isEmpty()){
        tmp = accessibleBox.takeFirst();
        for(int i = 0; i < accessibleBox.size(); ++i)
            if(linkJudgement(tmp, accessibleBox[i])){
                if(isHinting && highlightBoxes[0] == nullptr && highlightBoxes[1] == nullptr){
                    highlightBoxes[0] = tmp;
                    highlightBoxes[1] = accessibleBox[i];
                    update();
                }
                return true;
            }
    }
    return false;
}



void LinkMap::updateTime()
{
    --countdownTime;
    emit timeChanged(countdownTime);
    if(!countdownTime){
        timer->stop();
        isGameOver = true;
        emit sendMsg(tr("时间到，游戏结束"));
    }
}

void LinkMap::hintOver()
{
    if(!isHinting)  return;
    isHinting = false;
    highlightBoxes[0] = highlightBoxes[1] = nullptr;
    emit sendMsg(tr("hint时间结束"));
    update();
}

void LinkMap::flashOver()
{
    if(!isFlashing) return;
    isFlashing = false;
    emit sendMsg(tr("flash时间结束"));
}
