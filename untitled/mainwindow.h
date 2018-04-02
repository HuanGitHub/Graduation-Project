#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtNetwork/qtcpserver.h>
#include <qjsondocument.h>
#include <QTime>
#include <QtNetwork/qtcpserver.h>
#include <QImage>
#define Ser_IP  "192.168.0.104"
#define Ser_Port 8080
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QByteArray File_line[256];
    struct TCP_Rxdata{
         QString temp;
         QString hum;
         QString Bright;
         QString air;
         QString gas;
    }Tcp_Rxdata;

    struct API_DATA{
        QString fl;
        QString tmp;
        QString cond_txt;
        QString wind_dir;
        QString wind_sc;
        QString hum;
        QString vis;

        QString comf;
        QString drsg;
        QString flu;
        QString sport;
        QString trav;
        QString uv;
        QString cw;
        QString air;



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
    void Open_TCPServer();
    void Show_Tcp_stat();
    void File_Open(QString File_path);
private slots:
    void newClient();
    void deleteLater();
    void readData();
    void RefreshTime();
    void exit();


private:
    Ui::MainWindow *ui;
    QTcpServer *Qser;
    QByteArray arry;
    QJsonDocument doucment;
    QTimer *timer1;
    int Cli_Num;
    QImage* img;


};

#endif // MAINWINDOW_H
