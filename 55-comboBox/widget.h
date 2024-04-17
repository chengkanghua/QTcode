#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void oncurrentIndexChanged(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
