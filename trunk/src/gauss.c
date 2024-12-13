#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
     	 for(int i=1;i<=b->r-1;i++) {

             if(mat->data[i][i] == 0.0)
             {
                 printf("Mathematical Error!");
                 exit(0);
             }
             for(int j=i+1;j<=b->r;j++)
             {
                 double ratio = mat->data[j][i]/b->data[i][i];

                 for(int k=1;k<=b->r+1;k++)
                 {
                     mat->data[j][k] = mat->data[j][k] - ratio*mat->data[i][k];
                 }
		  }
	 }

		return 0;
}

