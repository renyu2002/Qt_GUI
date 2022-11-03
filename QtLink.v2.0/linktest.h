#ifndef LINKTEST_H
#define LINKTEST_H

#include <QObject>
#include <QtTest/QtTest>

class LinkTest : public QObject
{
    Q_OBJECT
public:
    explicit LinkTest(QObject *parent = nullptr);

private slots:
    void case1_testcase();
    void case2_testcase();
};

#endif // LINKTEST_H
