#include<iostream>
using namespace std;

class Point{
    private:
        int x,y;
    public:
        Point(int a,int b){
            x=a;
            y=b;
        }
        void Move(int a,int b){
            x+=a;
            y+=b;
        }
        void Print(){
            cout<<"x="<<x<<" y="<<y<<endl;
        }
};
 int main(){
    const Point point1(10,10);              //��������ʼ����������
                                            //������ֻ�ܵ�����ĳ���Ա�����Լ���ľ�̬��Ա���� 
    //point1.Move(2,2);                     //������point1�����ݲ��ܱ����ģ���
    //point1.Print();                       //Print()������thisָ�벻��ָ�򳣶���
    return 0;
 }
