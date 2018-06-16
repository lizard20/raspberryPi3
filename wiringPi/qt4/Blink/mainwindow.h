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

private:
    Ui::MainWindow *ui;
    quint8 port;
    quint8 state;
    QTimer* timer;
};

#endif // MAINWINDOW_H
