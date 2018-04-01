/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_7;
    QTextEdit *textEdit_2;
    QLabel *label_19;
    QLabel *week;
    QFrame *frame_Head;
    QLabel *local_city;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_door;
    QPushButton *pushButton_light;
    QLabel *label_17;
    QFrame *frame_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_18;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 768);
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(940, 730, 200, 38));
        QFont font1;
        font1.setPointSize(14);
        lcdNumber->setFont(font1);
        lcdNumber->setCursor(QCursor(Qt::BlankCursor));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 220, 191, 321));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 171, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_1 = new QLabel(verticalLayoutWidget);
        label_1->setObjectName(QStringLiteral("label_1"));

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 111, 31));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(480, 200, 701, 451));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_4 = new QWidget(frame_2);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(40, 30, 91, 401));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(verticalLayoutWidget_4);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_4->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_4->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_4);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_4->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_4->addWidget(label_14);

        label_15 = new QLabel(verticalLayoutWidget_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(verticalLayoutWidget_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_4->addWidget(label_16);

        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        label_16->raise();
        label_15->raise();
        verticalLayoutWidget_2 = new QWidget(frame_2);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(140, 30, 561, 401));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(13);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_3 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        verticalLayout_2->addWidget(textEdit_3);

        textEdit_4 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));

        verticalLayout_2->addWidget(textEdit_4);

        textEdit_6 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));

        verticalLayout_2->addWidget(textEdit_6);

        textEdit_5 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));

        verticalLayout_2->addWidget(textEdit_5);

        textEdit_7 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));

        verticalLayout_2->addWidget(textEdit_7);

        textEdit_2 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 0, 111, 31));
        label_19->setFont(font2);
        week = new QLabel(centralWidget);
        week->setObjectName(QStringLiteral("week"));
        week->setGeometry(QRect(1139, 730, 61, 38));
        frame_Head = new QFrame(centralWidget);
        frame_Head->setObjectName(QStringLiteral("frame_Head"));
        frame_Head->setGeometry(QRect(0, 0, 1200, 188));
        frame_Head->setFrameShape(QFrame::StyledPanel);
        frame_Head->setFrameShadow(QFrame::Raised);
        local_city = new QLabel(centralWidget);
        local_city->setObjectName(QStringLiteral("local_city"));
        local_city->setGeometry(QRect(0, 732, 167, 35));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        local_city->setFont(font3);
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(1060, 660, 101, 41));
        pushButton_door = new QPushButton(centralWidget);
        pushButton_door->setObjectName(QStringLiteral("pushButton_door"));
        pushButton_door->setGeometry(QRect(940, 660, 101, 41));
        pushButton_light = new QPushButton(centralWidget);
        pushButton_light->setObjectName(QStringLiteral("pushButton_light"));
        pushButton_light->setGeometry(QRect(810, 660, 101, 41));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(910, 740, 21, 21));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(210, 220, 191, 321));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_5 = new QWidget(frame_3);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 30, 171, 291));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_5->addWidget(label_10);

        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_5->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_5->addWidget(label_9);

        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_18 = new QLabel(frame_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 0, 111, 31));
        label_18->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        frame_2->raise();
        week->raise();
        lcdNumber->raise();
        frame_Head->raise();
        local_city->raise();
        pushButton_exit->raise();
        pushButton_door->raise();
        pushButton_light->raise();
        label_17->raise();
        frame_3->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The most enjoyable Smart Home", 0));
        label_1->setText(QApplication::translate("MainWindow", "\346\270\251      \345\272\246 \357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\271\277       \345\272\246 \357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\205\211        \344\272\256 \357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\347\251\272\346\260\224\350\264\250\351\207\217 \357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\234\211\345\256\263\346\260\224\344\275\223 \357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "\345\256\244\345\206\205\347\216\257\345\242\203 \357\274\232", 0));
        label_11->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\214\207\346\225\260 \357\274\232", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\210\222\351\200\202\346\214\207\346\225\260 \357\274\232", 0));
        label_13->setText(QApplication::translate("MainWindow", "\347\251\272\346\260\224\350\264\250\351\207\217 \357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\204\237\345\206\222\346\214\207\346\225\260 \357\274\232", 0));
        label_15->setText(QApplication::translate("MainWindow", "\347\251\277\350\241\243\346\214\207\346\225\260 \357\274\232", 0));
        label_16->setText(QApplication::translate("MainWindow", "\347\264\253\345\244\226\347\272\277\346\214\207\346\225\260 \357\274\232", 0));
        label_19->setText(QApplication::translate("MainWindow", "\347\224\237\346\264\273\350\264\264\345\243\253 \357\274\232", 0));
        week->setText(QString());
        local_city->setText(QString());
        pushButton_exit->setText(QApplication::translate("MainWindow", "EXIT", 0));
        pushButton_door->setText(QApplication::translate("MainWindow", "Open door", 0));
        pushButton_light->setText(QApplication::translate("MainWindow", "Open light", 0));
        label_17->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251        \345\272\246 \357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "\344\275\223\346\204\237\346\270\251\345\272\246 \357\274\232", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\271\277         \345\272\246 \357\274\232", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\244\251        \346\260\224 \357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\243\216        \345\212\233 \357\274\232", 0));
        label_18->setText(QApplication::translate("MainWindow", "\345\256\244\345\244\226\347\216\257\345\242\203 \357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
