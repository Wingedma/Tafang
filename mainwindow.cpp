#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QTimer>
#include "mybutton.h"
#include "mywindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
    MyButton * btn=new MyButton(":/startbutton.jpg");
    btn->setParent(this);
    btn->move(324,485);
    //connect(btn,&MyButton::clicked,this,&QMainWindow::close);//关闭界面
    MyWindow * scene= new MyWindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        QTimer::singleShot(200,this,[=](){
            this->hide();
            scene->show();
        });
        //this->hide();
        //scene->show();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pixmap(":/firstpage.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
