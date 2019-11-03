/*
list��һ��˫������
1�����캯��ģ��
��1��list()������һ���յ�list
��2��list(const list &)���������캯��
2�����ӡ�ɾ������ģ��
��1��void push_back(const Type &e)��list����βԪ�غ�����һ��Ԫ��e
��2��void push_front(const Type &e)��list������Ԫ��ǰ����һ��Ԫ��e
��3��void pop_back()�����ҽ���������Ϊ��ʱ��ɾ������βԪ��
��4��void pop_front()�����ҽ���������Ϊ��ʱ��ɾ��������Ԫ��
��5��void remove(const Type &e)��ɾ������������Ԫ��ֵ����e��Ԫ��
��6��void clear()��ɾ������������Ԫ��
��7��iterator insert(iterator it,const Type &e=Type())���ڵ�����itǰ�����Ԫ��e������ָ��e�ĵ�����
��8��void insert(iterator it,int n,const Type &e)���ڵ�����itǰ����n����ͬԪ��e
��9��iterator erase(iterator it)��ɾ���ô�ȥit��Ӧ��Ԫ��
��10��iterator erase(iterator first,iterator last)��ɾ��������[first,last)���Ԫ��
3����������ģ��
��1��iterator begin()��������Ԫ�صĵ�����
��2��iterator end()������βԪ�غ�ĵ�������������βԪ�صĵ�����
��3��reverse_iterator rbegin():����βԪ�ص���������������������������
��4��reverse_iterator rend()��������Ԫ��ǰ����������������������������
��5��Type &front()��������Ԫ�ص�����
��6��Type &back()������βԪ�ص�����
4����������ģ��
��1��void sort()������������Ԫ�ذ���������
��2��void reverse()����ת������Ԫ��˳��
��3��int size()const����������Ԫ�ظ���
��4��bool empty()cosnt���ж������Ƿ�գ�������true�����������ѿ� 
*/

//list����
#include<iostream>
#include<string>
#include<list>
using namespace std;

typedef list<string> strList;     //���Ͷ���

int main(){
	strList la;                   //�����������
	la.push_back("back");         //������β����롰back��
	la.push_front("middle");      //��������Ԫ��ǰ���롰middle�� 
	la.push_front("front");       //��������Ԫ��ǰ���롰front��
	
	cout<<la.front()<<endl;       //�����Ԫ�ء�front��
	cout<<*la.begin()<<endl;      //�����Ԫ�ء�front��
	cout<<la.back()<<endl;        //���βԪ�ء�back��
	cout<<*la.end()<<endl;        //���βԪ�ء�back��
	la.pop_front();               //ɾ����Ԫ�ء�front��
	la.pop_back();                //ɾ��βԪ�ء�back��
	cout<<la.front()<<endl;       //�����middle��
	
	system("PAUSE");
	return 0;  
} 
