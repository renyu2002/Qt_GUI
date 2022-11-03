#include "linktest.h"
#include "linkmap.h"

LinkTest::LinkTest(QObject *parent) : QObject(parent)
{

}

void LinkTest::case1_testcase()
{
    int **a = new int*[5];
    for(int i = 0; i < 5; ++i){
        a[i] = new int[4];
        for(int j = 0; j < 4; ++j)
            a[i][j] = -(i % 2);
    }

    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 0, 1) == true);
    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 2, 0) == true);
    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 0, 2) == true);
    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 2, 2) == true);
    QVERIFY(LinkMap::linkJudgement(a, 4, 1, 2, 0) == true);
    QVERIFY(LinkMap::linkJudgement(a, 4, 0, 0, 0) == true);
    QVERIFY(LinkMap::linkJudgement(a, 4, 1, 0, 0) == false);
}

void LinkTest::case2_testcase()
{
    int **a = new int*[5];
    for(int i = 0; i < 5; ++i){
        a[i] = new int[4];
        for(int j = 0; j < 4; ++j){
            a[i][0] = a[i][2] = 0;
            a[i][1] = -1;
            a[i][3] = 1;
        }
    }

    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 0, 2) == true);
    QVERIFY(LinkMap::linkJudgement(a, 0, 2, 0, 3) == false);
    QVERIFY(LinkMap::linkJudgement(a, 0, 0, 2, 2) == true);
    QVERIFY(LinkMap::linkJudgement(a, 3, 2, 1, 0) == true);
}


