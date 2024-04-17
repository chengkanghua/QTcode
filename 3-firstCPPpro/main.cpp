#include <iostream>

using namespace std;

int main()
{

    int a[10];
//    int data;
    for(int data=0;data<10;data++){
        a[data] = data+100;
    }

    cout << "inited array" <<endl;
    for(int data=0; data<10;data++){
        cout << a[data] <<endl;
    }
    cout << "Hello World! c++" << endl;
    return 0;
}
