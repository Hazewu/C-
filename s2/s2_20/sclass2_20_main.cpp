#include"sclass2_20_cnode.h"
#include"sclass2_20_cstack.h"

int main(void){
    CStack stack;            //����һ��ջ����
    //��ջ����
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    //��ջ����
    for(int i=0;i<3;i++){
        cout<<stack.Pop()<<" ";
    }
    cout<<endl;
    return 0;
}

