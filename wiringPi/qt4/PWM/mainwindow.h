#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
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
    void on_freqSlider_valueChanged ( int );
    void on_dcSlider_valueChanged ( int );
    void on_comboBox_currentIndexChanged ( int );

private:
    Ui::MainWindow *ui;
    int freq;
    int dutyCycleP;
    int pwmPort;
    QMap < int, QString > frequencyRange;

    void config ( void );
    void pwmOutput ( void );
};

#endif // MAINWINDOW_H
