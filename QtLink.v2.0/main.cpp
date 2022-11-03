#include "linkstartmenu.h"
#include "linktest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    LinkTest *test = new LinkTest;
    QTest::qExec(test);
    delete test;

    QApplication a(argc, argv);
    LinkStartmenu menu;
    menu.show();
    return a.exec();
}
