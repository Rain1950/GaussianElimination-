#include "gauss.h"
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
        // Check for zero pivot element
        if (fabs(mat->data[i][i]) < 1e-12) {
            fprintf(stderr, "Error: Element diagonalny równy 0 w wierszu %d\n", i);
            exit(1);
        }
    }
    // Forward Elimination
    for (i = 0; i < n; i++) {
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

