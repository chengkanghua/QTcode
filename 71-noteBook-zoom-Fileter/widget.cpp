#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QShortcut>
#include <QWheelEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) ////初始化列表来构造
{
    ui->setupUi(this);//设置QTdesigner里面的ui关联到widget类的私有变量ui里面

    ui->textEdit->installEventFilter(this);

    //配置记事本快捷键操作
    QShortcut *shortcutOpen = new QShortcut(QKeySequence(tr("Ctrl+O", "File|Open")),this);
    QShortcut *shortcutSave = new QShortcut(QKeySequence(tr("Ctrl+S", "File|Save")),this);
    QShortcut *shortcutZoomIn = new QShortcut(QKeySequence(tr("Ctrl+=", "File|Save")),this);
    QShortcut *shortcutZoomOut = new QShortcut(QKeySequence(tr("Ctrl+-", "File|Save")),this);

    connect(shortcutOpen,&QShortcut::activated,[=](){
        on_btnOpen_clicked();
    });
    connect(shortcutSave,&QShortcut::activated,[=](){
        on_btnSave_clicked();
    });
    connect(shortcutZoomIn,&QShortcut::activated,[=](){
        zoomIn();
    });
    connect(shortcutZoomOut,&QShortcut::activated,[=](){
        zoomOut();
    });


    // 让窗口变化与 布局和子控件一起调整
    this->setLayout(ui->verticalLayout);
    ui->widgetBottom->setLayout(ui->horizontalLayout);

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(onCurrentIndexChanged(int)));
    connect(ui->textEdit,SIGNAL(cursorPositionChanged()),this,SLOT(onCursorPositionChanged()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::zoomIn()
{
    //获得TextEdit的当前字体信息
    QFont font = ui->textEdit->font();
    //获得当前字体的大小
    int fontSize = font.pointSize();
    if(fontSize == -1) return;

    //改变大小，并设置字体大小
    int newFontSize = fontSize+1;
    font.setPointSize(newFontSize);
    ui->textEdit->setFont(font);
}

void Widget::zoomOut()
{
    //获得TextEdit的当前字体信息
    QFont font = ui->textEdit->font();
    //获得当前字体的大小
    int fontSize = font.pointSize();
    if(fontSize == -1) return;

    //改变大小，并设置字体大小
    int newFontSize = fontSize-1;
    font.setPointSize(newFontSize);
    ui->textEdit->setFont(font);
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    /* QKeyEvent *keyEvent = (QKeyEvent*)event;
     if(keyEvent->key() == Qt::Key_Control){
         qDebug() << "Ctrl";
     }
     */
     if(event->type() == QEvent::Wheel){
         if(QGuiApplication::keyboardModifiers() == Qt::ControlModifier){

              QWheelEvent *wheelEvent = dynamic_cast<QWheelEvent*>(event);
              if(wheelEvent->angleDelta().y() > 0){
                  zoomIn();
              }else if(wheelEvent->angleDelta().y()<0){
                  zoomOut();
              }
              return true;
         }

         return false;
     }
}


void Widget::on_btnOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "C:/Users/kanghua/Documents/QTcode/45-QFile001",
                                                      tr("Text (*.txt)"));
    ui->textEdit->clear();
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << "file open error";
        }
    // 打开文件的标题显示
    this->setWindowTitle(fileName + "   老六记事本");
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
    if(!file.isOpen()){
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
    QTextStream out(&file);
    out.setCodec(ui->comboBox->currentText().toStdString().c_str());
    // 写入文件之前 先把文件清空
    file.seek(0);
    file.resize(0);

    QString context = ui->textEdit->toPlainText();
    out << context;
}

void Widget::on_btnClose_clicked()
{
    QMessageBox msgBox;
    int ret = QMessageBox::warning(this, tr("mynotebook Notice:"),
                                    tr("The document has been modified.\n"
                                       "Do you want to save your changes?"),
                                    QMessageBox::Save | QMessageBox::Discard
                                    | QMessageBox::Cancel,
                                    QMessageBox::Save);

    switch (ret) {
       case QMessageBox::Save:
           // Save was clicked
            on_btnSave_clicked();
            qDebug() << "QMessageBox::Save:";
           break;
       case QMessageBox::Discard:
           // Don't Save was clicked
            ui->textEdit->clear();
            if(file.isOpen()){
                file.close();
                ui->textEdit->clear();
                this->setWindowTitle("MyNoteBook");
            }
            qDebug() << "QMessageBox::Discard:";
           break;
       case QMessageBox::Cancel:
           // Cancel was clicked
            qDebug() << "QMessageBox::Cancel:";
           break;
       default:
           // should never be reached
           break;
     }


}

void Widget::onCurrentIndexChanged(int)
{
    qDebug() << "currentItSignal";
    ui->textEdit->clear();
    if(file.isOpen()){
            qDebug() << "file is Open";
            QTextStream in(&file);
            in.setCodec(ui->comboBox->currentText().toStdString().c_str());
            file.seek(0); //光标移到文本开头位置
            while(!in.atEnd()){
                QString context = in.readLine();
                ui->textEdit->append(context);
            }
    }
}

void Widget::onCursorPositionChanged()
{
    QTextCursor cursor =  ui->textEdit->textCursor();
    //qDebug() << cursor.blockNumber()+1  <<","<< cursor.columnNumber() + 1;

    QString blockNum = QString::number(cursor.blockNumber()+1);
    QString columnNum = QString::number(cursor.columnNumber()+1);

//    const QString labelMes = "L:"+blockNum+"  C:"+columnNum+"   ";
    const QString labelMes = "行:"+blockNum+"  列:"+columnNum+"   ";
    ui->labelPosition->setText(labelMes);

    //设置当前行高亮
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection ext;

    //1. 知道当前行
    ext.cursor = cursor;

    QBrush qBrush(Qt::lightGray);
    //2. 颜色
    ext.format.setBackground(qBrush);
    //配置段属性：整行显示，没有这句话不行
    ext.format.setProperty(QTextFormat::FullWidthSelection, true);
    //ext.format.setFontUnderline(true);
    //3. 设置
    //把ext加到ext的容器中
    extraSelections.append(ext);
    ui->textEdit->setExtraSelections(extraSelections);

}
