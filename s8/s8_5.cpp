/*
�쳣�������
�����쳣��һ�ַ��������̡��쳣�����ó����ڻ������������쳣ʱ������������������������Ժ����
����˼�룺���쳣�ļ��ʹ���ֿ���
�ṹ����ʽ����throw��try��catch�ṹ��
throw���������û��Զ������͵��쳣���������׳��쳣
try��ʶ�������쳣����Ŀ�ʼ�����������쳣
catch��ʶ�쳣������ģ��Ŀ�ʼ�����ڲ��񡢴����쳣
һ���﷨�ṹ���£�
    throw <���ʽ>;
	
	try{
        //try���� 
	}
	catch(����1 ����1){
	    //�������1���쳣���� 
	} 
	catch(����2 ����2){
	    //�������2���쳣���� 
	} 
	//����
	catch(����n ����n){
	    //�������n���쳣���� 
	} 
*/

/*
��׼�쳣
��1��һ�����ࣺexception������C++�쳣�Ļ���
    class exception{
	public:
	    exception() throw();                                //Ĭ�Ϲ��캯��
		exception(const exception& rhs) throw();            //�������캯��
		exception& operator=(const exception& rhs) throw(); //��ֵ�����
		virtual ~exception() throw();                       //��������
		virtual const char *what() const throw();           //Ϊ�׳����쳣�ṩ�����ַ��� 
	}; 
��2�����������������쳣��
    logic_error              //���������߼����󣬿��ڳ���ִ��ǰ����⵽
	runtime_error            //�����������ʱ�Ĵ���ֻ�������е�ʱ����ܼ�⵽
	�������������ֱַ����Լ��������ࡣ
��3)��logic_error�������쳣��
    domain_error             //�쳣�����Ա��������domain error��
	invalid_argument         //�쳣�����յ�һ����Ч��ʵ�Σ��׳����쳣
	length_error             //�쳣��ͨ�����ڱ���ռ䲻��
	out_of_bounds            //�쳣��ͨ�����ڱ�ʾ�±����
��4����runtime_error�������쳣
    range_error              //�쳣����������������Ч��ʾ��Χ
	overflow_error           //�쳣���������������������������������ܹ���ʾ����
	underflow_error          //�쳣�����渡�����������������������С�ܹ���ʾ����
��׼C++���е���Щ�쳣�����Ϊ�����Ա���ر����Լ����Ŀ������ṩһЩ����
��5��bad_alloc�쳣
    ͨ����new.h�ļ���������bad_alloc�࣬��Ҳ�̳���exception�ࡣ
	bad_alloc�����ڴ����ڴ������󡣵�newʱδȡ��Ҫ����ڴ��������������쳣��
	bad_alloc                //��new()����ʱ���ܷ�����Ҫ��Ĵ洢��ʱ�����׳����쳣   
*/ 

//�쳣ʾ��
#include<iostream>
#include<string>
using namespace std;

void MyFunc(void);

class CMyException{                           //�����쳣�� 
public:
	CMyException(){ };
	~CMyException(){ };
	const char *ShowExceptionReason() const{  //��ʾ�쳣ԭ�� 
	    return "CMyException Exception.";
	}
};

class CDemo{      //����һ�������࣬������ʾ��ִ�����쳣�׳���˳�� 
public:
	CDemo();
	~CDemo();
};

CDemo::CDemo(){
	cout<<"Constructing CDemo."<<endl;
} 

CDemo::~CDemo(){
	cout<<"Destructing CDemo."<<endl;
}

//�쳣Ҳ���Զ���װ�����磺��MyFunc()�з�װthrow��try��catch����
//�����ﲶ������쳣��Ȼ��������ò��ٲ��񱾲㲻�ܲ�����쳣
//��ʾ������ֻ��main()�н������쳣������
void MyFunc(){
	CDemo D;
	cout<<"\nIn MyFunc(). Throwing CMyException exception."<<endl;
	throw CMyException();                   //�׳��쳣 
} 

int main(){
	try{                                   //��try��װ���ܻ�����쳣�Ĵ��� 
		cout<<"In try  block,calling MyFunc()."<<endl;
		MyFunc();
	}
	catch(CMyException E){                 //һ·���񲢴����쳣 
		cout<<"Caught: ";
		cout<<E.ShowExceptionReason()<<endl;
	}
	catch(string str){                     //��·���񲢴����쳣 
		cout<<"Caught some other exception: "<<str<<endl; 
	}
	
	return 0;
}
