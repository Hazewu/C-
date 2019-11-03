//铁路列车调度
#include<iostream>
#include<deque>
#include<stack>
#include<queue>
using namespace std;

bool TrainJudge(int a[],int n){
	int i;                //定义变量
	queue<int> inq;       //定义进站队列
	stack<int> s;         //定义调度栈
	
	for(i=1;i<=n;i++){
		//依次入栈
		inq.push(i);      //i入栈 
	} 
	
	for(i=0;i<n;i++){
		//调度a[i]
		if(a[i]<1||a[i]>n){
			//待调度的列车号应在1~n之间
			cout<<"待调度的列车号应在1~"<<n<<"之间"<<endl;
			return false;      //调度失败      
		}else if(!s.empty()&&a[i]==s.top()){
			//栈非空，待调度的列车就在栈顶，调度成功
			cout<<s.top()<<"号列车出站"<<endl;
			s.pop();           //出栈 
		}else if(!inq.empty()&&a[i]>=inq.front()){
			//队列非空，待调度的列车在车站队列中
			while(!inq.empty()&&a[i]>=inq.front()){
				//inq.front()进栈
				s.push(inq.front());
				cout<<inq.front()<<"号列车进站"<<endl;
				inq.pop();     //出队 
			} 
			
			cout<<s.top()<<"号列车出站"<<endl; //此时s.top()==a[i]
			s.pop();           //出栈 
		}else{
			//a[i]不在s栈顶，而在s栈的中间，无法出栈
			cout<<"调度不能实现"<<endl;        //调度失败
			return false; 
		}
	}
	return true;               //调度成功 
} 

int main(){
	int *a,i,n=6;                              //定义变量
	char select;                               //定义变量
	do{
		cout<<"输入列车数：";                  //输入提示
		cin>>n;                                //输入n
		a=new int[n];                          //分配空间
		cout<<"输入待调度的列车号：";          //输入提示
		for(i=0;i<n;i++){
			//依次输入待调度的列车号
			cin>>a[i];                         //输入a[i] 
		} 
		
		if(TrainJudge(a,n)){
			//调度成功
			cout<<"祝贺！调度成功！"<<endl; 
		}else{
			//调度失败
			cout<<"失败乃成功之母，最好重新调度"<<endl; 
		}
		
		delete []a;                             //释放空间
		
		cout<<"是否继续调度(Y/N)?"<<endl;
		cin>>select;                            //输入选择 
	} while(select=='Y'||select=='y');
	
	system("PAUSE");
	return 0;
}
