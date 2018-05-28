/*
** Program: main.cpp
** Purpose: Read analog data using 
**          ADS1115, 16 bits A/D converter,
**          through i2c-1 port
** Author:  Aldo Nunez
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ( "ADS1115" ); 
    w.setFixedSize ( 250, 190 );
    w.show();

    return a.exec();
}
