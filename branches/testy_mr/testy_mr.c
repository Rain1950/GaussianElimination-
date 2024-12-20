#include "testy_mr.h"
#include <stdio.h>
#include <math.h>
#include "../../trunk/src/mat_io.h"
#include "../../trunk/src/gauss.h"
#include "../../trunk/src/backsubst.h"
#include <stdlib.h>

int main(){
	if(CheckValidatedData() == 1) return 1;
	if(CheckDiagonalElementSelection() ==1) return 1;
	if(CheckSingularMatrix() == 1) return 1;
	if(CheckWrongFormat() == 1) return 1;
}
int  CheckValidatedData(){
 	Matrix * A = readFromFile("dane/A");
	Matrix * b = readFromFile("dane/b");
	Matrix * x;
	
	int res = eliminate(A,b);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
  		if(fabs(x->data[0][0]) - 29.518072 < 1e-2  && fabs( x->data[1][0]) -  19.759036 < 1e-2){	
			printf("Test 1 - Poprawne dane 2x2: OK\n");
			return 0;
		}
    	}

	printf("Test 1 - Poprawne dane 2x2: Wykryto błąd\n");
	return 1;

  	freeMatrix(x);
  	freeMatrix(A);
  	freeMatrix(b);



}

int CheckDiagonalElementSelection(){
	Matrix* mat = readFromFile("dane/diagonal");
	if (fabs(mat->data[0][0]) < 1e-12) {
	    printf("Test 2 - Selekcja elementu diagonalnego: OK\n");
            return 0;
        }
        
	printf("Test 2 - Selekcja elementu diagonalnego: Wykryto Błąd\n");

	return 1;
}
int  CheckSingularMatrix(){
	Matrix* A = readFromFile("dane/singularity1");
	Matrix* b = readFromFile("dane/singularity2");
	
	for(int i = 0; i< A->r; i++){
		if(A->data[i][i] == 0){
			printf("Test 3 - Macierz osobliwa: OK\n");
			return 0;
		}
	}
	
	printf("Test 3 - Macierz osobliwa: Wykryto Błąd\n");
	return 1;
}

int CheckWrongFormat(){
	
	Matrix* mat = readFromFile("dane/wrongformat");
	if(mat == NULL || mat->r < 1 || mat->c < 1){
		printf("Test 4 - Zły format: OK \n");
		return 0;
	}
	else{
		printToScreen(mat);
		printf("Test 4 - Zły format: Wykryto Błąd \n");
		return 1;
	}
	
}

