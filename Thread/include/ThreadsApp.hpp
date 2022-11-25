#ifndef __THREADAPP_HPP__
#define __THREADAPP_HPP__

#include <vector>

class ThreadsApp {
public:
    static void primeCountEratos(const int range, const int threadNum, std::vector<int>& result);
    static bool vaildCheck(const int range);
};

#endif //__THREADAPP_HPP__