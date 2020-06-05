#include "mywindow.h"
#include "mybutton.h"
#include "thirdwindow.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>


MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
   // MyButton *
    MyButton * continue_btn=new MyButton(":/continue");
    continue_btn->setParent(this);
    continue_btn->move(324,485);
    thirdwindow * thirdscene= new thirdwindow;
    connect(continue_btn,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(200,this,[=](){
            this->hide();
            thirdscene->show();
        });
    });

}
void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/secondpage.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
