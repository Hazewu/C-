#ifndef _SCLASS2_6_DATE_H_
#define _SCLASS2_6_DATE_H_

#include<iostream>
using namespace std;

class Date{
    public:
        Date(int y=2000,int m=1,int d=1);
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;
};

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
    cout<<year<<"Äê"<<month<<"ÔÂ"<<day<<"ÈÕ";
}
#endif
