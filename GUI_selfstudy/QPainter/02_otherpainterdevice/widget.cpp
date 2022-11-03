#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QPicture>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //Pixmap绘图设备 专门为平台做了显示的优化
//    QPixmap pix(300,300);

//    //填充背景色

//    pix.fill(Qt::white);
//    //声明画家
//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150,150),100,100);

//    //保存
//    pix.save("E:\\pix.png");

//    //*/QImage绘图设备  可以对像素进行访问
//    QImage img(300,300,QImage::Format_ARGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150,150),100,100);
//   img.save("E:\\img.png");

   //QPicture 绘图设备 可以记录和重现绘图指令
   QPicture pic;
   QPainter painter;
   //开始向pic上画图
   painter.begin(&pic);
   painter.setPen(QPen(Qt::cyan));
   painter.drawEllipse(QPoint(50,50),50,50);

   //结束画画
   painter.end();

   //保存到磁盘
   pic.save("E:\\pic.ry");
}
void  Widget::paintEvent(QPaintEvent *)
{
//    QPainter painter(this);

//    //利用QImag对像素进行更改
//    QImage img;
//    img.load(":/new/prefix1/mysource/a.jpg");
//    painter.drawImage(0,0,img);

//    //修改像素点
//    for (int i=50;i<100;++i) {
//        for (int j=50;j<100;++j) {
//            QRgb value=qRgb(255,0,0);
//            img.setPixel(i,j,value);
//        }
//    }

    //重现QPicture的绘图指令
    QPainter painter(this);
    QPicture pic;
    pic.load("E:\\pic.ry");
    painter.drawPicture(0,0,pic);

}

Widget::~Widget()
{
    delete ui;
}

