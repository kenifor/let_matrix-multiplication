#include "multiplyFunctions.h"
#include "IntGenerator.h"

#include <iostream>
#include <thread>
#include <time.h>


/* TIMER
 *
 * #include <time.h>
 *
 * clock_t start, end;
 *
 * start = clock();
 *
 * // some operation
 *
 * end = clock();
 *
 * float time = static_cast<float>(end-start) / CLOCKS_PER_SEC;
 *
 * */

void resultTest()
{
    IntGenerator gena;

    int size = 10;

    Matrix m1 = createMatrix(size, gena);
    printMatrix(m1);
    Matrix m2 = createMatrix(size, gena);
    printMatrix(m2);

    Matrix m3 = multiplyTwoMatrixes(m1, m2);
    printMatrix(m3);
    std::cout << m3.size() << std::endl;
}

void timeTest()
{
    IntGenerator gena;
    Matrix m1 = createMatrix(100, gena);
    Matrix m2 = createMatrix(100, gena);

    clock_t start, end;

    start = clock();
    Matrix m = multiplyTwoMatrixes(m1, m2);
    end = clock();

    auto t = (float)(end-start) / CLOCKS_PER_SEC;

    std::cout << "t = " << t << std::endl;
}

void resultTest1()
{
    Matrix m1 {
        {2, 1},
        {3, 7}
    };
    printMatrix(m1);

    Matrix m2 {
        {1, 8},
        {2, 1}
    };
    printMatrix(m2);

    Matrix m3 = multiplyTwoMatrixes(m1, m2);
    printMatrix(m3);

    /*
     * 4    17
     * 17   31
     * */
}

int main()
{
    //timeTest();
    //resultTest();
    resultTest1();
    return 0;
}
