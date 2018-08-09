#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout<<setw(4)<<"*";
	for(int i=1;i<=9;i++)
		cout<<setw(4)<<i;
	cout<<endl;
	for(int x=1;x<=40;x++)
		cout<<"-";
	cout<<endl;

	for (int m=1;m<=9;m++)
	{
		cout<<setw(4)<<m;
		for (int n=1;n<=9;n++)
			cout<<setw(4)<<m*n;
		cout<<endl;
	}
	return 0;
}