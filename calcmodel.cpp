#include "calcmodel.h"

CalcModel::CalcModel()
    :_value(0.0), _ope(), _nextValue()
{
}

void CalcModel::setOpe(std::string ope) {
    _ope=ope;
}

void CalcModel::pushNextValue(std::string digit) {
    _nextValue += digit;
}

std::string CalcModel::getNextValue() const {
    return _nextValue;
}

double CalcModel::compute() {
    double value = 0.0;

    if(!_nextValue.empty()) {
        try {
            std::setlocale(LC_ALL, "C"); // Pour s'assurer que le séparateur de décimale soit le point
            value = std::stod(_nextValue);
        } catch(std::exception &) {
            std::string nextValue =_nextValue;
            _value=0;
            _ope="";
            _nextValue="";
            throw CalcException("conversion impossible : " + nextValue);
        }
        if(_ope.empty()) {
            _value = value;
        }
    } else {
        if(_ope == "^2") {
            _value = std::pow(_value, 2.0);

            // On remet à zéro
            _nextValue="";
            _ope="";
        }
        return _value;
    }

    if(_ope == "+") {
        _value += value;
    } else if(_ope == "-") {
        _value -= value;
    } else if(_ope == "*") {
        _value *= value;
    } else if(_ope == "/") {
        if(value == 0.0) {
            throw CalcException("/ par 0");
        }
        _value /= value;
    } else if(_ope == "^2") {
        // On ignore la valeur tapée par l'utilisateur
        _value = std::pow(_value, 2.0);
    }

    // On remet à zéro
    _nextValue = "";
    _ope = "";

    return _value;
}
