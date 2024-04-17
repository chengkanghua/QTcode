#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <qtextedit.h>



class mytextedit : public QTextEdit
{
public:
    mytextedit(QWidget *parent);

protected:
    void wheelEvent(QWheelEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
private:
    bool ctrlKeyPressed = 0;

};

#endif // MYTEXTEDIT_H
