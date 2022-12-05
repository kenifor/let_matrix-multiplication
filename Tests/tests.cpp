#include "multiplyFunctions.h"
#include <gtest/gtest.h>

#define THREADS_COUNT 1

TEST(MultiplyTwoEmptyMatrixes, EmptyAndEmptyMatrixes) {
    Matrix matrix1{};
    Matrix matrix2{};

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    auto result = Matrix();

    ASSERT_EQ(matrix3, result);
}

TEST(MultiplyTwoEmptyMatrixes, Empty_And_not_empty_Matrix) {
    Matrix matrix1{};
    Matrix matrix2{
        {8, 7, 0},
        {6, 1, 10},
        {4, 11, 8}
    };

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    auto result = Matrix();

    ASSERT_EQ(matrix3, result);
}

TEST(MultiplyTwoEmptyMatrixes, Not_Empty_And_empty_Matrix) {
    Matrix matrix1{
        {8, 7, 0},
        {6, 1, 10},
        {4, 11, 8}
    };
    Matrix matrix2{};

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    auto result = Matrix();

    ASSERT_EQ(matrix3, result);
}
TEST(MultiplyTwoEmptyMatrixes, all_matrixes_normal) { // matrix_3x3 * matrix_3x3
    Matrix matrix1{
        {6, 2, 4},
        {0, 1, 10},
        {1, 7, 8}
    };
    Matrix matrix2{
        {4, 5, 6},
        {8, 9, 0},
        {1, 2, 7}
    };

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    Matrix result{

        {44, 56, 64},
        {18, 29, 70},
        {68, 84, 62}
    };

    ASSERT_EQ(matrix3, result);
}
TEST(MultiplyTwoEmptyMatrixes, rows_not_equal_columns) {
    Matrix matrix1{
        {8, 7, 0},
        {6, 1, 10},
        {4, 11, 8}
    };
    Matrix matrix2{

        {8, 1, 0},
        {3, 21, 5}
    };

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    auto result = Matrix();

    ASSERT_EQ(matrix3, result);
}

TEST(MultiplyTwoEmptyMatrixes2, rows_not_equal_columns) {
    Matrix matrix1{
        {100, 7, 0},
        {6, 1, 10},
        {4, 11, 8}
    };
    Matrix matrix2{
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    Matrix matrix3 = multiplyTwoMatrixes(matrix1, matrix2, THREADS_COUNT);
    auto result = Matrix();

    ASSERT_EQ(matrix3, matrix1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
