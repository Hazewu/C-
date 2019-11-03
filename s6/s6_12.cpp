/*
deque容器支持高效插入和删除容器的首尾部元素，也叫做双端队列
1、构造函数模板
（1）deque()：创建一个空deque
（2）deque(const deque &)：拷贝构造函数模板
2、增加函数模板
（1）void push_front(const Type &e)：双端队列首部增加一个元素e
（2）void push_back(const Type &e)：双端队列尾部增加一个元素e
3、删除函数模板
（1）void pop_front()：删除双端队列最前一个元素
（2）void pop_back()：删除双端队列最后一个元素
（3）void clear()：删除双端队列中所有元素
4、遍历函数模板
（1）Type &front()：返回首元素的引用
（2）Type &back()：返回尾元素的引用
（3）iterator begin()：返回头迭代器，指向第一个元素
（4）iterator end()：返回尾迭代器，不包括最后一个元素，在其下面
（5）reverse_iterator rbegin()：反向迭代器，返回指向最后一个元素的迭代器
（6）reverse_iterator rend()：反向迭代器，返回指向第一个元素的前一位置的迭代器
5、其他函数模板
（1）empty()const：向量是否为空，若true，则向量中无元素
（2）int size()const：返回元素的个数 
*/

//deque容器使用示例
#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<int> q;                     //定义双端队列对象
	deque<int>::iterator it;          //定义迭代器
	int a[]={5,1,8,18,16,19},n=6,i,e; //定义数组及整型变量
	
	for(i=0;i<n;i++){
	    //依次向双端队列中插入a[i]
		q.push_back(a[i]);            //向双端队列尾追加a[i] 
	} 
	
	for(it=q.begin();it!=q.end();it++){
		//依次输出各元素的值
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	q.clear();                        //清空双端队列
	for(i=0;i<n;i++){
		//依次向双端队列中插入a[i]
		q.push_front(a[i]);           //向双端队列首部插入a[i] 
	} 
	
	for(it=q.begin();it!=q.end();it++){
		//依次输出各元素的值
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	q.pop_front();                    //删除首元素
	cout<<q.front()<<endl;        //输出新首元素
	
	q.pop_back();                     //删除尾元素
	cout<<q.back()<<endl;         //输出新尾元素
	
	system("PAUSE");
	return 0; 
} 
