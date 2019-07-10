#include<iostream>
using namespace std;

int i=10;

void fun(){
    int i=20;
    cout<<"局部变量 i="<<i;            //visit local variable
    cout<<"，全局变量 i="<<::i;        //visit globle variable
}

int main(){
    fun();
    return 0;
}
/*
    '::' is Scope Resolution Operator 
    which uses to explain which class a member belongs to
*/
