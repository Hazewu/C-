#include<iostream>
using namespace std;

//��������ģ��
template<class Type>
struct Node{                          //�ýṹ�壿�������𣿴���ˣ� 
//���ݳ�Ա
    Type data;                        //����
	Node<Type> *next;                 //ָ�� 
}; 

//����������ģ��
template<class Type>
class Link{
private:
//���ݳ�Ա 
	Node<Type> *head;                 //��ͷ 
	Node<Type> *tail;                 //��β��Ϊ�˺������������Ҫ������ָ�����һ��Ԫ��
	                                  //���Ǵ�Ԫ�صĺ���,�˴�����β����ΪNULL��
	Node<Type> *prev;                 //��βǰ����prev->next==tail)

public:
//���к���ģ��
    Link(){                           //���캯��ģ�� 
    	head=prev=tail=NULL;          //��ʼ�������� 
	} 
	virtual ~Link(){                  //��������ģ�� 
		while(head->next!=NULL){
			//����ǿ�
			Node<Type> *p=head->next; //pָ���һ������Ԫ�ؽ��
			head->next=p->next;       //ɾ��p��ָ��㣬ֻ��ָ�ý������������
			delete p;                 //�ͷ�p��ָ�洢�ռ� 
		}
	}
	void Append(const Type &e){       //��ĩβ׷��Ԫ�� ,&e�������ã�������Եر仯 
		Node<Type> *p=new Node<Type>; //����洢�ռ�
		p->data=e;                    //����Ԫ��ֵΪe
		p->next=NULL;                 //�¼���ؽ����Ϊ��
		if(head==NULL){
			//������
			head=prev=p;              //head��prev��ָ���½��
			tail=prev->next;          //tailΪprev�غ��NULL 
		} else{
			//�ǿ�����
			prev->next=p;             //�½��׷����ĩβ
			prev=p;                   //pΪ�±�β
			tail=prev->next;          //tailΪprev�غ��NULL 
		}
	} 
	Node<Type> *Begin(){
		return head;                  //���ؿ�ʼ 
	}
	Node<Type> *End(){                //���ؽ��� 
		return tail; 
	}
}; 

//���������������ģ��
template<class Type>
class LinkIterator{
private:
//���ݳ�Ա 
	Type *itPtr;                      //�����������Ƕ�Type *�ط�װ

public:
//���к���ģ��
    LinkIterator(Type *p):itPtr(p){}  //���캯��ģ��
	bool operator!=(const LinkIterator &it) const{
	                                  //���ء���=����ϵ�����
		return this->itPtr!=it.itPtr; //����ֵ 
	} 
	void operator++(int){
		itPtr=itPtr->next;            //itPtrָ����һԪ�أ�������itPtr++����Ϊ����洢��ַ������ 
	}
	Type operator*(){                 //���ء�*��ָ������������� 
		return *itPtr;                //����itPtrָ���ֵ 
	}
}; 

template<class Type>
ostream &operator<<(ostream &out,const Node<Type> &nd){
	                                  //���ء�<<���������� 
	out<<nd.data;                     //�����������Ԫ��
	return out;                       //����out 
}

template<class It>
void Show(It begin,It end){           //������ʾ 
	for(It it=begin;it!=end;it++){
		//������ʾ��Ԫ��
		cout<<*it<<" "; 
	}
	cout<<endl;
}

int main(){
	int a[]={1,2,3,4,5,6};            			//����c����a
	int n=6;                          			//Ԫ�ظ���
	Link<int> la;                     			//�����������
	int i;                            			//������ʱ����
	
	for(i=0;i<n;i++){                 			//��ĩβ׷��Ԫ�� 
		la.Append(a[i]);
	} 
	             //<>����� Node<int>�����������itPtrʵ������Node<int>�͵� 
	LinkIterator<Node<int> > begin(la.Begin());	//����begin
	LinkIterator<Node<int> > end(la.End());      //����end 
	cout<<"����Ԫ�أ�";                         //�����ʾ
	Show(begin,end);                            //��ʾ����
	
	system("PAUSE");                            //���ÿ⺯��system()�����ϵͳ��ʾ��Ϣ
	return 0;                                   //����ֵ0�����ز���ϵͳ 
}
