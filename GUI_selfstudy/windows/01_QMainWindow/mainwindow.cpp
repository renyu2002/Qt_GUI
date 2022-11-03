#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口的大小
    resize(600,400);

    //菜单栏最多有一个
    //菜单栏的创建
    QMenuBar *bar= new QMenuBar;

    //将菜单栏放入到窗口中
    setMenuBar(bar);

    //创建菜单
    QMenu *fileMenu=bar->addMenu("文件");
    QMenu *editMenu=bar->addMenu("编辑");

    //创建菜单项
    QAction *newaction= fileMenu->addAction("新建");
    //添加分隔符
    fileMenu->addSeparator();
    QAction *openaction= fileMenu->addAction("打开");

    //工具栏
    //可以有多个
    QToolBar *toolbar=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolbar);

    //设置只允许左右停靠
   // toolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    //设置浮动操作
   // toolbar->setFloatable(false);

    //设置移动
    //总开关
    //toolbar->setMovable(false);

    //在工具栏中可以设置内容
    toolbar->addAction(newaction);
    toolbar->addSeparator();
    toolbar->addAction(openaction);

    //工具栏中添加一些控件
    QPushButton *button=new QPushButton;
    toolbar->addWidget(button);

    //状态栏
    //最多有一个
    QStatusBar*stBar= statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //放标签控件
    QLabel *lable=new QLabel("提示信息",this);
    stBar->addWidget(lable);
    QLabel *lable2=new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(lable2);

    //铆接部件 （浮动窗口） 可以有多个
    QDockWidget *dockwidget=new QDockWidget("浮动窗口");
    addDockWidget(Qt::BottomDockWidgetArea,dockwidget);
    //设置停靠区域，只允许上下
    dockwidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    //设置中心部件
    QTextEdit *edit=new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

