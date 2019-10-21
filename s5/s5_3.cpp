#include<iostream>
#include<string>
using namespace std;

//TClass����ģ�壬��CInterger���CFloat��ĳ�������
//����ģ��������ɾ����ģ���࣬ģ������������ڴ�������
//������ģ��
template<class Type>
class TClass{
	public:
		TClass(Type);              //ʹ��Ĭ�ϵ���������
		void SetItem(Type);
		Type GetItem(); 
	private:
		Type m_item;
}; 

//������ģ�幹�캯��
template<class Type>
TClass<Type>::TClass(Type item){
	m_item=item;
} 

//������ģ���Ա����
template<class Type>
void TClass<Type>::SetItem(Type item){
	m_item=item;
} 

//������ģ���Ա����
template<class Type>
Type TClass<Type>::GetItem(){
	return m_item;
} 

//���Գ���
int main(){
	TClass<int> Obj1(128);             //����һ��TClass<int>ģ�������
	cout<<Obj1.GetItem()<<endl;
	Obj1.SetItem(218);
	cout<<Obj1.GetItem()<<endl;
	TClass<float> Obj2(0.128);         //����һ��TClaa<int>ģ�������
	cout<<Obj2.GetItem()<<endl;
	Obj2.SetItem(0.218);
	cout<<Obj2.GetItem()<<endl;
	
	return 0; 
} 
