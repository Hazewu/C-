#ifndef _SCLASS2_9_DATE_H_
#define _SCLASS2_9_DATE_H_

#include<iostream>
using namespace std;

class Date{
    public:
        Date();
        Date(int y,int m,int d);            
        ~Date();                           //声明析构函数，不可重载
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year;
        int month;
        int day;
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

Date::~Date(){
    cout<<"正在析构"<<year<<"年"<<month<<"月"<<day<<"日日期对象"<<endl;
}

int Date::IsLeapYear(){
    return (year%4==0&&year%100!=0)||(year%400==0);
}

void Date::Print(){
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}
#endif
