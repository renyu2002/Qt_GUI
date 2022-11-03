#ifndef SIMPLETEST_H
#define SIMPLETEST_H
#include <QtTest/QtTest>
#include <QObject>

class simpletest
{
    Q_OBJECT
private slots :
    void case1_testcase();
    void case2_testcase();
public:
    simpletest();
};

#endif // SIMPLETEST_H
