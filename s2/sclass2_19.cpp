#include<iostream>
#include<cstring>
using namespace std;

class A{
    private:
        friend class B;                     //友元类
        char *name;
        int age;
    public:
        A(char *str,int n){ 
            name=new char[strlen(str)+1];   //new，数组型用法，strlen(str)+1个char型，1是为了‘/0’输出
            strcpy(name,str);
            age=n;
        }
};

class B{
    public:
        void show(A x){
            cout<<"姓名 "<<x.name<<endl;
            cout<<"年龄 "<<x.age;
        }
};

int main(){
    A a("左力",19);
    B b;
    b.show(a);
    return 0;
}
