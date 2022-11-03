#ifndef LINKBOX_H
#define LINKBOX_H

class LinkBox
{
public:
    int type;                           // -1 -- null, 0 -- apple, 1 -- banana, 2 -- orange
    int toolType;                       // 0 -- null, 1 -- +1s, 2 -- shuffle, 3 -- hint, 4 -- flash
    bool isActive;
    bool isSelected;

    LinkBox() {isActive = isSelected = false; toolType = 0; type = -1;}
    int x() {return boxX;}
    int y() {return boxY;}
    void setLocation(int x, int y){boxX = x, boxY = y;}
    void swap(LinkBox &box);

private:
    int boxX;
    int boxY;
};

#endif // LINKBOX_H
