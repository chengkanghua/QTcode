#ifndef WIDGET_H
#define WIDGET_H

#include <QFile>
#include <QWidget>
#include <QFileDialog>
#include <QTextCodec>
#include <qDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    QFile file;
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnOpen_clicked();

    void on_btnSave_clicked();

    void on_btnClose_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
