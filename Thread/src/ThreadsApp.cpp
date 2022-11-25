#include "../include/ThreadsApp.hpp"
#include <iostream>
#include <vector>

void ThreadsApp::primeCountEratos(const int range, const int threadNum, std::vector<int>& result) {
    int count = 0;
    bool* primeArray = new bool[range + 1];

    for (int i = 2; i<= range; ++i) {
        primeArray[i] = true;
    }

    for (int i = 2; i * i <= range; ++i) {
        if (true == primeArray[i]) {
            for (int j = i * i; j <= range; j +=i) {
                primeArray[j] = false;
            }
        } else {}
    }

    for (int i = 0; i < range; ++i) {
        if (true == primeArray[i]) {
            ++count;
        } else {}
    }

    result[threadNum - 1] = count;
    
    delete[] primeArray;
}

bool ThreadsApp::vaildCheck(const int range) {
    bool result = true;

    if (0 >= range) {
        result = false;
    } else {}

    return result;
}