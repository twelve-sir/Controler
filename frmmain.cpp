#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFontDatabase>
#include <QApplication>
#include <QDialog>

frmMain::frmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->init_style();
    showBool = 0;
//    ui->lb_6->setStyleSheet("border-image: url(:/icon/666.jpg)");
}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::init_style()
{
    //隐藏窗口的标题栏
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    //暗注释;
    ui->le_search->setPlaceholderText(QStringLiteral("搜索"));
}

void frmMain::mousePressEvent(QMouseEvent *e)
{
    last=e->globalPos();
}
void frmMain::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}
void frmMain::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    move(x()+dx, y()+dy);
}

void frmMain::on_pb_min_clicked()
{
    this->showMinimized();
}

void frmMain::on_pb_close_clicked()
{
    this->close();
}

void frmMain::on_pb_max_clicked()
{
    if(!showBool)
    {
        this->showFullScreen();
        showBool++;
    }else{
        this->showNormal();
        showBool--;
    }
}

