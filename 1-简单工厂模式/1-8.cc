#include <iostream>
#include <string>
using namespace std;

class Operation {
public:
    //运算函数，static静态函数可以不实例化对象而进行函数调用
    static double GetResult(double numberA, double numberB, char operate) {
        double result = 0;
        switch (operate)
        {
        case '+':
            result = numberA + numberB;
            break;
        case '-':
            result = numberA - numberB;
            break;
        case '*':
            result = numberA * numberB;
            break;
        case '/':
            result = numberA / numberB;
            break;
        default:
            break;
        }
        return result;
    }
};

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
        strResult = to_string(Operation::GetResult(strNumberA, strNumberB, strOperator));
        cout << "结果是: " + strResult << endl;
    }
    catch(const std::exception& e) {
        std::cerr << "您的输入有错: " << e.what() << '\n';
    }
    
}