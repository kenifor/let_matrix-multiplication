#include "multiplyFunctions.h"
#include "Cell.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <thread>
#include <fstream>

std::mutex mtx;

bool isEmptyMatrix(const Matrix & matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return true;

    return false;
}

bool writeMatrixToFile(const Matrix& matrix, const std::string& path)
{
    // check matrix
    if (isEmptyMatrix(matrix))
    {
        std::cout << "Output matrix is empty!" << std::endl;
        return false;
    }

    std::ofstream file(path, std::ios_base::out);

    // and check it's opening
    if (!file.is_open())
    {
        std::cout << "File \"" << path << "\" was not opened!" << std::endl;
        return false;
    }

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            file << matrix[row][col] << " ";
        }
        file << std::endl;
    }

    file.close();

    return true;
}

Matrix readMatrixFromFile(const std::string& path)
{
    Matrix matrix{};
    int row = 0;
    int col = 0;

    std::ifstream file(path, std::ios_base::in);

    // and check it's opening
    if (!file.is_open())
    {
        std::cout << "File \"" << path << "\" was not opened!" << std::endl;
        return matrix;
    }

    while (!file.eof())
    {
        std::string line;
        matrix.push_back(std::vector<int>());

        std::getline(file, line, '\n');
        int start = 0;
        col = 0;

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ' ')
            {
                int number = std::stoi(line.substr(start, i).c_str());
                matrix[row].push_back(number);
                col++;
                start = i+1;
            }
            else if (i == line.size()-1)
            {
                int number = std::stoi(line.substr(start, i));
                matrix[row].push_back(number);
                col++;
            }
        }
        row++;
    }

    file.close();
    return matrix;
}

Matrix createMatrix(int rows, int columns, IntGenerator& generator, MATRIX_TYPE matrixType)
{
    Matrix matrix{};

    if (rows <= 0 || columns <= 0)
        return matrix;

    // identity matrix must be square
    if (matrixType == IDENTITY)
        if (rows != columns)
            return matrix;

    // for random elements from -10 to 10
    int leftBorder = -10;
    int rightBorder = 10;

    // zero and identity (unity) matrix will be init by zeros
    if (matrixType == ZERO || matrixType == IDENTITY)
    {
        leftBorder = 0;
        rightBorder = 0;
    }

    // init matrix
    for (int r = 0; r < rows; r++)
    {
        matrix.push_back(std::vector<int>());

        for (int c = 0; c < columns; c++)
        {
            int newElement = generator.getNumber(leftBorder, rightBorder);
            matrix[r].push_back(newElement);
        }
    }

    // and identity matrix has unities on diagonal
    if (matrixType == IDENTITY)
    {
        for (int i = 0; i < rows; i++)
        {
            int unity = 1;
            matrix[i][i] = generator.getNumber(unity, unity);
        }
    }

    return matrix;
}

Matrix multiplyTwoMatrixes(const Matrix & M1, const Matrix & M2, int threadsCount)
{
    Matrix M3;

    if (threadsCount <= 0)
        threadsCount = 1;

    // Check first and second matrixes
    if (isEmptyMatrix(M1) || isEmptyMatrix(M2))
        return M3;

    int M1_cols = M1[0].size();
    int M2_rows = M2.size();

    if (M1_cols != M2_rows)
        return M3;

    IntGenerator gena;
    M3 = createMatrix(M2_rows, M1_cols, gena, ZERO);

    // create threads list
    std::vector<std::shared_ptr<std::thread>> threads;
    // init each thread and run it
    for (int th = 0; th < threadsCount; th++)
    {
        threads.push_back(std::make_shared<std::thread>(multiplyTwoMatrixesForThread, std::cref(M1), std::cref(M2), std::ref(M3)));
    }

    for (int th = 0; th < threadsCount; th++)
    {
        threads[th]->join();
    }

    return M3;
}

void multiplyTwoMatrixesForThread(const Matrix & M1, const Matrix & M2, Matrix & M3)
{
    int M1_rows = M1.size();
    int M1_cols = M1[0].size();
    //int M2_rows = M2.size();
    int M2_cols = M2[0].size();

    // Size of new matrix is M1_rows x M2_cols
    int M3_rows = M1_rows;
    int M3_cols = M2_cols;

    // this two variables is visible for each thread
    static int elementsCount = 0;
    static int totalCount = M3_rows * M3_cols;

    // lets fill the new matrix
    while (elementsCount < totalCount)
    {
        mtx.lock();
        // check and exit from function if need it
        if (elementsCount >= totalCount)
            return;

        // take next element of new matrix M3
        int newElementIndex = elementsCount;

        // increase index to order to give next element to the next thread
        ++elementsCount;
        mtx.unlock();

        // get number of row and get number of column
        Cell cell = getCell(M3, newElementIndex);

        // calculate new element and write it to the new matrix M3
        for (int i = 0; i < M1_cols; i++)
        {
            M3[cell.y][cell.x] += M1[cell.y][i] * M2[i][cell.x];
        }
    }
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
