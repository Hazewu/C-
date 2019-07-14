#ifndef _SCLASS2_27_STAFF_H_
#define _SCLASS2_27_STAFF_H_

#include<iostream>
using namespace std;

class Staff{
    public:
        Staff(void);                      //构造函数声明
        ~Staff(void);                     //析构函数声明
        void SetSalary(double s);         //改变月薪
        int GetNumber(void);              //访问工作编号
        double GetSalary(void);           //访问月薪
    private:
        int number;                       //工作编号
        float salary;                     //月薪
        static int count;                 // 编号递增器
};

int Staff::count=1000;

Staff::Staff(void){
    number=++count;                       //编号递增器先自增，在赋值给工作编号
    salary=1000.0;                        //月薪被初始化为1000

}
Staff::~Staff(void){ }                    //定义空析构函数

void Staff::SetSalary(double s){
    salary=s;                             //通过参数s修改数据成员salary的值
}

int Staff::GetNumber(void){
    return number;
}

double Staff::GetSalary(void){
    return salary;
}

#endif


