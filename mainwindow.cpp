#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matlib.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initCalc();

    QObject::connect(ui->pushButton0, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton5, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton6, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton7, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton8, SIGNAL(clicked()), this, SLOT(numberClicked()));
    QObject::connect(ui->pushButton9, SIGNAL(clicked()), this, SLOT(numberClicked()));

    QObject::connect(ui->pushButtonPoint, SIGNAL(clicked()), this, SLOT(pointClicked()));

    QObject::connect(ui->pushButtonPlus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    QObject::connect(ui->pushButtonMinus, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    QObject::connect(ui->pushButtonMul, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    QObject::connect(ui->pushButtonDiv, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    QObject::connect(ui->pushButtonPow, SIGNAL(clicked()), this, SLOT(operatorClicked()));
    QObject::connect(ui->pushButtonExp, SIGNAL(clicked()), this, SLOT(operatorClicked()));

    QObject::connect(ui->pushButtonFact, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));

    QObject::connect(ui->pushButtonEquals, SIGNAL(clicked()), this, SLOT(equalsClicked()));

    QObject::connect(ui->pushButtonC, SIGNAL(clicked()), this, SLOT(clearClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHelp_triggered()
{
    QString helpTitle = QString::fromUtf8("Nápoveda");
    QString helpString = QString::fromUtf8("Jednoduchá kalkulačka podporujúca operácie sčítania, odčítania, násobenia a delenia. "
                                           "Z pokročilejších funkcií podporuje mocninu, faktoriál a násobenie mocninou desiatky "
                                           "(tlačidlo EXP). Tlačidlo C vymaže výpočet. Výsledok výpočtu sa zobrazí po stlačení "
                                           "tlačidla =. Písmeno E naľavo od číselníka značí nepovolený výpočet.\n\nPríjemné "
                                           "počítanie praje team Miracle Coders.\n");
    QMessageBox helpMsg(QMessageBox::Information, helpTitle, helpString, QMessageBox::Ok, this);
    helpMsg.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::initCalc()
{
    this->operand1 = 0;
    this->operand2 = 0;
    this->result = 0;
    this->pointFlag = false;
    ui->label->clear();
    this->operatorFlag = false;
}

bool MainWindow::checkInteger(double number)
{
    double intpart;
    if (modf(number, &intpart) == 0.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::numberClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    if (this->operatorFlag)
    {
        ui->lineEdit->clear();
        this->operatorFlag = false;
    }

    if (ui->lineEdit->text() == "0")
    {
        ui->lineEdit->setText(clickedButton->text());
    }
    else
    {
        ui->lineEdit->setText(ui->lineEdit->text() + clickedButton->text());
    }
}

void MainWindow::pointClicked()
{
    if (!this->pointFlag)
    {
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
    }

    this->pointFlag = true;
}

void MainWindow::clearClicked()
{
    ui->lineEdit->setText("0");

    initCalc();

}

void MainWindow::operatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    ui->label->setText(clickedButton->text());
    this->operatorFlag = true;
}

void MainWindow::unaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    this->operand1 = ui->lineEdit->text().toDouble();

    if (clickedButton->text() == "!")
    {
        if (checkInteger(this->operand1))
        {

        }
        else
        {
            ui->label->setText("E");
        }
    }
}

void MainWindow::equalsClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    qDebug() << clickedButton->text();
}
