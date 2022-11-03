#include "button.h"
#include "mypushbutton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Button w;
    w.show();
    return a.exec();
}
