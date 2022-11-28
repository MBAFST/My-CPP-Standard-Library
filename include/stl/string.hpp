#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <cstring>
#include <ostream>

class String {
private:
    char *str;
public:
    static String reverse(const char *str);
    static String toString(int a);
    String() = default;
    String(const int a);
    String(const char *str);
    String(const String& str);
    const char *c_str() const;
    uint32_t length() const;
    String& operator=(const char *str);
    String operator+(const char *str);
    String operator+(const int a);
    String operator+(const String& str);
    String& operator+=(const char *str);
    String& operator+=(const String& str);
    bool operator==(const char *str);
    bool operator==(const String& str);
    char& operator[](size_t index);
    ~String();

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

#endif
