#pragma once
#include <vector>

typedef std::vector<std::vector<int>> Matrix;

Matrix multiplyTwoMatrixes(const Matrix & M1,const Matrix & M2);

void printMatrix(const Matrix & matrix);