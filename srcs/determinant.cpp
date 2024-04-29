#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (rows_ != cols_)
    throw std::invalid_argument(
        "Determinant exists only for square matrices\n");

  S21Matrix row_echelon(*this);

  row_echelon.GaussElimination(false);
  double det = 1.0;
  for (int i = 0; i < cols_; ++i) det *= row_echelon.matrix_[i][i];
  return det;
}
