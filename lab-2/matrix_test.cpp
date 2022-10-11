#include "IntegerMatrix.hpp"
#include <gtest/gtest.h>

IntegerMatrix create_matrix_empty() {
    auto matrix = IntegerMatrix(2, 3);

    return matrix;
}

IntegerMatrix create_matrix_filled() {
    auto matrix = create_matrix_empty();

    matrix.set(0, 0, 1);
    matrix.set(0, 1, 2);
    matrix.set(0, 2, 3);
    matrix.set(1, 0, 4);
    matrix.set(1, 1, 5);
    matrix.set(1, 2, 6);

    return matrix;
}

TEST(MatrixTest, TestGetWidth) {
    auto matrix = create_matrix_empty();

    EXPECT_EQ(2, matrix.get_width());
}

TEST(MatrixTest, TestGetHeight) {
    auto matrix = create_matrix_empty();

    EXPECT_EQ(3, matrix.get_height());
}
