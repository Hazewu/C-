#ifndef _SCLASS_CTRANSLATOR_H_
#define _SCLASS_CTRANSLATOR_H_

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//��������
class CTranslator{
private:
//���ݳ�Ա 
	ifstream fin;                 //�����ļ�
	ofstream fout;                //����ļ�
	string indent;                //�����ַ���

//��������
    void SkipSapces();            //sapce�ո������հף������ո��Ʊ�������з���
	bool GetToken(string &token); //��ȡ��ǣ����ļ��ѽ����򷵻�false�����򷵻�true
	string IntToStr(int i);       //������iת��Ϊ����Ϊ4�Ĵ�
	void ForEach();               //����foreachѭ��

public:
//���캯�������������뷽��
    CTranslator(const string &infName,const string &outfName);//���캯��
	virtual ~CTranslator(){       //�������� 
		fin.close();              //�ر��ļ� 
		fout.close();             //�ر��ļ� 
	}  
	void Run();                   //���������� 
}; 

#endif
