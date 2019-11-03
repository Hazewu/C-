/*
deque����֧�ָ�Ч�����ɾ����������β��Ԫ�أ�Ҳ����˫�˶���
1�����캯��ģ��
��1��deque()������һ����deque
��2��deque(const deque &)���������캯��ģ��
2�����Ӻ���ģ��
��1��void push_front(const Type &e)��˫�˶����ײ�����һ��Ԫ��e
��2��void push_back(const Type &e)��˫�˶���β������һ��Ԫ��e
3��ɾ������ģ��
��1��void pop_front()��ɾ��˫�˶�����ǰһ��Ԫ��
��2��void pop_back()��ɾ��˫�˶������һ��Ԫ��
��3��void clear()��ɾ��˫�˶���������Ԫ��
4����������ģ��
��1��Type &front()��������Ԫ�ص�����
��2��Type &back()������βԪ�ص�����
��3��iterator begin()������ͷ��������ָ���һ��Ԫ��
��4��iterator end()������β�����������������һ��Ԫ�أ���������
��5��reverse_iterator rbegin()�����������������ָ�����һ��Ԫ�صĵ�����
��6��reverse_iterator rend()�����������������ָ���һ��Ԫ�ص�ǰһλ�õĵ�����
5����������ģ��
��1��empty()const�������Ƿ�Ϊ�գ���true������������Ԫ��
��2��int size()const������Ԫ�صĸ��� 
*/

//deque����ʹ��ʾ��
#include<iostream>
#include<deque>
using namespace std;

int main(){
	deque<int> q;                     //����˫�˶��ж���
	deque<int>::iterator it;          //���������
	int a[]={5,1,8,18,16,19},n=6,i,e; //�������鼰���ͱ���
	
	for(i=0;i<n;i++){
	    //������˫�˶����в���a[i]
		q.push_back(a[i]);            //��˫�˶���β׷��a[i] 
	} 
	
	for(it=q.begin();it!=q.end();it++){
		//���������Ԫ�ص�ֵ
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	q.clear();                        //���˫�˶���
	for(i=0;i<n;i++){
		//������˫�˶����в���a[i]
		q.push_front(a[i]);           //��˫�˶����ײ�����a[i] 
	} 
	
	for(it=q.begin();it!=q.end();it++){
		//���������Ԫ�ص�ֵ
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	q.pop_front();                    //ɾ����Ԫ��
	cout<<q.front()<<endl;        //�������Ԫ��
	
	q.pop_back();                     //ɾ��βԪ��
	cout<<q.back()<<endl;         //�����βԪ��
	
	system("PAUSE");
	return 0; 
} 
