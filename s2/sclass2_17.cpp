#include<iostream>
#include<math.h>
using namespace std;

class CPoint{
    public:
        CPoint(double xx=0,double yy=0){
            x=xx;
            y=yy;
        }
        double GetX(){
            return x;
        }
        double GetY(){
            return y;
        }
        friend double fDist(CPoint *p1,CPoint *p2);//ֻ��˵�Լ��Ǳ��˵����ѣ�Ȼ����˿���ֱ�ӷ����Լ���˽�г�Ա 
    private:
        double x,y;
};
/*�ú�������ͨ���������Ǹ���ĳ�Ա���� */ 
double fDist(CPoint *p1,CPoint *p2){
    double x=double(p1->x-p2->x);                  //������Ԫ��ϵ��p1��p2����ֱ�ӷ�����ָ�����˽�г�Աx��y
    double y=double(p1->y-p2->y);
    return sqrt(x*x+y*y);
};

int main(){
    CPoint *p1=new CPoint(1,1);                    
    CPoint *p2=new CPoint(4,5);
    cout<<"The distance is��"<<fDist(p1,p2)<<endl;
    delete p1;
    delete p2;
    return 0;
}
/*
class A{
    friend void B::function();   //��Ԫ������������ĳ�Ա���� 
}
*/ 
