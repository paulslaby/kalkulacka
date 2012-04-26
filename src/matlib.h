/**
 * @file matlib.h
 * @author Pavel Slabý <xslaby00@stud.fit.vutbr.cz>
 * @author Peter Šlosár <xslosa00@stud.fit.vutbr.cz>
 * @author Martin Slezáček <xsleza18@stud.fit.vutbr.cz>
 *
 * 3. projekt do predmetu IVS - kalkulačka. Hlavičkový súbor pre matlib.cpp.
 */

#ifndef	_MATLIB_H
#define	_MATLIB_H

/** Súčet dvoch čísel
  * @param a Prvý operand súčtu
  * @param b Druhý operand súčtu
  * @return Výsledok súčtu
  */
double add_dd(double a, double b);

int add_ii(int a, int b);
double add_di(double a, int b);
double add_id(int a, double b);

/** Rozdiel dvoch čísel
  * @param a Prvý operand rozdielu
  * @param b Druhý operand rozdielu
  * @return Výsledok rozdielu
  */
double sub_dd(double a, double b);

int sub_ii(int a, int b);
double sub_di(double a, int b);
double sub_id(int a, double b);

/** Súčin dvoch čísel
  * @param a Prvý operand súčinu
  * @param b Druhý operand súčinu
  * @return Výsledok súčinu
  */
double mul_dd(double a, double b);

int mul_ii(int a, int b);
double mul_di(double a, int b);
double mul_id(int a, double b);

/** Podiel dvoch čísel
  * @param a Prvý operand podielu
  * @param b Druhý operand podielu
  * @return Výsledok podielu
  */
double div_dd(double a, double b);

double div_ii(int a, int b);
double div_di(double a, int b);
double div_id(int a, double b);

/** Výpočet faktoriálu
  * @param n Číslo, ktorého sa počíta faktoriál
  * @return Výsledok faktoriálu
  */
double fact(int n);

/** Výpočet mocniny
  * @param a Základ mocniny
  * @param n Exponent
  * @return Výsledok umocnenia
  */
double ivs_pow(double a, int n);

/** Výpočet násobenia mocninou desiatky
  * @param a Číslo, ktoré sa násobí
  * @param n Mocnina desiatky
  * @return Výsledok násobenia
  */
double ivs_exp(double a, int n);

#endif /* matlib.h  */
