#ifndef __TRANS_BIN_HPP__
#define __TRANS_BIN_HPP__

#include <string>

class Binary{
public:
    Binary();
    Binary(const std::string& str);

    void set_string(const std::string& str);
    std::string get_string();

    unsigned int trans_decimal();
    std::string trans_hexa();
    bool valid_check();

private:
    std::string binary;
};

#endif // __TRANS_BIN_HPP__