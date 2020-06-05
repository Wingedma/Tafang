#include "tower.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>

Tower::Tower(QPoint _pos,QString pixFileName) : QObject(0),pixmap(pixFileName)
{
    pos=_pos;
}
void Tower::draw(QPainter *painter){
    painter->drawPixmap(pos,pixmap);
}
