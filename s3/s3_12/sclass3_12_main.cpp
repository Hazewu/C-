#include"sclass3_12_ceducation.h"

int main(void)
{
	char flag='Y';                  //�����ж��Ƿ����¼��ı�־����ʼ��Ϊ��Y��
	while(toupper(flag)=='Y')
	{
		cout<<"��ѡ��¼�����1.���� 2.����Ա 3.���۾��� 4.������Ա����";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:
			{
				CManager staff;          //����һ�����������
				staff.InPut();           //���û���ĳ�Ա����
				staff.SetMData();        //���þ�����ĳ�Ա����
				staff.OutPut();          //���û���ĳ�Ա����
				staff.CalculateSal();    //���þ�����ĳ�Ա����
				break; 
			}
			case 2:
			{
				CSaleman staff;          //����һ��������Ա�����
				staff.InPut();
				staff.SetSData();
				staff.OutPut();
				staff.CalculateSal();    //����������Ա��ĳ�Ա���� 
				break; 
			}
			case 3:
			{
				CSaleManager staff;      //����һ�����۾�������� 
				staff.InPut();
				staff.SetMData();
				staff.SetSData();
				staff.OutPut();
				staff.CalculateSal();    //�������۾�����ĳ�Ա����
				break; 
			}
			case 4:
			{
				CAdminStaff staff;       //����һ��������Ա�����
				staff.InPut();
				staff.OutPut();
				staff.CalculateSal();    //����������Ա��ĳ�Ա����
				break; 
			}
			default:
			{
				cout<<"ѡ������";
				break;
			}
		}
	    cout<<endl<<"�Ƿ����¼����Ϣ����Y/N��";
	    cin>>flag;
	} 
	return 0;
}
