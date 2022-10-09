#include <iostream>
#include <string>
#include <vector>

using namespace std;

void greet(vector<string> names) {
    if (names.empty()) {
        return;
    } else if (names.size() == 1) {
        std::cout << names[0];
    } else if (names.size() == 2) {
        std::cout << names[0] << " and " << names[1];
    } else {
        std::cout << names[0] << ", ";
        greet(vector<string>(&names[1], &names[names.size()]));
    }
}

int main(int argc, char *argv[]) {
    vector<string> names(&argv[1], argv + argc);

    if (names.empty()) {
        std::cout << "No one to great!";
    } else {
        std::cout << "Hello to ";
        greet(names);
    }

    std::cout << endl;

    return 0;
}
