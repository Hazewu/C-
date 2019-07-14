#ifndef _SCLASS2_4_SQUARE_H_
#define _SCLASS2_4_SQUARE_H_

#include<iostream>
using namespace std;

class Square{
    public:
        Square(double s);                     //����Date��Ĵ��ι��캯��
        double GetSide();
        double GetCircumference();            //�����ܳ�
        double GetArea();                     //�������
        void Print();
    private:
        double side;                          //����������������ԣ��߳�
};

Square::Square(double s){
    side=s;
}

double Square::GetSide(){
    return side;
}

double Square::GetCircumference(){
    return 4*side;
}

double Square::GetArea(){
    return side*side;
}

void Square::Print(){
    cout<<"�߳�Ϊ"<<side<<"�������ε��ܳ��ǣ�"<<4*side<<"������ǣ�"<<side*side<<endl;
}

#endif
