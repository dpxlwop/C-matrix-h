#include "s21_matrix.h"

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int exit_status = OK;
  if (A == NULL || B == NULL)
    exit_status = WRONG_MATRIX;
  else if (A->matrix == NULL || B->matrix == NULL)
    exit_status = WRONG_MATRIX;
  else if (A->rows != B->rows || A->columns != B->columns)
    exit_status = CALC_ERROR;
  if (!exit_status) {
    exit_status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && exit_status == OK; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }
  return exit_status;
}