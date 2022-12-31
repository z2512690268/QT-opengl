#include "loadpic.h"
#include "myimage.h"
#include <QPushButton>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>

float Mesh_x = 0;
float Mesh_y = 0;
float Mesh_z = 0;

float Camera_x = -0.0;
float Camera_y = 3.0;
float Camera_z = 6.0;


Loadpic::Loadpic(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    // MyImage *image = new MyImage(this);
    // MyImage *image2 = new MyImage(this);
    slider1 = new QSlider(Qt::Horizontal, this);
    label1 = new QLabel(this);
    label1->setText("mesh x: 0.0");
    slider2 = new QSlider(Qt::Horizontal, this);
    label2 = new QLabel(this);
    label2->setText("mesh y: 0.0");
    slider3 = new QSlider(Qt::Horizontal, this);
    label3 = new QLabel(this);
    label3->setText("mesh z: 0.0");
    slider4 = new QSlider(Qt::Horizontal, this);
    label4 = new QLabel(this);
    label4->setText("camera x: 0.0");
    slider5 = new QSlider(Qt::Horizontal, this);
    label5 = new QLabel(this);
    label5->setText("camera y: 3.0");
    slider6 = new QSlider(Qt::Horizontal, this);
    label6 = new QLabel(this);
    label6->setText("camera z: 6.0");
    
    layout->addWidget(label1);
    layout->addWidget(slider1);
    layout->addWidget(label2);
    layout->addWidget(slider2);
    layout->addWidget(label3);
    layout->addWidget(slider3);
    layout->addWidget(label4);
    layout->addWidget(slider4);
    layout->addWidget(label5);
    layout->addWidget(slider5);
    layout->addWidget(label6);
    layout->addWidget(slider6);

    slider1->setValue(0);
    slider1->setMinimum(-100);
    slider1->setMaximum(100);
    slider1->setSingleStep(1);
    slider2->setValue(0);
    slider2->setMinimum(-100);
    slider2->setMaximum(100);
    slider2->setSingleStep(1);
    slider3->setValue(0);
    slider3->setMinimum(-100);
    slider3->setMaximum(100);
    slider3->setSingleStep(1);

    slider4->setValue(0);
    slider4->setMinimum(-100);
    slider4->setMaximum(100);
    slider4->setSingleStep(1);
    slider5->setValue(30);
    slider5->setMinimum(-100);
    slider5->setMaximum(100);
    slider5->setSingleStep(1);
    slider6->setValue(60);
    slider6->setMinimum(-100);
    slider6->setMaximum(100);
    slider6->setSingleStep(1);

    // slots
    connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));
    connect(slider2, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));
    connect(slider3, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));
    connect(slider4, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));
    connect(slider5, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));
    connect(slider6, SIGNAL(valueChanged(int)), this, SLOT(SyncData()));


    setLayout(layout);
}

Loadpic::~Loadpic()
{
    delete slider1;
    delete slider2;
    delete slider3;
    delete slider4;
    delete slider5;
    delete slider6;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
}

void Loadpic::SyncData() {
    Mesh_x = slider1->value() / 10.0;
    Mesh_y = slider2->value() / 10.0;
    Mesh_z = slider3->value() / 10.0;
    Camera_x = slider4->value() / 10.0;
    Camera_y = slider5->value() / 10.0;
    Camera_z = slider6->value() / 10.0;
    label1->setText("mesh x: " + QString::number(Mesh_x));
    label2->setText("mesh y: " + QString::number(Mesh_y));
    label3->setText("mesh z: " + QString::number(Mesh_z));
    label4->setText("camera x: " + QString::number(Camera_x));
    label5->setText("camera y: " + QString::number(Camera_y));
    label6->setText("camera z: " + QString::number(Camera_z));
    qDebug() << "Mesh_x: " << Mesh_x << "Mesh_y: " << Mesh_y << "Mesh_z: " << Mesh_z;
    qDebug() << "Camera_x: " << Camera_x << "Camera_y: " << Camera_y << "Camera_z: " << Camera_z;
}
