//简单工厂模式
#include <iostream>
#include <sstream>
#include <CashSuper.h>
using namespace std;

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