#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTcpSocket>
#include <qfile.h>
#include <qjsonarray.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
 //   qDebug()<< str;
    QJsonParseError jsonError;
    doucment = QJsonDocument::fromJson(line, &jsonError);
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

MainWindow::~MainWindow()
{
    delete ui;
}
