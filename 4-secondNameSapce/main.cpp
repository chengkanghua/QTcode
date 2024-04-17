#include <iostream>
#include "cir.h"
#include <stdio.h>
using namespace std;
using namespace cir;
int main()
{
    double myRadius = 5;
    // 这是c语言的写法
//    printf("length:%lf,are:%lf\n",cir::getLenthOfCircle(myRadius),
//           cir::getAreaOfCircle(myRadius));

    printf("length:%lf,are:%lf\n",getLenthOfCircle(myRadius),
           getAreaOfCircle(myRadius));
    cout << "Hello World!" << endl;
    return 0;
}
