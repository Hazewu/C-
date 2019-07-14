#include<iostream>
using namespace std;

class CDemo{
    public:
        CDemo(int ii=0):i(ii){           //i(ii)是指：i=ii
            j=i;
        }
        static int Incr(){              //定义一个静态成员函数实现对静态数据成员j的操作
            return ++j;
        }
/*       static int Incr(CDemo p){              //定义一个静态成员函数实现对静态数据成员j的操作
            return p.i+j;
        }
*/
    private:
       int i;
       static int j;
};

int CDemo::j=0;

int main(void){
	//CDemo p(1);
	cout<<"j="<<CDemo::Incr()<<endl;
    //cout<<"j="<<CDemo::Incr(p)<<endl;
    return 0;
}
