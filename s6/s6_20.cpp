//利用sort对整型向量进行降序排序，采用第二个sort()函数模板

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

template<class It>
void Show(const It &begin,const It &end){  //泛型显示 
	for(It it=begin;it!=end;it++){
		//依次显示各元素
		cout<<*it<<" "; 
	}
	cout<<endl;
} 

int main(){
	int a[]={1,8,6,9,18};                  //定义数组
	int n=sizeof(a)/sizeof(int);           //元素个数
	vector<int> v(n);                      //定义向量对象
	
	for(int i=0;i<n;i++){
		//依次向插入向量元素赋值
		v[i]=a[i];                         //将a[i]赋值给v[i] 
	} 
	
	cout<<"排序前：";
	Show(v.begin(),v.end());
	sort(v.begin(),v.end(),greater<int>());//降序排序 
	cout<<"排序后：";
	Show(v.begin(),v.end()); 
	
	system("PAUSE");
	return 0;
}
