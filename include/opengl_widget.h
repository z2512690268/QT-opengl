#ifndef OPENGL_WIDGET_H
#define OPENGL_WIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class OpenGLWidget : public QOpenGLWidget,
        protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

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
};

#endif // OPENGL_WIDGET_
