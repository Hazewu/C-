/*
vector向量类 
1、构造函数模板
（1）vector()：创建一个空vector
（2）vector(int n)：创建一个vector，其元素个数为n
（3）vector(int nSize,const Type &e)：创建一个vector，元素个数为nSize，且各元素的值均为e
（4）vector(const vector &)：拷贝构造函数模板
2、增加函数模板
（1）void push_back(const Type &e)：向量尾部增加一个元素e
（2）iterator insert(iterator it,const Type &e)：向量中某一个元素前增加一个元素e
（3）void insert(iterator it,int n,const Type &e)：向量中某一元素前增加n个相同的元素e
3、删除函数模板
（1）iterator erase(iterator it)：删除向量中某一个元素
（2）iterator erase(iterator first,iterator last)：删除向量中[first,last]中的元素
（3）void pop_back()：删除向量中最后一个元素
（4）void clear()：删除向量中所有元素
4、遍历函数模板
（1）Type &at(int pos)：返回pos位置元素的引用
（2）Type &front()：返回首元素的引用
（3）Type &back()：返回尾元素的引用
（4）iterator begin()：返回向量头迭代器，指向第一个元素
（5）iterator end()：返回尾迭代器，不包括最后一个元素，在其下面
（6）reverse_iterator rbegin()：反向迭代器，返回最后一个元素的迭代器，用于逆向遍历容器
（7）reverse_iterator rend()：反向迭代器，返回第一个元素之前的迭代器，用于逆向遍历容器
5、其他函数模板
（1）void assign(int n,const Type &e)：将向量中第n个元素设置成元素e
（2）bool empty()const：向量是否为空，如果向量无元素，则返回true，否则返回false
（3）int size()const：返回向量中元素的个数 
*/

//向量使用示例
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;                  //定义向量
	int a[]={1,2,3,4,5},n=5,i;      //定义数组及整型变量
	
	for(i=0;i<n;i++){
		//依次向v添加元素
		v.push_back(a[i]);          //通过push_back()函数添加元素 
	} 
	
	n=v.size();                     //获取向量元素个数
	cout<<"通过数组方式输出:"<<endl;//输出提示
	for(i=0;i<n;i++){
		//依次输出各元素
		cout<<v[i]<<" ";            //输出v[i] 
	} 
	cout<<endl;
	
	cout<<"通过获得引用输出:"<<endl;//输出提示
	for(i=0;i<n;i++){
		//依次输出各元素
		int &e=v.at(i);             //引用定义
		cout<<e<<" ";               //输出e 
	} 
	cout<<endl;
	
	cout<<"通过迭代器输出:"<<endl;  //输出提示
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		//依次输出各元素
		cout<<*it<<" ";             //输出*it 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
