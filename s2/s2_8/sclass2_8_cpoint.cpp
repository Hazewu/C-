#include"sclass2_8_cpoint.h"

int main(void){
    CPoint a(20,50);
    CPoint b(a);
    CPoint c=a;                  //ϵͳ���ÿ������캯��
    cout<<"��a�������ǣ�"<<a.GetX()<<"��"<<a.GetY()<<"��"<<endl;
    cout<<"��b�������ǣ�"<<b.GetX()<<"��"<<b.GetY()<<"��"<<endl;
    cout<<"��c�������ǣ�"<<c.GetX()<<"��"<<c.GetY()<<"��"<<endl;
    return 0;
}
