#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QThread>

QTime ref(0,0,0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //*timer = new QTimer(this);
    //this->setCentralWidget(ui->gridLayout);
    //setFixedSize(this->width(),this->height());
    connect(ui->beginDebate,&QPushButton::clicked,this,&MainWindow::BeginTimer);
    connect(ui->nextDebater,&QPushButton::clicked,this,&MainWindow::NextTimer);
    connect(ui->endDebate,&QPushButton::clicked,this,&MainWindow::EndTimer);
    connect(ui->pauseDebate,&QPushButton::clicked,this,&MainWindow::PauseTimer);
    refresh->setInterval(1000);
    //connect(timer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
    connect(refresh,&QTimer::timeout,this,&MainWindow::refreshTime);
    //refresh->start();
    //time=5000;//

    //timesec=time/1000;

    this->setWindowIcon(QIcon(":/OIP-C.jpg"));

    /*connect(refresh,&QTimer::timeout,this,[=]()mutable{
        int val=100;
        if(val>=0)
        {
            qDebug()<<"倒计时开始";
            val--;
            ui->Timer->display(secsToTime(val));

        }
        else
        {
            refresh->stop();
        }
    });*/
    //ui->Timer->display("12:08");

    ui->pauseDebate->hide();
    ui->endDebate->hide();
    ui->nextDebater->hide();
    ui->Timer->display("88:88");
    //timer->start(5000);
    ui->showDebater->setText("");
    bell->setSource(QUrl::fromLocalFile(":/bell/bell.wav"));
    bell->setVolume(1.0);
    bell->setLoopCount(1);
    ui->label_5->setText("本软件在GPL协议下发布");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BeginTimer(){
    counter=1;
    time=-ui->timeEdit->time().msecsTo(ref);
    timesec=time/1000;
    //timer->start(5000);//
    ui->beginDebate->hide();
    ui->pauseDebate->show();
    ui->endDebate->show();
    ui->nextDebater->show();
    ui->showDebater->setText("PM");
    refresh->start();
    ui->label_5->setText("本软件由HAOMING BAI制作");
}

void MainWindow::EndTimer(){
    //timer->stop();
    ui->pauseDebate->hide();
    ui->endDebate->hide();
    ui->nextDebater->hide();
    ui->showDebater->setText("");
    ui->beginDebate->show();
    counter=0;
    timesec=0;
    refresh->stop();
    ui->Timer->display("88:88");
    ui->pauseDebate->setText("暂停辩论");
    ui->label_5->setText("本软件在GPL协议下发布");
}

void MainWindow::PauseTimer(){
    if(state==1){
        //rmtime=timer->remainingTime();
        //timer->stop();
        refresh->stop();
        state=0;
        ui->pauseDebate->setText("继续辩论");
        ui->label_5->setText("这个软件是自由的！");
    }else{
        state=1;
        //timer->start(rmtime);
        refresh->start();
        ui->pauseDebate->setText("暂停辩论");
        if(counter<8) ui->label_5->setText("本软件由HAOMING BAI制作");
        else ui->label_5->setText("本软件无任何担保");
    }
}

void MainWindow::NextTimer(){
    counter++;
    handleTimeout();
    //timer->start(5000); //1000 should be substituted
    timesec=time/1000;
    switch(counter){
    case 2:{
        ui->showDebater->setText("LO");
        break;
    }
    case 3:{
        ui->showDebater->setText("DPM");
        break;
    }
    case 4:{
        ui->showDebater->setText("DLO");
        break;
    }
    case 5:{
        ui->showDebater->setText("MG");
        break;
    }
    case 6:{
        ui->showDebater->setText("MO");
        break;
    }
    case 7:{
        ui->showDebater->setText("GW");
        break;
    }
    case 8:{
        ui->showDebater->setText("OW");
        break;
        ui->nextDebater->hide();
    }
    }
    state=1;
    refresh->start();
    ui->pauseDebate->setText("暂停辩论");
}

void MainWindow::handleTimeout(){
    //timer->stop();
    if(counter>8){
        EndTimer();
    }else if(counter==8){
        //ui->pauseDebate->hide();
        ui->nextDebater->hide();
        ui->label_5->setText("本软件无任何担保");
    }
}


QString MainWindow::secsToTime(int s)
{
    int m=0;
    s%=3600;
    m=s/60;
    s%=60;
    //qDebug()<<"m"<<m;
    QString str=QString::number(m)+":"+QString::number(s);
    return str;
}

void MainWindow::refreshTime(){
    if(timesec){
        timesec--;
        ui->Timer->display(secsToTime(timesec));
    }else{
        ui->Timer->display("88:88");
        refresh->stop();
    }
    qDebug()<<(int)(time/1000);
    if((int)(time/1000)-60==timesec||timesec==60) bell->play();
    else if(timesec==0){
        bell->play();
        QThread::msleep(500);
        bell->play();
        refresh->stop();
    }
}
