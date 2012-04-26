#include "matlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define TRUE 1
#define FALSE 0

int main(){

	double ad = 1.0;
	double bd = 2.0;
	int ai = 3;
	int bi = 4;
	double zero = 0.0;
	int test=TRUE;

// scitani
	printf("TEST: add(double, double): ");
	if (add_dd(ad,bd) == ad+bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: add(int, int):  ");
	if (add_ii(ai,bi) == ai+bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: add(double, int):  ");
	if (add_dd(ad,bi) == ad+bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: add(int, double):  ");
	if (add_id(ai,bd) == ai+bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

// odcitani
	printf("TEST: sub(double, double): ");
	if (sub_dd(ad,bd) == ad-bd){
		printf("OK \n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: sub(int, int): ");
	if (sub_ii(ai,bi) == ai-bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: sub(double, int): ");
	if (sub_dd(ad,bi) == ad-bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: sub(int, double): ");
	if (sub_id(ai,bd) == ai-bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


// nasobeni
	printf("TEST: mul(double, double): ");
	if (mul_dd(ad,bd) == ad*bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: mul(int, int): ");
	if (mul_ii(ai,bi) == ai*bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: mul(double, int): ");
	if (mul_dd(ad,bi) == ad*bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: mul(int, double): ");
	if (mul_id(ai,bd) == ai*bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


// deleni
	printf("TEST: div(double, double): ");
	if (div_dd(ad,bd) == ad/bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: div(int, int): ");
	if (div_ii(ai,bi) == ai/bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: div(double, int): ");
	if (div_dd(ad,bi) == ad/bi){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}


	printf("TEST: div(int, double): ");
	if (div_id(ai,bd) == ai/bd){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: div(double, zero): ");
	if (div_dd(ai,zero) == DBL_MAX){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: fact(zero): ");
	if (fact(zero) == 1){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: fact(int): ");
	if (fact(bi) == 24){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: ivs_pow(int, int): ");
	if (ivs_pow(4,3) == 64){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: ivs_pow(int, int): ");
	if (ivs_pow(4,3) == 64){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}

	printf("TEST: ivs_exp(int, int): ");
	if (ivs_exp(4, 3) == 4000){
		printf("OK\n");
	}else{
		printf("FAILED\n");
		test = FALSE;
	}





	if (test == TRUE){
		printf("------------ TESTS OK ------------\n");
	}else{
		printf("------------ TESTS FAILED ------------\n");
		test = FALSE;
	}


}
