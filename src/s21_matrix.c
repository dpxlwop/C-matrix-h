#include "s21_matrix.h"

int main() {

    return 0;
}

int s21_create_matrix(int rows, int columns, matrix_t *result){
    int exit_status = 0;
    if (rows <= 0 || columns <= 0) exit_status = 1;
    if (!exit_status) {
        result->rows = rows;
        result->columns = columns;
        result->matrix = (double**)malloc(rows * sizeof(double*));
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = (double*)malloc(columns * sizeof(double));
        }
    }
    return exit_status;
}

void s21_remove_matrix(matrix_t *A){
    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);
}

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

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int exit_status = 0;
    if (A->matrix == NULL || B ->matrix == NULL) exit_status = 1;
    else  if(A->rows != B->rows || A->columns != B->columns) exit_status = 2;
    if(!exit_status){
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    return exit_status;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int exit_status = 0;
    if (A->matrix == NULL || B ->matrix == NULL) exit_status = 1;
    else if(A->rows != B->rows || A->columns != B->columns) exit_status = 2;
    if(!exit_status){
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
    return exit_status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result){
    int exit_status = 0;
    if (A->matrix == NULL) exit_status = 1;
    else if(A->rows <= 0 || A->columns <= 0) exit_status = 1; 
    if(!exit_status){
        for (int i = 0; i < A->rows; i++)
            for (int j = 0; j < A->columns; j++)
                result->matrix[i][j] = A->matrix[i][j] * number;
    }
    return exit_status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result){
    int exit_status = 0;
    if(A->matrix == NULL || B ->matrix == NULL) exit_status = 1;
    else if(A->columns != B->rows) exit_status = 2;
    if(!exit_status && s21_create_matrix(A->columns, B->rows, result)){
        for (int i = 0; i < result->rows; i++)
            for(int j = 0; j < result->columns; j++)
                result->matrix[i][j] = 0;
    }
    return exit_status;
}