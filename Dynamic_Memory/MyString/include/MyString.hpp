#ifndef __MYSTRING_HPP__
#define __MYSTRING_HPP__

#include <iostream>

int my_strlen(const char* str);

class MyString {
public:
    void setString(const char* str);
    char* getString();
    int getLength();

    MyString();
    MyString(const char c);
    MyString(const char* str);

    MyString(const MyString& str);

    ~MyString();

    const char* begin();
    const char* end();
    const char front();
    const char back();
    const int size();
    const int length();
    bool empty();
    void insert(const int pos, const char* str);
    void clear();
    void reverse();
    char at(const int i);
    void println();

    MyString& replace(const char* findStr, const char* replaceStr);
    MyString& replace(const int pos, const int len, const MyString& str);
    MyString& replace(const int pos, const int len, const char* str);

    MyString substr(const int pos, const int len);

    void assign(const char* str);
    void assign(const int count, const char& ch);
    void assign(const MyString& origin, const int start, const int count);

    void append(const char* str);
    void append(const int count, const char& ch);
    void append(const MyString& origin, const int start, const int count);

    int compare(const MyString& str);
    int compare(const char* str);

    void erase(const int pos);
    void erase(const int start, const int count);

    int find(const MyString& str, int pos = 0);
    int find(const char* str, int pos = 0);

    int copy(char* str, const int len, const int pos = 0);
    int copy(MyString& str, const int len, const int pos = 0);

    void move(MyString& str);

    MyString operator+(const MyString& str);
    MyString operator+(const char* str);

    void operator=(const char* str);
    void operator=(const MyString& str);

    bool operator==(const MyString& str);
    bool operator==(const char* str);

    void operator+=(const MyString& str);
    void operator+=(const char* str);

    char operator[](const int i);

    friend std::ostream& operator << (std::ostream &out, const MyString &element);
    friend std::istream& operator >> (std::istream &in, MyString &element);

private:
    char* element;
    int myLength;
};

#endif // __MYSTRING_HPP__