#ifndef MULTIPLYFUNCTION_H
#define MULTIPLYFUNCTION_H

#include "IntGenerator.h"

#include <vector>
#include <string>

enum MATRIX_TYPE {
    ZERO,       // нулевая
    IDENTITY,   // единичная
    RANDOM      // матрица со случайными элементами
};

typedef std::vector<std::vector<int>> Matrix;

void multiplyTwoMatrixesForThread(const Matrix & M1, const Matrix & M2, Matrix & M3);

Matrix multiplyTwoMatrixes(const Matrix & M1, const Matrix & M2, int threadsCount);

void printMatrix(const Matrix & matrix);

bool isEmptyMatrix(const Matrix & matrix);

Matrix createMatrix(int rows, int columns, IntGenerator& generator, MATRIX_TYPE matrixType=RANDOM);

Matrix readMatrixFromFile(const std::string& path);

bool writeMatrixToFile(const Matrix& matrix, const std::string& path);

#endif // MULTIPLYFUNCTION_H
