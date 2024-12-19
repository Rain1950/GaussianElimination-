#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {

	if(x->r != mat->r || x->r != b->r || b->r != mat->r ) return 2; // check czy liczba wierszy jest taka sama
								       
	for(int i = mat->r - 1; i >= 0 ; i--){
		for(int j = i+1; j < mat->r; j++){
		
			b->data[i][0] -= mat->data[i][j]*b->data[j][0];
		
		}
		if(mat->data[i][i] == 0) return 1;

		b->data[i][0] = b->data[i][0]/mat->data[i][i];
	
	
	} 

				/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

				
				for (int i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}

				return 0;
}


