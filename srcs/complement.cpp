#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw std::invalid_argument("Non square");
  }

  double det = this->Determinant();
  if (det == 0.0) {
    throw std::invalid_argument("Determinant is zero. No complements");
  }

  S21Matrix inverse = this->InverseMatrix();
  inverse.MulNumber(det);
  //inverse.Transpose();

  return inverse;
}
