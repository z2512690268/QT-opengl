#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QWidget>
#include <QPainter>
#include <QImage>

//使用painterevent，让图片随widget的大小自适应的调整
class MyImage:public QWidget
{
    Q_OBJECT

public:
    explicit MyImage(QWidget *parent = nullptr, QString path = ":/pic/pic/test.png");
    ~MyImage();
    void setImage(QImage image);
protected:
    void paintEvent(QPaintEvent *);
private:
    QImage image;
};






#endif // MYIMAGE_H
