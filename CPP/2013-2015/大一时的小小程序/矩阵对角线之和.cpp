#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[5][5]={1,2,3,4,5,
		         1,2,3,4,5,
		         1,2,3,4,5,
		         1,2,3,4,5,
		         1,2,3,4,6};
	int sum=0;
	int sum2=0;
	cout<<"Defualt:\n";
	for(int m=0;m<5;m++)
	{
		for(int n=0;n<5;n++)cout<<setw(4)<<a[m][n];
		cout<<endl;
	}
	for(int i=0;i<5;i++)
	{
		sum+=a[i][i];
		sum2+=a[i][4-i];
	}
	cout<<"\\对角线:"<<sum<<endl
	    <<"/对角线:"<<sum2<<endl;
	return 0;
}

