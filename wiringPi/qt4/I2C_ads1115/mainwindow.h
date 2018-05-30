#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <ads1115.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void displayValue ( void ) const;

private:
    Ui::MainWindow *ui;
    unsigned int pin;
};

#endif // MAINWINDOW_H
