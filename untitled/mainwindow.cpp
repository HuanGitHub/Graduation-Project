#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTcpSocket>
#include <qfile.h>
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <QTimer>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer1 = new QTimer();

    ui->setupUi(this);
    statShowUI();
    Init_label();
//    Qser = new QTcpServer(this);
//    Qser->listen(QHostAddress(Ser_IP),Ser_Port);
 //   connect(Qser, SIGNAL(newConnection()), this, SLOT(newClient()));
    QFile file("/home/zhanghuan/data.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QByteArray line = file.readAll();
    QString str(line);
    get_json(line,"tx2");

    connect(timer1, SIGNAL(timeout()), this, SLOT(RefreshTime()));
    timer1->start(1000);

}
void MainWindow::statShowUI()
{


    ui->week->setStyleSheet("color:white;background-color:#009ACD;");
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->setStyleSheet("color:white;background-color:#009ACD;");
    ui->frame_Head->setStyleSheet("border-image:url(:/qrc/bg.png);");
    ui->local_city->setText(" Local city: dalian ");
    ui->local_city->setStyleSheet("background-color:green;color:white");
    ui->pushButton->setStyleSheet("QPushButton{background-color:black;\
                                               color: white;   border-radius: 10px;  border: 2px groove gray;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:white; color: black;}"
                                             "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                              border-style: inset; }"
                                              );
    ui->pushButton_3->setStyleSheet("QPushButton{background-color:black;\
                                               color: white;   border-radius: 10px;  border: 2px groove gray;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:white; color: black;}"
                                             "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                              border-style: inset; }"
                                              );
                                              ui->pushButton_2->setStyleSheet("QPushButton{background-color:black;\
                                                                                         color: white;   border-radius: 10px;  border: 2px groove gray;\
                                                                                         border-style: outset;}"
                                                                                        "QPushButton:hover{background-color:white; color: black;}"
                                                                                       "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                                                                        border-style: inset; }"
                                                                                        );
    ui->pushButton_2->setStyleSheet("QPushButton{background-color:black;\
                                               color: white;   border-radius: 10px;  border: 2px groove gray;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:white; color: black;}"
                                             "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                              border-style: inset; }"
                                              );

    ui->frame->setStyleSheet("background-color:#009ACD;");
    ui->centralWidget->setStyleSheet("background-color:#96CDCD;");

}
void MainWindow::Init_label()
{
    Tcp_Rxdata.air_quality="NULL";
    Tcp_Rxdata.Bright_intensity="NULL";
    Tcp_Rxdata.humidity="NULL";
    Tcp_Rxdata.noxious_gas="NULL";
    Tcp_Rxdata.temperature="NULL";

//    ui->temp_l->setText(Tcp_Rxdata.temperature);
//    ui->hum_l->setText(Tcp_Rxdata.humidity);
//    ui->air_l->setText(Tcp_Rxdata.air_quality);
//    ui->briint_l->setText(Tcp_Rxdata.Bright_intensity);
//    ui->ngas_l->setText(Tcp_Rxdata.noxious_gas);
    ui->label_1->setStyleSheet("font:18px");
    ui->label_2->setStyleSheet("font:18px");
    ui->label_3->setStyleSheet("font:18px");
    ui->label_4->setStyleSheet("font:18px");
    ui->label_5->setStyleSheet("font:18px");
    ui->label_6->setStyleSheet("font:18px");
    ui->label_7->setStyleSheet("font:18px");
    ui->label_8->setStyleSheet("font:18px");
    ui->label_9->setStyleSheet("font:18px");
    ui->label_10->setStyleSheet("font:18px");
    ui->label_11->setStyleSheet("font:18px");
    ui->label_12->setStyleSheet("font:18px");
    ui->label_13->setStyleSheet("font:18px");
    ui->label_14->setStyleSheet("font:18px");
    ui->label_15->setStyleSheet("font:18px");
    ui->label_16->setStyleSheet("font:18px");

    QString str ;
    str = ui->label_1->text();
    ui->label_1->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_2->text();
    ui->label_2->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_3->text();
    ui->label_3->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_4->text();
    ui->label_4->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_5->text();
    ui->label_5->setText(str+Tcp_Rxdata.noxious_gas);

    str = ui->label_6->text();
    ui->label_6->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_7->text();
    ui->label_7->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_8->text();
    ui->label_8->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_9->text();
    ui->label_9->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_10->text();
    ui->label_10->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_11->text();
    ui->label_11->setText(str+Tcp_Rxdata.noxious_gas);

    str = ui->label_12->text();
    ui->label_12->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_13->text();
    ui->label_13->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_14->text();
    ui->label_14->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_15->text();
    ui->label_15->setText(str+Tcp_Rxdata.noxious_gas);
    str = ui->label_16->text();
    ui->label_16->setText(str+Tcp_Rxdata.noxious_gas);



}

void MainWindow::RefreshTime()
{
//    qDebug() << "time out";
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    QString current_week = current_date_time.toString("dddd");
    ui->lcdNumber->display(current_date);
    ui->week->setText("  "+current_week);

}

void MainWindow::NewCon()
{
    qDebug()<< "have cline\r\n";

}

void MainWindow::newClient()
{
       QTcpSocket *tcpClient = Qser->nextPendingConnection();
       qDebug() << "Client connected: ";
       connect(tcpClient, SIGNAL(disconnected()), tcpClient, SLOT(deleteLater()));
       connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readData()));
}

void MainWindow::deleteLater()
{
    qDebug() << "Client disconnect: ";

}
void MainWindow::checkData()
{



}
void MainWindow::readData()
{
    QTcpSocket* myClient = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = myClient->readAll();
    qDebug()<< data;
    QByteArray Hexdata = data.toHex();
    for(int i=0;i<Hexdata.size();i++)
        qDebug()<<Hexdata[i];
}

void MainWindow::deal_json(QByteArray line)
{

}
void MainWindow::deal_data(QJsonObject Jobject,QString str,QString *rstr)
{
    if(Jobject.contains(str))
    {
        QJsonValue value = Jobject.value(str);
        if(value.isArray())
        {
            qDebug()<<str+"is a array";
            qDebug()<<str<<":"<<value;
        }else{
 //           qDebug()<<str<<":"<<value;
            *rstr = value.toString();
        }

    }else{
        QStringList oblist = Jobject.keys();
        qDebug()<<"oblist:"<<oblist;
        for(int i=0;i<oblist.count();i++)
        {
            QJsonValue value = Jobject.value(oblist[i]);
            if(value.isArray())
            {
                QJsonArray array = value.toArray();
                int nSize = array.size();
                for (int i = 0; i < nSize; ++i)
                {
                    QJsonValue value = array.at(i);
                    if(array.at(i).isObject())
                    {
                        QJsonObject object = array.at(i).toObject();
                        deal_data(object,str,rstr);
                    }
                }
            }
            if(value.isObject())
            {
                QJsonObject object = value.toObject();
                deal_data(object,str,rstr);
            }
        }
      }
}

QString MainWindow::get_json(QByteArray line,QString value)
{
    QJsonParseError jsonError;
    QString rstr;
    doucment = QJsonDocument::fromJson(line, &jsonError);
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
         if (doucment.isObject()) {
            QJsonObject object = doucment.object();
            QStringList st = object.keys();
            deal_data(object,value,&rstr);
         }
    }
    qDebug()<<rstr;
    return rstr;

}
MainWindow::~MainWindow()
{
    delete ui;
}




