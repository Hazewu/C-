#include<iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle(int w,int wei){      //���๹�캯�������ڳ�ʼ����������
            wheels=w;
            weight=wei;
        }

        void Show(void) const{
            cout<<"��̥����"<<wheels<<" ���أ�"<<weight<<"kg"<<endl;
        }

    private:
        int wheels;                  //����
        int weight;                  //����
};

class Car:public Vehicle{            //����������
    public:
        Car(int w,int wei,int p):Vehicle(w,wei){                    //�����๹�캯���ĳ�ʼ���б�
            passenger_load=p;                                       //��ʼ�����������������ݳ�Ա
        }

        void Show(void) const{                                      
            cout<<"�˽γ�������ؿͣ�"<<passenger_load<<"��"<<endl;   //���ʱ���˽�����ݳ�Ա
            Vehicle::Show();                                        //���ʻ���ͬ����Ա����Show()����ʹ�������޶���
        }
    private:
        int passenger_load;                                         //�ؿ�����
};

int main(void){
    Car car(4,5000,5);            //����һ����������󣬴���ʱ�ṩ�ĵ�һ���ڶ����������ڵ��û��๹�캯��wheels��weight���������������ڳ�ʼ���������������ݳ�Աpassenger_load
    car.Show();
    return 0;
}
