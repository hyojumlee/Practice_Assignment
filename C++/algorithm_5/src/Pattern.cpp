#include "Pattern.hpp"
#include<iostream>

void Pattern::trianglePattern(const int num) {
    int numberColumn = 0;
    int spaceColumn = num;

    for (int row = 0 ; row <= num ; ++row) {

        for (int i = 0 ; i < spaceColumn ; ++i) {

            std::cout << " ";

        }

        for (int j = 1; j <= numberColumn ; ++j) {
            std::cout << j;

            if (j == row) {
                for (int k = j-1; k > 0 ; k--) {
                    std::cout << k;
                }
            } else {}
        }
        std::cout << std::endl;
        numberColumn++;
        spaceColumn--;
    }
}

bool Pattern::validCheck(const int num) {
    bool result = true;

    if (0 >= num || 10 <= num ) {
        result = false;
    } else {}

    return result;
}
