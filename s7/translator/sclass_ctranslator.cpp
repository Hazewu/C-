#include"sclass_ctranslator.h"

//���������ʵ��
void CTranslator::SkipSapces(){           //�����հף������ո��Ʊ�������з��� 
	char ch=fin.get();                    //�����ַ�
	while(isspace(ch)){
		ch=fin.get();                     //��chΪ�հ���ѭ�� 
	} 
	fin.putback(ch);                      //���ǿ��ַ�ch���������� 
} 

bool CTranslator::GetToken(string &token){//��ȡ��� 
	char ch,ch1;                          //���ڽ����ַ�
	static bool traceIndent=true;         //�Ƿ�׷�������ַ���
	
	token="";                             //�ñ��tokenΪ�մ�
	ch=fin.get();                         //��������finȡ���ַ�
	if(fin.eof()){                
		return false;                     //�ļ��ѽ���������false 
	} 
	
	if(isspace(ch)&&ch!='\n'){
		//����հ״�
		while(isspace(ch)&&ch!='\n'){
			//ѭ������հ��ַ�
			token+=ch;                    //��ch׷�ӵ���־token��ĩβ
			if(traceIndent){
				indent+=ch;               //ch׷�ӵ������ַ�ĩβ 
			} 
			ch=fin.get();                 //��������finȡ���ַ�
			if(fin.eof()){
				return false;             //�ļ��ѽ���������false 
			} 
		} 
		fin.putback(ch);                  //���ǿհ��ַ�ch����������
		return true;                      //�ļ�δ��������true 
	}
	
	if(ch=='\n'){
		//���з�
		indent="";                        //�����հ״��ÿ�
		traceIndent=true;                 //��ʼ׷�������ַ��� 
	}else{
		traceIndent=false;                //�����ǿհ��ַ�������׷�������ַ��� 
	}
	
	if(isalpha(ch)||ch=='_'){
		//��ʶ������ĸ���»��߿�ʼ
		while(isalpha(ch)||isdigit(ch)||ch=='_'){
			//��ʶ���ɰ�����ĸ�����ֻ��»���
			token+=ch;                    //��ch׷�ӵ����token��ĩβ
			ch=fin.get();                 //��������finȡ���ַ�
			if(fin.eof()){
				return false;             //�ļ��ѽ���������false 
			} 
		} 
		fin.putback(ch);                  //���Ǳ�ʶ���ַ�ch�ͻ�������
		return true;                      //�ļ�δ����������true 
	}
	
	if(isdigit(ch)){
		//�����ֿ�ʼ����ֵ
		while(isdigit(ch)||ch=='.'||ch=='e'||ch=='+'||ch=='-'){
			//��ֵ�ɰ������֡�С���㡢��ĸe��������
			token+=ch;                    //��ch׷�ӵ����token��ĩβ
			ch=fin.get();                 //��������finȡ���ַ�
			if(fin.eof()){
				return false;             //�ļ��ѽ����������ַ� 
			} 
		}
		fin.putback(ch);              //������ֵ�ַ�ch����������
		return true;                  //�ļ�δ����������false   
	}
	
	if(ch=='/'){
		//����//��
		ch1=fin.get();                //��������finȡ���ַ�
		if(fin.eof()){
			cout<<"�ļ��쳣������"<<endl;
			exit(1);
		} 
		
		if(ch1=='/'){
			//��ʾ��//��
			token+=ch;                //��ch�����ַ���/����׷�ӵ����token��ĩβ
			token+=ch1;               //��ch�����ַ���/����׷�ӵ����token��ĩβ
			return true;              //�ļ�δ����������true 
		}else{
			fin.putback(ch1);         //��ch1���͵�������fin 
		}
	}
	
	if(ch=='/'){
		//����/*��
		ch1=fin.get();                //��������finȡ���ַ�
		if(fin.eof()){
			cout<<"�ļ��쳣������"<<endl;
			exit(2);
		} 
		
		if(ch1=='*'){
			//��ʾ��/*��
			token+=ch;                //��ch�����ַ���/����׷�ӵ����token��ĩβ
			token+=ch1;               //��ch1�����ַ���*����׷�ӵ����token��ĩβ
			return true;              //�ļ�δ����������true 
		}
		else fin.putback(ch1);        //��ch1���͵�������fin 
	}
	
	if(ch=='*'){
		//����*/��
		ch1=fin.get();                //��������finȡ���ַ�
		if(fin.eof()){
			cout<<"�ļ��쳣������"<<endl;
			exit(3);
		} 
		
		if(ch1=='/'){
			//��ʾ��*/��
			token+=ch;                //��ch�����ַ���*����׷�ӵ����token��ĩβ
			token+=ch1;               //��ch1�����ַ���/����׷�ӵ����token��ĩβ
			return true;              //�ļ�δ����������true 
		}else{
			fin.putback(ch1);        //��ch1���͵�������fin 
		}
	}
	token+=ch;                        //�����������ch��Ϊ���
	return true;                      //�ļ�δ����������true 
}

string CTranslator::IntToStr(int i){  //������iת��Ϊ����Ϊ4�Ĵ� 
	char str[5];                      //��ʱ��
	
	if(i<=0||i>9999){
		cout<<"����������Χ��"<<endl;
		exit(4); 
	} 
	str[4]='\0';                      //��������
	for(int pos=3;pos>=0;pos--){
		//���ν���λ���ִ��봮str��
		str[pos]=i%10+'0';            //��i�ĸ�λ����ת��Ϊ�ַ������str[pos]��
		i=i/10;                       //��iȥ����λ���ֺ����������i 
	} 
	return str;                       //���ش� 
}

void CTranslator::ForEach()            //����foreachѭ��
//���磺
//foreach(double v in a)
//ת��Ϊ
//int _i0001=0;
//for(double v=a[0];
//    -i0001<sizeof(a)/sizeof(a[0]);
//    -i0001++,v=a[i0001])
{
    static int counter=0;             //������
	string token;                    //���
	string forVarName="_i"+IntToStr(++counter); 
	                                 //forѭ������������_i0001��_i9999��
	string typeName,arrayName;       //��������������
	
	//��ȡ�����Ϣ�������ȡ��foreach(double v in a)���еġ�(double v in a)��
	SkipSapces();                    //�����հף������ո��Ʊ�������з��� 
	GetToken(token);                 //��ȡ��ǣ�ӦΪ��(����
	if(token!="("){
		cout<<"ӦΪ("<<endl;
		exit(5);
	} 
	
	SkipSapces();
	GetToken(token);                 //��ȡ��ǣ������������硰v����
	string varName=token;            //�����������硰v����
	
	SkipSapces();
	GetToken(token);                 //��ȡ��ǣ�ӦΪ��in����
	if(token!="in"){                 
		cout<<"ӦΪin"<<endl;
		exit(6);
	} 
	GetToken(token);                 //��ȡ��ǣ�ӦΪ�����������硰a����
	arrayName=token;                 //�����������硰a����
	
	SkipSapces();
	GetToken(token);                 //��ȡ��ǣ�ӦΪ��)����
	if(token!=")"){
		cout<<"ӦΪ)"<<endl;
		exit(7); 
	} 
	
	//��������Ϣ
	fout<<"int "<<forVarName<<"=0;"<<endl;         //���ڶ�����������磺int _i0001=0;��
	fout<<indent<<"for("<<typeName<<" "
	    <<varName<<"="<<arrayName<<"[0];"<<endl;
	    //���磺for(double v=a[0]
	fout<<indent<<'\t'<<forVarName<<"sizeof("<<arrayName
	    <<")/sizeof("<<arrayName<<"[0]);"<<endl;   //�������forѭ����2��
		//���磺-i0001<sizeof(a)/sizeof(a[0]);
	fout<<indent<<'\t'<<forVarName<<"++,"<<varName
	    <<"="<<arrayName<<"["<<forVarName<<"])";   //�������forѭ����3��
		//���磺-i0001++,v=a[i0001]) 
}

CTranslator::CTranslator(const string &infName,const string &outfName):
	fin(infName.c_str()),fout(outfName.c_str()),indent(""){               //���캯�� 
	
	if(fin.fail()){
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(8);
	}	
	if(fout.fail()){
		cout<<"���ļ�ʧ�ܣ�"<<endl;
		exit(9);
	}
}

void CTranslator::Run(){              //���������� 
	string token;                     //��Ǵ�
	while(GetToken(token)){
		//�����ļ�δ����
		if(token=="//"){
			//������//��ʼ��ע��
			do{
				fout<<token;          //������
				if(!GetToken(token)){ //��ȡ�±�� 
					return ;              
				}
			}while(token!="\n");      //��ǲ��ǻ��У���ѭ��
			fout<<token;              //������ı�ǣ������з�����ʾ�ԡ�//����ʼ��ע�����ѽ���  
		} 
		else if(token=="/*"){
			//������/*��ʼ��ע��
			do{
				fout<<token;          //������
				if(!GetToken(token)){ //��ȡ�±�ǣ������ļ��������׳��쳣 
					cout<<"�ļ��쳣���"<<endl;
					exit(10);        
				} 
			}while(token!="*/");      //��ǲ�Ϊ��*/������ѭ��
			fout<<token;              //������ı�ǡ�*/�� 
		} 
		else if(token=="\""){
			//������\"��ʼ���ַ���
			do{
				fout<<token;          //������
				if(!GetToken(token)){ //��ȡ�±�ǣ������ļ��������׳��쳣 
					cout<<"�ļ��쳣���"<<endl;
					exit(11);
				} 
			}while(token!="\"");      //��ǲ�Ϊ��\"������δ��������ѭ��
			fout<<token;              //������ı�ǡ�\"�� 
		}
		else if(token=="foreach"){
			ForEach();                //����foreachѭ�� 
		}
		else{
			cout<<token;              //���һ��ı�� 
		}
	} 
}
