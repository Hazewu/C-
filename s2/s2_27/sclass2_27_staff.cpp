#include"sclass2_27_staff.h"

int main(){
    Staff staff1,staff2,staff3,staff4;   //����4��staff����------------------���Ի����������ĸ�����
    cout<<"��������һ��Ա������н��";
    double s;
    cin>>s;
    staff1.SetSalary(s);
    cout<<endl<<"��������һ��Ա������н��";
    cin>>s;
    staff2.SetSalary(s);
    cout<<endl<<"��������һ��Ա������н��";
    cin>>s;
    staff3.SetSalary(s);
    cout<<endl<<"��������һ��Ա������н��";
    cin>>s;
    staff4.SetSalary(s);
    cout<<"���"<<staff1.GetNumber()<<"����н��"<<staff1.GetSalary()<<endl;
    cout<<"���"<<staff2.GetNumber()<<"����н��"<<staff2.GetSalary()<<endl;
    cout<<"���"<<staff3.GetNumber()<<"����н��"<<staff3.GetSalary()<<endl;
    cout<<"���"<<staff4.GetNumber()<<"����н��"<<staff4.GetSalary()<<endl;
    return 0;
}
