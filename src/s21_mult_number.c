#include "s21_matrix.h"


int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    int exit_status = OK;
    if (A->matrix == NULL) exit_status = WRONG_MATRIX;
    else if(A->rows <= 0 || A->columns <= 0) exit_status = CALC_ERROR; 
    if(!exit_status){
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] * number;
    }
    return exit_status;
}