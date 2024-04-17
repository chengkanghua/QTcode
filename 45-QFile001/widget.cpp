#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnRead_clicked()
{
    // 1 打开文件
    QFile file;
    file.setFileName("C:/Users/kanghua/Documents/QTcode/45-QFile001/test.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "file open error";
    }
    // 2 读取文件
//    int size = file.size();
//    char* context = new char(size);
    QByteArray arr = file.readAll();
    QString str(arr); //QString str = QString(arr);
    // 3 输出文件内容
    qDebug() << str ;
    file.close();
}

void Widget::on_btnWrite_clicked()
{
    // 1.打开
     QFile file("C:/Users/kanghua/Documents/QTcode/45-QFile001/test1.txt");
     file.open(QIODevice::WriteOnly | QIODevice::Text);
    // 2. 写入
     file.write("Program 45-QFile001 write something to This File 我是老陈");
    // 3. 关闭
     file.close();
}

void Widget::on_btnstrRead_clicked()
{
    QFile file;
    file.setFileName("C:/Users/kanghua/Documents/QTcode/45-QFile001/test1.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "file open error";
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
   // QString context = in.read(file.size());
    while(!in.atEnd()){
        QString context = in.readLine();
        qDebug() << context;
        qDebug() << "--------";
    }

    file.close();
}

void Widget::on_btnstreamWrite_clicked()
{
    QFile file;
    file.setFileName("C:/Users/kanghua/Documents/QTcode/45-QFile001/test2.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "file open error";
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << "I write stream char to File";
    file.close();
}
