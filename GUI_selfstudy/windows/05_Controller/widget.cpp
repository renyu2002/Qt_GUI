#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButton1->setChecked(true);
    ui->radioButton3->setChecked(true);

    //选中女后触发信息
    connect(ui->radioButton2,&QRadioButton::clicked,[=](){
       qDebug() <<"选中的是女人";
    });

    //利用listwediget写诗
    QListWidgetItem *item =new QListWidgetItem("shi");
    QStringList list;
    list <<"a"<<"s"<<"c";
    //将一行诗放入list空间中
    ui->listWidget->addItem(item);

    item->setTextAlignment(0x0004);

    //QStringLists QList<QString>
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

