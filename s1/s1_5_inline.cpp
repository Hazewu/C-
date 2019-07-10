#include<iostream>
using namespace std;

inline int Add(int x,int y){     //inline is the symbol of inline function
    return x+y;
}

int main(){
    for(int i=0;i<10;i++){
        cout<<Add(i,i)<<" ";
    }
    return 0;
}
