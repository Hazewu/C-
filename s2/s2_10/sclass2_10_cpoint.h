#ifndef _SCLASS2_10_CPOINT_H_
#define _SCLASS2_10_VPOINT_H_

#include<iostream>
using namespace std;

class CPoint{
public:
    CPoint(){}
    ~CPoint(){}
    CPoint(float x1,float y1);
    void Move(float x1,float y1);
    float x;                       //为了便于类外访问，以下声明公有数据成员，分别代表属性：横、纵坐标
    float y;
};

CPoint::CPoint(float x1,float y1){
    x=x1;
    y=y1;
}

void CPoint::Move(float x1,float y1){
    x=x1;
    y=y1;
}
#endif
