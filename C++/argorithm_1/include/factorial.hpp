#ifndef __FACTORIAL_HPP__
#define _FACTORIAL_HPP__

#include <cstdint>

class Factorial{
public:
    //recursion function unused
    static uint64_t calc_fact(const uint64_t num);

    //recursion function used
    static uint64_t recursion_fact(const uint64_t num);
    static bool valid_check(const uint64_t num);
};

#endif // __FACTORIAL_HPP__
