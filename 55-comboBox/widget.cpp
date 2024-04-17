#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) ////初始化列表来构造
{
    ui->setupUi(this);//设置QTdesigner里面的ui关联到widget类的私有变量ui里面
    // 让窗口变化与 布局和子控件一起调整
    this->setLayout(ui->verticalLayout);
    ui->widgetBottom->setLayout(ui->horizontalLayout);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(oncurrentIndexChanged(int)));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::oncurrentIndexChanged(int index)
{
    qDebug() << index; // index 是comboBox的选项的索引
    qDebug() << ui->comboBox->currentText(); // comboBox的值
}

