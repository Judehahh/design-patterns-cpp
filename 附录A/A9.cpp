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
        return "\n我的名字叫" + name + ", " + result + "\n";
    }

protected:
    string name = "";
    int shoutNum = 3;
    virtual string getShoutSound() {
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

//"牛叫"按钮
void button3() {
    Cattle cattle = Cattle("小牛");
    cattle.setShoutNum(5);
    cout << cattle.Shout() << endl;
}

//"羊叫"按钮
void button4() {
    Sheep sheep = Sheep("小羊");
    sheep.setShoutNum(5);
    cout << sheep.Shout() << endl;
}

vector<Animal*> arrayAnimal;

//"动物报名"按钮
void button5() {
    arrayAnimal = vector<Animal*>(5);
    arrayAnimal[0] = new Cat("小花");
    arrayAnimal[1] = new Dog("阿毛");
    arrayAnimal[2] = new Cattle("小黑");
    arrayAnimal[3] = new Sheep("娇娇");
    arrayAnimal[4] = new Cat("咪咪");
    cout << "\n报名成功\n" << endl;
}

//"叫声比赛"按钮
void button6() {
    for(Animal* item : arrayAnimal) {
        cout << item->Shout() << endl;
    }
}

int main() {
    while(1 == 1) {
        cout << "1. 猫叫    2. 狗叫    3. 牛叫    4. 羊叫" << endl;
        cout << "5. 动物报名    6. 叫声比赛" << endl;
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
        case 6:
            button6();
            break;
        default:
            cout << "\n请输入正确的选项\n" << endl;
            break;
        }
    }
}