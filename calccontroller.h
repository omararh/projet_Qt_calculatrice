#ifndef CALCCONTROLLER_H
#define CALCCONTROLLER_H

#include <QObject>
#include "calcmodel.h"

class CalcController : public QObject
{
    Q_OBJECT
public:
    CalcController();

public slots:
    void one(bool);
    void two(bool);
    void three(bool);
    void four(bool);
    void five(bool);
    void six(bool);
    void seven(bool);
    void eight(bool);
    void nine(bool);
    void zero(bool);
    void comma(bool);

    void plus(bool);
    void minus(bool);
    void mult(bool);
    void div(bool);
    void square(bool);
    void equal(bool);

signals:
    void updateDigitsScreen(const QString &);
    void updateOpeScreen(const QString &);

private:
    CalcModel _calc;
};

#endif // CALCCONTROLLER_H
