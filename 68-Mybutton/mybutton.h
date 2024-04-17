#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton : public QWidget
{
    Q_OBJECT

private:
    QPixmap pic;
public:
    explicit MyButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void enterEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;


signals:
    void clicked();  //点击信号
};

#endif // MYBUTTON_H
