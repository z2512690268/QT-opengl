#include "myimage.h"

MyImage::MyImage(QWidget *parent, QString path)
{
    image.load(path);
}

MyImage::~MyImage()
{

}

void MyImage::paintEvent(QPaintEvent *)
{
    int width=this->width();
    int height=this->height();

    QPainter painter(this);
    painter.save();
    //调整图片的大小，保持宽高比例
    image.scaled(width,height);
    

    //绘制出图片
    painter.drawImage(this->rect(),image);
    painter.restore();
    painter.setRenderHints(QPainter::Antialiasing|QPainter::TextAntialiasing);
//    painter.translate(width/2,height/2);

    //可以设置成正方形，最小的大小位200*200；
    int side = qMin(width,height);
    painter.scale(side/200,side/200);
}

void MyImage::setImage(QImage image)
{
    this->image=image;
    update();
}
