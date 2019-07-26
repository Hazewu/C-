#ifndef _SCLASS3_11_PEOPLE_H_
#define _SCLASS3_11_PEOPLE_H_

#include<iostream>
using namespace std;

class Date{
    public:
        Date();                    //声明一个无参数的构造函数
        Date(int y,int m,int d);   //声明一个带3个参数的构造函数
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;        //声明日期类的属性：年、月、日
};

class People{
    public:
        People(int num,char s,int n,int m,int d);
        ~People();
        void SetNum(int n);
        void SetSex(char s);
        int GetNum() const;
        char GetSex() const;
        void Print();
    private:
        int number;
        char sex;
        Date birthday;
};

Date::Date(){                         //定义一个无参数的构造函数
    year=2000;
    month=1;
    day=1;
}

Date::Date(int y,int m,int d){         //定义一个带3个参数的构造函数
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

People::People(int num,char s,int n,int m,int d):birthday(n,m,d){
    number=num;
    sex=s;
}

People::~People(){};

int People::GetNum() const{
    return number;
}

char People::GetSex() const{
    return sex;
}

void People::Print(){
    cout<<"编号为"<<number<<"的人员出生日期是";
    birthday.Print();                         //调用公有成员函数Print()，输出birthday的年月日
}

void People::SetNum(int n){
    number=n;
}

void People::SetSex(char s){
    sex=s;
}

#endif


