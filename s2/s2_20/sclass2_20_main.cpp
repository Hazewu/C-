#include"sclass2_20_cnode.h"
#include"sclass2_20_cstack.h"

int main(void){
    CStack stack;            //建立一个栈对象
    //入栈操作
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    //出栈操作
    for(int i=0;i<3;i++){
        cout<<stack.Pop()<<" ";
    }
    cout<<endl;
    return 0;
}

