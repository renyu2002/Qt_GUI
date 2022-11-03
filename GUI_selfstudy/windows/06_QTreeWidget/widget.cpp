#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //TreeWidget树控件使用

    //设置水平表头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"Q技能"<<"W技能"<<"E技能"<<"R技能");

    //创建栏目
    QTreeWidgetItem *item1=new QTreeWidgetItem(QStringList()<<"刺客");
    QTreeWidgetItem *item2=new QTreeWidgetItem(QStringList()<<"战士");
    QTreeWidgetItem *item3=new QTreeWidgetItem(QStringList()<<"辅助");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);

    //追加子节点
    QStringList hero1;
    hero1<<"剑圣"<<"阿尔法突袭"<<"冥想"<<"强化"<<"高原血统";
    QTreeWidgetItem *L1=new QTreeWidgetItem(hero1);
    item1->addChild(L1);
}

Widget::~Widget()
{
    delete ui;
}

