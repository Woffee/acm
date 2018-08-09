#include <iostream>
using namespace std;
int main()
{
	int w[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char y[12]={"10X98765432"};
	char a[19];
	int sum=0,ans;
	int i,t;

	cin>>a;
	for(i=0;i<17;++i)
	{
		t=(a[i]-48);
		sum+=w[i]*(a[i]-48);
	}
	ans=sum%11;

	cout<<"Last= "<<y[ans]<<endl;
	if(y[ans]==a[17])cout<<"Right"<<endl;
	else cout<<"Wrong"<<endl;
}