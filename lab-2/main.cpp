//
// Created by simon on 11.10.22.
//

#include "IntegerMatrix.hpp"

int main() {
    auto matrix = IntegerMatrix(2, 3);
    matrix.set(0, 0, 1);
    matrix.set(0, 1, 40);
    matrix.set(0, 2, 300);
    matrix.set(1, 0, 5000);
    matrix.set(1, 1, 530);
    matrix.set(1, 2, 65);

    matrix.print();

    return 0;
}