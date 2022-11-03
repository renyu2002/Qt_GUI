#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Mypushbutton(QPushButton *parent = nullptr);

    ~Mypushbutton();

signals:

};

#endif // MYPUSHBUTTON_H
