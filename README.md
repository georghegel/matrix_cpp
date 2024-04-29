![Oxxxymiron](./screens/Cover_of_Gorgorod.jpg)
Oxxxymiron - ГОРГОРОД<br>
*The One Album to Rule Them All*

# Matrix - linear algebra library for C++

This project is similar to the project on C ([link](https://github.com/georghegel/matrix)) but with couple differences.<br>
Here we have better user experience because of the Object-Orientation of C++.

## Installation

### macOS

```shell
git clone https://github.com/georghegel/matrix_cpp.git
cd matrix_cpp
make
```
For test:
```shell
make test
```

### Linux
Similar to macOS:
```shell
git clone https://github.com/georghegel/matrix_cpp.git
cd matrix_cpp
make
```
For test:
```shell
not ready yet
```

## How to use

### Arithmetic operations

#### Addition/Subtraction
```c++
S21Matrix m1(3,3);
S21Matrix m2(3,3);

m1(0,0) = 1;
m1(0,1) = 2;
m1(0,2) = 3;
m1(1,0) = 4;
m1(1,1) = 5;
m1(1,2) = 6;
m1(2,0) = 7;
m1(2,1) = 8;
m1(2,2) = 9;

// let's say m2 fills in the same way
m1.SumMatrix(m2);
```

Let's print the result (it's located in m1):
```c++
m1.print();
//  2   4   6
//  8   10  12
//  14  16  18
```

#### Multiply by number
Element-wise multiplication by a given number:
```c++
S21Matrix m1(3,3); // just take the matrix from the previous example

double number = -3.0;
m1.MulNumber(number);

m1.print();
//  -3  -6  -9
//  -12 -15 -18
//  -21 -24 -27

```

#### Matrix multiplication
Here is [the link](https://en.wikipedia.org/wiki/Matrix_multiplication) how does it work:
```c++
S21Matrix m1(3,3); // as in the previous example
S21Matrix m2(3,3);

m2(0,0) = 0.7;
m2(0,1) = 11;
m2(0,2) = 0.3;
m2(1,0) = 11;
m2(1,1) = 2;
m2(1,2) = 1;
m2(2,0) = 0.5;
m2(2,1) = 3;
m2(2,2) = -1;

m1.MulMatrix(m2);

m1.print();

//  24.2    24    -0.7
//  60.8    72     0.2
//  97.4    120    1.1
```

### Determinant
How to calculate determinant in [Wiki](https://en.wikipedia.org/wiki/Determinant):
```c++
S21Matrix m1(2,2);

m1(0,0) = 1;
m1(0,1) = 2;
m1(1,0) = 3;
m1(1,1) = 4;

double det = m1.Determinant();
std::cout << "Determinant is equal to " << det << std::endl;
//  Determinant is equal to -2
```

### Inverse Matrix
About inverse matrix on [Wiki](https://en.wikipedia.org/wiki/Invertible_matrix):
```c++
S21Matrix m1(3,3);
S21Matrix inverse(3,3); // where will live our inverse matrix
m1(0,0) = 1;
m1(0,1) = 2;
m1(0,2) = 13;
m1(1,0) = 4;
m1(1,1) = 51;
m1(1,2) = 6;
m1(2,0) = 17;
m1(2,1) = 8;
m1(2,2) = 2;

inverse = m1.InverseMatrix();
inverse.print();

//  -54/10613   -100/10613    651/10613
//  -94/10613    219/10613    -46/10613
//  835/10613    -26/10613    -43/10613
```

### Conjugate Matrix
```c++
S21Matrix m1(3,3);
S21Matrix res(3,3);
m1(0,0) = 1;
m1(0,1) = 2;
m1(0,2) = 3;
m1(1,0) = 0;
m1(1,1) = 4;
m1(1,2) = 2;
m1(2,0) = 5;
m1(2,1) = 2;
m1(2,2) = 1;

res = m1.CalcComplements();
res.print();

//   0   10  -20
//   4  -14    8
//  -8   -2    4
```

### Some other useful functions:<br>

| Method signature                             | Description                                               |
|----------------------------------------------|-----------------------------------------------------------|
| <b>void Resize(int rows, int cols)</b>       | resizes matrix to the given rows and columns              |
| <b>void print()</b>                          | prints matrix                                             |
| <b>S21Matrix transpose()</b>                 | transposes initial matrix and returns new, transposed one |
| <b>bool EqMatrix(const S21Matrix& other)</b> | returns true, if matrices are equal. otherwise 0          |
