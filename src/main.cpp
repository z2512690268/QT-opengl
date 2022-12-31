#include "opengl_widget.h"
#include "qDebug2Logcat.h"
#include "QNavigationWidget.h"
#include "loadpic.h"
#include <QApplication>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
int main(int argc, char *argv[])
{
    // installLogcatMessageHandler("opengles");
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    OpenGLWidget w2;
    QNavigationWidget tabw;
    Loadpic w1;
    tabw.addTab(&w1, "Load Pic");
    tabw.addTab(&w2, "OpenGLES");
    tabw.show();
    // w.show();
    return a.exec();
}
