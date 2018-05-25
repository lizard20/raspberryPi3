/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QComboBox *portBox;
    QLabel *label;
    QPushButton *quitButton;
    QLabel *status;
    QPushButton *blinkButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(279, 195);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        portBox = new QComboBox(centralWidget);
        portBox->setObjectName(QString::fromUtf8("portBox"));
        portBox->setGeometry(QRect(100, 10, 48, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        portBox->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 51, 30));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(140, 90, 80, 30));
        QFont font2;
        font2.setPointSize(12);
        quitButton->setFont(font2);
        status = new QLabel(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(50, 50, 141, 30));
        status->setFont(font1);
        blinkButton = new QPushButton(centralWidget);
        blinkButton->setObjectName(QString::fromUtf8("blinkButton"));
        blinkButton->setGeometry(QRect(40, 90, 80, 30));
        blinkButton->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        quitButton->raise();
        blinkButton->raise();
        status->raise();
        label->raise();
        portBox->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 279, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(quitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        portBox->clear();
        portBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "33", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "35", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "36", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "37", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "40", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        status->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        blinkButton->setText(QApplication::translate("MainWindow", "Blink", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
