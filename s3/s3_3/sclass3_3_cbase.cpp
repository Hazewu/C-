#include"sclass3_3_cbase.h"

int main(){
    CDerived d;                   //�������������d
    d.SetValue(10,20);            //d���û���Ĺ��г�Ա����SetValue()��Ϊ��������ݳ�Աm��n����ֵ
    d.CalcuValue();               //d���û���Ĺ��г�Ա����CalcuValue()������������ʾ����Ļ��
    d.SetJ();                     //d���ñ���Ĺ��г�Ա����SetJ()��Ϊͬ������ݳ�Աj����ֵ
    d.SetK();                     //d���ñ���Ĺ��г�Ա����SetK()��Ϊͬ������ݳ�Աk����ֵ
    d.DisplayVal();               //d���ñ���Ĺ��г�Ա����DisplayVal()�������ݳ�Աj��k��ʾ����Ļ��
    return 0;
}
