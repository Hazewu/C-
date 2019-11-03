/*
查询算法find()
原型如下：
   template<class It,class Type>
   It find(It first,It last,const Type &e)
对参数说明如下：
（1）It可以是指针类型或迭代器
（2）first表示数组的起始元素或迭代器
（3）last表示数组尾指针或迭代器，不包括最后一个元素，而在其之后
（4）Type为模板类型参数
功能：查询[first,last)间对应的元素值是否有等于e的，若有则返回其指针或迭代器；若无，则返回last 
*/

//查询算法使用示例
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int a[]={1,4,2,8,5,6};                  //定义数组
	int n=sizeof(a)/sizeof(int);            //数组元素个数
	int *begin=a;                           //开始 
	int *end=a+n;                           //结束
	int e=8;                                //元素值 
	
	int *p=find(begin,end,e);               //指向首次元素值为e的数组的指针
	cout<<"元素值为"<<e<<"的元素的下标为"<<p-a<<endl;
	                                        //输出相关信息
	system("PAUSE");
	return 0; 
} 
