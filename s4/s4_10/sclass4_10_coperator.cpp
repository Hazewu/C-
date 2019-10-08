//主文件
#include"sclass4_10_coperator.h"

//主程序
int main(){
	COperator oCO1,oCO2(10);
	oCO1=++oCO2;            //此处为重载的前缀++，因为 oCO2是COperator的对象
	                        //oCO1()调用重载()，因为oCO1是COperator的对象
	cout<<"前缀++："<<oCO1()<<"="<<oCO2.m_v<<endl; 
	oCO1=oCO2++;            //此处为重载后缀++，因为oCO2是COperator的对象
	cout<<"后缀++："<<oCO1.m_v<<"<"<<oCO2.m_v<<endl;
	oCO1=10;                //调用重载运算符=，将10赋值给对象
	cout<<"赋值=："<<oCO1.m_v<<endl;
	oCO2=oCO2+oCO1;
	cout<<"对象+对象："<<oCO1.m_v<<";"<<oCO2.m_v<<endl;
	cout<<"对象>对象："<<(oCO2>oCO1)<<endl;
	cout<<"对象<=对象："<<(oCO2<=oCO1)<<endl;
	
	return 0; 
} 
