QT       += core gui
QT       += sensors
QT       += androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/opengl_widget.cpp \
    src/qDebug2Logcat.cpp \
    src/QNavigationWidget.cpp \
    src/QNavigationTab.cpp \
    src/myimage.cpp \
    src/loadpic.cpp \
    src/Camera.cpp \
    src/Dice.cpp \
    src/Light.cpp \
    src/Model.cpp \
    src/LightModel.cpp

HEADERS += \
    include/opengl_widget.h \
    include/opengl_widget.h \
    include/qDebug2Logcat.h \
    include/QNavigationWidget.h \
    include/QNavigationTab.h \
    include/myimage.h \
    include/loadpic.h \
    include/Camera.h \
    include/Dice.h \
    include/Light.h \
    include/Model.h \
    include/LightModel.h

INCLUDEPATH += include/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    shader.qrc
