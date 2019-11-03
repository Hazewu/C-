/*
���������㷨for_each()
ԭ��������ʾ��
    template<class It,class Fun)
	Fun for_each(It first,It last,Fun f);
�Բ���˵�����£�
��1��It������ָ�����ͻ������
��2��first��ʾ�������ʼԪ��ָ��������
��3��last��ʾ����βָ�������������������һ��Ԫ�أ�������֮��
��4��Funָ���������ָ������
��5��fΪһԪȫ�ֺ�����ҽԺ��������
���ܣ��˺���ģ��ĺ����Ƕ�[first,last)֮���ÿ��Ԫ�أ���Ϊ����f�Ĳ������벢ִ�к��� 
*/

//��ʾ������ÿ������Ԫ�ؼ���Ӧ������

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ShowCube(int n){                       //��ʾ��������Ӧ������ 
	cout<<n<<":\t"<<n*n*n<<endl;            //��������Ϣ 
} 

int main(){
	int n=8;                                //Ԫ�ظ��� 
	vector<int> v(n);                       //�����СΪn������
	
	for(int i=0;i<n;i++){
		//ͨ�����鷽ʽΪ����Ԫ�ظ�ֵ
		v[i]=i+1; 
	} 
	
	cout<<"i:\ti*i*i"<<endl;                //�����ʾ
	for_each(v.begin(),v.end(),ShowCube);   //���v��ÿ��Ԫ�ؼ�����Ӧ������
	
	system("PAUSE");
	return 0; 
} 
