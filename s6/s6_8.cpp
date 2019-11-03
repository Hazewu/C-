/*
vector������ 
1�����캯��ģ��
��1��vector()������һ����vector
��2��vector(int n)������һ��vector����Ԫ�ظ���Ϊn
��3��vector(int nSize,const Type &e)������һ��vector��Ԫ�ظ���ΪnSize���Ҹ�Ԫ�ص�ֵ��Ϊe
��4��vector(const vector &)���������캯��ģ��
2�����Ӻ���ģ��
��1��void push_back(const Type &e)������β������һ��Ԫ��e
��2��iterator insert(iterator it,const Type &e)��������ĳһ��Ԫ��ǰ����һ��Ԫ��e
��3��void insert(iterator it,int n,const Type &e)��������ĳһԪ��ǰ����n����ͬ��Ԫ��e
3��ɾ������ģ��
��1��iterator erase(iterator it)��ɾ��������ĳһ��Ԫ��
��2��iterator erase(iterator first,iterator last)��ɾ��������[first,last]�е�Ԫ��
��3��void pop_back()��ɾ�����������һ��Ԫ��
��4��void clear()��ɾ������������Ԫ��
4����������ģ��
��1��Type &at(int pos)������posλ��Ԫ�ص�����
��2��Type &front()��������Ԫ�ص�����
��3��Type &back()������βԪ�ص�����
��4��iterator begin()����������ͷ��������ָ���һ��Ԫ��
��5��iterator end()������β�����������������һ��Ԫ�أ���������
��6��reverse_iterator rbegin()��������������������һ��Ԫ�صĵ����������������������
��7��reverse_iterator rend()����������������ص�һ��Ԫ��֮ǰ�ĵ����������������������
5����������ģ��
��1��void assign(int n,const Type &e)���������е�n��Ԫ�����ó�Ԫ��e
��2��bool empty()const�������Ƿ�Ϊ�գ����������Ԫ�أ��򷵻�true�����򷵻�false
��3��int size()const������������Ԫ�صĸ��� 
*/

//����ʹ��ʾ��
#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;                  //��������
	int a[]={1,2,3,4,5},n=5,i;      //�������鼰���ͱ���
	
	for(i=0;i<n;i++){
		//������v���Ԫ��
		v.push_back(a[i]);          //ͨ��push_back()�������Ԫ�� 
	} 
	
	n=v.size();                     //��ȡ����Ԫ�ظ���
	cout<<"ͨ�����鷽ʽ���:"<<endl;//�����ʾ
	for(i=0;i<n;i++){
		//���������Ԫ��
		cout<<v[i]<<" ";            //���v[i] 
	} 
	cout<<endl;
	
	cout<<"ͨ������������:"<<endl;//�����ʾ
	for(i=0;i<n;i++){
		//���������Ԫ��
		int &e=v.at(i);             //���ö���
		cout<<e<<" ";               //���e 
	} 
	cout<<endl;
	
	cout<<"ͨ�����������:"<<endl;  //�����ʾ
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		//���������Ԫ��
		cout<<*it<<" ";             //���*it 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
