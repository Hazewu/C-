//����sort�������������н������򣬲��õڶ���sort()����ģ��

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

template<class It>
void Show(const It &begin,const It &end){  //������ʾ 
	for(It it=begin;it!=end;it++){
		//������ʾ��Ԫ��
		cout<<*it<<" "; 
	}
	cout<<endl;
} 

int main(){
	int a[]={1,8,6,9,18};                  //��������
	int n=sizeof(a)/sizeof(int);           //Ԫ�ظ���
	vector<int> v(n);                      //������������
	
	for(int i=0;i<n;i++){
		//�������������Ԫ�ظ�ֵ
		v[i]=a[i];                         //��a[i]��ֵ��v[i] 
	} 
	
	cout<<"����ǰ��";
	Show(v.begin(),v.end());
	sort(v.begin(),v.end(),greater<int>());//�������� 
	cout<<"�����";
	Show(v.begin(),v.end()); 
	
	system("PAUSE");
	return 0;
}
