#include"sclass4_8_caddition.h"

//主测试程序 
int main(){
	CAddition oCA;                    //创建一个CAddition类的对象
	oCA.Add(250,250);                 //调用Add(int a,int b)
	oCA.Add("很多250加起来","====0"); //调用Add(string s1,string s2)
	oCA.Add(128.118,128.218);         //调用Add(double d1,double d2)
	
	return 0; 
}
