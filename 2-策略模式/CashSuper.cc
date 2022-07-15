#include <CashSuper.h>

//正常收费子类
double CashNormal::acceptCash(double money) {
    return money;
}

//打折收费子类
CashRebate::CashRebate(double moneyRebate) : moneyRebate(moneyRebate) {}
double CashRebate::acceptCash(double money) {
    return money * moneyRebate;
}

//返利收费子类
CashReturn::CashReturn(double moneyCondition, double moneyReturn) : moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
double CashReturn::acceptCash(double money) {
    double result = money;
    if(money >= moneyCondition)
        result = money - (int)(money / moneyCondition) * moneyReturn;

    return result;
}