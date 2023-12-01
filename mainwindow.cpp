#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    //*timer = new QTimer(this);
    //this->setCentralWidget(ui->gridLayout);
    setFixedSize(this->width(),this->height());
    connect(ui->beginDebate,&QPushButton::clicked,this,&MainWindow::BeginTimer);
    connect(ui->nextDebater,&QPushButton::clicked,this,&MainWindow::NextTimer);
    connect(ui->endDebate,&QPushButton::clicked,this,&MainWindow::EndTimer);
    connect(ui->pauseDebate,&QPushButton::clicked,this,&MainWindow::PauseTimer);
    connect(timer,SIGNAL(timeout()),this,SLOT(handleTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::BeginTimer(){}

void MainWindow::EndTimer(){}

void MainWindow::PauseTimer(){}

void MainWindow::NextTimer(){}

void MainWindow::handleTimeout(){}
