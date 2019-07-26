#ifndef _SCLASS3_12_CEDUCATION_H_
#define _SCLASS3_12_CEDUCATION_H_

#include<iostream>
#include<string.h>
using namespace std;
const int LEN=50;                             //定义一个常量，表示字符数组长度

class CEducation                              //CEducation（教育背景）类的声明
{
	public:
		CEducation(){ };                      //构造函数
		CEducation(char cSchool[],char cDegree);//重载构造函数，为数据成员赋初值 
		void GetEdu(void);              //输入教育背景的有关数据
		void PutEdu(void);              //输出教育背景的有关数据
	private:
	    char m_cSchool[LEN];                  //毕业学校
		char m_cDegree;                       //最高学历：专科H、本科B、硕研M、博研D 
};

class Staff                                   //员工类（公共基类、组合类）
{
	public:
		Staff(void){ };                       //构造函数
		~Staff(void){ };                      //空析构函数
		void CalculateSal(void){ };           //计算实发工资
		void OutPut(void);                    //输出员工基本信息
		void InPut(void);                     //输入员工各项数据
	protected:
	    CEducation Edu;                       //子对象（教育背景）
		int m_iStaffNum;                      //工作编号
		char m_cName[LEN];                    //姓名
		float  m_fRateOfAttend;               //出勤率
		float m_fBasicSal;                    //基本工资
		float m_fPrize;                       //奖金
		static int s_iCount;                  //静态累加器 
}; 

class CAdminStaff:public Staff                //声明派生类：CAdminStaff（行政人员）
{
	public:
		CAdminStaff(){ };                     //派生类构造函数
		~CAdminStaff(){ };                    //派生类析构函数 
		void CalculateSal(void);
}; 

class CManager:virtual public Staff           //声明派生类CManager，将Staff声明为虚基类
{
	public:
		CManager(){ };                        //构造函数
		void SetMData(void);                  //输入经理数据
		void CalculateSal(void);          
	protected:
	    float m_fDeductTRate;                   //经理提成比例
		float m_fTAmount;                       //总销售额 
}; 

class CSaleman:virtual public Staff            //声明派生类CSaleman，将Staff声明为虚基类
{
	public:
		CSaleman(){ };                         //构造函数
		void SetSData(void);                    //输入销售员数据
		void CalculateSal(void);
	protected:
	    float m_fDeductRate;                   //销售员提成比例
		float m_fPersonAmount;                 //个人销售额 
}; 

class CSaleManager:public CSaleman,public CManager
                                               //声明多继承中的派生类CSaleManager
{
	public:
	    CSaleManager(){ };
		void CalculateSal(void); 
};

int Staff::s_iCount=1000;                       //初始化静态数据成员s_iCount

CEducation::CEducation(char cSchool[],char cDegree)
{
	strcpy(m_cSchool,cSchool);
	m_cDegree=cDegree;
}

void CEducation::GetEdu(void)
{
	cout<<endl<<"毕业学校：";
	cin>>m_cSchool;
	cout<<endl<<"最高学历：（专科H、本科B、硕研M、博研D）";
	cin>>m_cDegree;
	m_cDegree=toupper(m_cDegree);     //用toupper函数将用户输入的学历规范为大写字符 
}

void CEducation::PutEdu(void)   //实现类CEducation的成员函数PutEdu，输出信息
{
	cout<<endl<<"毕业学校："<<m_cSchool;
	cout<<endl<<"最高学历：";
	switch(m_cDegree){
		case 'H':
			cout<<"专科";
			break;
		case 'B':
		    cout<<"本科";
			break;
		case 'M':
		    cout<<"硕研";
			break;
		case 'D':
		    cout<<"博研";
		    break;
		default:
			cout<<"空";         //输出的学历在选项之外则为“空” 
			break;
	}
} 

void CAdminStaff::CalculateSal(void)  //计算行政人员的实际发放工资：基本工资+奖金*出勤率
{
	cout<<endl<<"当月实发工资："<<m_fBasicSal+m_fRateOfAttend<<"元"<<endl;
}

void CManager::SetMData(void)         //输入经理数据
{
	cout<<endl<<"公司总销售额：";
	cin>>m_fTAmount;
	cout<<endl<<"提成比例：";
	cin>>m_fDeductTRate;
}

void CManager::CalculateSal(void)    //计算经理的实际发放工资：基本工资+总销售额*提成比例
{
	cout<<endl<<"当月实发工资："<<m_fBasicSal+m_fTAmount*m_fDeductTRate<<"元"<<endl;
}

void CSaleman::SetSData(void)         //输入销售员数据
{
	cout<<endl<<"个人销售额：";
	cin>>m_fPersonAmount;
	cout<<endl<<"提成比例：";
	cin>>m_fDeductRate;
}

void CSaleman::CalculateSal(void)    //计算销售员的实际发放工资：基本工资+个人销售额*提成比例
{
	cout<<endl<<"当月实发工资："<<m_fBasicSal+m_fPersonAmount*m_fDeductRate<<"元"<<endl;
}

void CSaleManager::CalculateSal(void) //计算销售经理实发工资：基本工资+个人销售额*提成比例+总销售额*提成比例
{
	cout<<endl<<"当月实发工资：";
	cout<<m_fBasicSal+m_fPersonAmount*m_fDeductRate+m_fTAmount*m_fDeductTRate<<"元"<<endl; 
}

void Staff::InPut(void)               //输入员工各项数据
{
	m_iStaffNum=++s_iCount;           //静态累加器自加1后赋给工作编号
	cout<<endl<<"请输入编号为"<<m_iStaffNum<<"号员工的姓名：";
	cin>>m_cName;                     //输入员工姓名
	Edu.GetEdu();                     //子对象调用类CEducation的GetEdu()，输入教育背景数据
	cout<<endl<<"基本工资：";
	cin>>m_fBasicSal;                 //输入基本工资 
	cout<<endl<<"奖金：";
	cin>>m_fPrize;                    //输入奖金
	cout<<endl<<"出勤率：";  
	cin>>m_fRateOfAttend;             //输入出勤率
	//规范出勤率的值
	if(m_fRateOfAttend>1.0)
	{
		m_fRateOfAttend=1.0; 
	}
	else if(m_fRateOfAttend<0) 
	{
		m_fRateOfAttend=0;
	}
}

void Staff::OutPut(void)               //实现类Staff的成员函数OutPut，输出员工信息
{
	cout<<endl<<"显示员工的基本数据：";
	cout<<endl<<"姓名："<<m_cName;
	cout<<endl<<"工作编号："<<m_iStaffNum;
	Edu.PutEdu();                      //通过子对象调用类CEducation的成员函数PutEdu
	cout<<endl<<"基本工资："<<m_fBasicSal;
	cout<<endl<<"奖金："<<m_fPrize;
	cout<<endl<<"出勤率："<<m_fRateOfAttend*100<<"%"; 
} 
#endif											    
