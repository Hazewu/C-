/*
排序算法sort()
两种原型：
   template<class It>
   void sort(It first,It last)
   
   template<class It,class Pred>
   void sort(It first,It last,Pred pr)
对参数的说明如下：
（1）It可以是指针类型或迭代器类
（2）first表示起始指针或迭代器 
（3）last表示数组尾指针或迭代器，不包括最后一个元素，而在其之后
（4）Pred指普通全局函数二元函数或二元函数对象类类型参数
功能：第一个函数模板用于将[first,last)间迭代器或指针指示的元素数据默认升序排列
      第二个函数模板定义了比较函数pr(x,y)代替operator<(x,y)，功能是相似的 
*/ 

//利用sort对整型数组进行升序排序
#include<iostream>
#include<algorithm>
using namespace std;

template<class It>
void Show(const It &begin,const It &end){         //泛型显示 
	for(It it=begin;it!=end;it++){
		//依次显示各元素
		cout<<*it<<" "; 
	}
	cout<<endl;
} 

int main(){
	int a[]={1,8,6,9,5,18};                       //定义数组
	int n=sizeof(a)/sizeof(int);                  //元素个数
	int *begin=a;
	int *end=a+n;
	
	cout<<"排序前：";                             //输出提示
	Show(begin,end);                              //输出数组元素值
	sort(begin,end);                              //排序
	cout<<"排序后：";                             //输出提示
	Show(begin,end);                              //输出数组元素值
	
	system("PAUSE");
	return 0; 
}
