#include "mainwindow.h"
#include "mydice.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->rollButton,SIGNAL(clicked()),this,SLOT(RollButtonPressed()));
    connect(ui->RollFourSided,SIGNAL(clicked()),this,SLOT(RollFourSided()));
    connect(ui->RollSixSided,SIGNAL(clicked()),this,SLOT(RollSixSided()));
    connect(ui->RollEightSided,SIGNAL(clicked()),this,SLOT(RollEightSided()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RollAndDisplay(int sides, int count)
{
    ui->output->clear();

    MyDice dice(sides,count);
    int total = dice.RollAll();

    QString out = "Total: "+ QString::number(total)+"\r\n";
    QList<Die*> d = dice.GetDice();
    for(int i=0;i<d.length();i++){
        out += "--------------------------------------------------";
        out += "Die "+QString::number(i)+":\r\n";
        out += "Sides: "+QString::number(d[i]->GetSides())+"\r\n";
        out += "Result: "+QString::number(d[i]->GetResult())+"\r\n";
        out += "--------------------------------------------------";
    }
    ui->output->setText(out);
}

void MainWindow::RollButtonPressed()
{
    RollAndDisplay(ui->sides->value(),ui->numDice->value());
}

void MainWindow::RollFourSided()
{
    RollAndDisplay(4,ui->FourSided->value());
}
void MainWindow::RollSixSided()
{
    RollAndDisplay(6,ui->SixSided->value());
}
void MainWindow::RollEightSided()
{
    RollAndDisplay(8,ui->EightSided->value());
}
