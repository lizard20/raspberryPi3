#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <wiringPi.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dialFreq_valueChanged(int value);
    void on_dialDC_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    
    // frequency
    quint32 freq;
    // duty cyle percentage
    quint8 dutyCycleP;
    // PWM port number
    quint8 pwmPort;
 
    // function to config PWM port
    void config ( void );
    // function to generate pwm signal
    void pwmOutput ( void ) const;
};
#endif // MAINWINDOW_H
