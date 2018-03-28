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


    connect(timer1, SIGNAL(timeout()), this, SLOT(RefreshTime()));
    timer1->start(1000);

}
void MainWindow::statShowUI()
{
    Tcp_Rxdata.air_quality="NULL";
    Tcp_Rxdata.Bright_intensity="NULL";
    Tcp_Rxdata.humidity="NULL";
    Tcp_Rxdata.noxious_gas="NULL";
    Tcp_Rxdata.temperature="NULL";

    ui->week->setStyleSheet("color:white;background-color:blue;");
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdNumber->setStyleSheet("color:white;background-color:blue;");
    ui->frame_Head->setStyleSheet("border-image:url(:/qrc/bg.png);");
    ui->local_city->setText(" Local city: dalian ");
    ui->local_city->setStyleSheet("background-color:green;color:white");
    ui->centralWidget->setStyleSheet("border-image:url(:/qrc/bg1.png);");

    ui->temp_l->setText(Tcp_Rxdata.temperature);
    ui->hum_l->setText(Tcp_Rxdata.humidity);
    ui->air_l->setText(Tcp_Rxdata.air_quality);
    ui->briint_l->setText(Tcp_Rxdata.Bright_intensity);
    ui->ngas_l->setText(Tcp_Rxdata.noxious_gas);


}
void MainWindow::RefreshTime()
{
//    qDebug() << "time out";
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    QString current_week = current_date_time.toString("dddd");
    ui->lcdNumber->display(current_date);
    ui->week->setText(current_week);

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
void MainWindow::deal_json()
{
    QJsonParseError jsonError;
 //   doucment = QJsonDocument::fromJson(line, &jsonError);
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {
         if (doucment.isObject()) {
            QJsonObject object = doucment.object();
            if (object.contains("HeWeather6")) {
                      QJsonValue value = object.value("HeWeather6");
                 //     qDebug()<< value;
                      if(value.isArray())
                      {
                          QJsonArray array = value.toArray();
                          int nSize = array.size();
                          for (int i = 0; i < nSize; ++i)
                          {
                            qDebug()<< array.at(0);
                            QJsonValue value = array.at(i);
                            if(array.at(i).isObject())
                            {
                                QJsonObject object = array.at(i).toObject();
                                if(object.contains("update"))
                                {
                                      QJsonValue value = object.value("update");
                                //      qDebug()<< value;
                                      if(value.isObject())
                                      {
                                          qDebug()<< value;
                                          QJsonObject object = value.toObject();
                                          if(object.contains("loc"))
                                          {
                                              QJsonValue value = object.value("loc");
                                              qDebug()<< value;
                                              QString str =value.toString();
                                            //  ui->label_9->setText(str);
                                          }
                                      }
                                }
                            }
                          }


                      }
                      if (value.isString()) {
                          QString strName = value.toString();
                          qDebug() << "HeWeather6 : " << strName;
                      }
                  }
         }
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}
