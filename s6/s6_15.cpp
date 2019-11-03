/*
遍历容器算法for_each()
原型如下所示：
    template<class It,class Fun)
	Fun for_each(It first,It last,Fun f);
对参数说明如下：
（1）It可以是指针类型或迭代器
（2）first表示数组的起始元素指针或迭代器
（3）last表示数组尾指针或迭代器，不包括最后一个元素，而在其之后
（4）Fun指函数类或函数指针类型
（5）f为一元全局函数或医院函数对象
功能：此函数模板的含义是对[first,last)之间的每个元素，作为函数f的参数传入并执行函数 
*/

//显示向量中每个整型元素及相应的立方

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ShowCube(int n){                       //显示参数及相应的立方 
	cout<<n<<":\t"<<n*n*n<<endl;            //输出相关信息 
} 

int main(){
	int n=8;                                //元素个数 
	vector<int> v(n);                       //定义大小为n的向量
	
	for(int i=0;i<n;i++){
		//通过数组方式为向量元素赋值
		v[i]=i+1; 
	} 
	
	cout<<"i:\ti*i*i"<<endl;                //输出提示
	for_each(v.begin(),v.end(),ShowCube);   //输出v的每个元素及其相应的立方
	
	system("PAUSE");
	return 0; 
} 
