#ifndef __SMARTSTRING_HPP__
#define __SMARTSTRING_HPP__

#include <memory>
#include <iostream>

int my_strlen(const char* str);

class SmartString {
public:
    void setString(const char* str);
    char* getString();
    int getLength();

    SmartString();
    SmartString(const char c);
    SmartString(const char* str);

    SmartString(const SmartString& str);

    ~SmartString();

    const char* begin();
    const char* end();
    const char front();
    const char back();
    const void print();
    const void println();
    int size();
    int length();
    bool empty();
    void insert(const int pos, const char* str);
    void clear();
    void clear(const int length);
    void reverse();
    char at(const int pos);
    void resize(const int length);

    void replace(const char* findStr, const char* replaceStr);
    SmartString replace(const int pos, const int len, SmartString& str);
    SmartString replace(const int pos, const int len, const char* str);

    SmartString substr(const int pos, const int len);

    void assign(const char* str);
    void assign(const SmartString& str);
    void assign(const int count, const char& ch);
    void assign(const SmartString& origin, const int start, const int count);

    void append(const char* str);
    void append(const SmartString& str);
    void append(const int count, const char& ch);
    void append(const SmartString& origin, const int start, const int count);

    int compare(const SmartString& str);
    int compare(const char* str);

    void erase(const int pos);
    void erase(const int start, const int count);

    int count(const SmartString& str);
    int count(const char* str);

    int find(const SmartString& str, const int pos = 0);
    int find(const char* str, const int pos = 0);

    int copy(char* str, const int len, const int pos = 0);
    int copy(SmartString& str, const int len, const int pos = 0);

    void move(SmartString& str);

    SmartString operator+(const SmartString& str);
    SmartString operator+(const char* str);

    void operator=(const char* str);
    void operator=(const SmartString& str);

    bool operator==(const SmartString& str);
    bool operator==(const char* str);

    void operator+=(const SmartString& str);
    void operator+=(const char* str);

    char operator[](const int i);

    friend std::ostream& operator << (std::ostream &out,  SmartString &element);


private:
    std::unique_ptr<char[]> element = nullptr;
    int myLength = 0;
};

#endif // __SMARTSTRING_HPP__