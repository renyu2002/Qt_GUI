#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>

class Button : public QMainWindow
{
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    ~Button();
};
#endif // BUTTON_H
