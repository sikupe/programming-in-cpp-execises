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

IntegerMatrix create_matrix_filled_large_numbers() {
    auto matrix = create_matrix_empty();

    matrix.set(0, 0, 1);
    matrix.set(0, 1, 40);
    matrix.set(0, 2, 300);
    matrix.set(1, 0, 5000);
    matrix.set(1, 1, 530);
    matrix.set(1, 2, 65);

    matrix.reverse();

    return matrix;
}

TEST(MatrixTest, TestGetWidth) {
    auto matrix = create_matrix_empty();

    EXPECT_EQ(matrix.get_width(), 2);
}

TEST(MatrixTest, TestGetHeight) {
    auto matrix = create_matrix_empty();

    EXPECT_EQ(matrix.get_height(), 3);
}

TEST(MatrixTest, TestGet) {
    auto matrix = create_matrix_filled();

    EXPECT_EQ(matrix.get(0, 1), 2);
}

TEST(MatrixTest, TestSet) {
    auto matrix = create_matrix_empty();

    matrix.set(0, 1, 3);

    EXPECT_EQ(matrix.get(0, 1), 3);
}

TEST(MatrixTest, TestPrint) {
    auto matrix = create_matrix_filled();

    // I know, not a real unit test... But I was a bit too lazy to find out how to mock std::cout to check the result porperly
    matrix.print();
}

TEST(MatrixTest, TestSetWidth) {
    auto matrix = create_matrix_filled();

    matrix.set_width(3);

    EXPECT_EQ(matrix.get_width(), 3);
    EXPECT_EQ(matrix.get_height(), 3);
    EXPECT_EQ(matrix.get(2, 0), 0);
    EXPECT_EQ(matrix.get(2, 1), 0);
    EXPECT_EQ(matrix.get(2, 2), 0);
    EXPECT_EQ(matrix.get(0, 0), 1);
    EXPECT_EQ(matrix.get(0, 1), 2);
    EXPECT_EQ(matrix.get(0, 2), 3);
    EXPECT_EQ(matrix.get(1, 0), 4);
    EXPECT_EQ(matrix.get(1, 1), 5);
    EXPECT_EQ(matrix.get(1, 2), 6);
}

TEST(MatrixTest, TestSetHeight) {
    auto matrix = create_matrix_filled();

    matrix.set_height(4);

    EXPECT_EQ(matrix.get_height(), 4);
    EXPECT_EQ(matrix.get_width(), 2);
    EXPECT_EQ(matrix.get(0, 0), 1);
    EXPECT_EQ(matrix.get(0, 1), 2);
    EXPECT_EQ(matrix.get(0, 2), 3);
    EXPECT_EQ(matrix.get(0, 3), 0);
    EXPECT_EQ(matrix.get(1, 0), 4);
    EXPECT_EQ(matrix.get(1, 1), 5);
    EXPECT_EQ(matrix.get(1, 2), 6);
    EXPECT_EQ(matrix.get(1, 3), 0);
}


TEST(MatrixTest, TestGetRow) {
    auto matrix = create_matrix_filled();

    auto row = matrix.get_row(1);

    EXPECT_EQ(row.size(), 2);
    EXPECT_EQ(row[0], 2);
    EXPECT_EQ(row[1], 5);
}


TEST(MatrixTest, TestGetColumn) {
    auto matrix = create_matrix_filled();

    auto column = matrix.get_column(1);

    EXPECT_EQ(column[0], 4);
    EXPECT_EQ(column[1], 5);
    EXPECT_EQ(column[2], 6);
}

TEST(MatrixTest, TestGetRows) {
    auto matrix = create_matrix_filled();

    auto rows = matrix.get_rows();

    EXPECT_EQ(rows[0][0], 1);
    EXPECT_EQ(rows[1][0], 2);
    EXPECT_EQ(rows[2][0], 3);
    EXPECT_EQ(rows[0][1], 4);
    EXPECT_EQ(rows[1][1], 5);
    EXPECT_EQ(rows[2][1], 6);
}

TEST(MatrixTest, TestGetColumns) {
    auto matrix = create_matrix_filled();

    auto columns = matrix.get_columns();

    EXPECT_EQ(columns[0][0], 1);
    EXPECT_EQ(columns[0][1], 2);
    EXPECT_EQ(columns[0][2], 3);
    EXPECT_EQ(columns[1][0], 4);
    EXPECT_EQ(columns[1][1], 5);
    EXPECT_EQ(columns[1][2], 6);
}

TEST(MatrixTest, TestClear) {
    auto matrix = create_matrix_filled();

    matrix.clear();

    EXPECT_EQ(matrix.get_width(), 2);
    EXPECT_EQ(matrix.get_height(), 3);
    EXPECT_EQ(matrix.get(0, 0), 1);
    EXPECT_EQ(matrix.get(0, 1), 2);
    EXPECT_EQ(matrix.get(0, 2), 3);
    EXPECT_EQ(matrix.get(1, 0), 4);
    EXPECT_EQ(matrix.get(1, 1), 5);
    EXPECT_EQ(matrix.get(1, 2), 6);
}

TEST(MatrixTest, TestFillWithValue) {
    auto matrix = create_matrix_filled();

    matrix.fill_with_value(8);

    EXPECT_EQ(matrix.get_width(), 2);
    EXPECT_EQ(matrix.get_height(), 3);
    EXPECT_EQ(matrix.get(0, 0), 8);
    EXPECT_EQ(matrix.get(0, 1), 8);
    EXPECT_EQ(matrix.get(0, 2), 8);
    EXPECT_EQ(matrix.get(1, 0), 8);
    EXPECT_EQ(matrix.get(1, 1), 8);
    EXPECT_EQ(matrix.get(1, 2), 8);
}

TEST(MatrixTest, TestReverse) {
    auto matrix = create_matrix_filled();

    matrix.reverse();

    ASSERT_EQ(matrix.get_width(), 3);
    ASSERT_EQ(matrix.get_height(), 2);
    EXPECT_EQ(matrix.get(0, 0), 1);
    EXPECT_EQ(matrix.get(1, 0), 2);
    EXPECT_EQ(matrix.get(2, 0), 3);
    EXPECT_EQ(matrix.get(0, 1), 4);
    EXPECT_EQ(matrix.get(1, 1), 5);
    EXPECT_EQ(matrix.get(2, 1), 6);
}

TEST(MatrixTest, TestIsNegativeFalse1) {
    auto matrix = create_matrix_filled();

    auto is_negative = matrix.is_negative();

    EXPECT_FALSE(is_negative);
}

TEST(MatrixTest, TestIsNegativeFalse2) {
    auto matrix = create_matrix_filled();

    matrix.set(0, 0, -1);

    auto is_negative = matrix.is_negative();

    EXPECT_FALSE(is_negative);
}

TEST(MatrixTest, TestIsNegativeTrue) {
    auto matrix = IntegerMatrix(1, 2);

    matrix.set(0, 0, -1);
    matrix.set(0, 1, -1);

    auto is_negative = matrix.is_negative();

    EXPECT_TRUE(is_negative);
}

TEST(MatrixTest, TestCountZeroEmpty) {
    auto matrix = create_matrix_empty();

    auto zeros = matrix.zero_count();

    EXPECT_EQ(zeros, 6);
}

TEST(MatrixTest, TestCountZeroNotEmpty) {
    auto matrix = create_matrix_empty();
    matrix.set(1, 1, 1);

    auto zeros = matrix.zero_count();

    EXPECT_EQ(zeros, 5);
}

TEST(MatrixTest, TestIntWidth0) {
    auto width = int_width(0);

    EXPECT_EQ(width, 1);
}

TEST(MatrixTest, TestIntWidth1) {
    auto width = int_width(1);

    EXPECT_EQ(width, 1);
}

TEST(MatrixTest, TestIntWidth10) {
    auto width = int_width(10);

    EXPECT_EQ(width, 2);
}

TEST(MatrixTest, TestIntWidth100) {
    auto width = int_width(100);

    EXPECT_EQ(width, 3);
}

TEST(MatrixTest, TestColumnWidth) {
    auto matrix = create_matrix_filled_large_numbers();

    EXPECT_EQ(matrix.get_width(), 3);
    EXPECT_EQ(matrix.min_column_width(0), 4);
    EXPECT_EQ(matrix.min_column_width(1), 3);
    EXPECT_EQ(matrix.min_column_width(2), 3);
}