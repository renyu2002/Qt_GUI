#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <signal_game_window.h>
#include <double_game_window.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    signal_game_window *gamewindow1 = NULL;
    double_game_window *gamewindow2 = NULL;

    void paintEvent(QPaintEvent *event) override;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
