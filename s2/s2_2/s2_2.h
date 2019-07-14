#ifndef _SCLASS2_2_CDEMO_H_
#define _SCLASS2_2_CDEMO_H_

#include<iostream>
using namespace std;

class CDemo{                       //CDemo类的定义
    public:
        void SetI(int a){          //设置外部接口SetI()为i赋值
            i=a;
        }
        void SetJ(int b){          //设置外部接口SetJ()为j赋值
            j=b;
        }
        void GetI(){               //输出i的值
            cout<<"i="<<i<<endl;
        }
        void GetJ(){               //输出j的值
            cout<<"j="<<j<<endl;
        }
    protected:
        int j;
    private:
        int i;
};
#endif
