#include "s21_matrix.h"

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int exit_status = OK;
  if (A == NULL || B == NULL || result == NULL)
    exit_status = WRONG_MATRIX;
  else if (A->matrix == NULL || B->matrix == NULL)
    exit_status = WRONG_MATRIX;
  else if (A->rows <= 0 || A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    exit_status = WRONG_MATRIX;
  else if (A->columns != B->rows)
    exit_status = CALC_ERROR;
  if (!exit_status && !s21_create_matrix(A->rows, B->columns, result)) {
    for (int i = 0; i < result->rows; i++)
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = 0;
        for (int q = 0; q < A->columns; q++) {
          result->matrix[i][j] += A->matrix[i][q] * B->matrix[q][j];
        }
      }
  }
  return exit_status;
}
