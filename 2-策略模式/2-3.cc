//简单工厂模式
#include <iostream>
#include <sstream>
using namespace std;

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
    CashRebate(double moneyRebate) : moneyRebate(moneyRebate) {}
    virtual double acceptCash(double money) override;

private:
    double moneyRebate = 1.0;
};

//返利收费子类
class CashReturn : public CashSuper {
public:
    CashReturn(double moneyCondition, double moneyReturn) : moneyCondition(moneyCondition), moneyReturn(moneyReturn) {}
    virtual double acceptCash(double money) override;

private:
    double moneyCondition = 0.0;
    double moneyReturn = 0.0;
};

//现金收费工厂类
class CashFactory {
public:
    static CashSuper* createCashAccept(char type);
};

//程序主体
double total = 0.0;
stringstream ss;
void btnOK(char);

int main() {
    cout << "开始程序: " << endl;

    char type;
    cout << "请输入选项: " << endl;
    cout << "A. 正常收费    B. 满300返100    C. 打8折" << endl;
    cin >> type;

    while(1 == 1) {
        btnOK(type);
    }
}

//正常收费子类
double CashNormal::acceptCash(double money) {
    return money;
}

//打折收费子类
double CashRebate::acceptCash(double money) {
    return money * moneyRebate;
}

//返利收费子类
double CashReturn::acceptCash(double money) {
    double result = money;
    if(money >= moneyCondition)
        result = money - (int)(money / moneyCondition) * moneyReturn;

    return result;
}

//现金收费工厂类
CashSuper* CashFactory::createCashAccept(char type) {
    CashSuper* cs = nullptr;
    switch(type) {
        case 'A':
        case 'a':
            cs = new CashNormal();
            break;
        case 'B':
        case 'b':
            cs = new CashReturn(300, 100);;
            break;
        case 'C':
        case 'c':
            cs = new CashRebate(0.8);
            break;
    }
    return cs;
}

void btnOK(char type) {
    CashSuper* csuper = CashFactory::createCashAccept(type);
    
    double txtPrice = 0.0;
    int txtNum = 0;
    cout << "输入商品单价:";
    cin >> txtPrice;
    cout << "输入商品数量:";
    cin >> txtNum;

    double totalPrices = csuper->acceptCash(txtPrice * txtNum);
    total += totalPrices;
    ss << "单价" << txtPrice << " 数量: " << txtNum << " 合计: " << totalPrices << endl;

    cout << "\n***********\n";
    cout << ss.str();
    cout << "\n总计: " << total << endl;
    cout << "***********\n";
}