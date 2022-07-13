#include <iostream>
#include <sstream>
using namespace std;

double total = 0.0;
stringstream ss;

void btnOK();

int main() {
    cout << "开始程序: " << endl;
    
    while(1 == 1) {
        btnOK();
    }
}

void btnOK() {
    double txtPrice = 0.0;
    int txtNum = 0;
    cout << "输入商品单价:";
    cin >> txtPrice;
    cout << "输入商品数量:";
    cin >> txtNum;
    double totalPrices = txtPrice * txtNum;

    total += totalPrices;
    ss << "单价" << txtPrice << " 数量: " << txtNum << " 合计: " << totalPrices << endl;

    cout << "\n***********\n";
    cout << ss.str();
    cout << "\n总计: " << total << endl;
    cout << "***********\n";
}