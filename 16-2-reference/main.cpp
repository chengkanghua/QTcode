#include <iostream>

using namespace std;
/*
void swap(int a, int b)   //变量参数是做的值拷贝 无法修改成功
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "函数里：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void swap(int *pa, int *pb)    // 指针参数   访问指针变量---》根据指针变量地址 --》实际地址
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}*/

//void swap(int& a, int& b)  //引用参数  直达地址
//{
////    std::swap(a,b);
//    int tmp;
//    tmp = a;
//    a = b;
//    b = tmp;
//}

void swap(int *pa, int *pb)    // 指针参数   访问指针变量---》根据指针变量地址 --》实际地址
{
    int tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "交换之前：" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap(a,b);
    cout << "交换之后："<< endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
