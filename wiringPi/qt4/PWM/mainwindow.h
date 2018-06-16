#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtGlobal>
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
    quint32 freq;
    quint8 dutyCycleP;
    quint8 pwmPort;
    QMap < quint32, QString > frequencyRange;

    void config ( void );
    void pwmOutput ( void ) const;
};

#endif // MAINWINDOW_H
