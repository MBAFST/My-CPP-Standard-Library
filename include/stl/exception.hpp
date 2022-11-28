#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

class Exception {
private:
    char *msg;
public:
    Exception() = delete;
    Exception(const char *msg);
    char *getMessage() const;
    ~Exception();
};

#endif
