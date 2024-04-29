#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  S21Matrix() {
    rows_ = 0;
    cols_ = 0;
    matrix_ = NULL;
  }

  S21Matrix(int rows, int cols) {
    if (rows < 1 && cols < 1)
      throw std::invalid_argument(
          "Incorrect rows/cols. Set positive integer "
          "number for both rows and cols\n");

    rows_ = rows;
    cols_ = cols;
    matrix_ = new double *[rows_];

    if (matrix_ == nullptr)
      throw std::invalid_argument(
          "Couldn't allocate memory. Set another rows\n");
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
      if (matrix_[i] == nullptr)
        throw std::invalid_argument(
            "Couldn't allocate memory. Set another columns\n");
    }
    ZeroFiller();
  }

  S21Matrix(const S21Matrix &other) { *this = other; }
  S21Matrix(S21Matrix &&other) noexcept
      : rows_{other.rows_}, cols_{other.cols_} {
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.cols_ = 0;
    other.rows_ = 0;
  }
  ~S21Matrix() {
    for (int i = 0; i < rows_; ++i) delete[] matrix_[i];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }

  int GetRows() const { return rows_; }
  int GetCols() const { return cols_; }
  void ZeroFiller() const {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) matrix_[i][j] = 0;
    }
  }

  void print() const;

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  void Resize(int rows, int cols);

  void GaussElimination(bool inverse);
  void row_copy(double *term1, double *term2, int columns);
  void SwapRows(int row_1, int row_2);
  void CopyResult(S21Matrix &result);
  void InverseAugmented(const S21Matrix &initial_matrix);
  void CreateAugmentMatrix(const S21Matrix &initial_matrix);

  S21Matrix operator+(const S21Matrix &other) {
    if ((other.rows_ < 1 || other.cols_ < 1) || rows_ != other.rows_ ||
        cols_ != other.cols_)
      throw std::invalid_argument("Invalid or mismatched rows/cols\n");
    S21Matrix result(other.GetRows(), other.GetCols());

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j)
        result.matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
    return result;
  }
  S21Matrix operator-(const S21Matrix &other) {
    if ((other.rows_ < 1 || other.cols_ < 1) || rows_ != other.rows_ ||
        cols_ != other.cols_)
      throw std::invalid_argument("Invalid or mismatched rows/cols\n");
    S21Matrix result(other.GetRows(), other.GetCols());

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j)
        result.matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
    return result;
  }
  S21Matrix operator*(const S21Matrix &other) {
    if ((other.rows_ < 1 || other.cols_ < 1) || cols_ != other.rows_)
      throw std::invalid_argument("Invalid rows/cols\n");
    S21Matrix result(other.GetRows(), other.GetCols());

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < other.cols_; ++j) {
        for (int k = 0; k < cols_; ++k)
          result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
    return result;
  }
  S21Matrix operator*(const double num) {
    S21Matrix result(rows_, cols_);

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) result.matrix_[i][j] *= num;
    }
    return result;
  }
  bool operator==(const S21Matrix &other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) return false;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (matrix_[i][j] - other.matrix_[i][j] > 1e07) return false;
      }
    }
    return true;
  }

  // Without outside definition
  S21Matrix &operator+=(const S21Matrix &other) {
    S21Matrix tmp(rows_, cols_);

    tmp = *this + other;
    this->matrix_ = tmp.matrix_;
    this->cols_ = tmp.cols_;
    this->rows_ = tmp.rows_;
    return *this;
  }
  S21Matrix &operator-=(const S21Matrix &other) {
    S21Matrix tmp(rows_, cols_);

    tmp = *this - other;
    this->matrix_ = tmp.matrix_;
    this->cols_ = tmp.cols_;
    this->rows_ = tmp.rows_;
    return *this;
  }
  S21Matrix &operator*=(const S21Matrix &other) {
    S21Matrix tmp(rows_, cols_);

    tmp = *this * other;
    this->matrix_ = tmp.matrix_;
    this->cols_ = tmp.cols_;
    this->rows_ = tmp.rows_;
    return *this;
  }
  S21Matrix &operator=(const S21Matrix &other) {
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;

    this->matrix_ = new double *[rows_];
    if (this->matrix_ == nullptr)
      throw std::invalid_argument("Couldn't allocate memory\n");
    for (int i = 0; i < rows_; ++i) {
      this->matrix_[i] = new double[cols_];
      if (this->matrix_[i] == nullptr)
        throw std::invalid_argument("Couldn't allocate memory\n");
      ;
    }
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) this->matrix_[i][j] = other.matrix_[i][j];
    }
    return *this;
  }

  double *operator[](int i) { return matrix_[i]; }
  double *operator[](int i) const { return matrix_[i]; }
  double &operator()(int i, int j) {
    if ((i < 0 || i > rows_) || (j < 0 || j > cols_))
      throw std::invalid_argument("Index i/j is out of range\n");
    return matrix_[i][j];
  }
};

#endif
