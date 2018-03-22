#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/qtcpserver.h>
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

private slots:
    void newClient();
    void deleteLater();
    void readData();

private:
    Ui::MainWindow *ui;
    QTcpServer *Qser;

};

#endif // MAINWINDOW_H
