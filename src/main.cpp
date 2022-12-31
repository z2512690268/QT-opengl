#include "opengl_widget.h"
#include "qDebug2Logcat.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    installLogcatMessageHandler("opengles");
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    OpenGLWidget w;
    w.show();
    return a.exec();
}
