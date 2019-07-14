#include<iostream>
using namespace std;

class Date{
    public:
        void SetDate(int y,int m,int d){                    //���������Ϊ�����õ�ǰ���ڵ�������
            year=y;
            month=m;
            day=d;
        }
        int IsLeapYear(){                                   //��������Ϊ���жϵ�ǰ�����Ƿ���������
            return (year%4==0&&year%100!=0)||(year%400==0);
        }
        void Print(){                                       //��������Ϊ�������ǰ���ڵ�������
            cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;;
        }
    private:
        int year;
        int month;
        int day;
};

int main(){
    Date d1;
    d1.SetDate(2019,7,9);
    d1.Print();
    cout<<"������������"<<d1.IsLeapYear()<<endl;
    return 0;
}
