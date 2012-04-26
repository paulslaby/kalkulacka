/**
 * @file mainwindow.h
 * @author Peter Šlosár <xslosa00@stud.fit.vutbr.cz>
 * @author Pavel Slabý <xslaby00@stud.fit.vutbr.cz>
 * @author Martin Slezáček <xsleza18@stud.fit.vutbr.cz>
 *
 * 3. projekt do predmetu IVS - kalkulačka. Hlavičkový súbor pre mainwindow.cpp.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <math.h>

namespace Ui {
    class MainWindow;
}

/**
 * Trieda pre hlavné okno. Obstaráva GUI kalkulačky
 * a aplikačnú logiku za použitia matematickej knižnice.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// Konštruktor hlavného okna
    explicit MainWindow(QWidget *parent = 0);
    /// Deštruktor
    ~MainWindow();

private:
    /// Prvky GUI
    Ui::MainWindow *ui;
    /// Inicializuje kalkulačku do počiatočného stavu
    void initCalc();
    /// Príznak zadanej desatinnej čiarky
    bool pointFlag;
    /// Prvý operand matematickej operácie
    double operand1;
    /// Druhý operand matematickej operácie
    double operand2;
    /// Výsledok matematickej operácie
    double result;
    /** Overí, či je číslo celé
      * @param number Číslo na overenie
      * @return true, ak je číslo celé, v opačnom prípade vracia false
      */
    bool checkInteger(double number);
    /// Príznak zadaného operátora
    bool operatorFlag;
    /// Aktuálny operátor - hodnota z výčtu
    int currentOperator;
    /// Výčet operátorov
    enum {PLUS, MINUS, MUL, DIV, POW, EXP} operators;
    /// Vyznačí chybu výpočtu
    void markError();
    /// Vypočíta výsledok podľa aktuálneho operátora
    void computeResult();
    /// Zobrazí výsledok na číselník kalkulačky
    void displayResult();


private slots:
    /// Akcia pre ukončenie z menu
    void on_actionQuit_triggered();
    /// Akcia pre zobrazenie nápovedy
    void on_actionHelp_triggered();
    /// Akcia pre stlačenie tlačidla s číslom
    void numberClicked();
    /// Akcia pre stlačenie tlačidla desatinnej čiarky
    void pointClicked();
    /// Akcia pre stlačenie tlačidla operátora s dvoma operandmi
    void operatorClicked();
    /// Akcia pre stlačenie tlačidla unárneho operátora
    void unaryOperatorClicked();
    /// Akcia pre stlačenie tlačidla rovná sa
    void equalsClicked();
    /// Akcia pre stlačenie tlačidla C
    void clearClicked();
};

#endif // MAINWINDOW_H
