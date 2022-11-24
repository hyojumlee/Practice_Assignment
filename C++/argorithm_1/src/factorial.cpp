#include "factorial.hpp"

#include <iostream>

uint64_t Factorial::calc_fact(const uint64_t num)
{
    uint64_t calc_result = 1;

    for (int i = num; i > 1; --i) {
        calc_result *= i;
    }

    return calc_result;
}

uint64_t Factorial::recursion_fact(const uint64_t num)
{
    uint64_t recu_result = 1;

    if (1 <= num) {
        recu_result *= num * recursion_fact(num - 1);
    } else {}

    return recu_result;
}

bool Factorial::valid_check(const uint64_t num)
{
    bool result = true;

    if (20 < num) {
        result = false;
    } else if (1 > num) {
        result = false;
    } else {}

    return result;
}