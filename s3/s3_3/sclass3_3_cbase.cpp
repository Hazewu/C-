#include"sclass3_3_cbase.h"

int main(){
    CDerived d;                   //创建派生类对象d
    d.SetValue(10,20);            //d调用基类的公有成员函数SetValue()，为基类的数据成员m和n赋初值
    d.CalcuValue();               //d调用基类的公有成员函数CalcuValue()，将计算结果显示在屏幕上
    d.SetJ();                     //d调用本类的公有成员函数SetJ()，为同类的数据成员j赋初值
    d.SetK();                     //d调用本类的公有成员函数SetK()，为同类的数据成员k赋初值
    d.DisplayVal();               //d调用本类的公有成员函数DisplayVal()，将数据成员j和k显示在屏幕上
    return 0;
}
