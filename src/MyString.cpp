#include "MyString.hpp"

int my_strlen(const char *str) {
    int cnt = 0;

    while (*str != '\0') {
        cnt++;
        str++;
    }
    return cnt;
}

void MyString::setString(const char *str) {
    myLength = my_strlen(str);

    for (int i = 0; i != myLength; ++i) {
        element[i] = str[i];
    }
}

char *MyString::getString() {
    return element;
}

int MyString::getLength() {
    return myLength;
}

MyString::MyString() {
    element = new char[1];
    element[0] = '\0';
    myLength = 0;
}
MyString::MyString(char c) {
    element = new char[1];
    element[0] = c;
    myLength = 1;
}
MyString::MyString(const char *str) {
    myLength = my_strlen(str);
    element = new char[myLength];

    for (int i = 0; i != myLength; ++i) {
        element[i] = str[i];
    }
}
MyString::MyString(const MyString &str) {
    myLength = str.myLength;
    element = new char[myLength];

    for (int i = 0; i != myLength; ++i) {
        element[i] = str.element[i];
    }
}

MyString::~MyString() {
    delete[] element;
}

const char* MyString::begin() {
    return &element[0];
}
const char* MyString::end() {
    return &element[myLength];
}

const char MyString::front() {
    return element[0];
}

const char MyString::back() {
    return element[myLength - 1];
}

const int MyString::size() {
    return myLength;
}

const int MyString::length() {
    return myLength;
}

bool MyString::empty() {
    bool result = false;

    if (0 == myLength) {
        result = true;
    } else {}

    return result;
}

void MyString::insert(const int pos, const char* str) {
    if (0 <= pos && pos <= myLength) {
        int strLength = my_strlen(str);
        int count = 0;
        int posCount = pos;

        myLength += strLength;

        MyString copyString(element);

        delete[] element;

        element = new char[myLength];

        for (int i = 0 ; i != pos ; ++i) {
            element[i] = copyString.element[i];
            ++count;
        }
        for (int i = 0 ; i != strLength ; ++i) {
            element[count] = str[i];
            ++count;
        }
        for (int i = count ; i != myLength ; ++i) {
            element[i] = copyString.element[posCount];
            ++count;
            ++posCount;
        }
        myLength = count;
    } else {}
}

void MyString::clear() {
    delete[] element;

    element = new char[1];
    element[0] = '\0';
    myLength = 0;
}

void MyString::reverse() {
    MyString reverse(element);
    int originPoint = 0;
    int reversePoint = myLength - 1;

    for (int i = 0; i != myLength ; ++i) {
        element[originPoint] = reverse.element[reversePoint];
        ++originPoint;
        --reversePoint;
    }
}

char MyString::at(const int num) {
    char result;

    if (0 <= num && num <= myLength) {
        result = element[num-1];
    } else {
        result = '\0';
    }

    return result;
}

void MyString::println() {
    std::cout << element << std::endl;
    std::cout << myLength << std::endl;
}

MyString& MyString::replace(const char* findStr, const char* replaceStr) {
    MyString copyStr(element);
    MyString replace(findStr);
    const int findLength = my_strlen(findStr);
    const int replaceLength = my_strlen(replaceStr);
    const int stringGap = replaceLength - findLength;
    const int forCount = findLength - replaceLength;
    int count = 0;

    clear();

    for (int i = 0; '\0' != copyStr.element[count]; ++i) {
        int flag = 0;

        for (int j = 0; j < findLength; ++j) {
            if (copyStr.element[count+j] == replace.element[j]) {
                if (j + 1 == findLength) {
                    flag = 1;
                } else {}
                continue;
            } else {
                break;
            }
        }
        if (1 == flag) {
            insert(i, replaceStr);
            i += replaceLength -1;
            count += replaceLength - stringGap;
        } else if (0 == flag) {
            element[i] = copyStr.element[count];
            ++count;
            ++myLength;
        } else {}
    }

    return *this;
}

MyString& MyString::replace(const int pos, const int len, const MyString& str) {
    MyString copyStr(element);
    int count = 0;

    if (0 <= pos && pos <= size()) {
        clear();

        for (int i = 0; i < copyStr.myLength; ++i) {
            if (pos <= i && i < pos + len) {
                for (int j = 0; j < str.myLength; ++j) {
                    element[count] = str.element[j];
                    ++count;
                    ++myLength;
                }
                i += len - 1;
            } else {
                element[count] = copyStr.element[i];
                ++count;
                ++myLength;
            }
        }
        element[myLength] = '\0';
    } else {}

    return *this;
}

MyString& MyString::replace(const int pos, const int len, const char* str) {
    MyString copyStr(element);
    const int strLength = my_strlen(str);
    int count = 0;

    if (0 <= pos && pos <= size()) {
        clear();

        for (int i = 0; i < copyStr.myLength; ++i) {
            if (pos <= i && i < pos + len) {
                for (int j = 0; j < strLength; ++j) {
                    element[count] = str[j];
                    ++count;
                    ++myLength;
                }
                i += len - 1;
            } else {
                element[count] = copyStr.element[i];
                ++count;
                ++myLength;
            }
        }
    } else {}

    return *this;
}

MyString MyString::substr(const int pos, const int len) {
    MyString result;

    if (0 <= pos && pos + len <= size()) {
        int count = 0;

        for (int i = 0; i < len; ++i) {
            result.element[i] = element[pos + i];
        }
        result.element[len] = '\0';
        result.myLength = len;
    } else {}

    return result;
}

void MyString::assign(const char* str) {
    int length = my_strlen(str);

    clear();

    for (int i = 0; i < length; ++i) {
        element[i] = str[i];
    }
    myLength = length;
    element[myLength] = '\0';
}

void MyString::assign(const int count, const char& ch) {
    clear();

    for (int i = 0; i < count; ++i) {
        element[i] = ch;
        ++myLength;
    }
    element[myLength] = '\0';
}

void MyString::assign(const MyString& origin, const int start, const int count) {
    clear();

    if (0 <= start && start + count <= origin.myLength) {
        for (int i = 0; i < count; ++i) {
            element[i] = origin.element[start + i];
            ++myLength;
        }
        element[myLength] = '\0';
    } else {}
}

void MyString::append(const char* str) {
    int length = my_strlen(str);

    for (int i = 0; i < length; ++i) {
        element[myLength] = str[i];
        ++myLength;
    }
}

void MyString::append(const int count, const char& ch) {
    if (0 <= count && count <= size()) {
        for (int i = 0; i < count ; ++i) {
            element[myLength] = ch;
            ++myLength;
        }
    } else {}
}

void MyString::append(const MyString& origin, const int start, const int count) {
    if (0 <= start && start + count <= origin.myLength) {
        for (int i = 0; i < count; ++i) {
            element[myLength] = origin.element[start + i];
            ++myLength;
        }
    } else {}
}

int MyString::compare(const MyString& str) {
    int count = myLength >= str.myLength ? myLength + 1 : str.myLength + 1;
    int result = 0;

    for (int i = 0; i < count; ++i) {
        if (element[i] > str.element[i]) {
            result = 1;
            break;
        } else if (element[i] < str.element[i]) {
            result = -1;
            break;
        } else {
            continue;
        }
    }

    return result;
}

int MyString::compare(const char* str) {
    int length = my_strlen(str);
    int count = myLength >= length ? myLength + 1: length + 1;
    int result = 0;

    for (int i = 0; i< count; ++i) {
        if (element[i] > str[i]) {
            result = 1;
            break;
        } else if (element[i] < str[i]) {
            result = -1;
            break;
        } else {
            continue;
        }
    }

    return result;
}

void MyString::erase(const int pos) {
    if (0 <= pos && pos <= size()) {
        MyString copyStr(element);
        int count = myLength;
        int elementCount = 0;

        clear();

        for (int i = 0; i < count; ++i) {
            if (i == pos) {
                continue;
            } else {
                element[elementCount] = copyStr.element[i];
                ++elementCount;
                ++myLength;
            }
        }
    } else {}
}

void MyString::erase(const int start, const int count) {
    if (0 <= start && start + count <= size()) {
        MyString copyStr(element);
        int elementCount = 0;

        clear();

        for (int i = 0; i < copyStr.myLength; ++i) {
            if (start <= i && i < start + count) {
                continue;
            } else {
                element[elementCount] = copyStr.element[i];
                ++elementCount;
                ++myLength;
            }
            element[myLength] = '\0';
        }
    } else {}
}

int MyString::find(const MyString& str, int pos) {
    int result = -1;

    if (0 <= pos && pos <= size()) {
        for (int i = pos; i < myLength; ++i) {
            for (int j = 0; j < str.myLength; ++j) {
                if (element[i+j] == str.element[j]) {
                    if (j + 1 == str.myLength) {
                        result = i;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    break;
                }
            }
            if (-1 != result) {
                break;
            } else {}
        }
    } else {}

    return result;
}

int MyString::find(const char* str, int pos) {
    int result = -1;

    if (0 <= pos && pos <= size()) {
        int count = my_strlen(str);

        for (int i = pos; i < myLength; ++i) {
            for (int j = 0; j < count; ++j) {
                if (element[i+j] == str[j]) {
                    if (j + 1 == count) {
                        result = i;
                        break;
                    } else {
                        continue;
                    }
                } else {
                    break;
                }
            }
            if (-1 != result) {
                break;
            } else {}
        }
    } else {}

    return result;
}

int MyString::copy(char* str, const int len, const int pos) {
    int count = 0;

    if (0 <= pos && pos + len <= size()) {
        for (int i = 0; i < len; ++i) {
            str[i] = element[pos + i];
            ++count;
        }
    } else {}

    return count;
}

int MyString::copy(MyString& str, const int len, const int pos) {
    int count = 0;

    if (0 <= pos && pos + len <= size()) {
        for (int i = 0; i < len; ++i) {
            str.element[i] = element[pos + i];
            ++count;
        }
        str.myLength = count;
    } else {}

    return count;
}

void MyString::move(MyString& str) {
    for (int i = 0; i < str.myLength; ++i) {
        element[i] = str.element[i];
    }
    myLength = str.myLength;

    str.clear();
}

MyString MyString::operator+(const MyString& str) {
    MyString result(element);

    for (int i = 0; i < str.myLength; ++i) {
        result.element[result.myLength] = str.element[i];
        ++result.myLength;
    }

    return result;
}

MyString MyString::operator+(const char* str) {
    MyString result(element);
    const int strLength = my_strlen(str);

    for (int i = 0; i < strLength; ++i) {
        result.element[result.myLength] = str[i];
        ++result.myLength;
    }

    return result;
}

void MyString::operator=(const char* str) {
    int length = my_strlen(str);

    clear();

    for (myLength; myLength < length; ++myLength) {
        element[myLength] = str[myLength];
    }
    element[myLength] = '\0';
}

void MyString::operator=(const MyString& str) {
    clear();

    for (myLength; myLength < str.myLength; ++myLength) {
        element[myLength] = str.element[myLength];
    }
    element[myLength] = '\0';
}

bool MyString::operator==(const MyString& str) {
    bool result = true;

    if (myLength == str.myLength) {
        for (int i = 0; i < myLength; ++i) {
            if (element[i] == str.element[i]) {
                continue;
            } else {
                result = false;
            }
        }
    } else {
        result = false;
    }

    return result;
}

bool MyString::operator==(const char* str) {
    bool result = true;
    const int strLength = my_strlen(str);

    if (myLength == strLength) {
        for (int i = 0; i < myLength; ++i) {
            if (element[i] == str[i]) {
                continue;
            } else {
                result = false;
            }
        }
    } else {
        result = false;
    }

    return result;
}

void MyString::operator+=(const MyString& str) {
    for (int i = 0; i < str.myLength; ++i) {
        element[myLength] = str.element[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

void MyString::operator+=(const char* str) {
    int strLength = my_strlen(str);

    for (int i = 0; i < strLength; ++i) {
        element[myLength] = str[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

char MyString::operator[](const int i) {
    char result = '\0';

    if (false == empty()) {
        result = element[i];
    } else {}

    return result;
}

std::ostream &operator<<(std::ostream &out, const MyString &string) {
    out << string.element;

    return out;
}

std::istream &operator>>(std::istream &in, MyString &string) {
    in >> string.element;

    string.myLength = my_strlen(string.element);

    return in;
}