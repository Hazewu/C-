#include"sclass2_6_date.h"

int main(void){
    Date date1;
    Date date2(2019,7,1);
    date1.Print();
    cout<<"�Ƿ������ꣿ"<<date1.IsLeapYear()<<endl;
    date2.Print();
    cout<<"�Ƿ������ꣿ"<<date2.IsLeapYear()<<endl;
    return 0;
}
