#ifndef LOADPIC_H
#define LOADPIC_H

#include <QWidget>

class Loadpic : public QWidget
{
    Q_OBJECT
public:
    explicit Loadpic(QWidget *parent = nullptr);

// slots
protected slots:
    void loadPicFromFS();
    void loadPicFromFS2();

signals:

};

#endif // LOADPIC_H
