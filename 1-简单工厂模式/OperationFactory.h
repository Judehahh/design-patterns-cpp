#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

//运算类
class Operation {
public:
    double getNumberA();
    void setNumberA(double value);
    double getNumberB();
    void setNumberB(double value);
    virtual double getResult();
private:
    double numberA = 0;
    double numberB = 0;
};

//加法类
class OperationAdd : public Operation {
public:
    virtual double getResult() override;
};

//减法类
class OperationSub : public Operation {
public:
    virtual double getResult() override;
};

//乘法类
class OperationMul : public Operation {
public:
    virtual double getResult() override;
};

//除法类
class OperationDiv : public Operation {
public:
    virtual double getResult() override;
};

//简单工厂类
class OperationFactory {
public:
    static Operation* createOperate(char operate);
};

#endif