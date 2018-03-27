#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/qtcpserver.h>
#include <qjsondocument.h>

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

    ~MainWindow();
    void NewCon();
    void checkData();
private slots:
    void newClient();
    void deleteLater();
    void readData();

private:
    Ui::MainWindow *ui;
    QTcpServer *Qser;
    QByteArray arry;
    QJsonDocument doucment;

};

#endif // MAINWINDOW_H
