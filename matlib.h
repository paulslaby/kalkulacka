#ifndef	_MATLIB_H
#define	_MATLIB_H




//scitani
double add_dd(double a, double b);
int add_ii(int a, int b);
double add_di(double a, int b);
double add_id(int a, double b);

//odcitani
double sub_dd(double a, double b);
int sub_ii(int a, int b);
double sub_di(double a, int b);
double sub_id(int a, double b);


//nasobeni
double mul_dd(double a, double b);
int mul_ii(int a, int b);
double mul_di(double a, int b);
double mul_id(int a, double b);


//deleni
double div_dd(double a, double b);
double div_ii(int a, int b);
double div_di(double a, int b);
double div_id(int a, double b);

//faktorial
double fact(int n);

//mocnina
double ivs_pow(double a, int n);

//mocnina
double ivs_exp(double a, int n);

#endif /* matlib.h  */
