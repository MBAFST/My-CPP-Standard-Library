#include "exception.hpp"

#include <cstdlib>
#include <cstring>

Exception::Exception(const char *msg) {
    this->msg = (char *)malloc(strlen("Exception Error: ") + strlen(msg) + 1);
    strcpy(this->msg, "Exception Error: ");
    strcpy(this->msg + strlen("Exception Error: "), msg);
}

char *Exception::getMessage() const {
    return this->msg;
}

Exception::~Exception() { }
