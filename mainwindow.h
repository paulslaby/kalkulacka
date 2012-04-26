#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <math.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initCalc();
    bool pointFlag;
    double operand1;
    double operand2;
    double result;
    bool checkInteger(double number);
    bool operatorFlag;
    int currentOperator;
    enum {PLUS, MINUS, MUL, DIV, POW, EXP};
    void markError();
    void computeResult();
    void displayResult();


private slots:
    void on_actionQuit_triggered();
    void on_actionHelp_triggered();
    void numberClicked();
    void pointClicked();
    void operatorClicked();
    void unaryOperatorClicked();
    void equalsClicked();
    void clearClicked();
};

#endif // MAINWINDOW_H
