#include "linkbox.h"

void LinkBox::swap(LinkBox &box)
{
    int tmp = this->type;
    this->type = box.type;
    box.type = tmp;
    tmp = this->toolType;
    this->toolType = box.toolType;
    box.toolType = tmp;
    bool temp = this->isActive;
    this->isActive = box.isActive;
    box.isActive = temp;
}



