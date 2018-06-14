/**
** ** Program: main.cpp
** ** Purpose: Generates a PWM signal on Pin 35
** **          using wiringPi library.
** **          To execute: $ gksudo ./PWM
** ** Author:  Aldo Nunez
** **/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ( "PWM" );
    w.setFixedSize ( 660, 440 );
    w.show();

    return a.exec();
}
