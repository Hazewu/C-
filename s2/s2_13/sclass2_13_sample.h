#ifndef _SCLASS2_13_SAMPLE_H_
#define _SCLASS2_13_SAMPLE_H_

#include<iostream>
using namespace std;

class CSample{
    public:
        CSample(void){}
        CSample(int a);                           //���ع��캯��
        CSample Add(CSample s1,CSample s2);       //����CSample
        int GetN(void);                           //��ȡ����n��ֵ
    private:
        int n;
};

CSample::CSample(int a){
    n=a;
}

CSample CSample::Add(CSample s1,CSample s2){
    this->n=s1.n+s2.n;
    return (*this);                               //����thisָ��ָ��Ķ���
}

int CSample::GetN(void){
    return n;
}
#endif
