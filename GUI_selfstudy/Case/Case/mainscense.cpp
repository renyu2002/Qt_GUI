#include "mainscense.h"
#include "ui_mainscense.h"

MainScense::MainScense(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScense)
{
    ui->setupUi(this);
}

MainScense::~MainScense()
{
    delete ui;
}

