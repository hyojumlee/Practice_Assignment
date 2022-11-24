#include "words_count.hpp"

int Words::words_count(const std::string& input_s) {	
    bool flag = false;
    int words = 0;

    for (int i = 0; i < input_s.size(); ++i) {
        if (input_s[i] == ' ') {
            flag = false;
        } else {
            if (false == flag) {
               ++words;
               flag = true;
            }
        }
    }
    return words;
}
