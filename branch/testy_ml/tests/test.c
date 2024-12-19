#include "../src/gauss.h"
#include "../src/backsubst.h"
#include "../src/mat_io.h"
#include <stdlib.h>
#include <stdio.h>
void validate_test(int result, int expected) {
    switch (result) {
        case 1 :{
            printf("Błąd: Dzielenie przez zero\n");
            break;
            }
        case 2 :{
            printf("Błąd: Zły wymiar macierzy\n");
            break;
        }
    }
    if (result == expected) {
        printf("Test zdany\n");
    } else {
        printf("Test niezdany\n");
    }

}


int test(Matrix *A, Matrix *b) {
    int res;
    Matrix * x;

    res = eliminate(A,b);
    if (res == 1) return 1;

	x = createMatrix(b->r, 1);
    if (x == NULL) return 1;

  	res = backsubst(x,A,b);
    if (res != 0) return res;


    freeMatrix(x);
    freeMatrix(A);
    freeMatrix(b);
    return 0;
}

int main(int argc, char ** argv) {

    Matrix * A = readFromFile(argv[1]);
    Matrix * b = readFromFile(argv[2]);
    printf("Test 1 - Macierz %dx%d\n", A->c, A->r);
    printToScreen(A);
    int res1 = test(A, b);
    validate_test(res1, 0);
    Matrix * A2 = readFromFile(argv[3]);
    Matrix * b2 = readFromFile(argv[4]);
    printf("Test 2 - Macierz %dx%d\n", A2->c, A2->r);
    printToScreen(A2);
    int res2 = test(A2, b2);
    validate_test(res2, 1);
    Matrix * A3 = readFromFile(argv[5]);
    Matrix * b3 = readFromFile(argv[6]);
    printf("Test 3 - Macierz %dx%d\n", A3->c, A3->r);
    printToScreen(A3);
    int res3 = test(A3, b3);
    validate_test(res3, 0);
    Matrix * A4 = readFromFile(argv[7]);
    Matrix * b4 = readFromFile(argv[8]);
    printf("Test 4 - Macierz %dx%d\n", A4->c, A4->r);
    int res4 = test(A4, b4);
    validate_test(res4, 2);
    printToScreen(A4);
    Matrix * A5 = readFromFile(argv[9]);
    Matrix * b5 = readFromFile(argv[10]);
    printf("Test 5 - Macierz %dx%d\n", A5->c, A5->r);
    printToScreen(A5);
    int res5 = test(A5, b5);
    validate_test(res5, 0);

	return 0;
}

