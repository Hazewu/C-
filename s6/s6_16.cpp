//�����������Ԫ�صĺ͡����ֵ����Сֵ��ʵ��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//����GetInfo
class GetInfo{
private:
//���ݳ�Ա 
	int sum;                          //��
	int max;                          //���ֵ
	int min;                          //��Сֵ
	int count;                        //Ԫ�ظ���
public:
//���к���
    GetInfo():sum(0),count(0){}       //���캯��
	int GetSum()const{                //��ú� 
	    return sum;
	}
	int GetMax()const{                //������ֵ 
	    return max;
	} 
	int GetMin()const{                //�����Сֵ 
	    return min;
	}
	void operator()(int e){           //���ص������ĺ�������� 
		count++;                      //Ԫ�ظ����Լ�1 
		sum=sum+e;                    //�ۼ���� 
		if(count==1){
			//eΪ��һ��Ԫ��
			max=min=e;                //ֻ��һ��Ԫ��ʱ�����ֵ����Сֵ��Ϊe 
		}else{
			//�ж��Ԫ��
			if(max<e){
				//eΪ��ǰ�����ֵ��maxΪ��ǰ��������ֵ
				max=e;                //��e��ֵ��max 
			} else if(min>e){
				//eΪ��ǰ�����ֵ��minΪ��ǰ�������Сֵ
				min=e;                //��e��ֵ��min 
			}
		}
	}
}; 

int main(){
	int a[]={1,4,2,8,5,6};            //��������
	int n=sizeof(a)/sizeof(int);      //����Ԫ�ظ���
	int *begin=a;                     //��ʼ 
	int *end=a+n;                     //����
	
	GetInfo objGetInfo=for_each(begin,end,GetInfo());
	                                  //���庯������ͨ��for_each()�㷨���г�ʼ��
	cout<<"�ܺ��ǣ�"<<objGetInfo.GetSum()<<endl;
	cout<<"���ֵ��"<<objGetInfo.GetMax()<<endl;
	cout<<"��Сֵ��"<<objGetInfo.GetMin()<<endl;
	
	system("PAUSE");
	return 0; 
}