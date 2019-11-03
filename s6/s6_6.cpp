//关系运算类基本函数对象使用
#include<iostream>
#include<functional>
using namespace std;

int main(){
	//下面定义一些关系函数对象
	equal_to<int> objEqual;                //定义等于函数对象
	not_equal_to<int> objNotEqual;         //定义不等于函数对象
	greater<int> objGreat;                 //定义大于函数对象
	greater_equal<int> objGreatEqual;      //定义大于等于函数对象
	less<int> objLess;                     //定义小于函数对象
	less_equal<int> objLessEqual;          //定义小于等于函数对象 
	
	//下面运用上面定义的函数对象，实现相应的函数功能
	cout<<objEqual(2,6)<<endl;
	cout<<objNotEqual(2,6)<<endl;
	cout<<objGreat(2,6)<<endl;
	cout<<objGreatEqual(2,6)<<endl;
	cout<<objLess(2,6)<<endl;
	cout<<objLessEqual(2,6)<<endl;
	
	//下面直接以生成的临时函数对象实现相关函数功能
	cout<<equal_to<int>() (2,6)<<endl;
	cout<<not_equal_to<int>() (2,6)<<endl;
	cout<<greater<int>() (2,6)<<endl;
	cout<<greater_equal<int>() (2,6)<<endl;
	cout<<less<int>() (2,6)<<endl;
	cout<<less_equal<int>() (2,6)<<endl;
	
	system("PAUSE");
	return 0;
} 
