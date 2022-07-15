#ifndef CASHCONTEXT_H
#define CASHCONTEXT_H
#include <CashSuper.h>

class CashContext {
public:
    CashContext(char type);
    ~CashContext();
    double GetResult(double money);

private:
    CashSuper* cs = nullptr;
};

#endif