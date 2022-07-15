#ifndef CASHSUPER_H
#define CASHSUPER_H

//现金收费抽象类
class CashSuper {
public:
    virtual double acceptCash(double money) = 0;
};

//正常收费子类
class CashNormal : public CashSuper {
public:
    virtual double acceptCash(double money) override;
};

//打折收费子类
class CashRebate : public CashSuper {
public:
    CashRebate(double moneyRebate);
    virtual double acceptCash(double money) override;

private:
    double moneyRebate = 1.0;
};

//返利收费子类
class CashReturn : public CashSuper {
public:
    CashReturn(double moneyCondition, double moneyReturn);
    virtual double acceptCash(double money) override;

private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
};

#endif