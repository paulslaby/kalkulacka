/**
 * @file mainwindow.cpp
 * @author Peter Šlosár <xslosa00@stud.fit.vutbr.cz>
 * @author Pavel Slabý <xslaby00@stud.fit.vutbr.cz>
 * @author Martin Slezáček <xsleza18@stud.fit.vutbr.cz>
 *
 * 3. projekt do predmetu IVS - kalkulačka. Obsah hlavného okna.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matlib.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // inicializacia premennych a ciselnika
    initCalc();

    // spojenie signalov tlacidiel so slotmi
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
    // zobrazenie messageboxu s napovedou
    QMessageBox helpMsg(QMessageBox::Information, helpTitle, helpString, QMessageBox::Ok, this);
    helpMsg.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::initCalc()
{
    // vynulovanie operandov a vysledku
    this->operand1 = 0;
    this->operand2 = 0;
    this->result = 0;
    // desatinna ciarka este nebola zadana
    this->pointFlag = false;
    // vycistenie labelu s operatormi
    ui->label->clear();
    ui->labelExp->hide();
    // nebol este zadany ziadny operator
    this->operatorFlag = false;
    // na pociatku je zvoleny operator scitania, pretoze sucet s nulou produkuje prve zadane cislo
    this->currentOperator = 0;
}

bool MainWindow::checkInteger(double number)
{
    double intpart;
    // oddelenie celej a desatinnej casti cisla typu double
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
    // ziskanie odosielatela signalu
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    // ak uz bol zadany operator
    if (this->operatorFlag)
    {
        // zadavame nove cislo a vynulujeme prislusne priznaky
        ui->lineEdit->clear();
        this->operatorFlag = false;
        this->pointFlag = false;
    }

    // nula nemoze byt prvou cifrou
    if (ui->lineEdit->text() == "0")
    {
        ui->lineEdit->setText(clickedButton->text());
    }
    else
    {
        // pridavame dalsie cifry
        ui->lineEdit->setText(ui->lineEdit->text() + clickedButton->text());
    }
}

void MainWindow::pointClicked()
{
    // desatinna ciarka moze byt zadana len raz
    if (!this->pointFlag)
    {
        ui->lineEdit->setText(ui->lineEdit->text() + ".");
    }

    // nastavenie prislusneho priznaku
    this->pointFlag = true;
}

void MainWindow::clearClicked()
{
    // inicializacia kalkulacky
    initCalc();
    // zapis nuly na ciselnik
    ui->lineEdit->setText("0");
}

void MainWindow::operatorClicked()
{
    // nastavenie priznaku, ze bol zadany operator
    this->operatorFlag = true;

    // vypocet vysledku - pri prvom zadanom cisle ho vypise na ciselnik
    computeResult();
    // zobrazenie vysledku
    displayResult();

    // ziskanie odosielatela signalu
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    // volba operatora podla stlaceneho tlacidla
    if (clickedButton->text() == "+")
        this->currentOperator = PLUS;
    else if (clickedButton->text() == "-")
        this->currentOperator = MINUS;
    else if (clickedButton->text() == "\327")  // symbol nasobenia
        this->currentOperator = MUL;
    else if (clickedButton->text() == "\367")  // symbol delenia
        this->currentOperator = DIV;
    else if (clickedButton->text() == "^")
        this->currentOperator = POW;
    else if (clickedButton->text() == "EXP")
        this->currentOperator = EXP;

    // prepnutie na label pre operator EXP - ma inu velkost a preto je osobitne
    if (clickedButton->text() == "EXP")
    {
        ui->label->clear();
        ui->labelExp->show();
    }
    // ak sa nejedna o operaciu EXP, zobrazi sa znamienko v standardnom labeli
    else
    {
        ui->labelExp->hide();
        ui->label->setText(clickedButton->text());
    }

    // ulozenie cisla ako prvy operand
    this->operand1 = ui->lineEdit->text().toDouble();
}

void MainWindow::unaryOperatorClicked()
{
    // nastavenie priznaku, ze bol zadany operator
    this->operatorFlag = true;

    // ziskanie odosielatela signalu
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());

    this->operand1 = ui->lineEdit->text().toDouble();

    // operacia faktorialu
    if (clickedButton->text() == "!")
    {
        // kontrola, ci je zaklad faktorialu celociselny
        if (checkInteger(this->operand1))
        {
            // vypocet a zobrazenie vysledku
            this->result = fact(this->operand1);
            displayResult();
        }
        // zobrazenie chyby
        else
        {
            markError();
        }
    }
    // v pripadnych dalsich vetvach ifu spracovanie dalsich unarnych operatorov

    // pri unarnych operatoroch je nutne vynulovat prvy operand, aby bol vysledok dalsej operacie spravny
    // ak by ostal nevynulovany, kolidoval by a pocitalo by to blbosti
    this->operand1 = 0;
}

void MainWindow::equalsClicked()
{
    // zmazanie labelov s operatormi
    ui->label->clear();
    ui->labelExp->hide();
    // aj = je brane ako operator, aby bolo mozne zadat dalsie cislo od zaciatku a nie len ho nadpojit na sucasny obsah ciselnika
    this->operatorFlag = true;
    // vypocitanie a zobrazenie vysledku
    computeResult();
    displayResult();
    // vynulovanie prveho operandu a nastavenie operatoru na + aby sa korektne mohlo zadat dalsie cislo
    this->operand1 = 0;
    this->currentOperator = 0;
}

void MainWindow::markError()
{
    // prepnutie na label oznamujuci chybu vypoctu
    ui->labelExp->hide();
    ui->label->setText("E");
    // vynulovanie prveho operandu pre korektne dalsie vypocty
    this->operand1 = 0;
}

void MainWindow::computeResult()
{
    // druhym operandom je sucasny obsah ciselnika
    this->operand2 = ui->lineEdit->text().toDouble();

    // vypocet podla prislusneho operatora
    switch (this->currentOperator)
    {
    case PLUS:
        this->result = add_dd(this->operand1, this->operand2);
        break;
    case MINUS:
        this->result = sub_dd(this->operand1, this->operand2);
        break;
    case MUL:
        this->result = mul_dd(this->operand1, this->operand2);
        break;
    case DIV:
        this->result = div_dd(this->operand1, this->operand2);
        break;
    case POW:
        // mocnina musi mat celociselny exponent
        if (checkInteger(this->operand2))
        {
            this->result = ivs_pow(this->operand1, this->operand2);
        }
        // inak to je chyba vypoctu
        else
        {
            this->result = this->operand2;  // aby na ciselniku ostal druhy zadany operand namiesto prveho
            markError();
        }
        break;
    case EXP:
        // nasobenie _celociselnou_ mocninou desiatky
        if (checkInteger(this->operand2))
        {
            this->result = ivs_exp(this->operand1, this->operand2);
        }
        // inak chyba vypoctu
        else
        {
            this->result = this->operand2;  // aby na ciselniku ostal druhy zadany operand namiesto prveho
            markError();
        }
        break;
    default:
        break;
    }
}

void MainWindow::displayResult()
{
    QString output;
    // ciselnik je dimenzovany na 12 platnych cifier + desatinnu ciarku, preto:
    // ak je vysledok zaporny, zobrazi sa 11 cifier, pretoze pribuda znamienko minus
    if (this->result < 0)
    {
        output = QString::number(this->result, 'g', 11);
    }
    // v opacnom pripade sa zobrazi 12 cifier
    else
    {
        output = QString::number(this->result, 'g', 12);
    }
    ui->lineEdit->setText(output);
}
