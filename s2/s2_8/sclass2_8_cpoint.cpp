#include"sclass2_8_cpoint.h"

int main(void){
    CPoint a(20,50);
    CPoint b(a);
    CPoint c=a;                  //系统调用拷贝构造函数
    cout<<"点a的坐标是（"<<a.GetX()<<"，"<<a.GetY()<<"）"<<endl;
    cout<<"点b的坐标是（"<<b.GetX()<<"，"<<b.GetY()<<"）"<<endl;
    cout<<"点c的坐标是（"<<c.GetX()<<"，"<<c.GetY()<<"）"<<endl;
    return 0;
}
