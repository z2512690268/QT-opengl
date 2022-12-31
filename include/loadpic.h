#ifndef LOADPIC_H
#define LOADPIC_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class Loadpic : public QWidget
{
    Q_OBJECT
public:
    explicit Loadpic(QWidget *parent = nullptr);
    ~Loadpic();

// slots
protected slots:
    void SyncData();
signals:

private:
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QSlider *slider4;
    QSlider *slider5;
    QSlider *slider6;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
};

#endif // LOADPIC_H
