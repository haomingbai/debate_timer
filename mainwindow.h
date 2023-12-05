#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
//#include <QtMultimedia/qsoundeffect>
//#include "C:\Qt\Tools\QtDesignStudio\qt6_design_studio_reduced_version\include\QtMultimedia\qsoundeffect.h"
#include <QtMultimedia/QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    qint8 counter;
    qint64 rmtime;
    qint64 time;
    qint64 timesec;
    //QTime ref(0,0,0);
    bool state=1; //running 1;paused 0;
    //QTimer *timer=new QTimer(this);
    QTimer *refresh=new QTimer(this);
    QSoundEffect *bell = new QSoundEffect;


private slots:
    void BeginTimer();
    void NextTimer();
    void PauseTimer();
    void EndTimer();
    void handleTimeout();
    void refreshTime();
    QString secsToTime(int s);

};
#endif // MAINWINDOW_H
