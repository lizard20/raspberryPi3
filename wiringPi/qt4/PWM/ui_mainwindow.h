/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QDial *dialFreq;
    QLabel *labelFreq;
    QLCDNumber *lcdFreq;
    QLabel *labelFreqRange;
    QLabel *labelFreqUnits;
    QDial *dialDC;
    QLabel *labelDC;
    QLCDNumber *lcdDC;
    QLabel *labelDCRange;
    QLabel *labelDCUnits;
    QLabel *labelTitle;
    QLabel *labelPort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(686, 553);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dialFreq = new QDial(centralwidget);
        dialFreq->setObjectName(QString::fromUtf8("dialFreq"));
        dialFreq->setGeometry(QRect(100, 250, 151, 151));
        dialFreq->setMinimum(-1);
        dialFreq->setMaximum(100001);
        dialFreq->setWrapping(false);
        dialFreq->setNotchesVisible(true);
        labelFreq = new QLabel(centralwidget);
        labelFreq->setObjectName(QString::fromUtf8("labelFreq"));
        labelFreq->setGeometry(QRect(110, 420, 120, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        labelFreq->setFont(font);
        lcdFreq = new QLCDNumber(centralwidget);
        lcdFreq->setObjectName(QString::fromUtf8("lcdFreq"));
        lcdFreq->setGeometry(QRect(90, 130, 191, 61));
        labelFreqRange = new QLabel(centralwidget);
        labelFreqRange->setObjectName(QString::fromUtf8("labelFreqRange"));
        labelFreqRange->setGeometry(QRect(120, 200, 121, 21));
        labelFreqRange->setFont(font);
        labelFreqUnits = new QLabel(centralwidget);
        labelFreqUnits->setObjectName(QString::fromUtf8("labelFreqUnits"));
        labelFreqUnits->setGeometry(QRect(290, 150, 31, 21));
        labelFreqUnits->setFont(font);
        dialDC = new QDial(centralwidget);
        dialDC->setObjectName(QString::fromUtf8("dialDC"));
        dialDC->setGeometry(QRect(380, 250, 151, 151));
        dialDC->setMinimum(-1);
        dialDC->setMaximum(101);
        dialDC->setValue(50);
        dialDC->setWrapping(false);
        dialDC->setNotchesVisible(true);
        labelDC = new QLabel(centralwidget);
        labelDC->setObjectName(QString::fromUtf8("labelDC"));
        labelDC->setGeometry(QRect(400, 420, 135, 41));
        labelDC->setFont(font);
        lcdDC = new QLCDNumber(centralwidget);
        lcdDC->setObjectName(QString::fromUtf8("lcdDC"));
        lcdDC->setGeometry(QRect(360, 130, 191, 61));
        lcdDC->setProperty("intValue", QVariant(50));
        labelDCRange = new QLabel(centralwidget);
        labelDCRange->setObjectName(QString::fromUtf8("labelDCRange"));
        labelDCRange->setGeometry(QRect(420, 200, 81, 21));
        labelDCRange->setFont(font);
        labelDCUnits = new QLabel(centralwidget);
        labelDCUnits->setObjectName(QString::fromUtf8("labelDCUnits"));
        labelDCUnits->setGeometry(QRect(560, 150, 31, 21));
        labelDCUnits->setFont(font);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(140, 10, 411, 51));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(90, 70, 121, 51));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        labelPort->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 686, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        labelFreq->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">Frequency</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelFreqRange->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">0 - 100 K</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelFreqUnits->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">Hz</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelDC->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">Duty Cycle</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelDCRange->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">0 - 100</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelDCUnits->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">%</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#204a87;\">Square Wave Generator </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#3465a4;\">Port 35</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
