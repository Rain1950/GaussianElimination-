#include "../../trunk/src/mat_io.h"
#include "../../trunk/src/gauss.h"
#include "../../trunk/src/backsubst.h"
#include "testy_mr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int  CheckValidatedData(){
	Matrix * A = readFromFile("Validated1");
	Matrix * b = readFromFile("Validated2");
	Matrix * x;

	int res = eliminate(A,b);
   
	x = createMatrix(b->r, 1);
	if (x != NULL) res = backsubst(x,A,b);
   	if(x->data[0][0] != 1 || x->data[0][1] != 2){
	    printf("Test 1 - poprawne dane 2x2: Wystąpił BŁĄD!");
	    return 1;
	}
	else{
	    printf("Test 1 - poprawne dane 2x2: OK");
	}

  	freeMatrix(x);
  	freeMatrix(A);
  	freeMatrix(b);
	return 0;



}

int  CheckDiagonalElementSelection(){
	Matrix* mat = readFromFile("Diagonal");
        if (fabs(mat->data[1][1]) < 1e-12) {
            printf("Test 2 - Selekcja elementu diagonalnego: Wystąpił BŁĄD");
            return 1;
        }
	else{
	    printf("Test 2 - Selekcja elementu diagonalnego: OK");
	    return 0;
	}


}

int  CheckSingularMatrix(){
	Matrix* A = readFromFile("Singular1");
	Matrix* B = readFromFile("Singular2");

	if(eliminate(A,B) != 1){
	  printf("Test 3 - Macierz osobliwa: Wystąpił Błąd");
	  return 1;
	}
	else{
	  printf("Test 3 - Macierz osobliwa: OK");
	  return 0;
	}

}

int CheckWrongFormat(){
	if(readFromFile("WrongFormat") != NULL){
	  printf("Test 4 - Zły format: Wystąpił Błąd");
	  return 1;
	}else{
	  printf("Test 4 - Zły format: OK");
	  return 0;
	}
}

