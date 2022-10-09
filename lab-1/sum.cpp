#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<double> parse_inputs(vector<string> summand_strings) {
    vector<double> result(summand_strings.size());
    for (int i = 0; i < summand_strings.size(); i++) {
        try {
            double summand = stod(summand_strings[i]);
            result[i] = summand;
        } catch (invalid_argument &e) {
            std::cout << "Parameter " << i << " is not a number: \"" << summand_strings[i] << "\"" << endl;
            exit(1);
        }
    }
    return result;
}

void add_and_print(vector<double> summands) {
    double sum = 0;
    for (double summand : summands) {
        sum += summand;
    }
    std::cout << sum << endl;
}

int main(int argc, char *argv[]) {
    vector<string> summand_strings(&argv[1], argv + argc);

    auto summands = parse_inputs(summand_strings);

    add_and_print(summands);

    return 0;
}
