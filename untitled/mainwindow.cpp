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
#include <QImage>
#include <QDir>
#include <string.h>
QString File_Path = "/home/zhanghuan/Graduation-Project/Graduation-Project/untitled/qrc/data.json";
char *Py_Path = "/home/zhanghuan/Graduation-Project/Graduation-Project/getWeather.py";

QStringList UART_RXdata;
QStringList labellist;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Cli_Num = 0;
    timer1 = new QTimer();
    QString path = QDir::currentPath();//当前路径
    qDebug() << path;
    ui->setupUi(this);
    statShowUI();
    Init_label();

    Open_TCPServer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(RefreshTime()));
    timer1->start(1000);

    connect(ui->pushButton_exit,SIGNAL(clicked()),this,SLOT(exit()));
//    system(Py_Path);

}
void MainWindow::File_Open(QString File_path)
{
    QByteArray line;
    int i =0;
    QFile file(File_path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while((line =file.readLine()) != "")
    {
        File_line[i] = line;
        i++;
    }
    file.close();
}
void MainWindow::Open_TCPServer()
{
    Qser = new QTcpServer(this);
    Qser->listen(QHostAddress(Ser_IP),8080);
    connect(Qser, SIGNAL(newConnection()), this, SLOT(newClient()));

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
    ui->pushButton_door->setStyleSheet("QPushButton{background-color:black;\
                                               color: white;   border-radius: 10px;  border: 2px groove gray;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:white; color: black;}"
                                             "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                              border-style: inset; }"
                                              );
    ui->pushButton_exit->setStyleSheet("QPushButton{background-color:black;\
                                               color: white;   border-radius: 10px;  border: 2px groove gray;\
                                               border-style: outset;}"
                                              "QPushButton:hover{background-color:white; color: black;}"
                                             "QPushButton:pressed{background-color:rgb(85, 170, 255);\
                                              border-style: inset; }"
                                              );

    ui->pushButton_light->setStyleSheet("QPushButton{background-color:black;\
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
    labellist.append(str);
    str = ui->label_2->text();
    labellist.append(str);
    str = ui->label_3->text();
    labellist.append(str);
    str = ui->label_4->text();
    labellist.append(str);
    str = ui->label_5->text();
    labellist.append(str);

    str = ui->label_6->text();
    labellist.append(str);
    str = ui->label_7->text();
    labellist.append(str);
    str = ui->label_8->text();
    labellist.append(str);
    str = ui->label_9->text();
    labellist.append(str);
    str = ui->label_10->text();
    labellist.append(str);
    str = ui->label_11->text();
    labellist.append(str);

    str = ui->label_12->text();
    labellist.append(str);
    str = ui->label_13->text();
    labellist.append(str);
    str = ui->label_14->text();
    labellist.append(str);
    str = ui->label_15->text();
    labellist.append(str);
    str = ui->label_16->text();

}

void MainWindow::RefreshTime()
{

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    QString current_week = current_date_time.toString("dddd");
    ui->lcdNumber->display(current_date);
    ui->week->setText("  "+current_week);
 //   get_APIdata();
 //   get_UARTdata();
    Show_Tcp_stat();


}

int i;
void MainWindow::Show_Tcp_stat()
{
    static int i;
    static int lastTim;

    if(Cli_Num > 0)
    {
        if( i == 0){
            i = 1;
            ui->label_17->setStyleSheet("border-image:url(:/qrc/green.png);");
        }else
        {
            i = 0;
            ui->label_17->setStyleSheet("background-color:#96CDCD;");
        }
    }else{
        ui->label_17->setStyleSheet("border-image:url(:/qrc/red.png);");
    }

}


void MainWindow::newClient()
{
       tcpClient = Qser->nextPendingConnection();
       qDebug() << "Client connected ";
       connect(tcpClient, SIGNAL(disconnected()), this, SLOT(deleteLater()));
       connect(tcpClient, SIGNAL(readyRead()), this, SLOT(readData()));

       Cli_Num++;
}

void MainWindow::deleteLater()
{
    if(Cli_Num > 0)
        Cli_Num--;
    qDebug() << "Client disconnect: ";

}

void MainWindow::Write_Data(QTcpSocket *tcpClient)
{
    if(Tx_data != '0')
    {
//        qDebug("Tx_Data: %c",Tx_data);
        tcpClient->write(&Tx_data);
        Tx_data = '0';
//        qDebug("Tx_Data: %c",Tx_data);
    }else{
        tcpClient->write(&Tx_data);
//        qDebug("no have data send");
    }

}
void MainWindow::make_UARTdata(QByteArray data)
{
    QStringList UART_Rxlist;
    for(int i=0;i<data.count();i++)
    {
        QString s;
        s.sprintf("0x%02x",(unsigned char)data.at(i));
        int k = s.toInt(0,16);
        s = QString::number(k, 10);
//        qDebug()<< s;
        UART_Rxlist.append(s);
    }

    QString t1 = UART_Rxlist.value(6);
    QString t2 = UART_Rxlist.value(8);
    QString t3 = UART_Rxlist.value(7);
    QString t4 = UART_Rxlist.value(9);
    int tem1 = t1.toInt();
    int tem2 = t2.toInt();
    int tem3 = t3.toInt();
    int tem4 = t4.toInt();

    tem1 = (tem1 *256) +tem3;
    tem2 = (tem4 *256) +tem2;
    UART_Rxlist.insert(6,QString::number(tem1,10));
    UART_Rxlist.insert(8,QString::number(tem2,10));
//    qDebug()<<"tem1" <<  UART_Rxlist.value(6) <<"tem2"<<UART_Rxlist.value(8);

    UART_RXdata = UART_Rxlist;
}
void MainWindow::readData()
{
    QByteArray data = tcpClient->readAll();


    Write_Data(tcpClient);

    make_UARTdata(data);

}

void MainWindow::get_UARTdata()
{

    Tcp_Rxdata.air = UART_RXdata.value(5);
    Tcp_Rxdata.Bright= UART_RXdata.value(8);
    Tcp_Rxdata.gas= UART_RXdata.value(6);
    Tcp_Rxdata.hum= UART_RXdata.value(1);
    Tcp_Rxdata.temp= UART_RXdata.value(3);


    ui->label_1->setText(labellist.value(0)+Tcp_Rxdata.temp);
    ui->label_2->setText(labellist.value(1)+Tcp_Rxdata.hum);
    ui->label_3->setText(labellist.value(2)+Tcp_Rxdata.Bright);

    ui->label_4->setText(labellist.value(3)+Tcp_Rxdata.air);
//    qDebug()<<"labellist.value(3): "<<labellist.value(3);
    ui->label_5->setText(labellist.value(4)+Tcp_Rxdata.gas);
//    qDebug()<<"labellist.value(4): "<<labellist.value(4);
//    qDebug()<<"gas: "<<Tcp_Rxdata.gas <<"air" << Tcp_Rxdata.air;



}
void MainWindow::get_APIdata()
{
    File_Open(File_Path);

    API_data.tmp = get_json(File_line[0],"tmp");
    API_data.cond_txt =get_json(File_line[0],"cond_tx1");
    API_data.fl= get_json(File_line[0],"fl");
    API_data.wind_dir= get_json(File_line[0],"wind_dir");
    API_data.wind_sc= get_json(File_line[0],"wind_sc");
    API_data.hum= get_json(File_line[0],"hum");
    API_data.vis= get_json(File_line[0],"vis");

    API_data.comf= get_json(File_line[1],"tx1");
    API_data.drsg= get_json(File_line[1],"tx2");
    API_data.flu= get_json(File_line[1],"tx3");
    API_data.sport= get_json(File_line[1],"tx4");
    API_data.trav= get_json(File_line[1],"tx5");
    API_data.uv= get_json(File_line[1],"tx6");
    API_data.cw= get_json(File_line[1],"tx7");
    API_data.air= get_json(File_line[1],"tx8");
//    qDebug()<<API_data.comf;

    ui->label_6->setText(labellist.value(5) +API_data.tmp );
    ui->label_7->setText(labellist.value(6) + API_data.fl);
    ui->label_8->setText(labellist.value(7) + API_data.hum);
    ui->label_9->setText(labellist.value(8) + API_data.cond_txt);
    ui->label_10->setText(labellist.value(9)+ API_data.wind_sc);

//    ui->label_11->setText(labellist.value(10)+ API_data.sport);
//    ui->label_12->setText(labellist.value(11) + API_data.trav);
//    ui->label_13->setText(labellist.value(12) + API_data.uv);
//    ui->label_14->setText(labellist.value(13) +API_data.cw);
//    ui->label_15->setText(labellist.value(14) + API_data.air);
//    ui->label_16->setText(labellist.value(15) +API_data.flu);

    ui->textEdit_2->setText(API_data.uv);
    ui->textEdit_3->setText(API_data.sport);
    ui->textEdit_4->setText(API_data.comf);
    ui->textEdit_5->setText(API_data.flu);
    ui->textEdit_6->setText(API_data.air);
    ui->textEdit_7->setText(API_data.drsg);





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
            *rstr = value.toString();
        }

    }else{
        QStringList oblist = Jobject.keys();
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
//    qDebug()<<rstr;
    return rstr;
}

void MainWindow::exit()
{
    exit();
}
MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_door_clicked()
{

    if(lab_flag_d == 1)
    {
        lab_flag_d = 0;
        ui->pushButton_door->setText("open door");
        Tx_data = '1';

    }else{
        lab_flag_d = 1;
        ui->pushButton_door->setText("close door");
        Tx_data = '2';

    }
//    qDebug()<<Tx_data;
}

void MainWindow::on_pushButton_light_clicked()
{
    if(lab_flag_l == 1)
    {
        lab_flag_l = 0;
        ui->pushButton_light->setText("open light");
        Tx_data = '3';
    }else{
        lab_flag_l = 1;
        ui->pushButton_light->setText("close light");
        Tx_data = '4';
    }

}
