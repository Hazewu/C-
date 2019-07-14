#include<iostream>
using namespace std;

class Point{
    private:
        int x,y;
    public:
        Point(int a,int b){
            x=a;
            y=b;
        }
        void Move(int a,int b){
            x+=a;
            y+=b;
        }
        void Print(){
            cout<<"x="<<x<<" y="<<y<<endl;
        }
};
 int main(){
    const Point point1(10,10);              //声明并初始化常量对象
                                            //常对象只能调用类的常成员函数以及类的静态成员函数 
    //point1.Move(2,2);                     //常对象point1的数据不能被更改，错
    //point1.Print();                       //Print()函数的this指针不能指向常对象
    return 0;
 }
