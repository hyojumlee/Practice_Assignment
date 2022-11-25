#include "../include/ThreadsApp.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::thread> countPrime;
    std::vector<int> result(argc, 0);
    std::ofstream log1("log1.txt");
    std::ofstream log2("log2.txt");
    int number = 0;

    if (log1.fail() || log2.fail()) {
        std::cout << "Failed to open file." << std::endl;
        exit(-1);
    }

    if (1 == argc) {
        std::cout << "Usage : " << argv[0] << " <number1> <number2> <num..." << std::endl;
    } else {}

    for (int i = 1; i < argc; ++i) {
        number = atoi(argv[i]);
        
        if (false == ThreadsApp::vaildCheck(number)) {
            std::cout << "invalid value! valid range is 1 ~ more" << std::endl;
            exit(-1);
        } else {}

        countPrime.push_back(std::thread(ThreadsApp::primeCountEratos, number, i, std::ref(result)));

    }

    for (int i = 0; i < argc - 1; ++i) {
        countPrime[i].join();
    }

    for (int i = 0; i < argc - 1; ++i) {
        if (0 == i % 2) {
            log1 << "thread[" << i + 1 << "] finished. prime numbers between 0 and " << argv[i + 1] << " : " << result[i] << std::endl;
        } else {
            log2 << "thread[" << i + 1 << "] finished. prime numbers between 0 and " << argv[i + 1] << " : " << result[i] << std::endl;
        }
    }

    log1.close();
    log2.close();

    return 0;
}