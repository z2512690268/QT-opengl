#include "opengl_widget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      m_program(nullptr),
      m_vbo(QOpenGLBuffer::VertexBuffer),
      m_matrixUniform(0),
      m_pMat(),
      m_vao(),
      m_vbo_2(QOpenGLBuffer::VertexBuffer),
      m_vao_2()
{
}

OpenGLWidget::~OpenGLWidget()
{
    m_vbo.destroy();
    m_vbo_2.destroy();

    m_vao.destroy();
    m_vao_2.destroy();
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    makeCurrent();

    m_vbo.create();
    m_vbo_2.create();

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                       ":/shader/shader/shader.vs");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                       ":/shader/shader/shader.fs");

    if (!m_program->link()){
        qWarning() << "Could not link shader program:"
                   << m_program->log();
        close();
    }

    m_matrixUniform = m_program->uniformLocation("matrix");

    makeObject();
    makeObject_2();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    float aspect = float(w)/float(h?h:1);
    float fov = 45.0f, zNear = 0.1f, zFar = 100.f;
    m_pMat.setToIdentity();
    m_pMat.perspective(fov, aspect, zNear, zFar);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

    QMatrix4x4 mvMat;
    mvMat.translate(0.0f, 0.0f, -3.0f);
    m_program->setUniformValue(m_matrixUniform, m_pMat*mvMat);
    {
        QOpenGLVertexArrayObject::Binder vaoBind(&m_vao_2);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    }
    {
        QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
    }
    m_program->release();
}

void OpenGLWidget::makeObject()
{
    makeCurrent();

    float arrVertex[] {
        //   position                 color
        0.0f, 0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,
        -1.0f, 0.0f,  0.0f,     0.0f, 0.0f, 1.0f
    };

    QOpenGLVertexArrayObject::Binder vaoBind(&m_vao);
    m_vbo.bind();
    m_vbo.allocate(arrVertex, sizeof(arrVertex));

    int attr = -1;
    attr = m_program->attributeLocation("posAttr");
    m_program->setAttributeBuffer(attr, GL_FLOAT, 0,
                                  3, sizeof(float) * 6);
    m_program->enableAttributeArray(attr);

    attr = m_program->attributeLocation("colAttr");
    m_program->setAttributeBuffer(attr, GL_FLOAT, 3 * sizeof(float),
                                  3, sizeof(float) * 6);
    m_program->enableAttributeArray(attr);
    m_vbo.release();
}
void OpenGLWidget::makeObject_2()
{
    makeCurrent();

    float arrVertex[] {
        //   position                 color
        0.0f, 0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,
        1.0f, 0.0f,  0.0f,     0.0f, 0.0f, 1.0f
    };

    QOpenGLVertexArrayObject::Binder vaoBind(&m_vao_2);
    m_vbo_2.bind();
    m_vbo_2.allocate(arrVertex, sizeof(arrVertex));

    int attr = -1;
    attr = m_program->attributeLocation("posAttr");
    m_program->setAttributeBuffer(attr, GL_FLOAT, 0,
                                  3, sizeof(float) * 6);
    m_program->enableAttributeArray(attr);

    attr = m_program->attributeLocation("colAttr");
    m_program->setAttributeBuffer(attr, GL_FLOAT, 3 * sizeof(float),
                                  3, sizeof(float) * 6);
    m_program->enableAttributeArray(attr);
    m_vbo_2.release();
}
