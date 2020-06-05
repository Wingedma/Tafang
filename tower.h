#ifndef TOWER_H
#define TOWER_H

#include <QObject>
#include <QPoint>
#include <QPixmap>

class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint _pos,QString pixFileName);
    void draw(QPainter *painter);
private:
    QPoint pos;
    QPixmap pixmap;
signals:

};

#endif // TOWER_H
