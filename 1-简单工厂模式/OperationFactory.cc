#include <OperationFactory.h>
using namespace std;

//运算类
double Operation::getNumberA() {
    return numberA;
}

void Operation::setNumberA(double value) {
    numberA = value;
}

double Operation::getNumberB() {
    return numberB;
}

void Operation::setNumberB(double value) {
    numberB = value;
}

double Operation::getResult() {
    double result = 0;
    return result;
}

//加法类
double OperationAdd::getResult() {
    double result = 0;
    result = getNumberA() + getNumberB();
    return result;
}

//减法类
double OperationSub::getResult() {
    double result = 0;
    result = getNumberA() - getNumberB();
    return result;
}

//乘法类
double OperationMul::getResult() {
    double result = 0;
    result = getNumberA() * getNumberB();
    return result;
}

//除法类
double OperationDiv::getResult() {
    double result = 0;
    if(getNumberB() == 0)
        throw "除数不能为0。";
    result = getNumberA() / getNumberB();
    return result;
}

Operation* OperationFactory::createOperate(char operate) {
    Operation* oper = nullptr;
    switch (operate)
    {
    case '+':
        oper = new OperationAdd();
        break;
    case '-':
        oper = new OperationSub();
        break;
    case '*':
        oper = new OperationMul();
        break;
    case '/':
        oper = new OperationDiv();
        break;
    default:
        break;
    }
    return oper;
}