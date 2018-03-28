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
    ~MainWindow();
    void NewCon();
    void checkData();
    void deal_json();
    void statShowUI();


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
