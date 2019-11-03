//��·�г�����
#include<iostream>
#include<deque>
#include<stack>
#include<queue>
using namespace std;

bool TrainJudge(int a[],int n){
	int i;                //�������
	queue<int> inq;       //�����վ����
	stack<int> s;         //�������ջ
	
	for(i=1;i<=n;i++){
		//������ջ
		inq.push(i);      //i��ջ 
	} 
	
	for(i=0;i<n;i++){
		//����a[i]
		if(a[i]<1||a[i]>n){
			//�����ȵ��г���Ӧ��1~n֮��
			cout<<"�����ȵ��г���Ӧ��1~"<<n<<"֮��"<<endl;
			return false;      //����ʧ��      
		}else if(!s.empty()&&a[i]==s.top()){
			//ջ�ǿգ������ȵ��г�����ջ�������ȳɹ�
			cout<<s.top()<<"���г���վ"<<endl;
			s.pop();           //��ջ 
		}else if(!inq.empty()&&a[i]>=inq.front()){
			//���зǿգ������ȵ��г��ڳ�վ������
			while(!inq.empty()&&a[i]>=inq.front()){
				//inq.front()��ջ
				s.push(inq.front());
				cout<<inq.front()<<"���г���վ"<<endl;
				inq.pop();     //���� 
			} 
			
			cout<<s.top()<<"���г���վ"<<endl; //��ʱs.top()==a[i]
			s.pop();           //��ջ 
		}else{
			//a[i]����sջ��������sջ���м䣬�޷���ջ
			cout<<"���Ȳ���ʵ��"<<endl;        //����ʧ��
			return false; 
		}
	}
	return true;               //���ȳɹ� 
} 

int main(){
	int *a,i,n=6;                              //�������
	char select;                               //�������
	do{
		cout<<"�����г�����";                  //������ʾ
		cin>>n;                                //����n
		a=new int[n];                          //����ռ�
		cout<<"��������ȵ��г��ţ�";          //������ʾ
		for(i=0;i<n;i++){
			//������������ȵ��г���
			cin>>a[i];                         //����a[i] 
		} 
		
		if(TrainJudge(a,n)){
			//���ȳɹ�
			cout<<"ף�أ����ȳɹ���"<<endl; 
		}else{
			//����ʧ��
			cout<<"ʧ���˳ɹ�֮ĸ��������µ���"<<endl; 
		}
		
		delete []a;                             //�ͷſռ�
		
		cout<<"�Ƿ��������(Y/N)?"<<endl;
		cin>>select;                            //����ѡ�� 
	} while(select=='Y'||select=='y');
	
	system("PAUSE");
	return 0;
}
