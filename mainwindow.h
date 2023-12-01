#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    QTimer *timer=new QTimer(this);;

private slots:
    void BeginTimer();
    void NextTimer();
    void PauseTimer();
    void EndTimer();
    void handleTimeout();

};
#endif // MAINWINDOW_H
