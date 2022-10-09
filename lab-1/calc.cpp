#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

double apply_operator(char op, string summand_string) {
    double summand;
    try {
        summand = stod(summand_string);
    } catch (invalid_argument &e) {
        std::cout << "Could not parse number: " << "\"" << summand_string << "\"" << endl;
        exit(1);
    }

    if (op == '+') {
        return summand;
    } else {
        return -summand;
    }
}

double parse_and_calc_term(string term) {
    double result = 0;
    string current_number_string = "0";
    bool contains_dot = false;
    char current_operator = '+';
    for (auto c : term) {
        if (isdigit(c)) {
            current_number_string += c;
            std::cout << "character is a digit: " << c << endl;
        } else if (c == '.') {
            std::cout << "character is a dot";
            if (contains_dot) {
                std::cout << "Number contains multiple dots!" << endl;
                exit(1);
            } else {
                contains_dot = true;
                current_number_string += c;
            }
        } else if (c == '+' || c == '-') {
            std::cout << "current character is an operator: " << c;

            result += apply_operator(current_operator, current_number_string);

            current_number_string = "";
            contains_dot = false;

            current_operator = c;
        }
        std::cout << "current number string: " << current_number_string << endl;
        std::cout << "sum: " << result << endl;
    }
    result += apply_operator(current_operator, current_number_string);

    return result;
}

int main(int argc, char *argv[]) {
    vector<string> terms(&argv[1], argv + argc);

    for (auto term : terms) {
        std::cout << term << " = " << parse_and_calc_term(term) << endl;
    }

    return 0;
}