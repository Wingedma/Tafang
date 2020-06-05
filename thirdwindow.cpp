#include "thirdwindow.h"
#include "tower.h"
#include "mybutton.h"
#include <QList>
#include <QPainter>
#include "myobject.h"
#include <QTimer>
thirdwindow::thirdwindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    MyButton *setTower=new MyButton(":/towerbutton.jpg");
    setTower->setParent(this);
    setTower->move(200,200);
    connect(setTower,&MyButton::clicked,this,&thirdwindow::set_tower);
    connect(setTower,&MyButton::clicked,this,&thirdwindow::addMyObject);
   // this->addMyObject();
    QTimer * timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&thirdwindow::updateScene);
    timer->start(5);


}
void thirdwindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    foreach(Tower *tower,tower_list)
        tower->draw(&painter);
    foreach(MyObject * object,object_list)
        object->draw(&painter);

}
void thirdwindow::set_tower(){
    Tower * new_tower=new Tower(QPoint(200,50),":/tower1.jpg");

    //QPainter painter(this);
   // QPixmap pixmap(":/tower1.jpg");
    //painter.drawPixmap(200,100,this->width(),this->height(),pixmap);
    // this->paintEve

    tower_list.push_back(new_tower);
    update();
}
void thirdwindow::addMyObject(){
    MyObject* object= new MyObject(QPoint(100,300),QPoint(700,300),":/monster.jpg");
    object_list.push_back(object);
    object->move();
    update();
}
void thirdwindow::updateScene(){
    update();
}
