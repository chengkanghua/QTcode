#include <iostream>

using namespace std;

class Base {
public:
     int data;
     Base(int data){
         this->data = data;
     }
     void printInfo()
     {
         cout << data << endl;
     }
};
// 虚继承 解决了 菱形继承的问题
class Derived1 : virtual public Base {
    // 继承自 Base
public:

    Derived1(int data) : Base(data){

    }
};
// 虚继承 解决了 菱形继承的问题
class Derived2 : virtual public Base {
    // 继承自 Base
public:

    Derived2(int data) : Base(data){

    }
};

// 菱形继承 Derived1 和 Derived2 都继承了Base
class FinalDerived : public Derived1, public Derived2 {
    // 继承自 Derived1 和 Derived2
public:
    FinalDerived(int data) : Base(data),Derived1(data),Derived2(data){

    }
};

int main()
{
    FinalDerived final(10);
    final.printInfo();
    return 0;
}
