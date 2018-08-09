#include <iostream>
using namespace std;
void fan(long int n);
int main()
{
	cout<<"\n  0<n<2147483647\nn:";
	double n;
	cin>>n;
	fan(n);
	return 0;
}
void fan(long int n)
{
	long int m=n/10;
	int s=n-m*10;
	cout<<s;
	if(n>9)fan(m);
}