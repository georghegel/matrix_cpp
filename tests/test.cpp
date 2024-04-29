//#include "../s21_matrix_oop.h"
////#include <gmock/gmock.h>
//#include <gtest/gtest.h>
//
//TEST(MatrixTest, EqMatrixElementsAreEqual) {
//  S21Matrix matrix1;
//  S21Matrix matrix2;
//  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
//}
//
//TEST(MatrixTest, EqMatrixElementsAreDifferent) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 3.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
//}
//
//TEST(MatrixTest, EqMatrixSizesAreDifferent) {
//  S21Matrix matrix1(2, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 3.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
//}
//
//TEST(MatrixTest, EqMatrixEpsilon) {
//  S21Matrix matrix1(2, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.000001;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//
//  S21Matrix matrix2(2, 2);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.000000;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//
//  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
//}
//
//TEST(MatrixTest, EqMatrixOperatorElementsAreEqual) {
//  S21Matrix matrix1;
//  S21Matrix matrix2;
//  EXPECT_TRUE(matrix1 == matrix2);
//}
//
////TEST(MatrixTest, SumMatrixBasic) {
////  S21Matrix matrix1(3, 3);
////  S21Matrix matrix2(3, 3);
////
////  for (int i = 0; i < matrix1.GetRows(); ++i) {
////    for (int j = 0; j < matrix1.GetCols(); ++j) {
////      matrix1(i, j) = i + j;
////      matrix2(i, j) = i - j;
////    }
////  }
////
////  matrix1.SumMatrix(matrix2);
////
////  const S21Matrix const_matrix1 = std::move(matrix1);
////
////  for (int i = 0; i < const_matrix1.GetRows(); ++i) {
////    for (int j = 0; j < const_matrix1.GetCols(); ++j) {
////      double expected_value = (i + j) + (i - j);
////      EXPECT_DOUBLE_EQ(const_matrix1(i, j), expected_value);
////    }
////  }
////}
//
////TEST(MatrixTest, SumMatrixMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////  EXPECT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
////}
//
//TEST(MatrixTest, SumOperatorMatrix) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix matrix2(3, 3);
//  S21Matrix actual(3, 3);
//  S21Matrix expected(3, 3);
//  actual = matrix1 + matrix2;
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
////TEST(MatrixTest, SumOperatorMatrixMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////  EXPECT_THROW(matrix1 + matrix2, std::invalid_argument);
////}
//
//TEST(MatrixTest, AdditionAssignmentOperatorMatrix) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix matrix2(3, 3);
//  S21Matrix expected_matrix(3, 3);
//
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      double value = 2 * matrix1(i, j);
//      expected_matrix(i, j) = value;
//    }
//  }
//
//  S21Matrix actual_result = matrix1 += matrix2;
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
////TEST(MatrixTest, AdditionAssignmentOperatorMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////
////  EXPECT_THROW(matrix1 += matrix2, std::invalid_argument);
////}
//
//TEST(MatrixTest, SubMatrixBasic) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix matrix2(3, 3);
//  S21Matrix expected_matrix(3, 3);
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      expected_matrix(i, j) = 0.0;
//    }
//  }
//  matrix1.SubMatrix(matrix2);
//  EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
//}
//
////TEST(MatrixTest, SubMatrixMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////  S21Matrix expected_matrix;
////  EXPECT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
////}
//
//TEST(MatrixTest, SubOperatorMatrix) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix matrix2(3, 3);
//  S21Matrix expected_matrix(3, 3);
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      expected_matrix(i, j) = 0.0;
//    }
//  }
//  S21Matrix actual_result = matrix1 - matrix2;
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
////TEST(MatrixTest, SubOperatorMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////
////  EXPECT_THROW(matrix1 - matrix2, std::invalid_argument);
////}
//
//TEST(MatrixTest, DifferenceAssignmentOperatorMatrix) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix matrix2(3, 3);
//  S21Matrix expected_matrix(3, 3);
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      expected_matrix(i, j) = 0.0;
//    }
//  }
//  S21Matrix actual_result = matrix1 -= matrix2;
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
////TEST(MatrixTest, DifferenceAssignmentOperatorMatricesOfDifferentSizes) {
////  S21Matrix matrix1;
////  matrix1.ResizeCols(1);
////  S21Matrix matrix2;
////
////  EXPECT_THROW(matrix1 -= matrix2, std::invalid_argument);
////}
//
//TEST(MatrixTest, MultByNumberBasic) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix expected_matrix(3, 3);
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      expected_matrix(i, j) = matrix1(i, j) * 3.0;
//    }
//  }
//  matrix1.MulNumber(3.0);
//  EXPECT_TRUE(matrix1.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, MultByNumberOperator) {
//  S21Matrix matrix1(3, 3);
//  S21Matrix expected_matrix(3, 3);
//  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
//    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
//      expected_matrix(i, j) = matrix1(i, j) * 3.0;
//    }
//  }
//  S21Matrix actual_result = matrix1 * 3.0;
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
////TEST(MatrixTest, MultiplicationAssignmentOperatorMultNumber) {
////  S21Matrix matrix1(3, 3);
////  S21Matrix expected_matrix(3, 3);
////  for (int i = 0; i < expected_matrix.GetRows(); ++i) {
////    for (int j = 0; j < expected_matrix.GetCols(); ++j) {
////      expected_matrix(i, j) = matrix1(i, j) * 3.0;
////    }
////  }
////  S21Matrix actual_result = matrix1 *= 3.0;
////  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
////}
//
//TEST(MatrixTest, MultMatrixBasic) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  S21Matrix expected_matrix(3, 3);
//
//  expected_matrix(0, 0) = 3.0;
//  expected_matrix(0, 1) = 6.0;
//  expected_matrix(0, 2) = 9.0;
//  expected_matrix(1, 0) = 4.0;
//  expected_matrix(1, 1) = 8.0;
//  expected_matrix(1, 2) = 12.0;
//  expected_matrix(2, 0) = 5.0;
//  expected_matrix(2, 1) = 10.0;
//  expected_matrix(2, 2) = 15.0;
//
//  S21Matrix actual_result = matrix1;
//  actual_result.MulMatrix(matrix2);
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, MultMatrixMultIndalidMatrixSizeException) {
//  S21Matrix matrix1(3, 1);
//  matrix1(0, 0) = 1.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(2, 0) = 2.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  EXPECT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
//}
//
//TEST(MatrixTest, MultMatrixOperator) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  S21Matrix expected_matrix(3, 3);
//  expected_matrix(0, 0) = 3.0;
//  expected_matrix(0, 1) = 6.0;
//  expected_matrix(0, 2) = 9.0;
//  expected_matrix(1, 0) = 4.0;
//  expected_matrix(1, 1) = 8.0;
//  expected_matrix(1, 2) = 12.0;
//  expected_matrix(2, 0) = 5.0;
//  expected_matrix(2, 1) = 10.0;
//  expected_matrix(2, 2) = 15.0;
//
//  S21Matrix actual_result = matrix1 * matrix2;
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, MultiplicationAssignmentOperatorMultMatrix) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix matrix2(2, 3);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.0;
//  matrix2(0, 2) = 3.0;
//  matrix2(1, 0) = 1.0;
//  matrix2(1, 1) = 2.0;
//  matrix2(1, 2) = 3.0;
//
//  S21Matrix expected_matrix(3, 3);
//  expected_matrix(0, 0) = 3.0;
//  expected_matrix(0, 1) = 6.0;
//  expected_matrix(0, 2) = 9.0;
//  expected_matrix(1, 0) = 4.0;
//  expected_matrix(1, 1) = 8.0;
//  expected_matrix(1, 2) = 12.0;
//  expected_matrix(2, 0) = 5.0;
//  expected_matrix(2, 1) = 10.0;
//  expected_matrix(2, 2) = 15.0;
//
//  S21Matrix actual_result = matrix1 *= matrix2;
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, EqMatrixOperator) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix matrix2(3, 2);
//  matrix2(0, 0) = 1.0;
//  matrix2(0, 1) = 2.0;
//  matrix2(1, 0) = 3.0;
//  matrix2(1, 1) = 1.0;
//  matrix2(2, 0) = 2.0;
//  matrix2(2, 1) = 3.0;
//
//  EXPECT_TRUE(matrix1 == matrix2);
//}
//
//TEST(MatrixTest, TransposeMatrixBasic) {
//  S21Matrix matrix1(3, 2);
//  matrix1(0, 0) = 1.0;
//  matrix1(0, 1) = 2.0;
//  matrix1(1, 0) = 3.0;
//  matrix1(1, 1) = 1.0;
//  matrix1(2, 0) = 2.0;
//  matrix1(2, 1) = 3.0;
//
//  S21Matrix expected_matrix(2, 3);
//  expected_matrix(0, 0) = 1.0;
//  expected_matrix(0, 1) = 3.0;
//  expected_matrix(0, 2) = 2.0;
//  expected_matrix(1, 0) = 2.0;
//  expected_matrix(1, 1) = 1.0;
//  expected_matrix(1, 2) = 3.0;
//
//  S21Matrix transposed_matrix = matrix1.Transpose();
//
//  EXPECT_TRUE(transposed_matrix.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, CalcComplementsMatrixBasic00) {
//  S21Matrix input_matrix(1, 1);
//  input_matrix(0, 0) = 21.0;
//
//  S21Matrix expected_result(1, 1);
//  expected_result(0, 0) = 21.0;
//
//  S21Matrix actual_result = input_matrix.CalcComplements();
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_result));
//}
//
//TEST(MatrixTest, CalcComplementsMatrixBasic02) {
//  S21Matrix input_matrix(3, 3);
//  input_matrix(0, 0) = 1.0;
//  input_matrix(0, 1) = 2.0;
//  input_matrix(0, 2) = 3.0;
//  input_matrix(1, 0) = 1.0;
//  input_matrix(1, 1) = 3.0;
//  input_matrix(1, 2) = 2.0;
//  input_matrix(2, 0) = 5.0;
//  input_matrix(2, 1) = 2.0;
//  input_matrix(2, 2) = 1.0;
//
//  S21Matrix expected_matrix(3, 3);
//  expected_matrix(0, 0) = -1.0;
//  expected_matrix(0, 1) = 9.0;
//  expected_matrix(0, 2) = -13.0;
//  expected_matrix(1, 0) = 4.0;
//  expected_matrix(1, 1) = -14.0;
//  expected_matrix(1, 2) = 8.0;
//  expected_matrix(2, 0) = -5.0;
//  expected_matrix(2, 1) = 1.0;
//  expected_matrix(2, 2) = 1.0;
//
//  S21Matrix actual_result = input_matrix.CalcComplements();
//
//  EXPECT_TRUE(actual_result.EqMatrix(expected_matrix));
//}
//
//TEST(MatrixTest, CalcComplementsMatrixNotSquaredMatrixException) {
//  S21Matrix input_matrix(3, 1);
//
//  EXPECT_THROW(input_matrix.CalcComplements(), std::invalid_argument);
//}
//
//TEST(MatrixTest, DeterminantMatrixBasic00) {
//  S21Matrix input_matrix(3, 3);
//  input_matrix(0, 0) = 21.0;
//  input_matrix(0, 1) = 42.0;
//  input_matrix(0, 2) = 13.0;
//  input_matrix(1, 0) = 21.0;
//  input_matrix(1, 1) = 42.0;
//  input_matrix(1, 2) = 13.0;
//  input_matrix(2, 0) = 21.0;
//  input_matrix(2, 1) = 42.0;
//  input_matrix(2, 2) = 13.0;
//
//  double expected_result = 0.0;
//
//  double actual_result = input_matrix.Determinant();
//
//  ASSERT_DOUBLE_EQ(expected_result, actual_result);
//}
//
//TEST(MatrixTest, DeterminantMatrixBasic01) {
//  S21Matrix input_matrix(3, 3);
//  input_matrix(0, 0) = 2.0;
//  input_matrix(0, 1) = 5.0;
//  input_matrix(0, 2) = 7.0;
//  input_matrix(1, 0) = 6.0;
//  input_matrix(1, 1) = 3.0;
//  input_matrix(1, 2) = 4.0;
//  input_matrix(2, 0) = 5.0;
//  input_matrix(2, 1) = -2.0;
//  input_matrix(2, 2) = -3.0;
//
//  double expected_result = -1.0;
//
//  double actual_result = input_matrix.Determinant();
//
//  ASSERT_DOUBLE_EQ(expected_result, actual_result);
//}
//
//TEST(MatrixTest, DeterminantMatrixBasic02) {
//  S21Matrix input_matrix(1, 1);
//  input_matrix(0, 0) = 21.0;
//
//  double expected_result = 21.0;
//
//  double actual_result = input_matrix.Determinant();
//
//  ASSERT_DOUBLE_EQ(expected_result, actual_result);
//}
//
//TEST(MatrixTest, DeterminantNotSquaredMatrixException) {
//  S21Matrix input_matrix(3, 1);
//
//  EXPECT_THROW(input_matrix.Determinant(), std::invalid_argument);
//}
//
//TEST(MatrixTest, InverseMatrixBasic) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 2.0;
//  input(0, 1) = 5.0;
//  input(0, 2) = 7.0;
//  input(1, 0) = 6.0;
//  input(1, 1) = 3.0;
//  input(1, 2) = 4.0;
//  input(2, 0) = 5.0;
//  input(2, 1) = -2.0;
//  input(2, 2) = -3.0;
//
//  S21Matrix expected(3, 3);
//  expected(0, 0) = 1.0;
//  expected(0, 1) = -1.0;
//  expected(0, 2) = 1.0;
//  expected(1, 0) = -38.0;
//  expected(1, 1) = 41.0;
//  expected(1, 2) = -34.0;
//  expected(2, 0) = 27.0;
//  expected(2, 1) = -29.0;
//  expected(2, 2) = 24.0;
//
//  S21Matrix actual = input.InverseMatrix();
//
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
//TEST(MatrixTest, InverseMatrixZeroException) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 1.0;
//  input(0, 1) = 2.0;
//  input(0, 2) = 3.0;
//  input(1, 0) = 4.0;
//  input(1, 1) = 5.0;
//  input(1, 2) = 6.0;
//  input(2, 0) = 7.0;
//  input(2, 1) = 8.0;
//  input(2, 2) = 9.0;
//
//  EXPECT_THROW(input.InverseMatrix(), std::invalid_argument);
//}
//
//TEST(MatrixTest, ParametrizedConstructorTest) {
//  S21Matrix actual(3, 3);
//
//  S21Matrix expected(3, 3);
//  for (int row = 0; row < 3; ++row) {
//    for (int col = 0; col < 3; ++col) {
//      expected(row, col) = 0.0;
//    }
//  }
//
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
//TEST(MatrixTest, ParametrizedConstructorTestInvalidIndex00) {
//  EXPECT_THROW(S21Matrix expected(2, -42), std::invalid_argument);
//}
//
//TEST(MatrixTest, ParametrizedConstructorTestInvalidIndex01) {
//  EXPECT_THROW(S21Matrix expected(-42, -42), std::invalid_argument);
//}
//
//TEST(MatrixTest, ParametrizedConstructorTestInvalidIndex03) {
//  EXPECT_THROW(S21Matrix expected(-42, 42), std::invalid_argument);
//}
//
////TEST(MatrixTest, RectangleMatrixTestRows) {
////  S21Matrix actual(3, 3);
////  actual.ResizeRows(5);
////
////  S21Matrix expected(5, 3);
////  for (int row = 0; row < 5; ++row) {
////    for (int col = 0; col < 3; ++col) {
////      expected(row, col) = 0.0;
////    }
////  }
////
////  EXPECT_TRUE(actual.EqMatrix(expected));
////}
////
////TEST(MatrixTest, RectangleMatrixTestCols) {
////  S21Matrix actual(3, 3);
////  actual.ResizeCols(5);
////
////  S21Matrix expected(3, 5);
////  for (int row = 0; row < 3; ++row) {
////    for (int col = 0; col < 5; ++col) {
////      expected(row, col) = 0.0;
////    }
////  }
////
////  EXPECT_TRUE(actual.EqMatrix(expected));
////}
////
////TEST(MatrixTest, SetRowsToBelowZeroTest) {
////  S21Matrix actual(3, 3);
////  EXPECT_THROW(actual.ResizeRows(-5), std::invalid_argument);
////}
////
////TEST(MatrixTest, SetColsToBelowZeroTest) {
////  S21Matrix actual(3, 3);
////  EXPECT_THROW(actual.ResizeCols(-5), std::invalid_argument);
////}
//
//TEST(MatrixTest, GetInvalidElementTest) {
//  S21Matrix actual(3, 3);
//  EXPECT_THROW(actual(-5, 0), std::out_of_range);
//}
//
//TEST(MatrixTest, SetInvalidElementTest) {
//  S21Matrix actual(3, 3);
//  EXPECT_THROW(actual(-5, 0) = 42.0, std::out_of_range);
//}
//
//TEST(MatrixTest, CopyConstructorTest) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 1.0;
//  input(0, 1) = 2.0;
//  input(0, 2) = 3.0;
//  input(1, 0) = 4.0;
//  input(1, 1) = 5.0;
//  input(1, 2) = 6.0;
//  input(2, 0) = 7.0;
//  input(2, 1) = 8.0;
//  input(2, 2) = 9.0;
//
//  S21Matrix expected(3, 3);
//  for (int row = 0; row < 3; ++row) {
//    for (int col = 0; col < 3; ++col) {
//      expected(row, col) = input(row, col);
//    }
//  }
//
//  S21Matrix actual(input);
//
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
//TEST(MatrixTest, CopyAssignmentOperatorTest) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 1.0;
//  input(0, 1) = 2.0;
//  input(0, 2) = 3.0;
//  input(1, 0) = 4.0;
//  input(1, 1) = 5.0;
//  input(1, 2) = 6.0;
//  input(2, 0) = 7.0;
//  input(2, 1) = 8.0;
//  input(2, 2) = 9.0;
//
//  S21Matrix expected(3, 3);
//  for (int row = 0; row < 3; ++row) {
//    for (int col = 0; col < 3; ++col) {
//      expected(row, col) = input(row, col);
//    }
//  }
//
//  S21Matrix actual = input;
//
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
//TEST(MatrixTest, MovementConstructorTest) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 1.0;
//  input(0, 1) = 2.0;
//  input(0, 2) = 3.0;
//  input(1, 0) = 4.0;
//  input(1, 1) = 5.0;
//  input(1, 2) = 6.0;
//  input(2, 0) = 7.0;
//  input(2, 1) = 8.0;
//  input(2, 2) = 9.0;
//
//  S21Matrix expected(3, 3);
//  for (int row = 0; row < 3; ++row) {
//    for (int col = 0; col < 3; ++col) {
//      expected(row, col) = input(row, col);
//    }
//  }
//
//  S21Matrix actual(std::move(input));
//
//  EXPECT_TRUE(actual.EqMatrix(expected));
//}
//
////TEST(MatrixTest, DestructorTest) {
////  S21Matrix input(3, 3);
////  input(0, 0) = 1.0;
////  input(0, 1) = 2.0;
////  input(0, 2) = 3.0;
////  input(1, 0) = 4.0;
////  input(1, 1) = 5.0;
////  input(1, 2) = 6.0;
////  input(2, 0) = 7.0;
////  input(2, 1) = 8.0;
////  input(2, 2) = 9.0;
////
////  input.~S21Matrix();
////
////  int rows = input.GetRows();
////  int cols = input.GetCols();
////  bool is_null = input.IsNull();
////
////  ASSERT_EQ(rows, 0);
////  ASSERT_EQ(cols, 0);
////  EXPECT_TRUE(is_null);
////}
//
//TEST(MatrixTest, IndexationByMatrixElements) {
//  S21Matrix input(3, 3);
//  input(0, 0) = 1.0;
//  input(0, 1) = 2.0;
//  input(0, 2) = 3.0;
//  input(1, 0) = 4.0;
//  input(1, 1) = 5.0;
//  input(1, 2) = 6.0;
//  input(2, 0) = 7.0;
//  input(2, 1) = 8.0;
//  input(2, 2) = 9.0;
//
//  double actual = input(1, 1);
//  double expected = 5.0;
//
//  ASSERT_DOUBLE_EQ(expected, actual);
//}
//
//int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  ::testing::InitGoogleMock(&argc, argv);
//  return RUN_ALL_TESTS();
//}
//
#include <iostream>
#include <cstdio>
#include "../s21_matrix_oop.h"
#include <gtest/gtest.h>

void printMatrix(S21Matrix& m) {
    for (int i = 0; i < m.GetRows(); i++) {
        for (int j = 0; j < m.GetCols(); j++) {
            std::cout<<m(i, j)<<" ";
        }
        std::cout<<std::endl;
    }
}

namespace {
    TEST(Constructor, Default) {
        auto test = S21Matrix();
        EXPECT_EQ(test.GetRows(), 0);
        EXPECT_EQ(test.GetCols(), 0);
    }

    TEST(Constructor, By2Args) {
        auto test = S21Matrix(3, 3);
        EXPECT_EQ(test.GetRows(), 3);
        EXPECT_EQ(test.GetCols(), 3);
    }

    TEST(Constructor, Copy) {
        auto test = S21Matrix(3, 3);
        test(0,0) = 1;
        auto temp = S21Matrix(test);
        EXPECT_EQ(test, temp);
    }

    TEST(Constructor, Move) {
        auto test1 = S21Matrix(3, 3);
        test1(1, 1) = 5;
        auto test2 = S21Matrix(test1);
        auto test3 = S21Matrix(std::move(test1));
        EXPECT_EQ(test2, test3);
    }

    TEST(SimpleMathOperations, EqMatrix) {
//        auto test1 = S21Matrix(3, 3);
//        test1(1,2) = 5;
//        auto test2 = test1;
//        EXPECT_TRUE(test1.EqMatrix(test2));
//        EXPECT_TRUE(test1.EqMatrix(test2) == (test1 == test2));
//        test2(1, 1) = 1;
//        EXPECT_FALSE(test1.EqMatrix(test2));
//        EXPECT_TRUE(test1.EqMatrix(test2) == (test1 == test2));
//        auto test3 = S21Matrix(5, 5);
//        EXPECT_FALSE(test1.EqMatrix(test3));
//        EXPECT_TRUE(test1.EqMatrix(test3) == (test1 == test3));
        S21Matrix test1(3,3);
        S21Matrix test2(3,3);
        test1(0,0) = 1;
        test1(0,1) = 2;
        test1(0,2) = 3;
        test1(1,0) = 4;
        test1(1,1) = 5;
        test1(1,2) = 6;
        test1(2,0) = 7;
        test1(2,1) = 8;
        test1(2,2) = 9;
        test2 = test1;
        EXPECT_TRUE(test1.EqMatrix(test2));
    }

    TEST(SimpleMathOperations, SumMatrix) {
        auto test1 = S21Matrix(1, 1);
        test1(0, 0) = 1;
        auto test2 = test1;
        test1.SumMatrix(test2);
        EXPECT_EQ(test1(0, 0), 2);
    }

    TEST(SimpleMathOperations, SubMatrix) {
        auto test1 = S21Matrix(1, 1);
        test1(0, 0) = 1;
        auto test2 = test1;
        test1.SubMatrix(test2);
        EXPECT_EQ(test1(0, 0), 0);
    }

    TEST(SimpleMathOperations, MulNumber) {
        auto test1 = S21Matrix(1, 1);
        test1(0, 0) = 5;
        test1.MulNumber(3);
        EXPECT_EQ(test1(0, 0), 15);
    }

    TEST(SimpleMathOperations, MulMatrix) {
        auto test1 = S21Matrix(3, 3);
        for (int i = 0; i < test1.GetRows(); i++) {
            for (int j = 0; j < test1.GetCols(); j++) {
                test1(i, j) = test1.GetRows() * i + j + 1;
            }
        }
        auto test2 = test1;
        test1.MulMatrix(test2);
        test2(0, 0) = 30;
        test2(0, 1) = 36;
        test2(0, 2) = 42;
        test2(1, 0) = 66;
        test2(1, 1) = 81;
        test2(1, 2) = 96;
        test2(2, 0) = 102;
        test2(2, 1) = 126;
        test2(2, 2) = 150;
        EXPECT_EQ(test1, test2);
    }

    TEST(LinearOperations, Transpose) {
        auto test1 = S21Matrix(3, 3);
        for (int i = 0; i < test1.GetRows(); i++) {
            for (int j = 0; j < test1.GetCols(); j++) {
                test1(i, j) = test1.GetRows() * i + j + 1;
            }
        }
        test1 = test1.Transpose();
        auto test2 = S21Matrix(3, 3);
        test2(0, 0) = 1;
        test2(0, 1) = 4;
        test2(0, 2) = 7;
        test2(1, 0) = 2;
        test2(1, 1) = 5;
        test2(1, 2) = 8;
        test2(2, 0) = 3;
        test2(2, 1) = 6;
        test2(2, 2) = 9;
        EXPECT_EQ(test1, test2);
    }

    TEST(LinearOperations, CalcComplements) {
        auto test1 = S21Matrix(3, 3);
        test1(0, 0) = 1;
        test1(0, 1) = 2;
        test1(0, 2) = 3;
        test1(1, 0) = 0;
        test1(1, 1) = 4;
        test1(1, 2) = 2;
        test1(2, 0) = 5;
        test1(2, 1) = 2;
        test1(2, 2) = 1;
        test1 = test1.CalcComplements();
        auto test2 = S21Matrix(3, 3);
        test2(0, 0) = 0;
        test2(0, 1) = 10;
        test2(0, 2) = -20;
        test2(1, 0) = 4;
        test2(1, 1) = -14;
        test2(1, 2) = 8;
        test2(2, 0) = -8;
        test2(2, 1) = -2;
        test2(2, 2) = 4;
        EXPECT_EQ(test1, test2);
    }

    TEST(LinearOperations, Determinant) {
        auto test1 = S21Matrix(3, 3);
        test1(0, 0) = 1;
        test1(0, 1) = 2;
        test1(0, 2) = 3;
        test1(1, 0) = 0;
        test1(1, 1) = 4;
        test1(1, 2) = 2;
        test1(2, 0) = 5;
        test1(2, 1) = 2;
        test1(2, 2) = 1;
        EXPECT_DOUBLE_EQ(test1.Determinant(), -40);
    }

    TEST(LinearOperations, InverseMatrix) {
        auto test1 = S21Matrix(3, 3);
        S21Matrix res(3,3);
        test1(0, 0) = 2;
        test1(0, 1) = 5;
        test1(0, 2) = 7;
        test1(1, 0) = 6;
        test1(1, 1) = 3;
        test1(1, 2) = 4;
        test1(2, 0) = 5;
        test1(2, 1) = -2;
        test1(2, 2) = -3;
        res = test1.InverseMatrix();
        auto test2 = S21Matrix(3, 3);
        test2(0, 0) = 1;
        test2(0, 1) = -1;
        test2(0, 2) = 1;
        test2(1, 0) = -38;
        test2(1, 1) = 41;
        test2(1, 2) = -34;
        test2(2, 0) = 27;
        test2(2, 1) = -29;
        test2(2, 2) = 24;
        S21Matrix e(3,3);
        EXPECT_EQ(res, test2);
    }

    TEST(Technical, GetRows) {
        auto test1 = S21Matrix();
        EXPECT_EQ(test1.GetRows(), 0);
        auto test2 = S21Matrix(2, 2);
        EXPECT_EQ(test2.GetRows(), 2);
    }

    TEST(Technical, GetCols) {
        auto test1 = S21Matrix();
        EXPECT_EQ(test1.GetCols(), 0);
        auto test2 = S21Matrix(2, 2);
        EXPECT_EQ(test2.GetCols(), 2);
    }
}


