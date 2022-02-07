#include "calccontroller.h"

CalcController::CalcController()
{
}

void CalcController::one(bool) {
    _calc.pushNextValue("1");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::two(bool) {
    _calc.pushNextValue("2");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::three(bool) {
    _calc.pushNextValue("3");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::four(bool) {
    _calc.pushNextValue("4");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::five(bool) {
    _calc.pushNextValue("5");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::six(bool) {
    _calc.pushNextValue("6");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::seven(bool) {
    _calc.pushNextValue("7");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::eight(bool) {
    _calc.pushNextValue("8");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::nine(bool) {
    _calc.pushNextValue("9");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::zero(bool) {
    _calc.pushNextValue("0");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::comma(bool) {
    _calc.pushNextValue(".");
    emit updateDigitsScreen(QString(_calc.getNextValue().c_str()));
}

void CalcController::plus(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("+");
    emit updateOpeScreen("+");
}

void CalcController::minus(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("-");
    emit updateOpeScreen("-");
}

void CalcController::mult(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("*");
    emit updateOpeScreen("*");
}

void CalcController::div(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("/");
    emit updateOpeScreen("/");
}

void CalcController::square(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("^2");
    emit updateOpeScreen(QString("^2"));
}

void CalcController::equal(bool) {
    try {
        double res = _calc.compute();
        emit updateDigitsScreen(QString("%1").arg(res));
    } catch (CalcException &e) {
        emit updateDigitsScreen(QString(e.getMessage().c_str()));
    }

    _calc.setOpe("");
    emit updateOpeScreen(QString());
}
