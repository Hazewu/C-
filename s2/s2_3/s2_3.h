#ifndef _SCLASS2_3_DATE_H_
#define _SCLASS2_3_DATE_H

#include<iostream>
using namespace std;

class Date{
    public:
        Date();                                //构造函数
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;                    //声明日期类的属性：年月日
};
Date::Date(){                                  //定义Date类的构造函数，将对象初始化为2000年1月1日
    year=2000;
    month=1;
    day=1;
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
