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
        friend double fDist(CPoint *p1,CPoint *p2);//只能说自己是别人的朋友，然后别人可以直接访问自己的私有成员 
    private:
        double x,y;
};
/*该函数是普通函数，不是该类的成员函数 */ 
double fDist(CPoint *p1,CPoint *p2){
    double x=double(p1->x-p2->x);                  //由于友元关系，p1、p2可以直接访问所指对象的私有成员x和y
    double y=double(p1->y-p2->y);
    return sqrt(x*x+y*y);
};

int main(){
    CPoint *p1=new CPoint(1,1);                    
    CPoint *p2=new CPoint(4,5);
    cout<<"The distance is："<<fDist(p1,p2)<<endl;
    delete p1;
    delete p2;
    return 0;
}
/*
class A{
    friend void B::function();   //友元函数是其他类的成员函数 
}
*/ 
