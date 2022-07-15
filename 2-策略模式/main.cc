#include <iostream>
#include <sstream>
#include <CashContext.h>
#include <CashSuper.h>
using namespace std;

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
    CashContext* csuper = new CashContext(type);
    
    double txtPrice = 0.0;
    int txtNum = 0;
    cout << "输入商品单价:";
    cin >> txtPrice;
    cout << "输入商品数量:";
    cin >> txtNum;

    double totalPrices = csuper->GetResult(txtPrice * txtNum); 
    total += totalPrices;
    ss << "单价" << txtPrice << " 数量: " << txtNum << " 合计: " << totalPrices << endl;

    cout << "\n***********\n";
    cout << ss.str();
    cout << "\n总计: " << total << endl;
    cout << "***********\n";
}