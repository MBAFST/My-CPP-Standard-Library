#include "stl/exception.hpp"
#include "stl/string.hpp"

#include <cstdlib>
#include <cstring>
#include <cstdio>

String String::reverse(const char *str) {
    char *tmp = (char *)malloc(strlen(str) + 1);
    for (uint32_t i = 0; i < strlen(str); i++) {
        *(tmp + i) = *(str + (strlen(str) - 1) - i);
    }
    return String(tmp);
}

String String::toString(int a) {
    char *str = NULL;
    uint32_t counter = 0;
    while (a > 0) {
        str = (char *)realloc(str, counter + 1);
        str[counter++] = '0' + a % 10;
        a /= 10;
    }
    return String::reverse(str);
}

String::String(const int a) {
    String tmp = String::toString(a);
    this->str = (char *)malloc(tmp.length() + 1);
    strcpy(this->str, tmp.str);
}

String::String(const char *str) {
    this->str = (char *)malloc(strlen(str) + 1);
    strcpy(this->str, str);
}


String::String(const String& str) {
    this->str = (char *)malloc(strlen(str.str) + 1);
    strcpy(this->str, str.str);
}

uint32_t String::length() const {
    return strlen(this->str);
}

const char *String::c_str() const {
    return this->str;
}

String& String::operator=(const char *str) {
    free(this->str);
    this->str = (char *)malloc(strlen(str) + 1);
    strcpy(this->str, str);
    return *this;
}

String String::operator+(const char* str) {
    char *tmp = (char *)malloc(strlen(this->str) + strlen(str) + 1);
    strcpy(tmp, this->str);
    strcpy(tmp + strlen(this->str), str);
    return String(tmp);
}

String String::operator+(const int a) {
    String str = String::toString(a);
    char *tmp = (char *)malloc(strlen(this->str) + str.length() + 1);
    strcpy(tmp, this->str);
    strcpy(tmp + strlen(this->str), str.c_str());
    return String(tmp);
}

String String::operator+(const String& str) {
    char *tmp = (char *)malloc(strlen(this->str) + str.length() + 1);
    strcpy(tmp, this->str);
    strcpy(tmp + strlen(this->str), str.c_str());
    return String(tmp);
}

String& String::operator+=(const char *str) {
    this->str = (char *)realloc(this->str, strlen(this->str) + strlen(str) + 1);
    strcpy(this->str + strlen(this->str), str);
    return *this;
}

String& String::operator+=(const String& str) {
    this->str = (char *)realloc(this->str, strlen(this->str) + strlen(str.c_str()) + 1);
    strcpy(this->str + strlen(this->str), str.c_str());
    return *this;
}

bool String::operator==(const char *str) {
    return !strcmp(this->str, str);
}

bool String::operator==(const String& str) {
    return !strcmp(this->str, str.str);
}

char& String::operator[](int index) {
    if (index < 0 || index >= strlen(str))
        throw Exception("Array out of bound!");
    return *(str + index);
}

String::~String() {
    free(str);
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.str;
    return os;
}
