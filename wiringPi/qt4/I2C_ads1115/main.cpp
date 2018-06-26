/*
** Program: main.cpp
** Purpose: I2C_ads1115, reads analog data using 
**          ADS1115, 16 bits A/D converter chip,
**          through i2c-1 port
** Author:  Aldo Nunez
*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize ( 350, 200 );
    w.show();

    return a.exec();
}
