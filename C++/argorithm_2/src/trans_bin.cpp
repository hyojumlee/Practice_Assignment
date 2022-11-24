#include "trans_bin.hpp"

#include <iostream>
#include <cmath>

Binary::Binary() : Binary("") {}

Binary::Binary(const std::string& str) : binary(str) {}

void Binary::set_string(const std::string& str) {
    binary = str;
}

std::string Binary::get_string() {
    return binary;
}

unsigned int Binary::trans_decimal() {
    unsigned int result = 0;
    int length = binary.length() - 1;//string start 0

    for (int i = 0; i <= length; ++i) {
        if ('1' == binary[i]) {
            result += pow(2, length-i);
        } else {}
    }
    return result;
}

std::string Binary::trans_hexa() {
    std::string hexa = "0123456789ABCDEF";
    std::string result;
    unsigned int decimal = this->trans_decimal();
    unsigned int quotient = 0;
    unsigned int remainder = 0;

    if (0 == decimal) {
        result.insert(result.begin(), 2, hexa[0]);
    } else {}

    while (decimal > 0) {
        quotient = decimal/16;
        remainder = decimal%16;
        decimal = quotient;
        result.insert(result.begin(),hexa[remainder]);
    }
    result.insert(result.begin(), 'x');
    result.insert(result.begin(), '0');

    return result;
}

bool Binary::valid_check() {
    bool result = true;

    if (binary.size() > 32) {
        result = false;
    } else {
        for (int i = 0; i < binary.size(); ++i) {
            if ('1' !=  binary[i] && '0' != binary[i]) {
                result = false;
                break;
            } else {}
        }
    }
    
    return result;
}