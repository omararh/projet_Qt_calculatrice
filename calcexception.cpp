#include "calcexception.h"

CalcException::CalcException()
    :_message()
{
}

CalcException::CalcException(std::string message)
    :_message(message)
{
}

std::string CalcException::getMessage() const {
    return _message;
}
