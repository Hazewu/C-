#include<iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle(int w,int wei){      //基类构造函数，用于初始化基类数据
            wheels=w;
            weight=wei;
        }

        void Show(void) const{
            cout<<"轮胎数："<<wheels<<" 车重："<<weight<<"kg"<<endl;
        }

    private:
        int wheels;                  //轮数
        int weight;                  //车重
};

class Car:public Vehicle{            //定义派生类
    public:
        Car(int w,int wei,int p):Vehicle(w,wei){                    //派生类构造函数的初始化列表
            passenger_load=p;                                       //初始化派生类新增的数据成员
        }

        void Show(void) const{                                      
            cout<<"此轿车最多能载客："<<passenger_load<<"人"<<endl;   //访问本类私有数据成员
            Vehicle::Show();                                        //访问基类同名成员函数Show()，需使用作用限定符
        }
    private:
        int passenger_load;                                         //载客人数
};

int main(void){
    Car car(4,5000,5);            //创建一个派生类对象，创建时提供的第一、第二个参数用于调用基类构造函数wheels和weight，第三个参数用于初始化对象新增的数据成员passenger_load
    car.Show();
    return 0;
}
