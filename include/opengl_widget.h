#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QTouchEvent>
#include <QWindow>
#include <QGesture>
#include <QGestureEvent>
#include <QTapGesture>
#include <QPanGesture>
#include <QPinchGesture>
#include <QSwipeGesture>

class OpenGLWidget : public QOpenGLWidget,
        protected QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

protected:
    virtual bool event(QEvent *e) override;

private:
    void makeObject();
    void makeObject_2();
    void setVertexAttribute();
private:
    QOpenGLShaderProgram        *m_program;
    QOpenGLBuffer               m_vbo;
    int                         m_matrixUniform;
    QMatrix4x4                  m_pMat;
    QOpenGLVertexArrayObject    m_vao;
    QOpenGLBuffer               m_vbo_2;
    QOpenGLVertexArrayObject    m_vao_2;
    QMap<int,QPointF>           touches;
    float                       pinchScale;
};

#endif // OPENGL_WIDGET_
