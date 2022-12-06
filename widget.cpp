#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.5f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
};

void Widget::paintGL(){

};

void Widget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
};
