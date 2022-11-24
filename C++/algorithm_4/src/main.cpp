#include "Calculator.hpp"
#include <iostream>
#include <cstdlib>

int main(){
    std::string inputOperators;
    std::string firstBinary;
    std::string secondBinary;
    std::string result;
    int count = 0;
    bool flag = true;

    std::cout << "A : " ;
    std::getline(std::cin, firstBinary, '\n');

    if (false == Calculator::binaryValidCheck(firstBinary)) {
        std::cout << "Invalid value. You can enter only binary" << std::endl;
        flag = false;
    } else {}

    if (true == flag) {
        std::cout << "B : " ;
        std::getline(std::cin, secondBinary, '\n');

        if (false == Calculator::binaryValidCheck(secondBinary)) {
            std::cout << "Invalid value. You can enter only binary" << std::endl;
            flag = false;
        } else {}
        
        count = abs(firstBinary.length() - secondBinary.length());

        if (firstBinary.length() > secondBinary.length()) {
            Calculator::insertZero(secondBinary, count);
        } else {
            Calculator::insertZero(firstBinary, count);
        }

        if (true == flag) {
            std::cout << "OP : ";
            std::getline(std::cin, inputOperators, '\n');
        } else {}
    }

    result = Calculator::calculateBinary(firstBinary, secondBinary, inputOperators);

    std::cout << "Result : " << result << std::endl;

    return 0;
}
