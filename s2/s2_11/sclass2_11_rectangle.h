#ifndef _SCLASS2_11_RECTANGLE_H_
#define _SCLASS2_11_RECTANGLE_H_

#include<iostream>
using namespace std;

class Rectangle{
    public:
        Rectangle();
        Rectangle(double,double);
        ~Rectangle(){}
        void SetSize(double,double);
        double GetLength();
        double GetWidth();
        double GetArea();
        void Print();
    private:
        double length;
        double width;
};

Rectangle::Rectangle(){
    length=0;
    width=0;
}

Rectangle::Rectangle(double l,double w){
    length=l;
    width=w;
}

void Rectangle::SetSize(double l,double w){
    length=l;
    width=w;
}

double Rectangle::GetLength(){
    return length;
}

double Rectangle::GetWidth(){
    return width;
}

double Rectangle::GetArea(){
    return length*width;
}

void Rectangle::Print(){
    cout<<"长方形的长是"<<length<<"宽是"<<width<<"面积是"<<GetArea()<<endl;
}
#endif
