#ifndef LINKMAP_H
#define LINKMAP_H

#include <QFrame>
#include <QVector>
#include "linkbox.h"
#include "linkplayer.h"

class LinkMap : public QFrame
{
    Q_OBJECT
public:
    QSize sizeHint() const override;
    explicit LinkMap(QWidget *parent = nullptr);
    ~LinkMap();

    static bool linkJudgement(int **a, int x1, int y1, int x2, int y2);    // 测试用

public slots:
    void start();
    void start2();  // 开始双人游戏
    void pause();
    void save();
    void read();
    void restart();

signals:
    void sendMsg(const QString &);    // 向消息框发送信息
    void timeChanged(const int time);
    void scoreChanged(const int score);
    void score2Changed(const int score);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    LinkBox** boxes;
    QVector<LinkBox*> highlightBoxes;    // 保存hint状态下高亮的box
    LinkPlayer *player;
    LinkPlayer *player2;
    int boxNum;
    const int M, N;
    int countdownTime;    // 剩余时间
    int remainHintTime;    // 剩余hint时间
    int remainFlashTime;    // 剩余flash时间
    QTimer *timer;
    QTimer *hintTimer;
    QTimer *flashTimer;
    bool isStarted;
    bool isPaused;
    bool isGameOver;
    bool isHinting;
    bool isFlashing;
    bool isDoublePlayerMode;

    void initialize(bool isDouble);
    void shuffle();
    void select(LinkBox *box, LinkPlayer *player);
    void drawSelectedBox(LinkBox *box, bool isPlayer2, QPainter &painter);
    void drawLines(LinkBox *box1, LinkBox *box2, int x0, int y0 , bool isPlayer2, QPainter &painter);
    void removeBox(LinkPlayer *player, QPainter &painter);
    void drawTool(LinkBox *box, QPainter &painter);
    void drawHighlignt(LinkBox *box1, LinkBox *box2, QPainter &painter);
    void useTool(int type);
    bool havePlayer(LinkBox *box);
    bool linkJudgement(LinkBox *box1, LinkBox *box2) const;
    bool linkJudgement(LinkBox *box1, LinkBox *box2, int& x0, int& y0) const;
    bool isAccessible(LinkBox *startBox, LinkBox *endBox, int &type);
    bool isSolvable(LinkPlayer *player);

private slots:
    void updateTime();
    void hintOver();
    void flashOver();
};

#endif // LINKMAP_H
