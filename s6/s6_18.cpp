//����ѧ�Ų�ѯѧ����Ϣ
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//����ѧ����
class Student{
private:
//���ݳ�Ա 
	int num;                 //ѧ��
	string name;             //����
	int age;                 //����
	string sex;              //�Ա�
public:
//�����г�Ա
    Student(int n,const string &nm,int ag,const string &sx):num(n),name(nm),age(ag),sex(sx){}
	                         //���캯��
	int GetNum() const{      //����ѧ�� 
	    return num;
	} 
	string GetName() const{  //��������
	    return name;
	} 
	int GetAge() const{      //�������� 
	    return age;
	}
	string GetSex() const{   //�����Ա� 
	    return sex;
	}
	bool operator==(int n){  //��������������==�� 
		return num==n;       //ת��Ϊѧ�ŵıȽ� 
	}
}; 

int main(){
	vector<Student> v;           //������������,��Ҳ������Ϊһ�����ͣ�structҲ���� 
	
	v.push_back(Student(20120101,"�Ž���",18,"��"));
	                             //��vβ����һ��ѧ����Ϣ
	v.push_back(Student(20120102,"����ɺ",20,"Ů"));
	                             //��vβ����һ��ѧ����Ϣ
	v.push_back(Student(20120103,"���ٻ",19,"Ů")); 
	                             //��vβ����һ��ѧ����Ϣ
	
	vector<Student>::iterator begin,end,it;
	                             //���������
	begin=v.begin();             //��ʼ
	end=v.end();                 //����
	
	int findNum=20120102;        //��ѯ������ѧ��=20120102
	it=find(begin,end,findNum);  //��ѯ������ѧ��=20120102�ĵ�����
	
	cout<<"ѧ��Ϊ"<<findNum<<"��ѧ������Ϣ��"<<endl; 
	                             //�����ʾ
	if(it!=end){
		//��ѯ�ɹ�
		cout<<"ѧ�ţ�"<<it->GetNum()<<endl;
		cout<<"������"<<it->GetName()<<endl;
		cout<<"���䣺"<<it->GetAge()<<endl;
		cout<<"�Ա�"<<it->GetSex()<<endl; 
	}else{
		//��ѯʧ��
		cout<<"û�и�ѧ�ŵ�ѧ����"<<endl;  
	}
	
	system("PAUSE");
	return 0; 
}
