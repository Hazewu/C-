#include <iostream>

class Number {
	public:
		Number(int n,int scale);//���캯�� 
		int converto(int scale);//ת������ 
		void show();//չʾ 
	private:
		int num;
};

Number::Number(int n,int scale=10) {
	num=n;
}

int Number::converto(int scale) {
	int temp,i,newn=0,length;
	int a[20]={0};      //�������� 
	for(i=0;num>0;i++) {
		a[i]=num%scale;
		num=num/scale;
	}
	length=i;
	for(i=length;i>=0;i--)
	newn=newn*10+a[i];   //�µĽ����� 
	return newn;
}

void Number::show() {
	std::cout<<num<<std::endl;
}

int main() {
    int n, n1, n2;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cin >> n1 >> n2;
        Number no1(n1, 10);     //n1��10����������
        Number no3 = no1.converto(n2);  //no3��n2���Ƶ�������
        no3.show();     //������
    }
    return 0;
}

