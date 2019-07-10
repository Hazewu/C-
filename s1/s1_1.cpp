#include<iostream>
using namespace std;

int main(){
    int i=10;
    char c='a';
    float f=20.325;
    int *pi=&i;                     //the pointer pi points to i's address
    char *pa="Hello World!";        //the pointer pa points to the address of the character string
    cout<<i<<'\t'<<c<<'\t'<<f<<endl;//'\t' means jumping eight spaces
    cout<<pi<<'\t'<<pa<<endl;
    cout<<"这是一个字符常量！";
    return 0;
}
