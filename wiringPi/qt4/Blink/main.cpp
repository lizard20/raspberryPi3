/*
** ** Program: main.cpp
** ** Purpose: Blink, blinks led conected to  Pin 3
** **          using wiringPi library
** ** Author:  Aldo Nunez
** ** */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ( "Blink" );
    w.setFixedSize ( 370, 220 );
    w.show();

    return a.exec();
}
