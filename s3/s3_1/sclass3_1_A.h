#ifndef _SCLASS3_1_A_H_
#define _SCALSS3_1_A_H_

#include<iostream>
using namespace std;

class A{                                    //定义基类
    public:
        void SetX(int i);                   //为数据成员x赋值
        int GetX(void) const;               //获取数据成员x的值
        int z;                              //基类的公有数据成员
    protected:
        int y;                              //基类的保护数据成员
    private:
        int x;                              //基类的私有数据成员
};

class B:public A{                           //类B公有继承类A
    public:
        void SetValue(int,int,int,int,int);     //为基类和本类中的所有数据成员赋值
        void Display(void) const;           //显示各数据成员的值
    protected: 
        int m;                              //派生类的保护数据成员
    private:
        int n;                              //派生类的私有数据成员
};

void A::SetX(int i){
    x=i;
}

int A::GetX(void) const{
    return x;
}

void B::SetValue(int a,int b,int c,int d,int e){
    //x=a;                                   //基类的私有数据成员x对派生类不可见，故直接访问非法
    SetX(a);                                 //通过公有成员函数SetX()来间接访问基类的私有数据x
    y=b;                                     //将b的值赋给基类的保护成员y，访问合法
    z=c;                                     //将c的值赋给基类的公有成员z，访问合法
    m=d;
    n=e;
}

void B::Display(void) const{
    //cout<<"x="<<x<<endl;                   //x在派生类不可访问
    cout<<"x="<<GetX()<<endl;
    cout<<"y="<<y<<endl;
    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;
}
#endif
