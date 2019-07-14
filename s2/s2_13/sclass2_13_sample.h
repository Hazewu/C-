#ifndef _SCLASS2_13_SAMPLE_H_
#define _SCLASS2_13_SAMPLE_H_

#include<iostream>
using namespace std;

class CSample{
    public:
        CSample(void){}
        CSample(int a);                           //重载构造函数
        CSample Add(CSample s1,CSample s2);       //返回CSample
        int GetN(void);                           //获取数据n的值
    private:
        int n;
};

CSample::CSample(int a){
    n=a;
}

CSample CSample::Add(CSample s1,CSample s2){
    this->n=s1.n+s2.n;
    return (*this);                               //返回this指针指向的对象
}

int CSample::GetN(void){
    return n;
}
#endif
