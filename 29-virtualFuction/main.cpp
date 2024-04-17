#include <iostream>
using namespace std;

//基类，父类
class Vehicle{ //交通工具，车,抽象的概念
public:
    string contry;
    double price;

    Vehicle(){};   //空构造函数
    virtual ~Vehicle(){}; //虚析构函数：如果类中有虚函数，通常应该将析构函数也声明为虚的。
    Vehicle(string contry, double price){
        cout << "基类的构造函数被调用" << endl;
        this->contry = contry;
        this->price = price;
    };

    //基类中声明了一个虚函数
    virtual void run(){
        cout << "车跑起来了" << endl;
    }
    virtual void stop()=0;  // =0的写法是纯虚函数
};

class Bike : public Vehicle{
public:
    void run() override {  //派生类重写基类的虚函数
        cout << "脚踩自行车" << endl;
    }
    void stop() override{};  //必须要把基类的虚函数也写一遍 空函数体也行，不然编译器不通过
};

int main()
{
    Bike b;
    b.run();
    return 0;
}
