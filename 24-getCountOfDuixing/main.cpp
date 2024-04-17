#include <iostream>

using namespace std;

class Myclass{

private:
    static int staticNumofInstance;

public:
    Myclass(){
        staticNumofInstance++;
    }

    ~Myclass(){
        staticNumofInstance--;
    }

    static int getNunofInstance(){
        return staticNumofInstance;
    }
};

int Myclass::staticNumofInstance = 0;

int main()
{
    Myclass m1;
    cout << Myclass::getNunofInstance() << endl; //1
    Myclass m2;
    cout << m2.getNunofInstance() << endl; //2

    {
        Myclass m3;
        cout << Myclass::getNunofInstance() << endl; //3
        Myclass m4;
        cout << Myclass::getNunofInstance() << endl; //4
    }  // 此作用域结束会运行析构函数 两次 -2
    cout << Myclass::getNunofInstance() << endl;  //2
    Myclass *m5 = new Myclass;
    cout << Myclass::getNunofInstance() << endl;  //3
    delete m5;    // -1
    cout << Myclass::getNunofInstance() << endl;  //2
    return 0;
}
