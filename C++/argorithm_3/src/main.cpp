#include "words_count.hpp"
#include<iostream>

int main(){
    std::string input_s;
    int words = 0;
    
    std::cout << "Input string : ";
    std::getline(std::cin, input_s, '\n');

    words = Words::words_count(input_s);

    std::cout << "number of words : " << words << std::endl;

    return 0;
}
