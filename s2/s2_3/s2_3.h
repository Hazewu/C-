#ifndef _SCLASS2_3_DATE_H_
#define _SCLASS2_3_DATE_H

#include<iostream>
using namespace std;

class Date{
    public:
        Date();                                //���캯��
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;                    //��������������ԣ�������
};
Date::Date(){                                  //����Date��Ĺ��캯�����������ʼ��Ϊ2000��1��1��
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
    cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
}

#endif
