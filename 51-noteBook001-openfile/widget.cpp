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
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C:/Users/kanghua/Documents/QTcode/45-QFile001",
                                                      tr("Text (*.txt)"));
    ui->textEdit->clear();
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "file open error";
        }
    QTextStream in(&file);
    in.setCodec("UTF-8");
//    in.setCodec("ANSI");
    while(!in.atEnd()){
        QString context = in.readLine();
//        qDebug() << qPrintable(context);  //在命令行输出
//        ui->textEdit->setText(context);  //只有一行
        ui->textEdit->append(context);
    }
//    file.close();
}

void Widget::on_btnSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "C:/Users/kanghua/Documents/QTcode/45-QFile001/untitled.txt",
                                tr("Text (*.txt *.doc)"));
    qDebug()<<fileName;

    file.setFileName(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "file open error";
    }

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    QString context = ui->textEdit->toPlainText();

    out << context;
//    file.close();
}

void Widget::on_btnClose_clicked()
{
    if(file.isOpen()){
        file.close();
        ui->textEdit->clear();
    }
}
