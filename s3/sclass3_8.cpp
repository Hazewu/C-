#include<iostream>
using namespace std;

class B1{               //基类B1，构造函数有参数
    public:
        B1(int i){
            this->i=i;
            cout<<"constructing B1, i="<<this->i<<endl;
        }
    private:
        int i;
};

class B2{              //基类B2，构造函数有参数
    public:
        B2(int j){
            this->j=j;
            cout<<"constructing B2, j="<<this->j<<endl;
        }
    private:
        int j;
};

class B3{             //基类B3，构造函数无参数
    public:
        B3(){
            cout<<"constructing B3*"<<endl;
        }
};

class C:public B1,public B2,public B3{
    public:
        C(int a,int b,int c):B1(a),B2(b){
            k=c;
            cout<<"constructing C, k="<<k<<endl;
        }
    private:
        int k;
};

int main(){
    C obj(1,2,3);
    return 0;
}
