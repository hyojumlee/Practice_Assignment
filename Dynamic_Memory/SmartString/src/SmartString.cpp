#include "SmartString.hpp"

#include <memory>

int my_strlen(const char *str) {
    int cnt = 0;

    while (*str != '\0') {
        cnt++;
        str++;
    }
    return cnt;
}

void SmartString::setString(const char* str) {
    myLength = my_strlen(str);

    for (int i = 0; i != myLength; ++i) {
        element[i] = str[i];
    }    
}

char* SmartString::getString() {
    return &element[0];
}

int SmartString::getLength() {
    return myLength;
}

SmartString::SmartString() {
    std::unique_ptr<char[]> newElement (new char[1]);

    newElement[0] = '\0';
    element = std::move(newElement);
}

SmartString::SmartString(const char c) {
    std::unique_ptr<char[]> newElement (new char[1]);

    newElement[0] = c;
    ++myLength;
    newElement[myLength] = '\0';

    element = std::move(newElement);
}

SmartString::SmartString(const char* str) {
    int count = my_strlen(str);

    clear(count);

    for (int i = 0; i < count; ++i) {
        element[i] = str[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

SmartString::SmartString(const SmartString& str) {
    int count = str.myLength;

    clear(count);

    for (int i = 0; i < count; ++i) {
        element[i] = str.element[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

SmartString::~SmartString() {

}

const char* SmartString::begin() {
    return &element[0];
}

const char* SmartString::end() {
    return &element[myLength];
}

const char SmartString::front() {
    return element[0];
}

const char SmartString::back() {
    return element[myLength];
}

const void SmartString::print() {
    std::cout << getString() << "\t" << getLength();
}

const void SmartString::println() {
    std::cout << getString() << std::endl;
    std::cout << getLength() << std::endl;
}

int SmartString::size() {
    return myLength;
}

int SmartString::length() {
    return myLength;
}

bool SmartString::empty() {
    bool result = true;

    if (0 != myLength) {
        result = false;
    } else {}

    return result;
}

void SmartString::insert(const int pos, const char* str) {
    if (0 <= pos && pos <= myLength) {
        int strLength = my_strlen(str);
        int count = 0;
        int posCount = pos;
        int size = myLength + strLength;

        SmartString copyStr(getString());

        clear(size);

        for (int i = 0 ; i < pos ; ++i) {
            element[i] = copyStr.element[i];
            ++count;
        }
        for (int i = 0 ; i != strLength ; ++i) {
            element[count] = str[i];
            ++count;
        }
        for (int i = count ; i != size ; ++i) {
            element[i] = copyStr.element[posCount];
            ++count;
            ++posCount;
        }
        myLength = count;
    } else {}
}

void SmartString::clear() {
    std::unique_ptr<char[]> newElement (new char[1]);
    newElement[0] = '\0';
    myLength = 0;

    element = std::move(newElement);
}

void SmartString::clear(const int length) {
    std::unique_ptr<char[]> newElement (new char[length]);
    myLength = 0;

    element = std::move(newElement);
}

void SmartString::reverse() {
    int count = myLength - 1;
    std::unique_ptr<char[]> newElement(new char[count]);


    for (int i = 0; i <= count; ++i) {
        newElement[i] = element[count - i];
    }

    element.reset();
    element = std::move(newElement);
}

char SmartString::at(const int pos) {
    return element[pos];
}

void SmartString::resize(const int length) {
    std::unique_ptr<char[]> newElement (new char[length]);
    int count = myLength;
    
    for (int i = 0; i < count; ++i) {
        newElement[i] = element[i];
    }

    element = std::move(newElement);
}

void SmartString::replace(const char* findStr, const char* replaceStr) {
    SmartString copyStr(getString());
    int insertStrCnt = 0;
    int copyCount = 0;
    int findLength = my_strlen(findStr);
    int replaceLength = my_strlen(replaceStr);
    int stringGap = replaceLength - findLength;
    int size = myLength + (count(findStr) * stringGap);

    clear(size);

    for (int i = 0; i < size; ++i) {
        int pos = -1;

        pos = copyStr.find(findStr, i);
        pos += insertStrCnt * stringGap;

        if (i == pos) {
            for (int j = 0; j < replaceLength; ++j) {
                element[j+i] = replaceStr[j];
                ++myLength;
            }
            copyCount += findLength;
            i += replaceLength - 1;
            ++insertStrCnt;
        } else {
            element[i] = copyStr.element[copyCount];
            ++copyCount;
            ++myLength;
        }
    }
    element[myLength] ='\0';

    return;
}

SmartString SmartString::replace(const int pos, const int len, SmartString& str) {
    SmartString copyStr(str.getString());
    int length = myLength;

    if (0 <= pos && pos <= size()) {

        erase(pos, len);
        insert(pos, copyStr.getString());

        copyStr.clear(myLength);

        for (int i = 0; i < length; ++i) {
            copyStr.element[i] = element[i];
        }
        copyStr.myLength = myLength;
        copyStr.element[myLength] = '\0';
    } else {}

    return copyStr;
}

SmartString SmartString::replace(const int pos, const int len, const char* str) {
    SmartString copyStr;

    if (0 <= pos && pos <= size()) {
        erase(pos, len);
        insert(pos, str);

        copyStr.clear(myLength);

        for (int i = 0; i < myLength; ++i) {
            copyStr.element[i] = element[i];
        }
        copyStr.myLength = myLength;
        copyStr.element[myLength] = '\0';
    } else {}

    return copyStr;
}

SmartString SmartString::substr(const int pos, const int len) {
    SmartString result;
    int count = 0;

    if (0 <= pos && pos + len <= size()) {
        for (int i = 0; i < len; ++i) {
            result.element[i] = element[pos + i];
            ++result.myLength;
        }
        result.element[len] = '\0';
    } else {}

    return result;
}

void SmartString::assign(const char *str) {
    int length = my_strlen(str);

    clear(length);

    for (int i = 0; i < length; ++i) {
        element[i] = str[i];
    }
    myLength = length;
    element[myLength] = '\0';
}

void SmartString::assign(const SmartString& str) {
    int length = str.myLength;

    clear(length);

    for (int i = 0; i < length; ++i) {
        element[i] = str.element[i];
    }
    myLength = length;
    element[myLength] = '\0';
}

void SmartString::assign(const int count, const char &ch) {
    clear(count);

    for (int i = 0; i < count; ++i) {
        element[i] = ch;
        ++myLength;
    }
    element[myLength] = '\0';
}

void SmartString::assign(const SmartString &origin, const int start, const int count) {
    clear(count);

    if (0 <= start && start + count <= origin.myLength) {
        for (int i = 0; i < count; ++i) {
            element[i] = origin.element[start + i];
            ++myLength;
        }
        element[myLength] = '\0';
    } else {}
}

void SmartString::append(const char *str) {
    int length = my_strlen(str);
    int size = length + myLength;

    resize(size);

    for (int i = 0; i < length; ++i) {
        element[myLength] = str[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

void SmartString::append(const SmartString& str) {
    int length = str.myLength;
    int size = length + myLength;

    resize(size);

    for (int i = 0; i < length; ++i) {
        element[i] = str.element[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

void SmartString::append(const int count, const char &ch) {
    if (0 <= count && count <= size()) {
        int size = myLength + count;

        resize(size);

        for (int i = 0; i < count ; ++i) {
            element[myLength] = ch;
            ++myLength;
        }
        element[myLength] = '\0';
    } else {}
}

void SmartString::append(const SmartString &origin, const int start, const int count) {
    if (0 <= start && start + count <= origin.myLength) {
        int size = count + myLength;

        resize(size);

        for (int i = 0; i < count; ++i) {
            element[myLength] = origin.element[start + i];
            ++myLength;
        }
    } else {}
}

int SmartString::compare(const SmartString &str) {
    int count = myLength >= str.myLength ? str.myLength + 1 : myLength + 1;
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

int SmartString::compare(const char *str) {
    int length = my_strlen(str);
    int count = myLength >= length ? myLength + 1: length + 1;
    int result = 0;

    for (int i = 0; i < count; ++i) {
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

void SmartString::erase(const int pos) {
    if (0 <= pos && pos <= size()) {
        for (int i = pos; i < myLength; ++i) {
            element[i] = element[i + 1];
        }
        --myLength;
        element[myLength] = '\0';
    } else {}
}
void SmartString::erase(const int start, const int count) {
    if (0 <= start && start + count <= size()) {
        for (int i = 0; i < count; ++i) {
            for (int j = start; j < myLength; ++j) {
                element[j] = element[j + 1];
            }
        }
        myLength -= count;
        element[myLength] = '\0';
    } else {}
}

int SmartString::count(const SmartString &str) {
    int result = 0;

    for (int i = 0; i < myLength; ++i) {
        for (int j = 0; j < str.myLength; ++j) {
            if (element[i+j] == str.element[j]) {
                if (j + 1 == str.myLength) {
                    ++result;
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }

    return result;
}

int SmartString::count(const char* str) {
    int result = 0;
    int length = my_strlen(str);

    for (int i = 0; i < myLength; ++i) {
        for (int j = 0; j < length; ++j) {
            if (element[i+j] == str[j]) {
                if (j + 1 == length) {
                    ++result;
                } else {
                    continue;
                }
            } else {
                break;
            }
        }
    }

    return result;
}

int SmartString::find(const SmartString &str, const int pos) {
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
            }
        }
    } else {}
    return result;
}

int SmartString::find(const char *str, const int pos) {
    int result = -1;
    int count = my_strlen(str);

    if (0 <= pos && pos <= size()) {
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
            if (-1!= result) {
                break;
            }
        }
    } else {}

    return result;
}

int SmartString::copy(char *str, const int len, const int pos) {
    int count = 0;

    if (0 <= pos && pos + len <= size()) {
        for (int i = 0; i < len; ++i) {
            str[i] = element[pos+i];
            ++count;
        }
    } else {}

    return count;
}
int SmartString::copy(SmartString &str, const int len, const int pos) {
    int count = 0;

    if (0 <= pos && pos + len <= size()) {    
        str.clear(len);

        for (int i = 0; i < len; ++i) {
            str.element[i] = element[pos + i];
            ++count;
        }
        str.myLength = count;
    } else {}
    return count;
}

void SmartString::move(SmartString &str) {
    element = std::move(str.element);
    myLength = str.myLength;
    str.clear();
}

SmartString SmartString::operator+(const SmartString& str) {
    SmartString result(getString());

    for (int i = 0; i < str.myLength; ++i) {
        result.element[result.myLength] = str.element[i];
        ++result.myLength;
    }
    
    return result;
}

SmartString SmartString::operator+(const char* str) {
    SmartString result(getString());
    const int strLength = my_strlen(str);

    for (int i = 0; i < strLength; ++i) {
        result.element[result.myLength] = str[i];
        ++result.myLength;
    }

    return result;
}

void SmartString::operator=(const char* str) {
    int length = my_strlen(str);

    clear();
    
    for (myLength; myLength < length; ++myLength) {
        element[myLength] = str[myLength];
    }
    element[myLength] = '\0';
}

void SmartString::operator=(const SmartString& str) {
    clear();
    
    for (myLength; myLength < str.myLength; ++myLength) {
        element[myLength] = str.element[myLength];
    }
    element[myLength] = '\0';
}

bool SmartString::operator==(const SmartString& str) {
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

bool SmartString::operator==(const char* str) {
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

void SmartString::operator+=(const SmartString& str) {
    for (int i = 0; i < str.myLength; ++i) {
        element[myLength] = str.element[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

void SmartString::operator+=(const char* str) {
    int strLength = my_strlen(str);

    for (int i = 0; i < strLength; ++i) {
        element[myLength] = str[i];
        ++myLength;
    }
    element[myLength] = '\0';
}

char SmartString::operator[](const int i) {
    char result = '\0';

    if (false == empty()) {
        result = element[i];
    }

    return result;
}

std::ostream &operator<<(std::ostream &out, SmartString &string) {
    out << string.getString();

    return out;
}
