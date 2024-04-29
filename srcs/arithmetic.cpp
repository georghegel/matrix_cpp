#include "../s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ && this->cols_ != other.cols_)
    throw std::invalid_argument("Invalid matrices. Rows/cols didn't match\n");

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j)
      this->matrix_[i][j] += other.matrix_[i][j];
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->rows_ != other.rows_ && this->cols_ != other.cols_)
    throw std::invalid_argument("Invalid matrices. Rows/cols didn't match\n");

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j)
      this->matrix_[i][j] -= other.matrix_[i][j];
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) this->matrix_[i][j] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (this->cols_ != other.rows_)
    throw std::invalid_argument(
        "Invalid matrices. Columns of the first matrix should be equal to rows "
        "of the second matrix\n");

  S21Matrix result(this->rows_, this->cols_);

  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < this->cols_; ++k)
        result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
    }
  }
  *this = result;
}

bool S21Matrix::EqMatrix(const S21Matrix &other) { return *this == other; }
