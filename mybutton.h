#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPushButton>
#include "thirdwindow.h"

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(QString pix);
    friend class thirdwindow;

signals:

};

#endif // MYBUTTON_H
