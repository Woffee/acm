#include "iostream"
using namespace std;
int main()
{
	int s,a=0,b=0,c=0;
	cin>>s;
	if(s%3!=0&&s%5!=0&&s%7!=0)cout<<"它不能被3，5，7中任何一个整除。";
	else cout<<"它能被其中 ";
	if(s%3==0)cout<<"3 ";
	if(s%5==0)cout<<"5 ";
	if(s%7==0)cout<<"7 ";
	cout<<"整除.";
	return 0;
}
