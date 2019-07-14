#ifndef _SCLASS2_14_CPOINT_H_
#define _SCLASS2_14_CPOINT_H_

#include<iostream>
using namespace std;

class Point{
    public:
        Point(){
            x=0;
            y=0;
            counter++;           //当创建对象调用构造函数时，计数器的值递增一个
        }
        ~Point(){
            counter--;          //当析构对象调用析构函数时，计数器的值递减一个
        }
        Point(float x,float y){ //重载构造函数
            this->x=x;
            this->y=y;
            counter++;
        }
        void move(float x,float y){
            this->x=x;
            this->y=y;
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
    private:
        float x,y;
    public:
        static int counter;     //计数器
};

int Point::counter=0;
#endif

/*
static int getCounter(){           //静态成员函数 
    return counter;                 
} 

访问静态成员函数
Point::getCounter(); 
*/
