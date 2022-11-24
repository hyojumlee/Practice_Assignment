#ifndef __TRANS_BIN_HPP__
#define __TRANS_BIN_HPP__

#include <string>

class Binary{
public:
	//constructor
    Binary();
    Binary(const std::string& str);

	//get,set private member func
    void set_string(const std::string& str);
    std::string get_string();
	
	//binary to decimal
    unsigned int trans_decimal();

    //binary to hexa
	std::string trans_hexa();
    
	//check input value
	bool valid_check();

private:
    std::string binary;
};

#endif // __TRANS_BIN_HPP__
