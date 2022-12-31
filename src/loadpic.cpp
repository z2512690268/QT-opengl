#include "loadpic.h"
#include "myimage.h"
#include <QPushButton>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
Loadpic::Loadpic(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    MyImage *image = new MyImage(this);
    QPushButton *button = new QPushButton("Load Pic 1", this);
    MyImage *image2 = new MyImage(this);
    QPushButton *button2 = new QPushButton("Load Pic 2", this);
    QPushButton *button3 = new QPushButton("Generate Mesh", this);

    layout->addWidget(image);
    layout->addWidget(button);
    layout->addWidget(image2);
    layout->addWidget(button2);
    layout->addWidget(button3);

    // slots
    connect(button, &QPushButton::clicked, this, &loadPicFromFS);
    connect(button2, &QPushButton::clicked, this, &loadPicFromFS2);

    setLayout(layout);
}

void Loadpic::loadPicFromFS() {
    qDebug() << "Loadpic::loadPicFromFS()";
}
void Loadpic::loadPicFromFS2() {
    qDebug() << "Loadpic::loadPicFromFS2()";
}
