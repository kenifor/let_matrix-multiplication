#include "multiplyFunctions.h"

#include <iostream>

Matrix multiplyTwoMatrixes(const Matrix & M1,const Matrix & M2)
{    Matrix M3{};

    // Check first matrix
    if (M1.empty() || M1[0].empty())
    {
        // And check second matrix
        if (M2.empty() || M2[0].empty())
        {
            std::cout << "Both matrixes are empty!" << std::endl;
            return M3;
        }

        std::cout << "The first matrix is empty!" << std::endl;
        return M3;
    }

    // Check second matrix
    if (M2.empty() || M2[0].empty())
    {
        std::cout << "The second matrix is empty!" << std::endl;
        return M3;
    }

    int M1_cols = M1[0].size();
    int M2_rows = M2.size();

    if (M1_cols != M2_rows)
    {
        std::cout << "Different sizes (cols and rows)!" << std::endl;
        return M3;
    }

    // Size of new matrix is M1_rows x M2_cols
    int M3_rows = M1.size(); // M1_rows
    int M3_cols = M2[0].size(); // M2_cols

    for (int i = 0; i < M3_rows; i++)
    {
        M3.push_back({});

        for (int j = 0; j < M3_cols; j++)
        {
            int new_element = 0;
            for (int r = 0; r < M1_cols; r++)
            {
                new_element += M1[i][r] * M2[r][j];
            }

            M3[i].push_back(new_element);
        }
    }
    return M3;
}

void printMatrix(const Matrix & matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}