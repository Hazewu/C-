#include"sclass3_1_A.h"

int main(void){
    B objb;
    objb.SetValue(1,2,3,4,5);
    objb.Display();
    cout<<"z="<<objb.z<<endl;               //公有权限，可通过对象访问
    return 0;
}
