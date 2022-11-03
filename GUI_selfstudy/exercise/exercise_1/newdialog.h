#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QWidget>

class newdialog : public QWidget
{
    Q_OBJECT
public:
    explicit newdialog(QWidget *parent = nullptr);
    void openwindow();
    void closewindow();
    QWidget newwindow;
signals:

};

#endif // NEWDIALOG_H
