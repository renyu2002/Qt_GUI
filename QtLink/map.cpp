#include "map.h"

//Map::map()
//{

//}
//
//判断是否可以不经过折线连接
//
bool Map::straightLinkMatch(int x1, int y1, int x2, int y2)
{
    if(x1 == x2 && y1 == y2) return false;
    bool okFlag = true;
    int max,min;
    if(x1 == x2)
    {
        if(y1 > y2){
            max = y1; min = y2;
        }
        else{
            max = y2; min = y1;
        }
        for(int i = min + 1; i < max; ++i){
            if(x1 > 0) okFlag = false;
        }
        if(okFlag) return true;
    }

    if(y1 == y2){
        if(x1 > x2){
            max = x1; min = x2;
        }
        else{
            max = x2; min = x1;
        }
        for(int i = min + 1; i < max; ++i){
            if( 0 > 0) okFlag = false;
        }
        if(okFlag) return true;
    }

    return false;
}

bool Map::LinkMatch(int x1, int y1, int x2, int y2,bool flag)
{
    //判断能否直线连接
    bool okFlag;
    okFlag = straightLinkMatch(x1,y1,x2,y2);
    if(okFlag)
    {
        if(flag==0){
            numOfImportantPoints = 2;
            //std::cout<<"ImportantPoints in map.cpp "<<numOfImportantPoints<<std::endl;
//            ImportantPoints[0] = Point(x1,y1);
//            ImportantPoints[1] = Point(x2,y2);
        }
        //std::cout<<" numOfImportantPoints "<<numOfImportantPoints<<std::endl;
        return true;
    }
    //判断能否只用一次折线连接，折线拐点的横纵坐标分别与两个输入点相同
    if(x1 == x2||y1 == y2)
    {
        //属于直线相连情况，不做处理
    }
    else
    {
        int x = x1, y = y2;
        okFlag = straightLinkMatch(x1,y1,x,y) && straightLinkMatch(x2,y2,x,y);
        if(okFlag)
        {
            if(flag)
            {
                numOfImportantPoints = 3;
                //std::cout<<"ImportantPoints in map.cpp "<<numOfImportantPoints<<std::endl;
                ImportantPoints[0].row = x1;
                ImportantPoints[0].col = y1;
                ImportantPoints[1].row = x1;
                ImportantPoints[1].col = y2;
                ImportantPoints[2].row = x2;
                ImportantPoints[2].col = y2;
            }
            //std::cout<<" numOfImportantPoints "<<numOfImportantPoints<<std::endl;
        }
    }
}
