#include <float.h>
#include <limits.h>
#include "matlib.h"


//scitani
double add_dd(double a, double b){
	return a+b;
}

int add_ii(int a, int b){
	return a+b;
}
double add_di(double a, int b){
	return a+b;
}
double add_id(int a, double b){
	return a+b;
}

// odcitani
double sub_dd(double a, double b){
	return a-b;
}
int sub_ii(int a, int b){
	return a-b;
}
double sub_di(double a, int b){
	return a-b;
}
double sub_id(int a, double b){
	return a-b;
}

// nasobeni
double mul_dd(double a, double b){
	return a*b;
}
int mul_ii(int a, int b){
	return a*b;
}
double mul_di(double a, int b){
	return a*b;
}
double mul_id(int a, double b){
	return a*b;
}

// deleni
double div_dd(double a, double b){
	if (b==0){
		return DBL_MAX;
	}
	return a/b;
}
double div_ii(int a, int b){
	if (b==0){
		return DBL_MAX;
	}
	return a/b;
}
double div_di(double a, int b){
	if (b==0){
		return DBL_MAX;
	}
	return a/b;
}
double div_id(int a, double b){
	if (b==0){
		return DBL_MAX;
	}
	return a/b;
}

// faktorial
double fact(int n){
	if (n < 0){
		return -1;
	}
        double sum=1;
	for (int i = 2; i<=n; i++){
		sum *= i;
	}
	return sum;
}

// mocnina
double ivs_pow(double a, int n){
        if (n < 0){
		return -1;
	}
        if (n == 0)
            return 1;
        double sum=1;
	for (int i=1;i<=n; i++){
		sum*=a;
	}
	return sum;
}

double ivs_exp(double a, int n){
        return a*ivs_pow(10,n);
}


