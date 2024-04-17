#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
// 1 定义信号
signals:
    void mysignal();
    void mysignalparams(int value);

// 2 定义槽
private slots:
    void myslot();
    void myslotparams(int value);


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
