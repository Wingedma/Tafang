#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QMainWindow>
#include "tower.h"
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include "myobject.h"
#include "mybutton.h"

class thirdwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit thirdwindow(QWidget *parent = nullptr);

    void set_tower();
    void paintEvent(QPaintEvent*);
    void addMyObject;
    void updateScene();
private:
    QList<Tower*> tower_list;
    QList<MyObject*> object_list;

signals:

};

#endif // THIRDWINDOW_H
