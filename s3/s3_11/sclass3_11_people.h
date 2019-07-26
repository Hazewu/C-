#ifndef _SCLASS3_11_PEOPLE_H_
#define _SCLASS3_11_PEOPLE_H_

#include<iostream>
using namespace std;

class Date{
    public:
        Date();                    //����һ���޲����Ĺ��캯��
        Date(int y,int m,int d);   //����һ����3�������Ĺ��캯��
        void SetDate(int y,int m,int d);
        int IsLeapYear();
        void Print();
    private:
        int year,month,day;        //��������������ԣ��ꡢ�¡���
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

Date::Date(){                         //����һ���޲����Ĺ��캯��
    year=2000;
    month=1;
    day=1;
}

Date::Date(int y,int m,int d){         //����һ����3�������Ĺ��캯��
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
    cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
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
    cout<<"���Ϊ"<<number<<"����Ա����������";
    birthday.Print();                         //���ù��г�Ա����Print()�����birthday��������
}

void People::SetNum(int n){
    number=n;
}

void People::SetSex(char s){
    sex=s;
}

#endif


