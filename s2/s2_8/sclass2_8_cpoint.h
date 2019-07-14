#ifndef _SCALSS2_8_CPOINT_H_
#define _SCALSS2_8_CPOINT_H_

#include<iostream>
using namespace std;

class CPoint{
    public:
        CPoint(int x1,int y1);            //声明构造函数
        CPoint(CPoint &obj);              //声明拷贝构造函数
        int GetX(void);
        int GetY(void);
    private:
        int x;
        int y;
};

CPoint::CPoint(int x1,int y1){
    x=x1;
    y=y1;
}

CPoint::CPoint(CPoint &obj){
    x=obj.x;
    y=obj.y;
}

int CPoint::GetX(void){
    return x;
}

int CPoint::GetY(void){
    return y;
}
#endif
