#ifndef _SCLASS2_27_STAFF_H_
#define _SCLASS2_27_STAFF_H_

#include<iostream>
using namespace std;

class Staff{
    public:
        Staff(void);                      //���캯������
        ~Staff(void);                     //������������
        void SetSalary(double s);         //�ı���н
        int GetNumber(void);              //���ʹ������
        double GetSalary(void);           //������н
    private:
        int number;                       //�������
        float salary;                     //��н
        static int count;                 // ��ŵ�����
};

int Staff::count=1000;

Staff::Staff(void){
    number=++count;                       //��ŵ��������������ڸ�ֵ���������
    salary=1000.0;                        //��н����ʼ��Ϊ1000

}
Staff::~Staff(void){ }                    //�������������

void Staff::SetSalary(double s){
    salary=s;                             //ͨ������s�޸����ݳ�Աsalary��ֵ
}

int Staff::GetNumber(void){
    return number;
}

double Staff::GetSalary(void){
    return salary;
}

#endif


