#include <iostream>

#include "multiplyFunctions.h"
#include "Timer.h"

int main()
{
    std::vector<std::vector<int>> t1m1 =
    {
        {6, 9},
        {4, 2},
        {7, 5},
        {1, 0}
    };

    std::vector<std::vector<int>> t1m2 =
    {
        {2, 9, 3, 5},
        {7, 1 ,44, 1}
    };

    std::vector<std::vector<int>> t2m1 =
    {
        {}
    };

    std::vector<std::vector<int>> t2m2 =
    {
        {}
    };

    std::vector<std::vector<int>> t3m1 =
    {
        {1, 5, 9, 4}
    };

    std::vector<std::vector<int>> t3m2 =
    {
        {2},
        {7},
        {100},
        {5}
    };

    std::vector<std::vector<int>> t4m1 =
    {
        {100}
    };

    std::vector<std::vector<int>> t4m2 =
    {
        {}
    };

    std::vector<std::vector<int>> t5m1 =
    {
        {9, 5},
        {1, 0}
    };

    std::vector<std::vector<int>> t5m2 =
    {
        {2, 9},
        {7, 1}
    };

    Timer timer;

    //timer.

    Matrix m3;
    
    // start
    timer.start();
    m3 = multiplyTwoMatrixes(t1m1, t1m2);
    timer.stop();
    //  stop timer
    // print time of timer

    printMatrix(m3);
    std::cout << "Time of multiply: " << timer.getTime() << std::endl;

    m3 = multiplyTwoMatrixes(t2m1, t2m2);
    printMatrix(m3);

    m3 = multiplyTwoMatrixes(t3m1, t3m2);
    printMatrix(m3);

    m3 = multiplyTwoMatrixes(t4m1, t4m2);
    printMatrix(m3);

    m3 = multiplyTwoMatrixes(t5m1, t5m2);
    printMatrix(m3);

    return 0;
}