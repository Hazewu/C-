#include<iostream>
#include<cstring>
using namespace std;

class A{
    private:
        friend class B;                     //��Ԫ��
        char *name;
        int age;
    public:
        A(char *str,int n){ 
            name=new char[strlen(str)+1];   //new���������÷���strlen(str)+1��char�ͣ�1��Ϊ�ˡ�/0�����
            strcpy(name,str);
            age=n;
        }
};

class B{
    public:
        void show(A x){
            cout<<"���� "<<x.name<<endl;
            cout<<"���� "<<x.age;
        }
};

int main(){
    A a("����",19);
    B b;
    b.show(a);
    return 0;
}
