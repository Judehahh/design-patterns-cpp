#include <iostream>
#include <OperationFactory.h>
using namespace std;

int main() {
    try {
        Operation* oper;
        oper = OperationFactory::createOperate('/');
        oper->setNumberA(1);
        oper->setNumberB(0);
        double result = oper->getResult();
        cout << "结果是: " << result << endl;
    }
    catch(const char* e) {
        cerr << "您的输入有错: " << e << '\n';
    }
}