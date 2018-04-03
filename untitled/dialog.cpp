#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->label->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_2->setAttribute(Qt::WA_TranslucentBackground);

    ui->frame->setStyleSheet("border-image:url(:/qrc/login.png);");
    ui->label->setStyleSheet("color:blue;");
    ui->label_2->setStyleSheet("color:blue;");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(show_page()));
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::show_page()
{
    QString name = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();
//    qDebug()<< name <<pwd;
    if((name == "zhanghuan" )&& (pwd == "zhanghuan"))
    {
        this->hide();
        m = new MainWindow();
        m->show();
    }else{
        QMessageBox::information(this,"提示","账号或者密码错误");
    }



}
