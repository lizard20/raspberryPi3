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
    void on_pushButtonBlink_clicked();
    void blink ( void );
    void config_port ( void );

private:
    Ui::MainWindow *ui;
    unsigned short int state;
    QList < int > ports;
    QTimer* timer;
};

#endif // MAINWINDOW_H
