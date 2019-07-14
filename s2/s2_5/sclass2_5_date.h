#ifndef _SCLASS2_5_DATA_H_
#define _SCLASS2_5_DATA_H_

#include<iostream>
using namespace std;

class Date{
    public:
        Date();                       //声明一个无参数的构造函数
        Date(int y,int m,int d);      //声明一个带3个参数的构造函数
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;
};

Date::Date(){
    year=2000;
    month=1;
    day=1;
}

Date::Date(int y,int m,int d){
    year=y;
    month=m;
    day=d;
}

void Date::SetDate(int y,int m,int d){
    year=y;
    month=m;
    day=d;
}

int Date::IsLeapYear(){
    return (year%4==0&&year%100!=0)||(year%400==0);
}

void Date::Print(){
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}
#endif
