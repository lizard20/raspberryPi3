#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <wiringPi.h>

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
    void on_blinkButton_clicked ();
    void blink ();

private: 
    Ui::MainWindow *ui;
    unsigned short int port;
    unsigned short int state;
    QTimer* timer;
};

#endif // MAINWINDOW_H
