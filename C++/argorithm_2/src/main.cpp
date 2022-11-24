#include "trans_bin.hpp"

#include <iostream>

int main(){
    Binary bin;
    std::string input;

    std::cout << "Input binary number : ";
    getline(std::cin, input, '\n');
    bin.set_string(input);

    if (false == bin.valid_check()) {
        std::cout << "Input value error!(binary, max size : 32)" << std::endl;
        exit(-1) ;
    } else {}

    std::cout << "Decimal : " << bin.trans_decimal() << std::endl;
    std::cout << "Hexadecimal : " << bin.trans_hexa() << std::endl;

    return 0;
}