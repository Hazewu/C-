#include<iostream>
using namespace std;

class Date{
    public:
        void SetDate(int y,int m,int d){                    //日期类的行为：设置当前日期的年月日
            year=y;
            month=m;
            day=d;
        }
        int IsLeapYear(){                                   //日期类行为：判断当前日期是否属于闰年
            return (year%4==0&&year%100!=0)||(year%400==0);
        }
        void Print(){                                       //日期类行为：输出当前日期的年月日
            cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;;
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
    cout<<"此年是闰年吗："<<d1.IsLeapYear()<<endl;
    return 0;
}
