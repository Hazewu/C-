#ifndef _SCLASS2_2_CDEMO_H_
#define _SCLASS2_2_CDEMO_H_

#include<iostream>
using namespace std;

class CDemo{                       //CDemo��Ķ���
    public:
        void SetI(int a){          //�����ⲿ�ӿ�SetI()Ϊi��ֵ
            i=a;
        }
        void SetJ(int b){          //�����ⲿ�ӿ�SetJ()Ϊj��ֵ
            j=b;
        }
        void GetI(){               //���i��ֵ
            cout<<"i="<<i<<endl;
        }
        void GetJ(){               //���j��ֵ
            cout<<"j="<<j<<endl;
        }
    protected:
        int j;
    private:
        int i;
};
#endif
