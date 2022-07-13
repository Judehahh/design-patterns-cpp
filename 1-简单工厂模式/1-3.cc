#include <iostream>
#include <string>
using namespace std;

int main() {
    try {
        double strNumberA, strNumberB;
        string strResult;
        char strOperator;
        cout << "请输入数字A: ";
        cin >> strNumberA;
        cout << "请选择运算符号(+、-、*、/): ";
        cin >> strOperator;
        cout << "请输入数字B: ";
        cin >> strNumberB;
        switch (strOperator)
        {
        case '+':
            strResult = to_string(strNumberA + strNumberB);
            break;
        case '-':
            strResult = to_string(strNumberA - strNumberB);
            break;
        case '*':
            strResult = to_string(strNumberA * strNumberB);
            break;
        case '/':
            if(strNumberB != 0)
                strResult = to_string(strNumberA / strNumberB);
            else
                strResult = "除数不能为0";
            break;
        default:
            break;
        }
        cout << "结果是: " + strResult << endl;
    }
    catch(const std::exception& e) {
        std::cerr << "您的输入有错: " << e.what() << '\n';
    }
}