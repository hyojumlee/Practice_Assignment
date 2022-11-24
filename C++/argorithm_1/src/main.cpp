#include "factorial.hpp"
#include <iostream>

int main()
{
    uint64_t number = 0;
    uint64_t calc_result = 1;
    uint64_t recu_result = 1;

    std::cout << "Input number: ";
    std::cin >> number;
	//예외처리
    if (false == Factorial::valid_check(number)) {
        std::cout << "Invalid value!!(valid value : 1 ~ 20)" << std::endl;
        exit(-1);
    } else {}

    calc_result = Factorial::calc_fact(number);
    recu_result = Factorial::recursion_fact(number);

    std::cout << "calc Factorial of " << number << " is " << calc_result << std::endl;
    std::cout << "recursion Factorial of " << number << " is " << recu_result << std::endl;

    return 0;
}
