#ifndef _SCLASS3_1_A_H_
#define _SCALSS3_1_A_H_

#include<iostream>
using namespace std;

class A{                                    //�������
    public:
        void SetX(int i);                   //Ϊ���ݳ�Աx��ֵ
        int GetX(void) const;               //��ȡ���ݳ�Աx��ֵ
        int z;                              //����Ĺ������ݳ�Ա
    protected:
        int y;                              //����ı������ݳ�Ա
    private:
        int x;                              //�����˽�����ݳ�Ա
};

class B:public A{                           //��B���м̳���A
    public:
        void SetValue(int,int,int,int,int);     //Ϊ����ͱ����е��������ݳ�Ա��ֵ
        void Display(void) const;           //��ʾ�����ݳ�Ա��ֵ
    protected: 
        int m;                              //������ı������ݳ�Ա
    private:
        int n;                              //�������˽�����ݳ�Ա
};

void A::SetX(int i){
    x=i;
}

int A::GetX(void) const{
    return x;
}

void B::SetValue(int a,int b,int c,int d,int e){
    //x=a;                                   //�����˽�����ݳ�Աx�������಻�ɼ�����ֱ�ӷ��ʷǷ�
    SetX(a);                                 //ͨ�����г�Ա����SetX()����ӷ��ʻ����˽������x
    y=b;                                     //��b��ֵ��������ı�����Աy�����ʺϷ�
    z=c;                                     //��c��ֵ��������Ĺ��г�Աz�����ʺϷ�
    m=d;
    n=e;
}

void B::Display(void) const{
    //cout<<"x="<<x<<endl;                   //x�������಻�ɷ���
    cout<<"x="<<GetX()<<endl;
    cout<<"y="<<y<<endl;
    cout<<"m="<<m<<endl;
    cout<<"n="<<n<<endl;
}
#endif
