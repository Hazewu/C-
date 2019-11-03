/*
list是一个双向链表
1、构造函数模板
（1）list()：创建一个空的list
（2）list(const list &)：拷贝构造函数
2、增加、删除函数模板
（1）void push_back(const Type &e)：list容器尾元素后增加一个元素e
（2）void push_front(const Type &e)：list容器首元素前增加一个元素e
（3）void pop_back()：当且仅当容器不为空时，删除容器尾元素
（4）void pop_front()：当且仅当容器不为空时，删除容器首元素
（5）void remove(const Type &e)：删除容器中所有元素值等于e的元素
（6）void clear()：删除容器中所有元素
（7）iterator insert(iterator it,const Type &e=Type())：在迭代器it前面插入元素e，返回指向e的迭代器
（8）void insert(iterator it,int n,const Type &e)：在迭代器it前插入n个相同元素e
（9）iterator erase(iterator it)：删除得带去it对应的元素
（10）iterator erase(iterator first,iterator last)：删除迭代器[first,last)间的元素
3、遍历函数模板
（1）iterator begin()：返回首元素的迭代器
（2）iterator end()：返回尾元素后的迭代器，而不是尾元素的迭代器
（3）reverse_iterator rbegin():返回尾元素的逆向迭代器，用于逆向遍历容器
（4）reverse_iterator rend()：返回首元素前的逆向迭代器，用于逆向遍历容器
（5）Type &front()：返回首元素的引用
（6）Type &back()：返回尾元素的引用
4、其他函数模板
（1）void sort()：容器内所有元素按升序排序
（2）void reverse()：反转容器中元素顺序
（3）int size()const：返回容器元素个数
（4）bool empty()cosnt：判断容器是否空，若返回true，表明容器已空 
*/

//list容器
#include<iostream>
#include<string>
#include<list>
using namespace std;

typedef list<string> strList;     //类型定义

int main(){
	strList la;                   //定义链表对象
	la.push_back("back");         //向链表尾后插入“back”
	la.push_front("middle");      //向链表首元素前插入“middle” 
	la.push_front("front");       //向链表首元素前插入“front”
	
	cout<<la.front()<<endl;       //输出首元素“front”
	cout<<*la.begin()<<endl;      //输出首元素“front”
	cout<<la.back()<<endl;        //输出尾元素“back”
	cout<<*la.end()<<endl;        //输出尾元素“back”
	la.pop_front();               //删除首元素“front”
	la.pop_back();                //删除尾元素“back”
	cout<<la.front()<<endl;       //输出“middle”
	
	system("PAUSE");
	return 0;  
} 
