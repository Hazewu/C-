#ifndef _SCLASS2_4_SQUARE_H_
#define _SCLASS2_4_SQUARE_H_

#include<iostream>
using namespace std;

class Square{
    public:
        Square(double s);                     //声明Date类的带参构造函数
        double GetSide();
        double GetCircumference();            //计算周长
        double GetArea();                     //计算面积
        void Print();
    private:
        double side;                          //声明正方形类的属性：边长
};

Square::Square(double s){
    side=s;
}

double Square::GetSide(){
    return side;
}

double Square::GetCircumference(){
    return 4*side;
}

double Square::GetArea(){
    return side*side;
}

void Square::Print(){
    cout<<"边长为"<<side<<"的正方形的周长是："<<4*side<<"，面积是："<<side*side<<endl;
}

#endif
