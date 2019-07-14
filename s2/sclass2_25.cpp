#include<iostream>
using namespace std;

class A{
    public:
        int GetValue() const{      //常成员函数
            return w*h;
        }
        int GetValue(){           //成员函数，重载函数 
            return w+h;
        } 
        A(int x,int y){
            w=x;
            h=y;
        }
        A(){};
    private:
        int w,h;
};

int main(){
    A const a(3,4);               //常对象调用常成员函数 
    A c(2,6);                     //当存在重载函数时，普通对象调用普通成员函数 
    cout<<a.GetValue()<<endl<<c.GetValue()<<"cctwlTest";  //输出和
    return 0;
}
