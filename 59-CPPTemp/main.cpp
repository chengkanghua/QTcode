#include <iostream>

using namespace std;

class PrintInt{
private:
    int data;
public:
    void printInt();
    void setInt(int data);
};

void PrintInt::printInt(){
    cout << data;
}
void PrintInt::setInt(int data){
    this->data = data;
}

// 类模板
template<typename T>
class PrintEverything{
private:
    T data;
public:
    void printEverything(){
        cout << data;
    }
    void setEverything(T data){
        this->data = data;
    }
};

int main()
{
    PrintInt p1;
    p1.setInt(10);
    p1.printInt();

    // 类模板实例化的时候指定类型 string
    PrintEverything<string> p2;
    p2.setEverything("hhh");
    p2.printEverything();

    PrintEverything<int> p3;
    p3.setEverything(12);
    p3.printEverything();

    return 0;
}
