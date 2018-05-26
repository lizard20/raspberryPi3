/*
** Program: main.cpp
** Purpose: Blink any valid port
**          using wiringPi library
** Author:  Aldo Nunez
** */


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ( "Blink Port" );
    w.setFixedSize ( 300, 200 );
    w.show();

    return a.exec();
}
