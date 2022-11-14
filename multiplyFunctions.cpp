#include "multiplyFunctions.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <memory>

#define MAX_THREAD 2

Matrix multiplyTwoMatrixes(const Matrix & M1,const Matrix & M2)
{
    Matrix emptyMatrix{};

    // Check first matrix
    if (M1.empty() || M1[0].empty())
    {
        // And check second matrix
        if (M2.empty() || M2[0].empty())
        {
            std::cout << "Both matrixes are empty!" << std::endl;
            return emptyMatrix;
        }

        std::cout << "The first matrix is empty!" << std::endl;
        return emptyMatrix;
    }

    // Check second matrix
    if (M2.empty() || M2[0].empty())
    {
        std::cout << "The second matrix is empty!" << std::endl;
        return emptyMatrix;
    }

    int M1_cols = M1[0].size();
    int M2_rows = M2.size();

    if (M1_cols != M2_rows)
    {
        std::cout << "Different sizes (cols and rows)!" << std::endl;
        return emptyMatrix;
    }

    // Size of new matrix is M1_rows x M2_cols
    int M3_rows = M1.size(); // M1_rows
    int M3_cols = M2[0].size(); // M2_cols

    // allocate memory
    Matrix M3{};
    M3.resize(M3_rows);

    for (int i = 0; i < M3_rows; i++)
    {
        M3[i].resize(M3_cols);
    }

    std::vector<std::shared_ptr<std::thread>> threadsList;

    // run multiplying functions on threads
    for (int i = 0; i < MAX_THREAD; i++)
    {
        threadsList.push_back(std::make_shared<std::thread>(
                                  calculateNewMatrix, std::cref(M1), std::cref(M2), std::ref(M3)));
    }

    for (int i = 0; i < MAX_THREAD; i++)
        threadsList[i]->join();

    //calculateNewMatrix(M1, M2, M3);

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

void calculateNewMatrix(const Matrix& M1, const Matrix& M2, Matrix& M3)
{
    static std::mutex mtx;

    int M3_rows = M1.size();
    int M3_cols = M2[0].size();

    mtx.lock();

    // this is gloabl variable
    static int r = 0; // row
    static int c = 0; // column

    std::cout << "r=" << r << std::endl;
    std::cout << "c=" << c << std::endl;

    if (c != 0)
        ++c;

    if (c >= M3_cols)
    {
        ++r;
        c = 0;
    }


    while (r < M3_rows)
    {
        int row = r;

        while (c < M3_cols)
        {
            //mtx.lock();
            //int row = r;
            int col = c;

            mtx.unlock();

            for (int k = 0; k < M3_cols; k++)
            {

                M3[row][col] += M1[row][k] * M2[k][col];
            }

            mtx.lock();
            ++c; // increase column
            //mtx.unlock();
        }

        //mtx.lock();
        c = 0;
        ++r; // increase row
        //mtx.unlock();
    }

    mtx.unlock();
}

Matrix createMatrix(int size, IntGenerator& generator)
{
    int matrixSize = size;
    Matrix matrix{};

    if (size < 1)
        return matrix;

    for (int i = 0; i < size; i++)
    {
        matrix.push_back(std::vector<int>());

        for (int j = 0; j < size; j++)
        {
            matrix[i].push_back(generator.getNumber());
        }
    }

    return matrix;
}
