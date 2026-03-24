#include "s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  int exit_status = OK;
  if (A == NULL || result == NULL)
    exit_status = WRONG_MATRIX;
  else if (A->matrix == NULL || A->rows <= 0 || A->columns <= 0)
    exit_status = WRONG_MATRIX;
  else {
    exit_status = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && exit_status == OK; i++)
      for (int j = 0; j < A->columns; j++)
        result->matrix[j][i] = A->matrix[i][j];
  }
  return exit_status;
}