#include<iostream>
using namespace std;

class A{
    public:
        int GetValue() const{      //����Ա����
            return w*h;
        }
        int GetValue(){           //��Ա���������غ��� 
            return w+h;
        } 
        A(int x,int y){
            w=x;
            h=y;
        }
        A(){};
    private:
        int w,h;
};

int main(){
    A const a(3,4);               //��������ó���Ա���� 
    A c(2,6);                     //���������غ���ʱ����ͨ���������ͨ��Ա���� 
    cout<<a.GetValue()<<endl<<c.GetValue()<<"cctwlTest";  //�����
    return 0;
}
