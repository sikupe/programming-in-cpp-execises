//
// Created by simon on 10.10.22.
//

#ifndef INTEGER_MATRIX_INTEGERMATRIX_H
#define INTEGER_MATRIX_INTEGERMATRIX_H
//
// Created by simon on 10.10.22.
//

#include <vector>
#include <iostream>

using namespace std;

int int_width(int value);

class IntegerMatrix {
private:
    vector<vector<int>> matrix;
    int width;
    int height;

    void ensure_positive(int i) const;
    void ensure_in_range_x(int x) const;
    void ensure_in_range_y(int y) const;
    void ensure_in_range(int x, int y) const;
public:
    IntegerMatrix(int width, int height) ;

    void set(int x, int y, int value) ;

    int get(int x, int y) const ;

    void print() const;

    void set_width(int width);

    void set_height(int height);

    int get_width() const;

    int get_height() const;

    const vector<int> get_row(int x) const;

    const vector<int> get_column(int x) const;

    const vector<vector<int>> get_rows() const;

    const vector<vector<int>> get_columns() const;

    void clear();

    void fill_with_value(int value);

    void reverse();

    bool is_negative() const;

    int zero_count() const;

    int min_column_width(int column) const;
};

#endif //INTEGER_MATRIX_INTEGERMATRIX_H
