#include "mainscense.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScense w;
    w.show();
    return a.exec();
}
