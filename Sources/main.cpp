#include "multiplyFunctions.h"

#include <iostream>

int main(int argc, char** argv)
{
    // запишем третью матрицу в файл, который будет размещен в той же папке, что файл с первой матрицей
    std::string current_file = argv[1];
    std::string current_dir = current_file.substr(0, current_file.find_last_of('\\'));
    std::string output_path = current_dir + "\\output_matrix.txt";

    // must be 2 input files with matrixes
    if (argc != 3)
    {
        std::cout << "Must be two input files with matrixes!" << std::endl;
        return -1;
    }

    // read input matrix files
    Matrix m1 = readMatrixFromFile(argv[1]);
    Matrix m2 = readMatrixFromFile(argv[2]);

    // check input matrixes
    if (m1.empty() || m2.empty())
    {
        std::cout << "One of input matrix is empty!" << std::endl;
        return -1;
    }

    // multiply matrixes
    int threadsCount = 3;
    Matrix m3 = multiplyTwoMatrixes(m1, m2, threadsCount);

    // print result and write it to the output file
    printMatrix(m3);

    if (!writeMatrixToFile(m3, output_path))
    {
        std::cout << "Output file \"" << output_path << "\" was not writed!" << std::endl;
        return -1;
    }


    return 0;
}
