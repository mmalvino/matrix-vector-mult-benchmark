#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 9

int generateRandomInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = generateRandomInt(LOWER,UPPER);
        }
    }
}

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = generateRandomInt(LOWER,UPPER);
    }
}

void test_multiply_vector_matrix(int *M, int *v, int N, int *vector_expected){
    int *vo = (int*)malloc(N * sizeof(int));

    if (vo == NULL){
        printf("Malloc is failed!\n");
        return;
    }
    
    matVecMult(M, v, vo, N);

    int i;
    for (i = 0; i < N; i++){
        printf("Actual V[%d] = %-2d; Expected V[%d] = %-2d\n", i, vo[i], i, vector_expected[i]);
        assert(vo[i] == vector_expected[i]);
    }
}

int main(){
    int total_test_cases = 3;
    int N = 3;

    int matrix_input_test_case[3][9] = {
        {3, 5, 4, 3, 4, 4, 5, 5, 3},
        {4, 9, 6, 2, 3, 5, 2, 7, 1},
        {1, 3, 6, 4, 2, 9, 8, 4, 7}
    };

    int vector_input_test_case[3][3] = {
        {5, 1, 3},
        {1, 9, 4},
        {5, 3, 7}
    };

    int vector_expected_test_case[3][3] = {
        {32, 31, 39},
        {109, 49, 69},
        {56, 89, 101}
    };

    int i;
    for (i = 0; i < total_test_cases; i++)
    {
        printf("Test #%d:\n", i + 1);

        test_multiply_vector_matrix(
        matrix_input_test_case[i],
        vector_input_test_case[i],
        N,
        vector_expected_test_case[i]
        );
         
        printf("\n");
    }

    return 0;
}