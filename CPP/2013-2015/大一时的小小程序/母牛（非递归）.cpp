#include <iostream>
using namespace std;
int main()
{
	int m=0;    //母牛
	int n1=1;   //一岁小牛
	int n2=0;   //二岁小牛
	int n3=0;   //三岁小牛
	int p=0;    //四岁小牛

	int n,s;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		p=n3;
		n3=n2;
		n2=n1;
		m+=p;
		n1=m;
		s=m+n1+n2+n3;
	}
	cout<<s<<endl;
	return 0;
}
