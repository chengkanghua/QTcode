#include "mytextedit.h"

#include <QWheelEvent>
#include <QDebug>

mytextedit::mytextedit(QWidget *parent): QTextEdit(parent)
{

}

void mytextedit::wheelEvent(QWheelEvent *e)
{
    //qDebug() << e->angleDelta().y();
      if(ctrlKeyPressed == 1){
          if(e->angleDelta().y() > 0){
              zoomIn(15);
          }else if(e->angleDelta().y() < 0){
              zoomOut(15);
          }
          e->accept();
      }else{
          QTextEdit::wheelEvent(e);
      }
}

void mytextedit::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Control){
       // qDebug() << "ctrl Pressed";
        ctrlKeyPressed = 1;
    }
    QTextEdit::keyPressEvent(e);
}

void mytextedit::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Control){  // 按住ctrl键
       // qDebug() << "ctrl Release";
        ctrlKeyPressed = 0;
    }
    QTextEdit::keyPressEvent(e);
}
