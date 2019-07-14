#include"sclass2_10_cpoint.h"

int main(void){
    CPoint *p=new CPoint[5];          //声明一个对象数组，为其分配堆内存
    for(int i=0;i<5;i++){
        p[i].Move(i,i);
    }
    for(int i=0;i<5;i++){
        cout<<p[i].x<<","<<p[i].y<<endl;
    }
    delete []p;
    return 0;
}
