#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
int money = 0;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoke->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);

}

Widget::~Widget()
{

    delete ui;
}

bool Widget:: changeMoney(int n)
{
    if((money + n) < 0) return false;
    money += n;
    ui->number->display(money);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
    }
    else
    {
        ui->pbCoffee->setEnabled(true);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
    }
    else
    {
        ui->pbTea->setEnabled(true);
    }
    if(money<200){
        ui->pbCoke->setEnabled(false);
    }
    else
    {
        ui->pbCoke->setEnabled(true);
    }

    return true;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);

}
void Widget::on_pb50_clicked()
{   changeMoney(50);

}
void Widget::on_pb100_clicked()
{   changeMoney(100);

}
void Widget::on_pb500_clicked()
{   changeMoney(500);

}

void Widget::on_pbCoffee_clicked()
{

    changeMoney(-100);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbReset_clicked()
{

    QMessageBox msgBox;
    int m500 = money/500;
    money = money%500;
    int m100 = money/100;
    money = money%100;
    int m50 = money/50;
    money = money%50;
    int m10 = money/10;
    money = money%10;
    msgBox.information(nullptr, "Reset Coin", QString("500 won =%1\n 100 won = %2\n 50 won = %3\n 10 won = %4\n").arg(m500).arg(m100).arg(m50).arg(m10));
    ui->pbCoke->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->number->display(money);
}
