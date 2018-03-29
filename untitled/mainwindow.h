#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/qtcpserver.h>
#include <qjsondocument.h>
#include <QTime>
#define Ser_IP "127.0.0.1"
#define Ser_Port 8080
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    struct TCP_Rxdata{
         QString temperature;
         QString humidity;
         QString Bright_intensity;
         QString air_quality;
         QString noxious_gas;
    }Tcp_Rxdata;
    struct API_DATA{
        QString fengxiang;
        QString tiganwendu;
        QString xiangduisidu;
        QString feng;
        QString wendu;

        QString yundongzhishu;
        QString huwaizhishu;
        QString UV_index;
        QString Cold_index;
        QString Air_quality;
        QString Dress_index;


    }API_data;
    ~MainWindow();
    void NewCon();
    void checkData();
    void get_UARTdata();
    void get_APIdata();
    void statShowUI();
    void Init_label();
    QString get_json(QByteArray line,QString value);
    void deal_data(QJsonObject Jobject,QString str,QString *rstr);

private slots:
    void newClient();
    void deleteLater();
    void readData();
    void RefreshTime();


private:
    Ui::MainWindow *ui;
    QTcpServer *Qser;
    QByteArray arry;
    QJsonDocument doucment;
    QTimer *timer1;

};

#endif // MAINWINDOW_H
