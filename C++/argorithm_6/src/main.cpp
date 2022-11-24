#include "Circle.hpp"

#include <iostream>

int main() {
    int diameter;

    std::cout << "Input diameter of circle : ";
    std::cin >> diameter;

    if (true == Circle::validCheck(diameter)) {
        Circle::createCircle(diameter);
    } else {
        std::cout << "invalid value! valid range is 1 ~ " << Circle::winSize() << std::endl;
    }

    return 0;
}