/**
** ** Program: main.cpp
** ** Purpose: PWM, generates a PWM signal on Pin 35
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
    w.show();
    return a.exec();
}
