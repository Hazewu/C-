#ifndef _SCLASS3_3_CBASE_H_
#define _SCLASS3_3_CBASE_H_

#include<iostream>
using namespace std;

class CBase{                        //声明基类
    public:
        CBase(void){}               //构造函数
        void SetValue(int a,int b); //为数据成员m和n赋值
        void CalcuValue(void);      //用于计算的接口，并将计算结果显示在屏幕上
    protected:
        int m;                      //保护成员
    private:
        int n;                      //私有成员 
};

class CDerived:public CBase{        //声明派生类，公有继承CBase
    public:
        CDerived(void){}              
        void SetJ(void);
        void SetK(void);
        void DisplayVal(void);
    private:
        int j;
        int k;
};

void CBase::SetValue(int a,int b){
    n=a;
    m=b;
    cout<<"基类成员 n="<<n<<endl;
    cout<<"基类成员 m="<<m<<endl;
}

void CBase::CalcuValue(void){
    cout<<"m X n="<<m*n<<endl;
}

void CDerived::SetJ(void){
    j=2*m;                         //派生成员可以访问基类的保护数据m
}

void CDerived::SetK(void){
    //k=2*n;                       //非法！派生成员不可以访问基类的私有成员
    k=0;
}

void CDerived::DisplayVal(void){
    cout<<"派生类成员 j="<<j<<endl;
    cout<<"派生类成员 k="<<k<<endl;
}

#endif
