#ifndef __CALCULATOR_HPP__
#define __CALCULATOR_HPP__

#include <string>

class Calculator{
public:
    static void insertZero(std::string& binary, const int count);
	//calc binary number
    static std::string calculateBinary(const std::string& first, const std::string& second, const std::string& operators);
    //input number vaild check
	static bool binaryValidCheck(const std::string& binary);
};

#endif // __CALCULATOR_HPP__
