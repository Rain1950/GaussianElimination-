#include "gauss.h"
#include "mat_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i, j, k;
    int n = mat->r;
    for (i = 0; i < n; i++) {
        int maxRow = i;
        for (k = i + 1; k < n; k++) {
            if (fabs(mat->data[k][i]) > fabs(mat->data[maxRow][i])) {
                maxRow = k;
            }
        }

        // Swap rows in A and b if necessary
        if (maxRow != i) {
            double *tempRow = mat->data[i];
            mat->data[i] = mat->data[maxRow];
            mat->data[maxRow] = tempRow;

            double tempVal = b->data[i][0];
            b->data[i][0] = b->data[maxRow][0];
            b->data[maxRow][0] = tempVal;
        }

        // Check for zero pivot element
        if (fabs(mat->data[i][i]) < 1e-12) {
            return 1;
        }

    }

    // Eliminacja
    for (i = 0; i < n; i++) {
        // Check for zero pivot element again
        if (fabs(mat->data[i][i]) < 1e-12) {
            return 1;
        }
        // Make all rows below this one 0 in the current column
        for (k = i + 1; k < n; k++) {
            double factor = mat->data[k][i] / mat->data[i][i];
            for (j = i; j < n; j++) {
                mat->data[k][j] -= factor * mat->data[i][j];
            }
            b->data[k][0] -= (factor * b->data[i][0]);
        }
    }
    return 0;

}

