#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ANIMATIONPERIOD     5
#define ANIMATIONPX         5
#define BTNSIZEY            30
#define STARTX              50
#define STARTY              20
#define FRAMEFIRSTY         120
#define FRAMESECONDY        120
#define FRAMETHIRDY         120
#define FRAMEWIDTH          700


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    animationTimer = new QTimer();
    connect(animationTimer,SIGNAL(timeout()),this,SLOT(animationTimerFunc()));
    animationTimer->setInterval(ANIMATIONPERIOD);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::animationTimerFunc()
{
    if(animationNumber==1)
    {
        ui->f_First->resize(FRAMEWIDTH,ui->f_First->size().height()+ANIMATIONPX);
        ui->pb_Second->move(STARTX,ui->pb_Second->pos().y()+ANIMATIONPX);
        ui->f_Second->move(STARTX,ui->f_Second->pos().y()+ANIMATIONPX);
        ui->pb_Third->move(STARTX,ui->pb_Third->pos().y()+ANIMATIONPX);
        ui->f_Third->move(STARTX,ui->f_Third->pos().y()+ANIMATIONPX);

        if(ui->f_First->size().height()>=FRAMEFIRSTY)
            animationTimer->stop();
    }
    else if(animationNumber == 2)
    {
        ui->f_First->resize(FRAMEWIDTH,ui->f_First->size().height()-ANIMATIONPX);
        ui->pb_Second->move(STARTX,ui->pb_Second->pos().y()-ANIMATIONPX);
        ui->f_Second->move(STARTX,ui->f_Second->pos().y()-ANIMATIONPX);
        ui->pb_Third->move(STARTX,ui->pb_Third->pos().y()-ANIMATIONPX);
        ui->f_Third->move(STARTX,ui->f_Third->pos().y()-ANIMATIONPX);

        if(ui->f_First->size().height()==0)
            animationTimer->stop();
    }
    else if(animationNumber == 3)
    {
        ui->f_Second->resize(FRAMEWIDTH,ui->f_Second->size().height()+ANIMATIONPX);
        ui->pb_Third->move(STARTX,ui->pb_Third->pos().y()+ANIMATIONPX);
        ui->f_Third->move(STARTX,ui->f_Third->pos().y()+ANIMATIONPX);

        if(ui->f_Second->size().height()>=FRAMESECONDY)
            animationTimer->stop();
    }
    else if(animationNumber == 4)
    {
        ui->f_Second->resize(FRAMEWIDTH,ui->f_Second->size().height()-ANIMATIONPX);
        ui->pb_Third->move(STARTX,ui->pb_Third->pos().y()-ANIMATIONPX);
        ui->f_Third->move(STARTX,ui->f_Third->pos().y()-ANIMATIONPX);

        if(ui->f_Second->size().height()==0)
            animationTimer->stop();
    }
    else if(animationNumber == 5)
    {
        ui->f_Third->resize(FRAMEWIDTH,ui->f_Third->size().height()+ANIMATIONPX);

        if(ui->f_Third->size().height()>=FRAMETHIRDY)
            animationTimer->stop();
    }
    else if(animationNumber == 6)
    {
        ui->f_Third->resize(FRAMEWIDTH,ui->f_Third->size().height()-ANIMATIONPX);

        if(ui->f_Third->size().height()==0)
            animationTimer->stop();
    }
}

void MainWindow::on_pb_First_pressed()
{
    if(ui->f_First->size().height()==0)
    {
        animationNumber = 1;
    }
    else
    {
        animationNumber = 2;
    }
    animationTimer->start();
}


void MainWindow::on_pb_Second_pressed()
{
    if(ui->f_Second->size().height()==0)
    {
        animationNumber = 3;
    }
    else
    {
        animationNumber = 4;
    }
    animationTimer->start();
}


void MainWindow::on_pb_Third_pressed()
{
    if(ui->f_Third->size().height()==0)
    {
        animationNumber = 5;
    }
    else
    {
        animationNumber = 6;
    }
    animationTimer->start();
}

