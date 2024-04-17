#include "mybutton.h"

#include <QPainter>

MyButton::MyButton(QWidget *parent) : QWidget(parent)
{
    pic.load(":/o1.png");
    setFixedSize(pic.size()); //图片多大就显示多大
    update();
}

// 鼠标按下的函数
void MyButton::mousePressEvent(QMouseEvent *event)
{
    pic.load(":/o3.png");
    update();
    emit clicked();   //发送点击信号  触发槽函数
}

// 鼠标离开的函数
void MyButton::leaveEvent(QEvent *event)
{
    pic.load(":/o1.png");
    update();
}

// 鼠标进入的函数
void MyButton::enterEvent(QEvent *event)
{
    pic.load(":/o2.png");
    update();//update是去调用绘画事件
}

// 绘图事件
void MyButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),pic);
}
