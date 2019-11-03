//sort()、reverse()成员函数模板使用示例
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> la;                  //定义链表对象
	list<int>::iterator it;        //定义迭代器
	int a[]={1,6,3,5,3,2},n=6;     //定义数组及整型变量
	
	for(int i=0;i<n;i++){
		//依次向线性表中插入a[i] 
		la.push_back(a[i]);        //向链表表尾追加a[i] 
	} 
	
	for(it=la.begin();it!=la.end();it++){
		//依次输出各元素的值 
		cout<<*it<<" ";        
	}
	cout<<endl;
	
	la.reverse();                  //反转链表元素顺序
	for(it=la.begin();it!=la.end();it++){
		//依次输出各元素的值
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	la.sort();                     //升序排序链表
	for(it=la.begin();it!=la.end();it++){
		//依次输出各元素的值
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
