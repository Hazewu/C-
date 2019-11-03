//遍历线性表示例
#include<iostream>
#include<list>
using namespace std;

int main(){
	list<int> la;                  //定义链表对象
	
	for(int i=1;i<=6;i++){
		//依次向线性表中插入值
		la.push_back(i);           //向链表表尾追加i 
	} 
	
	//正向显示链表
	for(list<int>::iterator it=la.begin();it!=la.end();it++){
		//依次输出各元素的值
		cout<<*it<<" "; 
	} 
	cout<<endl;
	
	//逆向显示链表
	for(list<int>::reverse_iterator rit=la.rbegin();rit!=la.rend();rit++){
		//依次输出各元素的值
		cout<<*rit<<" "; 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
