#include "s21_matrix.h"


int s21_eq_matrix(matrix_t *A, matrix_t *B){
    int exit_status = 0, is_matrix_eq = 1;
    if (A->matrix == NULL || B ->matrix == NULL) exit_status = 1;
    else if(A->rows != B->rows || A->columns != B->columns) exit_status = 2;
    if(!exit_status){
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                if (A->matrix[i][j] != B->matrix[i][j])
                    is_matrix_eq = 0;
    }
    return is_matrix_eq;
}