#include "s21_matrix.h"


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int exit_status = OK;
    if(A->matrix == NULL || B ->matrix == NULL) exit_status = WRONG_MATRIX;
    else if(A->columns != B->rows) exit_status = 2;
    if(!exit_status && s21_create_matrix(A->columns, B->rows, result)){
        for (int i = 0; i < result->rows; i++)
            for(int j = 0; j < result->columns; j++)
                result->matrix[i][j] = 0;
    }
    return exit_status;
}

