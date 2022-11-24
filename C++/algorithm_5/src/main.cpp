#include "Pattern.hpp"
#include <iostream>

int main() {
    int number;

    std::cout << "Input number of rows : ";
    std::cin >> number;

    if (false == Pattern::validCheck(number)) {
        std::cout << "Invalid value. You can enter number from 1 to 9" << std::endl;
    } else {
        Pattern::trianglePattern(number);
    }

    return 0;
}
