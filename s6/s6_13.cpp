/*����������ĸ���

    //���������ģ��
	tempalte<class Type,class Container=deque<type>>
	class queue{
	protected:
	//˽�г�Ա
	    Container c;                    //���ڴ洢����Ԫ��
	
	public:
	//���к���ģ��
	    void push(const Type &e){       //Ԫ��eѹ���β 
	        c.push_back(e);             //ʵ�����ǵ���deque��push_back()���� 
	    }
	    ���� 
    };
    
  queue���ǶԻ���������Container���ٷ�װ�����������¶��� 
*/ 

/*
queue��stack���� 
1�����캯��ģ��
��1��queue(class Type,class Container=deque<Type>)������Ԫ������ΪType�Ŀն��У�Ĭ������ʱdeque
��2��stack(class Type,class Container=deque<Type>)������Ԫ������ΪType�Ŀ�ջ��Ĭ��������deque
2�����к�ջ���к���ģ��
��1��bool empty()��������У�ջ��Ϊ�շ���true�����򷵻�false
��2��int size()�����ض��У�ջ����Ԫ�ظ���
��3��void push(const Type &e)����Ԫ��eѹ���β��ջ����
��4��void pop()���ڶ��У�ջ���ǿ�����£�ɾ����ͷ��ջ����Ԫ��
3�����ж��к���ģ��
��1��Type &front()���ڶ��зǿ�����£����ض�ͷԪ������
��2��type &back()���ڶ��зǿյ�����£����ض�βԪ�ص�����
4��ջ���к���ģ��
Type &top()����ջ�ǿ�����£�����ջ��Ԫ�ص����� 
*/ 

//stackʹ��ʾ�� 
#include<iostream>
#include<deque>
#include<stack>
using namespace std;

int main(){
	stack<int> s;                  //����ջ����
	for(int i=1;i<=5;i++){
		//������ջ
		s.push(i);                 //i��ջ 
	} 
	
	cout<<"ջs��";                 //�����ʾ
	while(!s.empty()){
		//ջs�ǿ�
		cout<<s.top()<<" ";        //���ջ��
		s.pop();                   //��ջ 
	} 
	cout<<endl;
	
	system("PAUSE");
	return 0;
} 
