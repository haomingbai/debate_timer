#include "Debate Timer.h"

Debate Timer::Debate Timer(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_Debate Timer)
{
    ui->setupUi(this);
}

Debate Timer::~Debate Timer()
{
    delete ui; 
}