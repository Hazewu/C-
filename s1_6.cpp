#include<iostream>
using namespace std;

int MAX(int a,int b){
    if(b>a){
        return b;
    } else{
        return a;
    }
}

float MAX(float a,float b,float c){  //overloaded function
    if(b>a){
        a=b;
    }
    if(c>a){ 
        a=c;
    }
    return a;
}

int main(){
    int a,b;
    float d,e,f;
    cin>>a>>b;
    cin>>d>>e>>f;
    int m;
    m=MAX(a,b);
    cout<<"max_i="<<m<<endl;
    float n;
    n=MAX(d,e,f);
    cout<<"max_f="<<n<<endl;
    return 0;
}
/*
    overloaded function require:
    There must be at least one different in its parameter type, number and order 
*/
