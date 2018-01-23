#ifndef QUADRATICEQUATIONCALCMAINWINDOW_H
#define QUADRATICEQUATIONCALCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class QuadraticEquationCalcMainWindow;
}

class QuadraticEquationCalcMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadraticEquationCalcMainWindow(QWidget *parent = 0);
    ~QuadraticEquationCalcMainWindow();

private slots:
    void on_pushButton_clicked();
    void EquationCalc();

private:
    Ui::QuadraticEquationCalcMainWindow *ui;
};

#endif // QUADRATICEQUATIONCALCMAINWINDOW_H
