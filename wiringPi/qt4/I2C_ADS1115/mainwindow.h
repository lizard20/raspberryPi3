#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <wiringPiI2C.h>
#include "i2c_ads1115.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow ( QWidget *parent = 0 ) ;
    ~MainWindow();

private slots:
    void displayValue ( void ) const;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
