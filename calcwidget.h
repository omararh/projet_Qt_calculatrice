#ifndef CALCWIDGET_H
#define CALCWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>

#include "calccontroller.h"

class CalcWidget : public QWidget
{
    Q_OBJECT

public:
    CalcWidget(QWidget *parent = nullptr);
    ~CalcWidget();

protected:
    void keyPressEvent(QKeyEvent* event) override;

    CalcController _controller;
};

#endif // CALCWIDGET_H
