#include "quadraticequationcalcmainwindow.h"
#include "ui_quadraticequationcalcmainwindow.h"
#include <QDoubleValidator>
#include <QMessageBox>
#include <QDebug>

QuadraticEquationCalcMainWindow::QuadraticEquationCalcMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QuadraticEquationCalcMainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->lineEdit->setValidator(new QDoubleValidator);
    ui->lineEdit_2->setValidator(new QDoubleValidator);
    ui->lineEdit_3->setValidator(new QDoubleValidator);
}

QuadraticEquationCalcMainWindow::~QuadraticEquationCalcMainWindow()
{
    delete ui;
}

void QuadraticEquationCalcMainWindow::EquationCalc()
{
    QLocale polish (QLocale::Polish);
    QMessageBox msgBox;
    QString tmpStr;
    ui->textBrowser->clear();
    double a,b,c,x1,x2=0.0,delta=0.0;
    a=polish.toDouble(ui->lineEdit->text());  //i used QLocale polish to convert "," to "." in double values
    b=polish.toDouble(ui->lineEdit_2->text());
    c=polish.toDouble(ui->lineEdit_3->text());
    if (a==0){
        msgBox.setText("wrong parameters (A cannot be 0 )");
        msgBox.exec();
        return;
    }
    QString aStr,bStr,cStr;
    aStr=QString("%1").arg(a);
    if (b>=0)
        bStr=QString("+%1").arg(b);
    else
        bStr=QString("%1").arg(b);
    if (c>=0)
        cStr=QString("+%1").arg(c);
    else
        cStr=QString("%1").arg(c);
    ui->textBrowser->append("equation: "+aStr+"x^2 "+bStr+"x "+cStr+" = 0");
    delta=b*b-(4*a*c);
    if (delta>0)
    {
        x1=(-b-sqrt(delta))/2*a;
        x2=(-b+sqrt(delta))/2*a;
        ui->textBrowser->append("1 root= "+QString("%1").arg(x1));
        ui->textBrowser->append("2 root= "+QString("%1").arg(x2));
    }
    if (delta==0)
    {
        x1=-b/(2*a);
        ui->textBrowser->append("1 root= "+QString("%1").arg(x1));
    }
    if (delta<0)
    {
        ui->textBrowser->append("doesn't have solution!");
    }
}

void QuadraticEquationCalcMainWindow::on_pushButton_clicked()
{
    EquationCalc();

}
