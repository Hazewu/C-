#include<iostream>
using namespace std;

class CDemo{
    public:
        CDemo(int ii=0):i(ii){           //i(ii)��ָ��i=ii
            j=i;
        }
        static int Incr(){              //����һ����̬��Ա����ʵ�ֶԾ�̬���ݳ�Աj�Ĳ���
            return ++j;
        }
/*       static int Incr(CDemo p){              //����һ����̬��Ա����ʵ�ֶԾ�̬���ݳ�Աj�Ĳ���
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
