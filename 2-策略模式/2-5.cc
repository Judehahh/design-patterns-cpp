//策略模式实现
#include <iostream>
#include <sstream>
#include <CashSuper.h>
using namespace std;

//上下文类
class CashContext {
public:
    CashContext(CashSuper* csuper);
    ~CashContext();
    double GetResult(double money);
private:
    CashSuper* cs;
};

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

void btnOK(char type) {
    CashContext* cc = nullptr;
    switch (type)
    {
    case 'A':
    case 'a':
        cc = new CashContext(new CashNormal);
        break;
    case 'B':
    case 'b':
        cc = new CashContext(new CashReturn(300, 100));
        break;
    case 'C':
    case 'c':
        cc = new CashContext(new CashRebate(0.8));
        break;
    default:
        cout << "输入有误" << endl;
        break;
    }
    
    double txtPrice = 0.0;
    int txtNum = 0;
    cout << "输入商品单价:";
    cin >> txtPrice;
    cout << "输入商品数量:";
    cin >> txtNum;

    double totalPrices = cc->GetResult(txtPrice * txtNum);
    delete cc;    
    total += totalPrices;
    ss << "单价" << txtPrice << " 数量: " << txtNum << " 合计: " << totalPrices << endl;

    cout << "\n***********\n";
    cout << ss.str();
    cout << "\n总计: " << total << endl;
    cout << "***********\n";
}


//上下文类
CashContext::CashContext(CashSuper* csuper) : cs(csuper) {}
CashContext::~CashContext() {
    delete cs;
}
double CashContext::GetResult(double money) {
    return cs->acceptCash(money);
}