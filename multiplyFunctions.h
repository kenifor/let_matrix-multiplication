#pragma once

#include "IntGenerator.h"

#include <vector>

typedef std::vector<std::vector<int>> Matrix;

Matrix multiplyTwoMatrixes(const Matrix & M1,const Matrix & M2);

void printMatrix(const Matrix & matrix);

void calculateNewMatrix(const Matrix& M1, const Matrix& M2, Matrix& M3);

Matrix createMatrix(int size, IntGenerator& generator);
