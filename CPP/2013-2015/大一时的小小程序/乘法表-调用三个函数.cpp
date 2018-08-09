#include<iostream>
#include<iomanip>
void zuoxia();
void youshang();
void quan();
using namespace std;
int main()
{
	youshang();cout<<endl;
	zuoxia();cout<<endl;
	quan();cout<<endl;
	return 0;
}

void zuoxia()
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

		for (int n=1;n<=m;n++)
			cout<<setw(4)<<m*n;
		cout<<endl;
	}
}

void youshang()
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
			if(m>n)
				 cout<<setw(4)<<" ";
		    else cout<<setw(4)<<m*n;
		cout<<endl;
	}
}

void quan()
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
}
