#include<iostream>
using namespace std;

class A{
    public:
        A(void){
            cout<<"������A�Ĺ��캯��"<<endl;
        }
        ~A(void){
            cout<<"������A����������"<<endl;
        }
};

class B:public A{          //����������B��Ϊ��ָ�����༰�̳з�ʽ
    public:
        B(void){
            cout<<"������B�Ĺ��캯��"<<endl;
        }
        ~B(void){
            cout<<"������B����������"<<endl;
        }
};

int main(void){
    B b;                 //ͨ�����������b�Ĵ������۲�����������๹�캯��������˳��
                         //ͨ������b���������۲�ϵͳ���û���������������������˳��
    return 0;
}
