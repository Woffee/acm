#include <iostream>
using namespace std;
int main()
{
	int m=0;    //ĸţ
	int n1=1;   //һ��Сţ
	int n2=0;   //����Сţ
	int n3=0;   //����Сţ
	int p=0;    //����Сţ

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
