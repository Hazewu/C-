#include<iostream>
using namespace std;

class Base1 {                               //�������Base1
    public:
        Base1(void){                        //���캯��
            cout<<"class Base1"<<endl;
        }
};

class Base2{
    public:
        Base2(void){                        //���캯��
            cout<<"class Base2"<<endl;
        }
};

class Level1:virtual public Base2,virtual public Base1{    //����������Level1��ָ��Base1��Base2Ϊ�����
    public:
        Level1(void){
            cout<<"class Level1"<<endl;
        }
};

class Level2:virtual public Base1,virtual public Base2{    //����������Level2��ָ��Base1��Base2Ϊ�����
    public:
        Level2(void){
            cout<<"class Level2"<<endl;
        }
};

class Leaf:public Level1,virtual public Level2{            //���������ָ࣬��Level2Ϊ�����
    public:
       Leaf(void){
           cout<<"class Leaf"<<endl;
       }
};

int main(void){
    Leaf obj;              //����һ��������Leaf�Ķ���չʾ�����๹�캯���ĵ���˳��
                           //�����Base2��Base1�Ĺ��캯��ֻ����һ��
    return 0;
}
