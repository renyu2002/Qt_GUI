#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionnew->setIcon(QIcon("E:/a.jpg"));

    //使用添加Qt资源
    ui->actionnew->setIcon(QIcon(":/ /mysource/a.jpg"));
    ui->actionopen->setIcon(QIcon(":/ /mysource/resizeApi.jpg"));

    QPushButton *button=new QPushButton("按钮");
    ui->toolBar->addWidget(button);
    button->setIcon(QIcon(":/ /mysource/resizeApi2.jpg"));

    ui->pushButton->setIcon(QIcon(":/ /mysource/src=http___5b0988e595225.cdn.sohucs.com_images_20180125_318664736f1f41b8a3b7982c6bf9322f.jpeg&refer=http___5b0988e595225.cdn.sohucs.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

