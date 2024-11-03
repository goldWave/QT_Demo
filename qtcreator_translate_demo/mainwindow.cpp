#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    auto testStr = tr("not good");
    qDebug() << "not good > " << testStr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

