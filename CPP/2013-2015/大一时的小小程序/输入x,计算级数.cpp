#include <iostream>
using namespace std;
int main()
{
	double x;
	cin>>x;
	double s=1,item,last_item,z=1,m=1;
	for(int n=1;;n++)
	{
		m=1;
		z=1;
		for(int i=1;i<=n;i++)z*=x;
		for(int i=1;i<=n;i++)m*=i;
		item=z/m;
		if(n>3){if(item<0.00000001) break;}
		
		if(n%2==0)s-=item;
		else s+=item;
		cout<<item<<endl;
	}
	cout<<"s="<<s;
	return 0;
}


