#include"sclass2_27_staff.h"

int main(){
    Staff staff1,staff2,staff3,staff4;   //创建4个staff对象------------------可以换成数组对象的更方便
    cout<<"请输入下一个员工的月薪：";
    double s;
    cin>>s;
    staff1.SetSalary(s);
    cout<<endl<<"请输入下一个员工的月薪：";
    cin>>s;
    staff2.SetSalary(s);
    cout<<endl<<"请输入下一个员工的月薪：";
    cin>>s;
    staff3.SetSalary(s);
    cout<<endl<<"请输入下一个员工的月薪：";
    cin>>s;
    staff4.SetSalary(s);
    cout<<"编号"<<staff1.GetNumber()<<"的月薪是"<<staff1.GetSalary()<<endl;
    cout<<"编号"<<staff2.GetNumber()<<"的月薪是"<<staff2.GetSalary()<<endl;
    cout<<"编号"<<staff3.GetNumber()<<"的月薪是"<<staff3.GetSalary()<<endl;
    cout<<"编号"<<staff4.GetNumber()<<"的月薪是"<<staff4.GetSalary()<<endl;
    return 0;
}
