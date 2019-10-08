#include<iostream>
#include<stdlib.h>
#include"sclass4_11_Node.h"

/************************************************************************************/  
//CNode�Ĵ��ι��캯��
CNode::CNode(string str){                  //��㹹�캯�� 
	m_pStr=new string(str);                //new�ַ�������ռ䣬������
	if(m_pStr==NULL){
		cout<<"�ڴ����ʧ�ܡ�"<<endl;
		exit(0);                           //�ڴ����ʧ�ܣ��˳� 
	} 
	m_nodeNum=GetNumber();                 //ȡ�ý���ţ�����ֵ��m_nodeNum
	cout<<"CNodeȫ�´������No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl; 
} 

//CNode�Ŀ������캯��
CNode::CNode(const CNode &oCN){
	m_pStr=new string(*oCN.m_pStr);        //new�ַ�������ռ䣬������
	if(m_pStr==NULL){
		cout<<"�ڴ����ʧ�ܡ�"<<endl;
		exit(0);                           //�ڴ����ʧ�ܣ��˳� 
	} 
	m_nodeNum=GetNumber();                 //ȡ�ý���ţ�����ֵ��m_nodeNum
	cout<<"CNode�����������No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl;  
} 

//CNode����������
CNode::~CNode(){
	cout<<"~CNode���ٽ��,No:"<<m_nodeNum<<",Name"<<*m_pStr<<endl;
	delete m_pStr;                         //�Զ�����m_pStrָ���string���� 
} 

//����CNode�ĸ�ֵ������������������������ͬ������ڣ�
CNode &CNode::operator=(const CNode &oCN){
	if(this==&oCN){                        //�ж��Ƿ��Լ���ֵ�Լ� 
		return *this;                      //����ǣ����ظ��ƣ����� 
	}
	delete m_pStr;                         //�ͷŸ�ֵ�������߶�����ַ�������ָ����ָ����
	m_pStr=new string(*oCN.m_pStr);        //new�ַ�������ռ䣬������
	if(m_pStr==NULL){
		cout<<"�ڴ����ʧ�ܡ�"<<endl;
		exit(0);                           //�ڴ����ʧ�ܣ��˳� 
	} 
	//ע���˴�ֻ�ܿ��Ǹ�ֵ�������ָ�ֵ������ı��⡣��m_nodeNum�����ظ���
	m_nodeNum=oCN.m_nodeNum;               //ȡ�ý���ţ�����ֵ��m_nodeNum
	cout<<"CNode��ֵ�˶���No:"<<m_nodeNum<<",Name:"<<*m_pStr<<endl;
	return *this; 
} 

//����CNode�ġ��������������
const CNode &CNode::operator,(const CNode &oCN){
	return oCN;                            //ֱ�ӷ��صڶ��������� 
} 

//����CNode����������,scout��ͬ��cout 
ostream& operator<<(ostream& scout,CNode& obj){
	scout<<"Node Name:"<<*(obj.GetStr())<<",";
	scout<<"Node Number:"<<obj.GetNodeNum()<<"."<<endl;
	return scout; 
} 

//����CNode�����������
istream& operator>>(istream& scin,CNode& obj){
	char s[81];                            //����81����Ϊ�˱�̷���
	cout<<"Please Enter Node Name:";       
	scin.getline(s,81,'\n');               //getline(scin,*(obj.GetStr());
	*(obj.GetStr())=s;                     //sת��Ϊstring������ٸ�ֵ
	cout<<"Please Enter Node Number:";
	scin>>obj.GetNodeNum();                //�˴����������Ľ���Ŵ�Сδ������
	return scin; 
}  

//���ص�ǰsNodeNum��������1
int CNode::GetNumber(void){
	return sNodeNum<LEN ? sNodeNum++:(sNodeNum=0);   //ȷ��С��LEN 
} 

//����ָ�������ֵ��ַ���ָ��
string *CNode::GetStr(){
	return m_pStr;
} 

//���ؽ��ı�ţ�Ҳ��m_nodeNum
int &CNode::GetNodeNum(){
	return m_nodeNum;
} 

//CNodeArray��Ĺ��캯��
CNodeArray::CNodeArray(int aLength){
	for(int i=0;i<aLength;i++){
		m_poCN[i]=NULL;                 //ָ�������ʼ����ȫ��ָ��NULL 
	}
	m_aLength=aLength;                  //���鳤������
	m_aIndex=0;                         //��ǰ����±�����Ϊ0
	cout<<"CNodeArray������һ������������length=:"<<m_aLength<<endl; 
} 

//~CNodeArray����������ȷ��m_poCNָ��Ķ����ָ����ָ��Ŀռ��Ƿ�������
CNodeArray::~CNodeArray(void){
	for(int i=0;i<m_aLength;i++){
		if(m_poCN[i]!=NULL){           //m_poCN[i]ָ�����ʱ���ŵ���delete����� 
			delete m_poCN[i];           //��� m_poCN[i]ָ����󣬻��Զ�����~CNode()
			cout<<"delete:m_poCN["<<i<<"]."<<endl; 
		}
	}
	cout<<"~CNodeArray:������ɡ�"<<endl;
} 

//��������˺ܼ򵥵Ľ����빦�ܣ���ֻ���������CNodeָ��ָ���½����ѡ�
//Ϊ�˰�ȫ���ȶԲ���λ�������жϣ����ԭ���н�㣬������ʧ�ܣ����ء�
//Ҳ��������ԭ��㣬ǿ�Ʋ��롣
bool CNodeArray::Insert(CNode &oCN){
	if(m_aIndex>=m_aLength){
		cout<<"�Բ��𣬳�������������±꣬�����ٲ��룡"<<endl;
		return false;
	}
	
	//��Ҫ����Ľ�㸳ֵ�����������
	if(m_poCN[m_aIndex]!=NULL){
		cout<<"��λ�����н�㣬�����ٲ��룡"<<endl;
		return false; 
	} 
	
	m_poCN[m_aIndex]=&oCN;
	cout<<"�����½�㣬Pos:"<<m_aIndex<<",No:"<<oCN.GetNodeNum()<<",Name:"<<*oCN.GetStr()<<endl;
	m_aIndex++;
	return true;
} 

//���ﲻ������������൱��deleteһ����㣬����ָ��Ϊ�ռ���
bool CNodeArray::Delete(int index){
	if(m_poCN[index]==NULL){
		cout<<"Pos:"<<index<<"=NULL,�������delete�����."<<endl;
		return false;
	}
	delete m_poCN[index];          //�ͷŵ�ǰ���
	m_poCN[index]=NULL;
	cout<<"delete:m_poCN["<<index<<"],Pos:"<<index<<",��λ��ָ��Ľ��delete�ɹ���"<<endl;
	return true; 
} 

//CNodeArray�ġ�[]�����ظ����ء����ﷵ����һ�����󣬵�[]������ʱ
//���Թ۲쵽CNode�Ŀ������캯�������������ĵ��ù��̡�
CNode CNodeArray::operator[](int i){
	if((i<m_aIndex)&&(i>=0)){
		return *m_poCN[i];         //���ص�i�����ָ����ָ��Ķ��� 
	}else{
		if(m_poCN[i]==NULL){
			cout<<"û��Ԫ�أ�����"<<endl;
			exit(0);
		}
		cout<<"����Խ��"<<endl;
		exit(0);
	}
} 

//����CNodeArray��new�����
void *CNodeArray::operator new(size_t size){
	cout<<"����CNodeArray�Զ����new��������"<<endl;
	return malloc(size);
} 

//����CNodeArray��delete�����
void CNodeArray::operator delete(void*p){
	cout<<"����CNodeArray�Զ����delete���ٶ���"<<endl;
	free(p);
} 

//�����������������˼����Ҫ��Ϊ�˱���ѧϰ�͹۲����C++���ƣ���
//�������������г�����ϸ�۲졢���ɼ������ظ�������
int CNode::sNodeNum=0;
 
int main(){
	cout<<"1==============================================."<<endl;
	//��һ����������Ҫ�۲쿽�����캯����new��delete�����������
	{
		CNodeArray oCNA1;                                //����һ�������������
		//�ڲ�������ȥ��ע�Ϳɹ۲쵽oCN1��oCN2������λ��
		{
			int i;
			char s[81];                                  //��ʱ��Ż�ȡ�Ľ������
			string str;                                  //����һ��string����
			CNode oCN1("Zhang San"),oCN2("Li Si");       //����������
			oCN2=oCN1;                                   //�������صĸ�ֵ�����
			CNode *poCN1,*poCN2;                          //����һ��CNodeָ��
			for(i=0;i<5;i++){
				cout<<"Input a Node Name or word \"stop\":";
				cin.getline(s,81,'\n');                  //�����ַ�����Ϊ�����
				str=s;                                   //�ַ���ת��Ϊ�ַ�������
				if(str=="stop")                          //��������ַ���Ϊ��stop�������˳�
				    break;
				poCN1=new CNode(str);                    //����һ�㹹�캯���½�����
				poCN2=new CNode(*poCN1);                 //���ÿ������캯���½�����
				oCNA1.Insert(*poCN1);                    //�������ָ��ָ��ö���
				oCNA1.Insert(*poCN2);                    //�������ָ��ָ��ö��� 
			} 
		} 
		cout<<"====START==================================."<<endl;
//Ϊʲô�����⣿		cout<<oCNA1[0];                                  //�۲����صġ�<<���͡�[]�������
		cout<<"====END====================================."<<endl;
		for(int i=0;i<5;i++){
			oCNA1.Delete(i);                             //ע�͵������ɹ۲쵽delete������ 
		} 
	}
	cout<<"2=============================================."<<endl;
	//�ڶ�����������Ҫ�۲����ص�new��delete�ĵ���
	{
		CNode oCN1("Genghis khan");                      //Ԫ̫�棬����ľ��
		CNodeArray *poCN3=new CNodeArray;                //�������ء�new��
		delete poCN3;                                    //��������delete��ͨ��::delete�ɵ�ϵͳdelete 
	}
	cout<<"3=============================================."<<endl;
	//��������������Ҫ�۲����صġ�<<��>>������=��������ĵ���
	{
		CNode oCN1("Genghis khan"),oCN2("11"),oCN3(oCN1);//Ԫ̫�棬����ľ��
		cin>>oCN3;                                       //�������صġ�>>������� 
		cout<<oCN3;                                      //�������صġ�<<������� 
		oCN3=oCN2,oCN1;                                  //�������صġ�,���͡�=������� 
		cout<<oCN3;                                       //�������صġ�>>������� 
	}
	return 0; 
} 
