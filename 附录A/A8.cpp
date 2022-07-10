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
        return "";
    }

protected:
    string name = "";
    int shoutNum = 3;
};

//猫类
class Cat : public Animal {
public :
    Cat() : Animal() {}
    Cat(string name) : Animal(name) {}
    string Shout() override {
        string result = "";
        for(int i = 0; i < shoutNum; i++) {
            result += "喵～";
        }
        return "\n我的名字叫" + name + ", " + result + "\n";
    }
};

//狗类
class Dog : public Animal {
public :
    Dog() : Animal() {}
    Dog(string name) : Animal(name) {}
    string Shout() override {
        string result = "";
        for(int i = 0; i < shoutNum; i++) {
            result += "汪～";
        }
        return "\n我的名字叫" + name + ", " + result + "\n";
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
    arrayAnimal[2] = new Dog("小黑");
    arrayAnimal[3] = new Cat("娇娇");
    arrayAnimal[4] = new Cat("咪咪");
    cout << "\n报名成功\n" << endl;
}

//"叫声比赛"按钮
void button4() {
    for(Animal* item : arrayAnimal) {
        cout << item->Shout() << endl;
    }
}

int main() {
    while(1 == 1) {
        cout << "1. 猫叫    2. 狗叫    3. 动物报名    4. 叫声比赛" << endl;
        cout << "请输入选项：";
        int i = 0;
        cin >> i;
        switch (i) {
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
        default:
            cout << "\n请输入正确的选项\n" << endl;
            break;
        }
    }
}