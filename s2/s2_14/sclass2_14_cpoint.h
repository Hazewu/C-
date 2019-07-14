#ifndef _SCLASS2_14_CPOINT_H_
#define _SCLASS2_14_CPOINT_H_

#include<iostream>
using namespace std;

class Point{
    public:
        Point(){
            x=0;
            y=0;
            counter++;           //������������ù��캯��ʱ����������ֵ����һ��
        }
        ~Point(){
            counter--;          //���������������������ʱ����������ֵ�ݼ�һ��
        }
        Point(float x,float y){ //���ع��캯��
            this->x=x;
            this->y=y;
            counter++;
        }
        void move(float x,float y){
            this->x=x;
            this->y=y;
        }
        float getX(){
            return x;
        }
        float getY(){
            return y;
        }
    private:
        float x,y;
    public:
        static int counter;     //������
};

int Point::counter=0;
#endif

/*
static int getCounter(){           //��̬��Ա���� 
    return counter;                 
} 

���ʾ�̬��Ա����
Point::getCounter(); 
*/
