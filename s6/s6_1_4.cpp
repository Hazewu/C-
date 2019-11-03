#include<iostream>
using namespace std;

//����������ģ��
template<class Type>
class Link{
public:
//������Ƕ����ģ��
    //������Ƕ�׽����ģ��
	struct Node{
	//���ݳ�Ա
	    Type data;                        //����
		Node *next;                       //ָ�� 
	}; 
	
	//������Ƕ��������������ģ��
	class LinkIterator{
	private:
	//���ݳ�Ա 
		Node *itPtr;                      //�����������Ƕ�Node *�ķ�װ 
		
	public:
	//���к���ģ��
	    LinkIterator(Node *p):itPtr(p){}  //���캯��ģ��
		bool operator!=(const LinkIterator &it)const{
		                                  //���ء���=����ϵ����� 
		    return this->itPtr!=it.itPtr; //����ֵ 
		} 
		void operator++(int){             //���غ�׺��++������� 
			itPtr=itPtr->next;            //itPtrָ����һԪ�� 
		}
		Node operator*(){                 //���ء�*��ָ������������� 
			return *itPtr;                //����itPtrָ���ֵ 
		}
	}; 

public:
//���к���ģ��
    Link(){                               //���캯��ģ�� 
    	head=prev=tail=NULL;
	} 
	virtual ~Link(){                      //��������ģ�� 
		while(head->next!=NULL){
			//�����ǿ�
			Node *p=head->next;           //pָ���һ������Ԫ�ؽ��
			head->next=p->next;           //ɾ��p��ָ��Ľ��
			delete p;                     //�ͷ�p��ָ�洢�ռ� 
		}
	}
	void Append(const Type &e){           //��ĩβ׷��Ԫ�� 
		Node *p=new Node;                 //����洢�ռ�
		p->data=e;                        //����Ԫ��ֵΪe
		p->next=NULL;                     //�¼���Ľ����Ϊ��
		if(head==NULL){
			//������
			head=prev=p;                  //head��prev��ָ���µĽ�� 
			tail=prev->next;              //tailΪprev�ĺ��NULL 
		} else{
			//�ǿ�����
			prev->next=p;                 //�½��׷����ĩβ 
			prev=p;                       //pΪ�±�β 
			tail=prev->next;              //tailΪprev�ĺ��NULL 
		}
	}
	Node *Begin(){                        //���ؿ�ʼ 
		return head;
	}
	Node *End(){                          //���ؽ��� 
		return tail; 
	}

private:
//���ݳ�Ա
    Node *head;                           //��ͷ
	Node *tail;                           //��β��Ϊ��ʵ�ֵ���������Ҫ��
	Node *prev;                           //��βǰ����prev->next==tail�� 
}; 

template<class Type>
ostream &operator<<(ostream &out,const struct Link<Type>::Node &nd){
	                                      //���ء�<<���������� 
	out<<nd.data;                         //�����������Ԫ��ֵ 
	return out;                           //����out 
}

template<class It>
void Show(It begin,It end){               //������ʾ 
	for(It it=begin;it!=end;it++){
		//������ʾ��Ԫ��
		cout<<*it<<" "; 
	}
	cout<<endl;
}

int main(){
	int a[]={1,2,3,4,5,6};                //����c����a
	int n=6;                              //Ԫ�ظ���
	Link<int> la;                         //������������
	int i;                                //������ʱ����
	
	for(i=0;i<n;i++){                     
		la.Append(a[i]);                  //��ĩβ׷��Ԫ�� 
	} 
	
	Link<int>::LinkIterator begin(la.Begin());//����begin
	Link<int>::LinkIterator end(la.End());    //����end
	cout<<"����Ԫ�أ�";                       //�����ʾ
	Show(begin,end);                          //��ʾ����
	system("PAUSE");                          //���ÿ⺯��system(),���ϵͳ��ʾ��Ϣ
	return 0;                                 //����0�����ز���ϵͳ 
}

//Ҫ���ˣ�<<�������������Ⱑ���������ϴ�ģ��ٶ���Ҳû�иĺã����ȷ�һ���� 