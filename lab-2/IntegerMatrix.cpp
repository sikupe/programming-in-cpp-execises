//
// Created by simon on 10.10.22.
//

#include <vector>
#include <iostream>
#include <cmath>
#include "IntegerMatrix.hpp"

using namespace std;

int int_width(int i) {
    if (i == 0) {
        return 1;
    }
    return (int) ceil(log10(i));
}

void IntegerMatrix::ensure_positive(int i) const {
    if (i < 0) {
        throw invalid_argument("Index or size must be positive");
    }
}

void IntegerMatrix::ensure_in_range_x(int x) const {
    if (x < 0 || x >= width) {
        throw invalid_argument("Out of range x: " + to_string(x));
    }
}

void IntegerMatrix::ensure_in_range_y(int y) const {
    if (y < 0 || y >= height) {
        throw invalid_argument("Out of range y: " + to_string(y));
    }
}

void IntegerMatrix::ensure_in_range(int x, int y) const {
    ensure_in_range_x(x);
    ensure_in_range_y(y);
}

int IntegerMatrix::min_column_width(int column) const {
    int current_width = 1;
    for (auto value: get_column(column)) {
        auto char_width = int_width(value);
        if (char_width > current_width) {
            current_width = char_width;
        }
    }
    return current_width;
}

IntegerMatrix::IntegerMatrix(int width, int height) {
    ensure_positive(width);
    ensure_positive(height);
    matrix = vector<vector<int>>(width, vector<int>(height));
}

void IntegerMatrix::set(int x, int y, int value) {
    ensure_in_range(x, y);

    matrix[x][y] = value;
}

int IntegerMatrix::get(int x, int y) const {
    ensure_in_range(x, y);

    return matrix[x][y];
}

void IntegerMatrix::print() const {
    for (int y = 0; y < height; y++) {
        for (int x= 0; x < width; x++) {
            auto value = get(x, y);
            std::cout << " ";
            auto min_width = min_column_width(x);
            for (int i = int_width(value); i < min_width; i++) {
                std::cout << " ";
            }
            std::cout << to_string(value) << " ";
        }
        std::cout << endl;
    }
}

void IntegerMatrix::set_width(int new_width) {
    ensure_positive(new_width);
    matrix.resize(new_width);
    for (int i = width; i < new_width; i++) {
        matrix[i] = vector<int>(height);
    }
    width = new_width;
}

void IntegerMatrix::set_height(int new_height) {
    ensure_positive(new_height);
    for (auto row : matrix) {
        row.resize(new_height);
        for (int i = height; i < new_height; i++) {
            row[i] = 0;
        }
    }
    height = new_height;
}

int IntegerMatrix::get_width() const {
    return width;
}

int IntegerMatrix::get_height() const {
    return height;
}

const vector<int> IntegerMatrix::get_row(int y) const {
    vector<int> result(width);
    for (int i = 0; i < width; ++i) {
        result[i] = matrix[i][y];
    }
    return result;
}

const vector<int> IntegerMatrix::get_column(int x) const {
    return matrix[x];
}

const vector<vector<int>> IntegerMatrix::get_rows() const {
    vector<vector<int>> result(height);
    for (int y = 0; y < height; ++y) {
        result[y] = get_row(y);
    }
    return result;
}

const vector<vector<int>> IntegerMatrix::get_columns() const {
    return matrix;
}

void IntegerMatrix::clear() {
    for (auto row : matrix) {
        row.clear();
    }
}

void IntegerMatrix::fill_with_value(int value) {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            matrix[x][y] = value;
        }
    }
}

void IntegerMatrix::reverse() {
    auto previous_width = width;
    auto previous_height = height;
    if (previous_width > previous_height) {
        set_height(previous_width);
    } else if (previous_height > previous_width) {
        set_width(previous_width);
    }

    for (int x = 0; x < previous_width; ++x) {
        for (int y = 0; y < previous_height; ++y) {
            auto buffer = matrix[x][y];
            matrix[x][y] = matrix[y][x];
            matrix[y][x] = buffer;
        }
    }

    set_width(previous_height);
    set_height(previous_width);
}

bool IntegerMatrix::is_negative() const {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (matrix[x][y] < 0) {
                return true;
            }
        }
    }
    return false;
}

int IntegerMatrix::zero_count() const {
    int count = 0;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (matrix[x][y] == 0) {
                count++;
            }
        }
    }
    return count;
}
