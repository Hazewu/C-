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
    float x;                       //Ϊ�˱���������ʣ����������������ݳ�Ա���ֱ�������ԣ��ᡢ������
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
