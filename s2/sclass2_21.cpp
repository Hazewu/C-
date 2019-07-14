#include<iostream>
using namespace std;

void Print(const int &n);         //提前声明
int main(void){
    int i=10;
    Print(i);
}

void Print(const int &n){        //const int &n 常引用
    //n++;                       //n为常引用，值不可改变 
    cout<<n<<endl;
}
