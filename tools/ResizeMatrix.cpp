#include "../s21_matrix_oop.h"

void S21Matrix::Resize(int rows, int cols) {
  if (rows < 1 || cols < 1)
    throw std::invalid_argument("Incorrect rows/cols\n");

  S21Matrix tmp(rows, cols);
  for (int i = 0; i < std::min(rows, rows_); ++i) {
    for (int j = 0; j < std::min(cols, cols_); ++j) {
      tmp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = std::move(tmp);
  rows_ = rows;
  cols_ = cols;
}
