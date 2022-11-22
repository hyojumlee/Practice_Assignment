#include "MyString.hpp"

#include <memory>
#include <string>

int main(){
    MyString test1;
    MyString test2 = "hyojun";
    int pos = 0;
    int length = 0;

    test1.setString("Hello World!");
    length = test1.length();

    std::cout << std::endl << "setString!!----------------------------" << std::endl;
    test1.println();

    test1.insert(length, "!");
    std::cout << std::endl << "insert()!!----------------------------" << std::endl;
    test1.println();

    char ch = test1[1];

    std::cout << std::endl << "[]operator!!----------------------------" << std::endl;
    std::cout << ch << std::endl;

    test1.reverse();
    std::cout << std::endl << "reverse()!!----------------------------" << std::endl;
    test1.println();

    test1.clear();
    std::cout << std::endl << "clear()!!----------------------------" << std::endl;
    test1.println();

    test1 += "wow";
    std::cout << std::endl << "+=operator!!----------------------------" << std::endl;
    test1.println();

    test1.clear(); //test1 = ""
    test1.append("ABCDEF"); //test1 = "ABCDEF"
    test1.append(3,'a'); //test1 = "ABCDEFaaa"
    test2.append(test1,0,3); //test2 = "hyojunABC"
    std::cout << std::endl << "append()!!----------------------------" << std::endl;
    test1.println();
    test2.println();

    pos = test2.find("ABC");
    std::cout << std::endl << "find()!!----------------------------" << std::endl; 
    std::cout << "ABC is test2["<<pos << "]" << std::endl;

    length = test2.length() - pos;
    test2.replace(pos, length, "_Lee"); //test2 = "hyojun_Lee"
    std::cout << std::endl << "replace()!!----------------------------" << std::endl;
    test2.println();

    test1 = test2.substr(1, 6); //test1 = "yojun_"
    std::cout << std::endl << "substr()!!----------------------------" << std::endl;
    test1.println();

    test1.assign("Hello world"); //test1 = "Hello world"
    test2.assign(5, 'A'); //test2 = "AAAAA"
    std::cout << std::endl << "assign()!!----------------------------" << std::endl;
    test1.println();
    test2.println();

    char buffer[10];
    length = test1.copy(buffer, 5, 6); //buffer = "world", length = 5
    std::cout << std::endl << "copy()!!----------------------------" << std::endl;
    std::cout << "buffer : " << buffer << std::endl;
    test1.println();

    MyString move;
    move.move(test1); //test1 = "", move = "Hello world"
    std::cout << std::endl << "move()!!----------------------------" << std::endl;
    test1.println();
    move.println();

    std::cout << std::endl << "compare()!!----------------------------" << std::endl;
    test1.assign("ABCD");
    test2.assign("ABCD");

    if (0 == test1.compare(test2)) {
        std::cout << "It matches!" << std::endl;
    } else {
        std::cout << "It doesn't match!" << std::endl;
    }

    return 0;
}