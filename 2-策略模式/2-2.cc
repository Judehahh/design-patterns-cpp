#include <iostream>
#include <sstream>
using namespace std;

double total = 0.0;
stringstream ss;

double btnDiscount();
void btnOK(double);

int main() {
    cout << "开始程序: " << endl;
    
    double discount = btnDiscount();

    while(1 == 1) {
        btnOK(discount);
    }
}

double btnDiscount() {
    double discount = 1.0;
    char opt = 'A';
    cout << "请选择折扣: " << endl;
    cout << "A. 正常收费    B. 打八折    C. 打七折    D. 打五折" << endl;
    cin >> opt;
    switch (opt)
    {
    case 'B':
    case 'b':
        discount = 0.8;
        break;
    case 'C':
    case 'c':
        discount = 0.7;
        break;
    case 'D':
    case 'd':
        discount = 0.5;
        break;
    default:
        break;
    }
    return discount;
}

void btnOK(double discount) {
    double txtPrice = 0.0;
    int txtNum = 0;
    cout << "输入商品单价:";
    cin >> txtPrice;
    cout << "输入商品数量:";
    cin >> txtNum;
    double totalPrices = txtPrice * txtNum * discount;

    total += totalPrices;
    ss << "单价" << txtPrice << " 数量: " << txtNum << " 合计: " << totalPrices << endl;

    cout << "\n***********\n";
    cout << ss.str();
    cout << "\n总计: " << total << endl;
    cout << "***********\n";
}