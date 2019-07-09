#include<iostream>
using namespace std;

void fun(){
    printf("The first line\n");
    int i=10;                    //declare varables anywhere, anytime
    printf("i=%d",i);
}

int main(){
    fun();
    return 0;
}
