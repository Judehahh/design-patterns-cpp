#include <iostream>
#include <vector>
using namespace std;

//哺乳动物动物父类
class Animal {
public :
    Animal() {
        this->name = "无名";
    }
    Animal(string name) {
        this->name = name;
    }
    int getShoutNum() const {
        return shoutNum;
    }
    void setShoutNum(int value) {
        shoutNum = value;
    }
    string getName() {
        return name;
    }
    virtual string Shout() {
        string result = "";
        for(int i = 0; i < shoutNum; i++) {
            result += getShoutSound() + "～";
        }
        return "我的名字叫" + name + ", " + result;
    }

protected:
    string name = "";
    int shoutNum = 3;
    virtual string getShoutSound() {
        return "";
    }
};

//"变东西"接口
class IChange {
public:
    virtual string ChangeThing(string thing) {
        return "";
    }
};

//猫类
class Cat : public Animal {
public :
    Cat() : Animal() {}
    Cat(string name) : Animal(name) {}

protected:
    string getShoutSound() override {
        return "喵";
    }
};

//狗类
class Dog : public Animal {
public :
    Dog() : Animal() {}
    Dog(string name) : Animal(name) {}

protected:
    string getShoutSound() override {
        return "汪";
    }
};

//牛类
class Cattle : public Animal {
public :
    Cattle() : Animal() {}
    Cattle(string name) : Animal(name) {}

protected:
    string getShoutSound() override {
        return "哞";
    }
};

//羊类
class Sheep : public Animal {
public :
    Sheep() : Animal() {}
    Sheep(string name) : Animal(name) {}

protected:
    string getShoutSound() override {
        return "咩";
    }
};

//猴类
class Monkey : public Animal {
public :
    Monkey() : Animal() {}
    Monkey(string name) : Animal(name) {}

protected:
    string getShoutSound() override {
        return "吱";
    }
};

//"机器猫"类
class MachineCat : public Cat, public IChange {
public:
    MachineCat() : Cat() {}
    MachineCat(string name) : Cat(name) {}
    string ChangeThing(string thing) override {
        return Shout() + " 我有万能的口袋, 我可变出: " + thing;
    }
};

//"孙悟空"类
class StoneMonkey : public Monkey, public IChange {
public:
    StoneMonkey() : Monkey() {}
    StoneMonkey(string name) : Monkey(name) {}
    string ChangeThing(string thing) override {
        return Shout() + " 我会七十二变, 可变出: " + thing;
    }
};

//"猫叫"按钮
void button1() {
    Cat cat = Cat("小咪");
    cat.setShoutNum(5);
    cout << cat.Shout() << endl;
}

//"狗叫"按钮
void button2() {
    Dog dog = Dog("旺财");
    dog.setShoutNum(5);
    cout << dog.Shout() << endl;
}

vector<Animal*> arrayAnimal;

//"动物报名"按钮
void button3() {
    arrayAnimal = vector<Animal*>(5);
    arrayAnimal[0] = new Cat("小花");
    arrayAnimal[1] = new Dog("阿毛");
    arrayAnimal[2] = new Cattle("小黑");
    arrayAnimal[3] = new Sheep("娇娇");
    arrayAnimal[4] = new Cat("咪咪");
    cout << "报名成功" << endl;
}

//"叫声比赛"按钮
void button4() {
    for(Animal* item : arrayAnimal) {
        cout << item->Shout() << endl;
    }
}

//"变出东西"按钮
void button5() {
    MachineCat mcat = MachineCat("叮当");
    StoneMonkey wukong = StoneMonkey("孙悟空");

    vector<IChange*> array = vector<IChange*>(2);
    array[0] = &mcat;
    array[1] = &wukong;

    cout << array[0]->ChangeThing("各种各样的东西! ") << endl;
    cout << array[1]->ChangeThing("各种各样的东西! ") << endl;
}

int main() {
    while(1 == 1) {
        cout << "1. 猫叫    2. 狗叫    3. 动物报名    4. 叫声比赛    5. 变出东西" << endl;
        cout << "请输入选项：";
        int i = 0;
        cin >> i;
        switch(i) {
        case 1:
            button1();
            break;
        case 2:
            button2();
            break;
        case 3:
            button3();
            break;
        case 4:
            button4();
            break;
        case 5:
            button5();
            break;
        // case 6:
        //     button6();
        //     break;
        default:
            cout << "\n请输入正确的选项\n" << endl;
            break;
        }
    }
}