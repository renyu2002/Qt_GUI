#ifndef MAINSCENSE_H
#define MAINSCENSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScense; }
QT_END_NAMESPACE

class MainScense : public QMainWindow
{
    Q_OBJECT

public:
    MainScense(QWidget *parent = nullptr);
    ~MainScense();

private:
    Ui::MainScense *ui;
};
#endif // MAINSCENSE_H
