#include"sclass2_14_cpoint.h"

int main(){
    Point *p1=new Point(1,1);
    Point *p2=new Point(2,2);
    Point *p3=new Point(3,3);
    cout<<"�Ѵ����ĵ����ǣ�"<<Point::counter<<endl;
    delete p1;
    delete p2;
    delete p3;
    cout<<"�����ڵĵ����ǣ�"<<Point::counter<<endl;
    return 0;
}
