#include<iostream>
using namespace std;

int i=10;

void fun(){
    int i=20;
    cout<<"�ֲ����� i="<<i;            //visit local variable
    cout<<"��ȫ�ֱ��� i="<<::i;        //visit globle variable
}

int main(){
    fun();
    return 0;
}
/*
    '::' is Scope Resolution Operator 
    which uses to explain which class a member belongs to
*/
