#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cout << "你好世界  我是c++" << endl;
    cout << "你好世界  我是c++" << "你好我是补充输出的" << endl;
    cin >> a;
    cin >> b;
    cout << a << "," << b << endl;
    cout << a << "+" << b <<"="<< a+b << endl;
    cerr << "程序错误退出" << endl;
    return 0;
}
