#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 3 连接信号于槽
    connect(this,SIGNAL(mysignal()),this,SLOT(myslot()));
    connect(this,SIGNAL(mysignalparams(int)),this,SLOT(myslotparams(int)));
    // 4 发射信号
    emit mysignal();
    emit mysignalparams(100);
}

Widget::~Widget()
{
    delete ui;
}

// 这里写具体的槽的 方法内容
void Widget::myslot()
{
    std::cout << "myslot" << std::endl;
}

void Widget::myslotparams(int value)
{
    qDebug() << "myslotparams";   //使用debug方法输出内容
    qDebug() << value ;
}




