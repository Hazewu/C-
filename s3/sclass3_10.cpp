#include<iostream>
using namespace std;

class Base1 {                               //定义基类Base1
    public:
        Base1(void){                        //构造函数
            cout<<"class Base1"<<endl;
        }
};

class Base2{
    public:
        Base2(void){                        //构造函数
            cout<<"class Base2"<<endl;
        }
};

class Level1:virtual public Base2,virtual public Base1{    //定义派生类Level1，指定Base1，Base2为虚基类
    public:
        Level1(void){
            cout<<"class Level1"<<endl;
        }
};

class Level2:virtual public Base1,virtual public Base2{    //定义派生类Level2，指定Base1，Base2为虚基类
    public:
        Level2(void){
            cout<<"class Level2"<<endl;
        }
};

class Leaf:public Level1,virtual public Level2{            //定义派生类，指定Level2为虚基类
    public:
       Leaf(void){
           cout<<"class Leaf"<<endl;
       }
};

int main(void){
    Leaf obj;              //创建一个派生类Leaf的对象，展示各基类构造函数的调用顺序
                           //虚基类Base2和Base1的构造函数只调用一次
    return 0;
}
