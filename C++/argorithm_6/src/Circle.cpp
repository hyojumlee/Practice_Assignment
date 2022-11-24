#include "Circle.hpp"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

#define SPACE "   "

void Circle::createCircle(const int diameter) {
    //x^2 + y^2 = r^2
    int smallDiameter = diameter * (0.8);

    for (int x = -diameter; x <= diameter; ++x) {
        for (int y = -diameter; y<= diameter; ++y) {
            if (x*x + y*y <= diameter*diameter && x*x + y*y >= smallDiameter*smallDiameter) {
                std::cout << "***";
            } else {
                std::cout << SPACE;
            }
        }
        std::cout << "\n";
    }
}

bool Circle::validCheck(const int diameter) {
    bool result = true;
    int maxSize = 0;

    maxSize = winSize();

    if (0 >= diameter || diameter > maxSize) {
        result = false;
    } else {}

    return result;
}

int Circle::winSize() {
    struct winsize w;
    int windowSize = 0;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    windowSize = w.ws_col / 6.2;

    return windowSize;
}