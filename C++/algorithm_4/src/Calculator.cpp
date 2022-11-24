#include "Calculator.hpp"
#include <cstdlib>
#include <cmath>
#include <iostream>

void Calculator::insertZero(std::string& binary, int count){
    binary.insert(0, count, '0');
}

std::string Calculator::calculateBinary(const std::string& first, const std::string& second, const std::string& operators) {
    std::string calcResult;
    int firstNum = 0;
    int secondNum = 0;
    int afterCalc = 0;

    for (int i = 0; i < first.length(); ++i) {
        firstNum = first[i] - '0';
        secondNum = second[i] - '0';

        if ("or" == operators || "OR" == operators) {

            afterCalc = firstNum | secondNum;

        } else if ("nor" == operators || "NOR" == operators) {

            afterCalc = !(firstNum | secondNum);

        } else if ("and" == operators || "AND" == operators) {

            afterCalc = firstNum & secondNum;

        } else if ("xor" == operators || "XOR" == operators) {

            afterCalc = firstNum ^ secondNum;

        } else {

            calcResult = "Invalid operators.";
            break;

        }
        calcResult.push_back(afterCalc + '0');
    }

    return calcResult;
}

bool Calculator::binaryValidCheck(const std::string& binary) {
    bool result = true;

    for (int i = 0; i < binary.length(); ++i) {
        if (binary[i] != '1' && binary[i] != '0') {
            result = false;
            break;
        } else {}
    }

    return result;
}
