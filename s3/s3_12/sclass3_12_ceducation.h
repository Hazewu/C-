#ifndef _SCLASS3_12_CEDUCATION_H_
#define _SCLASS3_12_CEDUCATION_H_

#include<iostream>
#include<string.h>
using namespace std;
const int LEN=50;                             //����һ����������ʾ�ַ����鳤��

class CEducation                              //CEducation�������������������
{
	public:
		CEducation(){ };                      //���캯��
		CEducation(char cSchool[],char cDegree);//���ع��캯����Ϊ���ݳ�Ա����ֵ 
		void GetEdu(void);              //��������������й�����
		void PutEdu(void);              //��������������й�����
	private:
	    char m_cSchool[LEN];                  //��ҵѧУ
		char m_cDegree;                       //���ѧ����ר��H������B��˶��M������D 
};

class Staff                                   //Ա���ࣨ�������ࡢ����ࣩ
{
	public:
		Staff(void){ };                       //���캯��
		~Staff(void){ };                      //����������
		void CalculateSal(void){ };           //����ʵ������
		void OutPut(void);                    //���Ա��������Ϣ
		void InPut(void);                     //����Ա����������
	protected:
	    CEducation Edu;                       //�Ӷ��󣨽���������
		int m_iStaffNum;                      //�������
		char m_cName[LEN];                    //����
		float  m_fRateOfAttend;               //������
		float m_fBasicSal;                    //��������
		float m_fPrize;                       //����
		static int s_iCount;                  //��̬�ۼ��� 
}; 

class CAdminStaff:public Staff                //���������ࣺCAdminStaff��������Ա��
{
	public:
		CAdminStaff(){ };                     //�����๹�캯��
		~CAdminStaff(){ };                    //�������������� 
		void CalculateSal(void);
}; 

class CManager:virtual public Staff           //����������CManager����Staff����Ϊ�����
{
	public:
		CManager(){ };                        //���캯��
		void SetMData(void);                  //���뾭������
		void CalculateSal(void);          
	protected:
	    float m_fDeductTRate;                   //������ɱ���
		float m_fTAmount;                       //�����۶� 
}; 

class CSaleman:virtual public Staff            //����������CSaleman����Staff����Ϊ�����
{
	public:
		CSaleman(){ };                         //���캯��
		void SetSData(void);                    //��������Ա����
		void CalculateSal(void);
	protected:
	    float m_fDeductRate;                   //����Ա��ɱ���
		float m_fPersonAmount;                 //�������۶� 
}; 

class CSaleManager:public CSaleman,public CManager
                                               //������̳��е�������CSaleManager
{
	public:
	    CSaleManager(){ };
		void CalculateSal(void); 
};

int Staff::s_iCount=1000;                       //��ʼ����̬���ݳ�Աs_iCount

CEducation::CEducation(char cSchool[],char cDegree)
{
	strcpy(m_cSchool,cSchool);
	m_cDegree=cDegree;
}

void CEducation::GetEdu(void)
{
	cout<<endl<<"��ҵѧУ��";
	cin>>m_cSchool;
	cout<<endl<<"���ѧ������ר��H������B��˶��M������D��";
	cin>>m_cDegree;
	m_cDegree=toupper(m_cDegree);     //��toupper�������û������ѧ���淶Ϊ��д�ַ� 
}

void CEducation::PutEdu(void)   //ʵ����CEducation�ĳ�Ա����PutEdu�������Ϣ
{
	cout<<endl<<"��ҵѧУ��"<<m_cSchool;
	cout<<endl<<"���ѧ����";
	switch(m_cDegree){
		case 'H':
			cout<<"ר��";
			break;
		case 'B':
		    cout<<"����";
			break;
		case 'M':
		    cout<<"˶��";
			break;
		case 'D':
		    cout<<"����";
		    break;
		default:
			cout<<"��";         //�����ѧ����ѡ��֮����Ϊ���ա� 
			break;
	}
} 

void CAdminStaff::CalculateSal(void)  //����������Ա��ʵ�ʷ��Ź��ʣ���������+����*������
{
	cout<<endl<<"����ʵ�����ʣ�"<<m_fBasicSal+m_fRateOfAttend<<"Ԫ"<<endl;
}

void CManager::SetMData(void)         //���뾭������
{
	cout<<endl<<"��˾�����۶";
	cin>>m_fTAmount;
	cout<<endl<<"��ɱ�����";
	cin>>m_fDeductTRate;
}

void CManager::CalculateSal(void)    //���㾭���ʵ�ʷ��Ź��ʣ���������+�����۶�*��ɱ���
{
	cout<<endl<<"����ʵ�����ʣ�"<<m_fBasicSal+m_fTAmount*m_fDeductTRate<<"Ԫ"<<endl;
}

void CSaleman::SetSData(void)         //��������Ա����
{
	cout<<endl<<"�������۶";
	cin>>m_fPersonAmount;
	cout<<endl<<"��ɱ�����";
	cin>>m_fDeductRate;
}

void CSaleman::CalculateSal(void)    //��������Ա��ʵ�ʷ��Ź��ʣ���������+�������۶�*��ɱ���
{
	cout<<endl<<"����ʵ�����ʣ�"<<m_fBasicSal+m_fPersonAmount*m_fDeductRate<<"Ԫ"<<endl;
}

void CSaleManager::CalculateSal(void) //�������۾���ʵ�����ʣ���������+�������۶�*��ɱ���+�����۶�*��ɱ���
{
	cout<<endl<<"����ʵ�����ʣ�";
	cout<<m_fBasicSal+m_fPersonAmount*m_fDeductRate+m_fTAmount*m_fDeductTRate<<"Ԫ"<<endl; 
}

void Staff::InPut(void)               //����Ա����������
{
	m_iStaffNum=++s_iCount;           //��̬�ۼ����Լ�1�󸳸��������
	cout<<endl<<"��������Ϊ"<<m_iStaffNum<<"��Ա����������";
	cin>>m_cName;                     //����Ա������
	Edu.GetEdu();                     //�Ӷ��������CEducation��GetEdu()�����������������
	cout<<endl<<"�������ʣ�";
	cin>>m_fBasicSal;                 //����������� 
	cout<<endl<<"����";
	cin>>m_fPrize;                    //���뽱��
	cout<<endl<<"�����ʣ�";  
	cin>>m_fRateOfAttend;             //���������
	//�淶�����ʵ�ֵ
	if(m_fRateOfAttend>1.0)
	{
		m_fRateOfAttend=1.0; 
	}
	else if(m_fRateOfAttend<0) 
	{
		m_fRateOfAttend=0;
	}
}

void Staff::OutPut(void)               //ʵ����Staff�ĳ�Ա����OutPut�����Ա����Ϣ
{
	cout<<endl<<"��ʾԱ���Ļ������ݣ�";
	cout<<endl<<"������"<<m_cName;
	cout<<endl<<"������ţ�"<<m_iStaffNum;
	Edu.PutEdu();                      //ͨ���Ӷ��������CEducation�ĳ�Ա����PutEdu
	cout<<endl<<"�������ʣ�"<<m_fBasicSal;
	cout<<endl<<"����"<<m_fPrize;
	cout<<endl<<"�����ʣ�"<<m_fRateOfAttend*100<<"%"; 
} 
#endif											    
