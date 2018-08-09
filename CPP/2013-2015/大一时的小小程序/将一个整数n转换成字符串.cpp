#include <iostream>
using namespace std;
char ch[20];
int i=0;
void fan(long int n);
int main()
{
	double n;
	cin>>n;
	ch[i]='\"';
	i++;
	fan(n);
	ch[i]='\"';
	for(int t=i;t>=0;t--)
        cout<<ch[t];
	return 0;
}
void fan(long int n)
{
	long int m=n/10;
	int s=n-m*10+48;
	ch[i]=s;
	i++;
	if(n>9)fan(m);
}
