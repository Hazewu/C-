#ifndef _SCLASS3_3_CBASE_H_
#define _SCLASS3_3_CBASE_H_

#include<iostream>
using namespace std;

class CBase{                        //��������
    public:
        CBase(void){}               //���캯��
        void SetValue(int a,int b); //Ϊ���ݳ�Աm��n��ֵ
        void CalcuValue(void);      //���ڼ���Ľӿڣ�������������ʾ����Ļ��
    protected:
        int m;                      //������Ա
    private:
        int n;                      //˽�г�Ա 
};

class CDerived:public CBase{        //���������࣬���м̳�CBase
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
    cout<<"�����Ա n="<<n<<endl;
    cout<<"�����Ա m="<<m<<endl;
}

void CBase::CalcuValue(void){
    cout<<"m X n="<<m*n<<endl;
}

void CDerived::SetJ(void){
    j=2*m;                         //������Ա���Է��ʻ���ı�������m
}

void CDerived::SetK(void){
    //k=2*n;                       //�Ƿ���������Ա�����Է��ʻ����˽�г�Ա
    k=0;
}

void CDerived::DisplayVal(void){
    cout<<"�������Ա j="<<j<<endl;
    cout<<"�������Ա k="<<k<<endl;
}

#endif
