#include<iostream>
#include<string>
using namespace std;

class CNode;                                //CNode��ǰ���������Ա���TLinkList��ʹ��

//����һ���������ģ�塪���ڸ������еĽ���������
template<class Type>
class TLinkList{
	public:
		TLinkList();                        //���캯�� 
		virtual ~TLinkList();               //��������
		 
		virtual bool Insert(Type value);    //�������в���һ����㣬���ڱ�ͷ����
		bool Delete(Type value);            //��������ɾ��ֵΪvalue�Ľ��
		bool Search(Type value);            //�ж��������Ƿ����ֵΪvalue�Ľ��
		bool Modify(Type v1,Type v2);       //���ҽ��ֵΪv1�Ľ�㣬���޸�Ϊv2
		virtual void Print();               //��������˳����������еĽ��ֵ
	
	public:
	    CNode *m_pHead;                     //���������ͷ���ָ��         
}; 

//�������������ģ�塪���ڸ������еĽ�����������е�
template<class Type>
class TOrderedLinkList:public TLinkList<Type>{
	public:
		TOrderedLinkList();                  //���캯��
		virtual ~TOrderedLinkList();                 //��������
		
	public:
	    virtual bool Insert(Type value);     //�������
		virtual void Print();                //��������˳����������еĽ��ֵ 
	public:
		CNode *m_pHead;
}; 

//�������ṹ��
class CNode{
	friend class TLinkList<int>;             //����ģ����ΪCNode����Ԫ
	friend class TOrderedLinkList<int>;      //����ģ����ΪCNode����Ԫ
	
	public:
	    CNode(int value);
	    ~CNode();
	
	private:
		int m_value;                         //���ֵ
		CNode *m_pNext;                      //����̣�ָ����һ�����
		CNode *m_pPre;                       //���ǰ����ָ����һ����� 
}; 

//����๹�캯��
CNode::CNode(int value){
	m_value=value;                           //���ֵ
	m_pNext=NULL;                            //�����
	m_pPre=NULL;                             //���ǰ�� 
} 

//�������������
CNode::~CNode() {
	;
}

//TLinkList��ģ��Ĺ��캯��
template<class Type>
TLinkList<Type>::TLinkList(){
	m_pHead=NULL;                             //����ͷ 
} 

//TLinkList��ģ�����������============================���һ�£�Ӧ�ÿ��Ի��ַ��� 
template<class Type>
TLinkList<Type>::~TLinkList(){
	CNode *p=m_pHead;                         //pָ���һ����� 
	for( ;p!=NULL; ){                         //ֱ����һ����㲻Ϊ�� 
		m_pHead=p->m_pNext;                   //ͷָ��ָ����һ�����
		delete p;                             //�ͷ�p��ָ��Ľ�㣬�������ͷ�p��
		p=m_pHead;                            //pָ���µ�ͷ��� 
	}
} 

//����һ���½�㣬��ֻ��ͷָ��������
template<class Type>
bool TLinkList<Type>::Insert(Type value){
	CNode *pTemp=new CNode(value);            //����һ���½�㣬CNode(value)һ��������������m_value=value
	if(pTemp==NULL){                          //�ڴ�ռ����벻�ɹ� 
		exit(0);                              //ִֹͣ�г��� 
	} 
	
	if(m_pHead==NULL){                        //��ͷΪ��ʱ���������������ͬ 
		pTemp->m_pNext=NULL;                  //1.�����Ϊ��
		pTemp->m_pPre=NULL;                   //2.���ǰ��Ϊ��
		m_pHead=pTemp;                        //3.ͷָ��ָ����½�� 
	}else{                                    //��ͷ��Ϊ��ʱ 
		pTemp->m_pNext=m_pHead;               //1.��ԭ�������Ϊ��ͷ���ĺ��
		pTemp->m_pPre=NULL;                   //2.����ͷ����ǰ������ΪNULL
		m_pHead->m_pPre=pTemp;                //3.����ͷ�������Ϊԭͷ����ǰ��
		m_pHead=pTemp;                        //4.����ͷ�������Ϊ�µı�ͷ 
	}
	
	return true; 
}

//ɾ��ֵΪvalue�����н��
//ɾ���㷨���£����ȴ���һ����ʱ��㣨���ֵ����趨�����뵽����ͷ��Ϊ�µ���ʱͷ��㣬
//Ȼ����p1ָ���µ�ͷ��㣬p2ָ�����̣�ԭʼͷ��㣩��Ȼ�����p2��ָ�Ƿ�Ӧ��ɾ����
//���Ӧ��ɾ������ɾ����ɾ����p1������p2ָ�����̣������Ӧ��ɾ������p1��p2ָ�����̡�
//��˷���֪��p2ָ��NULL�������m_pHeadָ����ʱͷ��㡣
template<class Type>
bool TLinkList<Type>::Delete(Type value){
	bool flag=false;                           //0��ʾû��ɾ���κν�㣬1��ʾɾ����
	//������ͷ����һ����ʱ��ͷ
	CNode oCN(0);                              //����һ���½���Բ��뵽��ͷ��Ϊ��ʱͷ���
	oCN.m_pNext=m_pHead;                       //��ԭͷ�������Ϊ��ʱͷ���ĺ��
	oCN.m_pPre=NULL;                           //����ʱͷ����ǰ������ΪNULL
	m_pHead->m_pPre=&oCN;                      //����ʱͷ�������Ϊԭͷ����ǰ��
	m_pHead=&oCN;                              //����ʱͷ�������Ϊ�µı�ͷ
	//ɾ��ֵΪvalue�����н��
	CNode *p1=m_pHead,*p2=m_pHead->m_pNext;    //p1ָ���±�ͷ��㣬p2ָ������
	for( ;p2!=NULL; ){                         //p2Ϊ��˵�������Ѿ�������ȫ�� 
        if(p2->m_value==value){                //��p2��ָ��Ľ������Ҫɾ���Ľ�� 
        	p1->m_pNext=p2->m_pNext;           //p2�ĺ�̸�ֵ��p1�ĺ��
			(p2->m_pNext)->m_pPre=p1;          //p1��ֵ��p2�ĺ�̵�ǰ����ַ
			delete p2;                         //ɾ��p2��ָ���㣨������������
			flag=true;                         //˵���н�㱻ɾ�� 
		}else{                                 //���p2��ָ�Ĳ���Ҫɾ���Ľ�� 
			p1=p2;                             //p1ָ��p2 
			p2=p2->m_pNext;                    //p2ָ��p2�ĺ�� 
		} 
	}
	//����ʱ��ͷɾ����ע��oCN����new�Ķ�������ɾ��
	m_pHead=oCN.m_pNext;
	(oCN.m_pNext)->m_pPre=NULL;
	
	return flag; 
}

//�����������Ƿ�������Ϊֵvalue�Ľ�㣬�У�����true��û�з���false
template<class Type>
bool TLinkList<Type>::Search(Type value){
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		if(p->m_value==value){                 //�ҵ��ý�㣬����true 
			return true;
		}
	}
	return false; 
} 

//�������н��ֵΪv1�Ľ��ȫ���޸�Ϊv2���޸ĳɹ�����true������false
template<class Type>
bool TLinkList<Type>::Modify(Type v1,Type v2){
	bool flag=false;                           //0��ʾû���κ��޸ģ�1��ʾ���޸�
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		if(p->m_value==v1){                    //�ҵ��ý�㣬�޸�Ϊv2������true 
			p->m_value=v2;
			true=1;
		}
	} 
	return flag;
} 

//��������˳��ӱ�ͷ��ʼȡ�����ֵ����ʾ
template<class Type>
void TLinkList<Type>::Print(){
	cout<<"��TLinkList��ͷ��ʼ����ֵ����Ϊ��\n";
	//���������Զ���ÿһ������ֵ�������ն���ʾ
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		cout<<p->m_value<<", ";                //��ʾ���ֵ 
	} 
	cout<<endl;                                //��������� 
}

//TOrderedLinkList��ģ��Ĺ��캯��
template<class Type>
TOrderedLinkList<Type>::TOrderedLinkList():TLinkList<Type>(){
	;
} 

//TOrderedLinkList��ģ�����������
template<class Type>
TOrderedLinkList<Type>::~TOrderedLinkList(){
	;
} 

//TOrderedLinkList�Ľ����뷽����TLinkList��Ψһ��ͬ������������룬
//Ҳ����˵����λ�ò�һ���ڱ�ͷ��������������룬��ͷֵС����βֵ��
//�����ڱ�ͷ�ͱ�β�ֱ����һ����Сֵ��һ�����ֵ��
//����ڱ�ͷ�ͱ�β֮���ú����forѭ��Ѱ�Ҳ���λ�ò��룬���ɾ����ͷ�ͱ�β
template<class Type>
bool TOrderedLinkList<Type>::Insert(Type value){
	CNode *p1,*p2;                             //��������ָ�룬�������ʱʹ��
	CNode *pTemp=new CNode(value);             //����pTempָ��new�Ĵ�������
	if(pTemp==NULL){                           //�ڴ�ռ����벻�ɹ� 
		exit(0);                               //ִֹͣ�г��� 
	} 
	
	if(m_pHead==NULL){                         //��ͷΪ��ʱ����Ϊ��һ����� 
		pTemp->m_pNext=NULL;                   //1.�½��ĺ��ΪNULL
		pTemp->m_pPre=NULL;                    //2.�½���ǰ��ΪNULL
		m_pHead=pTemp;                         //3.ͷָ��ָ���½�� 
	}else{                                     //����ͷ��Ϊ��ʱ������ҪѰ�Ҳ���λ�ã�Ȼ����ܲ����� 
		if(value<m_pHead->m_value){            //�ڱ��ͷ���ǰ���� 
			pTemp->m_pNext=m_pHead;            //1.��ԭͷ�������Ϊ��ͷ���ĺ��
			pTemp->m_pPre=NULL;                //2.����ͷ����ǰ������ΪNULL
			m_pHead->m_pPre=pTemp;             //3.����ͷ�������Ϊԭͷ����ǰ��
			m_pHead=pTemp;                     //4.����ͷ�������Ϊ�µı�ͷ 
		}else{                                 //������ͷ���ǰ���� 
			//��p2ָ��p1��ǰ������Ҫ���Ǳ�β���Ĳ��룩
			for(p2=m_pHead,p1=m_pHead->m_pNext;p1!=NULL;p2=p1,p1=p1->m_pNext){
				if(value<p1->m_value){          //�������м���� 
					(p1->m_pPre)->m_pNext=pTemp;//1.p1��ǰ���ĺ��ָ���½��
					pTemp->m_pPre=p1->m_pPre;   //2.�½���ǰ��ָ��p1��ǰ��
					pTemp->m_pNext=p1;          //3.�½��ĺ��ָ��p2
					p1->m_pPre=pTemp;           //4.p1��ǰ��ָ���½��
					break; 
				}
			}
			if(p1==NULL){                       //������ĩβ���� 
				pTemp->m_pNext=NULL;            //1.�½��ĺ������ΪNULL
				pTemp->m_pPre=p2;               //2.�½���ǰ��ָ��p2
				p2->m_pNext=pTemp;              //3.p2�ĺ��ָ���½�� 
			}
		}
	} 
	return true; 
} 

//��������˳��ӱ�ͷ��ʼȡ�����ֵ����ʾ
template<class Type>
void TOrderedLinkList<Type>::Print(){
	cout<<"��TOrderedLinkList��ͷ��ʼ������ֵ����Ϊ��\n";
	//���������Զ���ÿһ������ֵ�����ն���ʾ
	for(CNode *p=m_pHead;p!=NULL;p=p->m_pNext){
		cout<<p->m_value<<", ";                  //��ʾ���ֵ 
	} 
	cout<<endl;                                  //��������� 
} 

//�����Գ���
int main(){
	TLinkList<int> oILL;
	oILL.Insert(12);
	oILL.Insert(24);                             //������oILL�У����β���24
	oILL.Insert(48);                             //������oILL�У����β���48
	oILL.Insert(96);
	oILL.Insert(24);
	oILL.Insert(48);
	oILL.Insert(96);
	oILL.Insert(35);
	oILL.Print();                                //ɾ��ǰ��ʾ
	oILL.Delete(24);                             //ɾ��ֵΪ24�Ľ��
	oILL.Print();                                //ɾ������ʾ
 
	TOrderedLinkList<int> oDLL;
	oDLL.Insert(12);
	oDLL.Insert(24);                             //�ڼ���oDLL�У����β���24
	oDLL.Insert(48);                             //�ڼ���oDLL�У����β���48
	oDLL.Insert(96);
	oDLL.Insert(24);
	oDLL.Insert(48);
	oDLL.Insert(96);
	oDLL.Insert(35);
	oDLL.Print();                                //ɾ��ǰ��ʾ
	oDLL.Delete(24);                             //ɾ��ֵΪ24�Ľ��
	oDLL.Print();                                //ɾ������ʾ
	
	return 0;  
} 
	//�������⣿�ڴ�ԭ����ֻ�е�һ��Print�����ն���ʾ���������ʧЧ
