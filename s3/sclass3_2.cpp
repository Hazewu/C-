#include<iostream>
using namespace std;

const double PI=3.1415;
class Circle{
    public:
        void SetRadius(double r){
            radius=r;
        }
        double GetRadius() const{
            return radius;
        }
        double GetArea() const{
            return PI*radius*radius;
        }
        void Print() const{
            cout<<"半径为"<<radius<<"的圆的面积是"<<GetArea()<<endl;
        }
    private:
        double radius;
};

class Cylinder:Circle{
    public:
        void SetHeight(double h){
            height=h;
        }
        double GetHeight(){
            return height;
        }
        void SetRadius(double r){
            Circle::SetRadius(r);         //使用作用域限定符来表明调用基类的同名函数
        }
        double GetRadius() const{         //派生类定义与基类同名的公有成员函数，便于类外访问
            return Circle::GetRadius();    
        }
        double GetArea() const{
            return (2*PI*GetRadius()*GetRadius()+2*PI*GetRadius()*height);
        }
        double GetVolume() const{
            return (PI*GetRadius()*GetRadius()*height);
        }
        void Print() const{
            cout<<"底半径为"<<GetRadius()<<"高为"<<height<<"的圆柱体的表面积是"<<GetArea()<<"体积是"<<GetVolume()<<endl;
        }
    private:
        double height;                    //新增
};

int main(){
    Cylinder cylinder;
    cylinder.SetRadius(12.5);
    cylinder.SetHeight(10.5);
    cout<<"圆柱体的表面积是"<<cylinder.GetArea()<<endl;
    cout<<"圆柱的体积是"<<cylinder.GetVolume()<<endl;
    cylinder.Print();
    return 0;
}
