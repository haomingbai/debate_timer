#pragma once
#include "ui_Debate Timer.h"
#include <QMainWindow>

class Debate Timer : public QMainWindow {
    Q_OBJECT
    
public:
    Debate Timer(QWidget* parent = nullptr);
    ~Debate Timer();

private:
    Ui_Debate Timer* ui;
};