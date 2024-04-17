#include <iostream>
#include <string>

using namespace std;

class Car{

    public:
        //成员数据
        string color;
        string brand;
        string type;
        int year;
        //其实也是成员数据，指针变量，指向函数的变量，并非真正的成员函数
        void (*printCarInfo)(string color,string brand,string type, int year); //函数指针，指向车介绍函数
        void (*carRun)(string type);       //函数指针，指向车运行的函数
        void (*carStop)(string type);      //函数指针，执行车停止的函数

        void realPrintCarInfo(); //声明成员函数
};

void Car::realPrintCarInfo()  //类的外部进行成员函数的实现
{
    string str = "车的品牌是："+ brand
            + ",型号是:" + type
            + ",颜色是：" + color
            + ",上市年限是:" + std::to_string(year);
    cout << str << endl;
}

int main()
{
    Car BWMthree;
    BWMthree.color = "白色";
    BWMthree.brand = "宝马";
    BWMthree.type = "3系";
    BWMthree.year = 2023;
    BWMthree.realPrintCarInfo();

    Car *AodiA6 = new Car();
    AodiA6->color = "黑色";
    AodiA6->brand = "奥迪";
    AodiA6->type = "A6";
    AodiA6->year = 2008;
    AodiA6->realPrintCarInfo();

    return 0;
}
