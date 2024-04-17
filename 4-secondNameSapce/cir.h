#ifndef CIR_H
#define CIR_H

namespace cir {
    double PI = 3.141592653;
    //获取圆形周长的函数
    double getLenthOfCircle(double radius){
        return PI*radius*2;
    }
    //获取圆形面积的函数
    double getAreaOfCircle(double radius ){
        return PI*radius*radius;
    }
}


#endif // CIR_H
