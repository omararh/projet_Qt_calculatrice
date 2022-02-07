#include "calcwidget.h"

CalcWidget::CalcWidget(QWidget *parent)
    : QWidget(parent), _controller()
{
    // Layouts
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QGridLayout *digitsLayout = new QGridLayout;
    QGridLayout *opeLayouts = new QGridLayout;

    // Widgets
    QLineEdit *digitsScreen = new QLineEdit(this);
    QLineEdit *opeScreen = new QLineEdit(this);

    QPushButton *digitsButtons[11];
    for(int i=0; i<10; i++) {
        digitsButtons[i] = new QPushButton(QString("%1").arg(i), this);
    }
    digitsButtons[10] = new QPushButton(QString(","), this);

    QPushButton *plusButton = new QPushButton(QString("+"), this);
    QPushButton *minusButton = new QPushButton(QString("-"), this);
    QPushButton *multButton = new QPushButton(QString("*"), this);
    QPushButton *divButton = new QPushButton(QString("/"), this);
    QPushButton *squareButton = new QPushButton(QString("^2"), this);
    QPushButton *equalButton = new QPushButton(QString("="), this);

    // Positionnements
    opeLayouts->setSpacing(0);
    opeLayouts->addWidget(plusButton, 0, 0);
    opeLayouts->addWidget(minusButton, 0, 1);
    opeLayouts->addWidget(multButton, 1, 0);
    opeLayouts->addWidget(divButton, 1, 1);
    opeLayouts->addWidget(squareButton, 2, 0);
    opeLayouts->addWidget(equalButton, 2, 1);

    digitsLayout->setSpacing(0);
    digitsLayout->addWidget(digitsButtons[7], 0, 0);
    digitsLayout->addWidget(digitsButtons[8], 0, 1);
    digitsLayout->addWidget(digitsButtons[9], 0, 2);
    digitsLayout->addWidget(digitsButtons[4], 1, 0);
    digitsLayout->addWidget(digitsButtons[5], 1, 1);
    digitsLayout->addWidget(digitsButtons[6], 1, 2);
    digitsLayout->addWidget(digitsButtons[1], 2, 0);
    digitsLayout->addWidget(digitsButtons[2], 2, 1);
    digitsLayout->addWidget(digitsButtons[3], 2, 2);
    digitsLayout->addWidget(digitsButtons[0], 3, 0, 1, 2); // 0 prend deux places
    digitsLayout->addWidget(digitsButtons[10], 3, 2); // ,

    buttonsLayout->addStretch();
    buttonsLayout->addLayout(digitsLayout);
    buttonsLayout->addStretch();
    buttonsLayout->addLayout(opeLayouts);
    buttonsLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addWidget(digitsScreen);
    mainLayout->addWidget(opeScreen, 0, Qt::AlignRight);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);
    mainLayout->addStretch();

    // Personnalisations
    digitsScreen->setReadOnly(true); // On ne peut pas éditer le texte en tapant directement
    opeScreen->setReadOnly(true); // On ne peut pas éditer le texte en tapant directement

    opeScreen->setFixedWidth(30); // L'éditeur d'opérateur est plus petit

    digitsScreen->setAlignment(Qt::AlignRight); // Alignement du texte à droite
    opeScreen->setAlignment(Qt::AlignRight); // Alignement du texte à droite

    // Connexions
    QObject::connect(digitsButtons[0], &QPushButton::clicked, &_controller, &CalcController::zero);
    QObject::connect(digitsButtons[1], &QPushButton::clicked, &_controller, &CalcController::one);
    QObject::connect(digitsButtons[2], &QPushButton::clicked, &_controller, &CalcController::two);
    QObject::connect(digitsButtons[3], &QPushButton::clicked, &_controller, &CalcController::three);
    QObject::connect(digitsButtons[4], &QPushButton::clicked, &_controller, &CalcController::four);
    QObject::connect(digitsButtons[5], &QPushButton::clicked, &_controller, &CalcController::five);
    QObject::connect(digitsButtons[6], &QPushButton::clicked, &_controller, &CalcController::six);
    QObject::connect(digitsButtons[7], &QPushButton::clicked, &_controller, &CalcController::seven);
    QObject::connect(digitsButtons[8], &QPushButton::clicked, &_controller, &CalcController::eight);
    QObject::connect(digitsButtons[9], &QPushButton::clicked, &_controller, &CalcController::nine);
    QObject::connect(digitsButtons[10], &QPushButton::clicked, &_controller, &CalcController::comma);

    QObject::connect(plusButton, &QPushButton::clicked, &_controller, &CalcController::plus);
    QObject::connect(minusButton, &QPushButton::clicked, &_controller, &CalcController::minus);
    QObject::connect(multButton, &QPushButton::clicked, &_controller, &CalcController::mult);
    QObject::connect(divButton, &QPushButton::clicked, &_controller, &CalcController::div);
    QObject::connect(squareButton, &QPushButton::clicked, &_controller, &CalcController::square);
    QObject::connect(equalButton, &QPushButton::clicked, &_controller, &CalcController::equal);

    QObject::connect(&_controller, &CalcController::updateDigitsScreen, digitsScreen, &QLineEdit::setText);
    QObject::connect(&_controller, &CalcController::updateOpeScreen, opeScreen, &QLineEdit::setText);
}

CalcWidget::~CalcWidget()
{

}

void CalcWidget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_0:
        _controller.zero(true);
        break;
    case Qt::Key_1:
        _controller.one(true);
        break;
    case Qt::Key_2:
        _controller.two(true);
        break;
    case Qt::Key_3:
        _controller.three(true);
        break;
    case Qt::Key_4:
        _controller.four(true);
        break;
    case Qt::Key_5:
        _controller.five(true);
        break;
    case Qt::Key_6:
        _controller.six(true);
        break;
    case Qt::Key_7:
        _controller.seven(true);
        break;
    case Qt::Key_8:
        _controller.eight(true);
        break;
    case Qt::Key_9:
        _controller.nine(true);
        break;
    case Qt::Key_Comma: // virgule
    case Qt::Key_Period: // ou point, même combat
        _controller.comma(true);
        break;

    case Qt::Key_Plus:
        _controller.plus(true);
        break;
    case Qt::Key_Minus:
        _controller.minus(true);
        break;
    case Qt::Key_Asterisk:
        _controller.mult(true);
        break;
    case Qt::Key_Slash:
        _controller.div(true);
        break;
    case Qt::Key_Return: // Entrée du milieu
    case Qt::Key_Enter: // Entrée du pavé numérique
        _controller.equal(true);
        break;
    }
}
