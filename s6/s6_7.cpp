//逻辑函数对象用法示例
#include<iostream>
#include<functional>
using namespace std;

int main(){
	//下面定义一些逻辑函数对象
	logical_and<int> objAnd;                   //定义逻辑与函数对象
	logical_or<int> objOr;                     //定义逻辑或函数对象
	logical_not<int> objNot;                   //定义逻辑非函数对象
	
	//下面运用上面定义的函数对象，实现相应的函数功能
	cout<<objAnd(true,true)<<endl;
	cout<<objOr(true,false)<<endl;
	cout<<objNot(true)<<endl;
	
	//下面直接以生成的临时对象实现相关函数功能
	cout<<logical_and<int>() (true,true)<<endl;
	cout<<logical_or<int>() (true,false)<<endl;
	cout<<logical_not<int>() (true)<<endl;
	
	system("PAUSE");
	return 0;
} 
