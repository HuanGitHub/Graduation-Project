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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
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
    QLabel *label_20;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_18;
    QLabel *label_21;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1824, 1007);
        QFont font;
        font.setKerning(true);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(1461, 927, 251, 61));
        QFont font1;
        font1.setPointSize(14);
        lcdNumber->setFont(font1);
        lcdNumber->setCursor(QCursor(Qt::BlankCursor));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(980, 200, 821, 591));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(55);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_4 = new QWidget(frame_2);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(40, 70, 151, 501));
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
        verticalLayoutWidget_2->setGeometry(QRect(190, 70, 601, 502));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit_3 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        QFont font2;
        font2.setPointSize(20);
        textEdit_3->setFont(font2);

        verticalLayout_2->addWidget(textEdit_3);

        textEdit_4 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setFont(font2);

        verticalLayout_2->addWidget(textEdit_4);

        textEdit_6 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setFont(font2);

        verticalLayout_2->addWidget(textEdit_6);

        textEdit_5 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setFont(font2);

        verticalLayout_2->addWidget(textEdit_5);

        textEdit_7 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_7->setObjectName(QStringLiteral("textEdit_7"));
        textEdit_7->setFont(font2);

        verticalLayout_2->addWidget(textEdit_7);

        textEdit_2 = new QTextEdit(verticalLayoutWidget_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setFont(font2);

        verticalLayout_2->addWidget(textEdit_2);

        label_19 = new QLabel(frame_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 0, 181, 61));
        QFont font3;
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        label_19->setFont(font3);
        verticalLayoutWidget_4->raise();
        verticalLayoutWidget_2->raise();
        label_19->raise();
        week = new QLabel(centralWidget);
        week->setObjectName(QStringLiteral("week"));
        week->setGeometry(QRect(1710, 927, 111, 61));
        QFont font4;
        font4.setFamily(QStringLiteral("Abyssinica SIL"));
        font4.setPointSize(20);
        week->setFont(font4);
        frame_Head = new QFrame(centralWidget);
        frame_Head->setObjectName(QStringLiteral("frame_Head"));
        frame_Head->setGeometry(QRect(-10, 0, 1931, 188));
        frame_Head->setFrameShape(QFrame::StyledPanel);
        frame_Head->setFrameShadow(QFrame::Raised);
        local_city = new QLabel(centralWidget);
        local_city->setObjectName(QStringLiteral("local_city"));
        local_city->setGeometry(QRect(0, 940, 311, 51));
        QFont font5;
        font5.setFamily(QStringLiteral("Abyssinica SIL"));
        font5.setPointSize(30);
        local_city->setFont(font5);
        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(1540, 810, 171, 71));
        QFont font6;
        font6.setPointSize(20);
        font6.setBold(true);
        font6.setWeight(75);
        pushButton_exit->setFont(font6);
        pushButton_door = new QPushButton(centralWidget);
        pushButton_door->setObjectName(QStringLiteral("pushButton_door"));
        pushButton_door->setGeometry(QRect(1340, 810, 161, 71));
        pushButton_door->setFont(font6);
        pushButton_light = new QPushButton(centralWidget);
        pushButton_light->setObjectName(QStringLiteral("pushButton_light"));
        pushButton_light->setGeometry(QRect(1150, 810, 151, 71));
        pushButton_light->setFont(font6);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1391, 940, 61, 41));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(440, 770, 471, 181));
        horizontalFrame = new QFrame(centralWidget);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(10, 200, 891, 561));
        horizontalLayout_8 = new QHBoxLayout(horizontalFrame);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame = new QFrame(horizontalFrame);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 70, 261, 381));
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
        label->setGeometry(QRect(0, 0, 181, 51));
        label->setFont(font3);
        verticalLayoutWidget->raise();
        label->raise();

        horizontalLayout_8->addWidget(frame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        frame_3 = new QFrame(horizontalFrame);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_5 = new QWidget(frame_3);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(50, 70, 261, 381));
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
        label_18->setGeometry(QRect(0, 0, 201, 51));
        label_18->setFont(font3);
        verticalLayoutWidget_5->raise();
        label_18->raise();
        frame->raise();
        frame->raise();

        horizontalLayout_8->addWidget(frame_3);

        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(230, 850, 171, 51));
        label_21->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        frame_2->raise();
        week->raise();
        lcdNumber->raise();
        frame_Head->raise();
        local_city->raise();
        pushButton_exit->raise();
        pushButton_door->raise();
        pushButton_light->raise();
        label_17->raise();
        label_20->raise();
        horizontalFrame->raise();
        label_21->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The most enjoyable Smart Home", 0));
        label_11->setText(QApplication::translate("MainWindow", "\350\277\220\345\212\250\346\214\207\346\225\260 \357\274\232", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\210\222\351\200\202\346\214\207\346\225\260 \357\274\232", 0));
        label_13->setText(QApplication::translate("MainWindow", "\347\251\272\346\260\224\350\264\250\351\207\217 \357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\204\237\345\206\222\346\214\207\346\225\260 \357\274\232", 0));
        label_15->setText(QApplication::translate("MainWindow", "\347\251\277\350\241\243\346\214\207\346\225\260 \357\274\232", 0));
        label_16->setText(QApplication::translate("MainWindow", "\347\264\253\345\244\226\347\272\277\346\214\207\346\225\260 \357\274\232", 0));
        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_19->setText(QApplication::translate("MainWindow", "\347\224\237\346\264\273\350\264\264\345\243\253 ", 0));
        week->setText(QString());
        local_city->setText(QString());
        pushButton_exit->setText(QApplication::translate("MainWindow", "EXIT", 0));
        pushButton_door->setText(QApplication::translate("MainWindow", "Open door", 0));
        pushButton_light->setText(QApplication::translate("MainWindow", "Open light", 0));
        label_17->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264\346\230\276\347\244\272\345\214\272\345\237\237", 0));
        label_1->setText(QApplication::translate("MainWindow", "\346\270\251      \345\272\246 \357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "\346\271\277       \345\272\246 \357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\205\211        \344\272\256 \357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\347\251\272\346\260\224\350\264\250\351\207\217 \357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\234\211\345\256\263\346\260\224\344\275\223 \357\274\232", 0));
        label->setText(QApplication::translate("MainWindow", "\345\256\244\345\206\205\347\216\257\345\242\203 ", 0));
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251        \345\272\246 \357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "\344\275\223\346\204\237\346\270\251\345\272\246 \357\274\232", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\271\277        \345\272\246 \357\274\232", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\244\251        \346\260\224  \357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "\351\243\216        \345\212\233  \357\274\232", 0));
        label_18->setText(QApplication::translate("MainWindow", "\345\256\244\345\244\226\347\216\257\345\242\203 ", 0));
        label_21->setText(QApplication::translate("MainWindow", "\347\233\221\346\216\247\345\214\272\345\237\237", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
