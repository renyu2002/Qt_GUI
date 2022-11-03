#include "linkplayer.h"


LinkPlayer::LinkPlayer()
    : selectedBoxNum(0), isPlayer2(false), playerX(-1), playerY(-1), score(0)
{
    selectedBox.resize(2);
    selectedBox[0] = selectedBox[1] = nullptr;
}

LinkPlayer::~LinkPlayer()
{
}

void LinkPlayer::clear()
{
    playerX = playerY = -1;
    score = 0;
    selectedBoxNum = 0;
    selectedBox[0] = selectedBox[1] = nullptr;
}



