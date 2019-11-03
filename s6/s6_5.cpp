//算术类基本函数对象使用 
#include<iostream> 
#include<functional>
using namespace std;

int main(){
	//下面定义一些算术函数对象
	plus<int> objPlus;               //定义加法算术对象
	minus<int> objMinus;             //定义减法算术对象
	multiplies<int> objMul;          //定义乘法算术对象
	divides<int> objDiv;             //定义除法算术对象
	modulus<int> objMod;             //定义求余算术对象
	negate<int> objNeg;              //定义取反算术对象
	
	//下面运用上面定义的函数对象，实现相应的函数功能
	cout<<objPlus(2,6)<<endl;
	cout<<objMinus(2,6)<<endl;
	cout<<objMul(2,6)<<endl;
	cout<<objDiv(2,6)<<endl;
	cout<<objMod(2,6)<<endl;
	cout<<objNeg(2)<<endl;
	
	//下面直接以生成的临时函数对象实现相关函数功能
	cout<<plus<int>() (2,6)<<endl;
	cout<<minus<int>() (2,6)<<endl;
	cout<<multiplies<int>() (2,6)<<endl;
	cout<<divides<int>() (2,6)<<endl;
	cout<<modulus<int>() (2,6)<<endl;
	cout<<negate<int>() (2)<<endl;
	
	system("PAUSE");
	return 0; 
}
