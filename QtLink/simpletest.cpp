#include "simpletest.h"
#include <map.h>
#include <QObject>
#include <QtTest/QtTest>
//SimpleTest::SimpleTest(QObject *parent) : QObject(parent)
//{

//}

//simpletest::SimpleTest(){

//}

void simpletest::case1_testcase(){
    Map map(1, 6, 6);
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            map.myMap[i][j] = i;
        }
    }
    //构造矩阵如下
    // [ [ 0, 0, 0, 0, 0, 0 ],
    //   [ 1, 1, 1, 1, 1, 1 ],
    //   [ 2, 2, 2, 2, 2, 2 ],
    //   [ 3, 3, 3, 3, 3, 3 ],
    //   [ 4, 4, 4, 4, 4, 4 ],
    //   [ 5, 5, 5, 5, 5, 5 ] ]

    QVERIFY(map.straightLinkMatch(1,1,1,4) == false);
    QVERIFY(map.straightLinkMatch(2,3,2,4) == true);
    QVERIFY(map.straightLinkMatch(3,2,3,3) == true);
    QVERIFY(map.LinkMatch(1,1,1,4,0) == true);
    QVERIFY(map.LinkMatch(2,1,2,4,0) == false);
    QVERIFY(map.LinkMatch(3,2,3,3,0) == true);
}

void simpletest::case2_testcase(){
    Map map(1, 6, 6);
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            map.myMap[i][j] = (i + j) % 2;
        }
    }
    map.myMap[2][2] = 2;
    map.myMap[1][2] = 0;
    //构造矩阵如下
    // [ [ 0, 1, 0, 1, 0, 1 ],
    //   [ 1, 0, 0, 0, 1, 0 ],
    //   [ 0, 1, 2, 1, 0, 1 ],
    //   [ 1, 0, 1, 0, 1, 0 ],
    //   [ 0, 1, 0, 1, 0, 1 ],
    //   [ 1, 0, 1, 0, 1, 0 ] ]

    QVERIFY(map.straightLinkMatch(1,0,1,4) == true);
    QVERIFY(map.straightLinkMatch(0,1,2,1) == true);
    QVERIFY(map.straightLinkMatch(0,3,4,3) == false);
    QVERIFY(map.straightLinkMatch(1,1,2,1) == true);
    QVERIFY(map.straightLinkMatch(1,1,1,3) == true);
    QVERIFY(map.straightLinkMatch(1,3,2,3) == true);
    QVERIFY(map.LinkMatch(2,1,1,4,0) == true);
    QVERIFY(map.LinkMatch(2,1,2,3,0) == true);
    QVERIFY(map.LinkMatch(2,1,0,3,0) == true);
    QVERIFY(map.LinkMatch(2,1,4,3,0) == false);
}


