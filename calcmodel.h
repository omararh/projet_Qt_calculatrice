#ifndef CALCMODEL_H
#define CALCMODEL_H

#include <string>
#include <cmath>
#include "calcexception.h"

class CalcModel
{
public:
    CalcModel();

    void setOpe(std::string ope);
    void pushNextValue(std::string digit);

    std::string getNextValue() const;
    double compute() noexcept(false);

private:
    double _value;
    std::string _ope;
    std::string _nextValue;
};

#endif // CALCMODEL_H
