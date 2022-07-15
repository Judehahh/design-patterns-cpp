//策略模式
#include <iostream>
using namespace std;

//Strategy类，定义所有支持的算法的公共接口
class Strategy {
public:
    virtual void AlgorithmInterface() = 0;
};

//具体算法A
class ConcreteStrategyA : public Strategy {
public:
    virtual void AlgorithmInterface() {
        cout << "算法A实现" << endl;
    }
};

//具体算法B
class ConcreteStrategyB : public Strategy {
public:
    virtual void AlgorithmInterface() {
        cout << "算法B实现" << endl;
    }
};

//具体算法C
class ConcreteStrategyC : public Strategy {
public:
    virtual void AlgorithmInterface() {
        cout << "算法C实现" << endl;
    }
};

//上下文
class Context {
public:
    Context(Strategy* strategy) : strategy(strategy) {}

    //上下文接口
    void ContextInterface() {
        strategy->AlgorithmInterface();
    }
    ~Context() {
        delete strategy;
    }

private:
    Strategy* strategy;
};

int main() {
    Context* context;
    
    context = new Context(new ConcreteStrategyA);
    context->ContextInterface();
    delete(context);

    context = new Context(new ConcreteStrategyB);
    context->ContextInterface();
    delete(context);

    context = new Context(new ConcreteStrategyC);
    context->ContextInterface();
    delete(context);
}