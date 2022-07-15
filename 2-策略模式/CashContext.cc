#include <CashSuper.h>
#include <CashContext.h>
#include <iostream>

CashContext::CashContext(char type) {
    switch (type)
    {
    case 'A':
    case 'a':
        cs = new CashNormal();
        break;
    case 'B':
    case 'b':
        cs = new CashReturn(300, 100);
        break;
    case 'C':
    case 'c':
        cs = new CashRebate(0.8);
        break;
    default:
        std::cout << "输入错误" << std::endl;
        break;
    }
}

CashContext::~CashContext() {
    delete cs;
}

double CashContext::GetResult(double money) {
    return cs->acceptCash(money);
}