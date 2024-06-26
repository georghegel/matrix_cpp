#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix tmp(cols_, rows_);

  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      tmp[i][j] = matrix_[j][i];
    }
  }
  return tmp;
}
