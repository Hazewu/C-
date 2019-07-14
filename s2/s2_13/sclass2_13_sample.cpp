#include"sclass2_13_sample.h"

int main(){
    CSample s1(10);
    CSample s2(20);
    CSample s3;
    s3.Add(s1,s2);                                //结果返回给s3
    cout<<"s3.n="<<s3.GetN();
    return 0;
}
