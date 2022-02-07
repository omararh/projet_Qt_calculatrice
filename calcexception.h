#ifndef CALCEXCEPTION_H
#define CALCEXCEPTION_H

#include <exception>
#include <string>

class CalcException : public std::exception
{
public:
    CalcException();
    CalcException(std::string message);

    std::string getMessage() const;

private:
    std::string _message;
};

#endif // CALCEXCEPTION_H
