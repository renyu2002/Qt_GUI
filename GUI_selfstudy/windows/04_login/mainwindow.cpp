#include "mainwindow.h"
#include <QWidget>
#include "ui_mainwindow.h"
#include <QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("登录窗口");
    setWindowIcon(QIcon("C:/Users/DELL/Desktop/GUI/GUI_selfstudy/02_QtSourse/mysource/a.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

