#include "iostream"
using namespace std;
int main()
{
	int s,a=0,b=0,c=0;
	cin>>s;
	if(s%3!=0&&s%5!=0&&s%7!=0)cout<<"�����ܱ�3��5��7���κ�һ��������";
	else cout<<"���ܱ����� ";
	if(s%3==0)cout<<"3 ";
	if(s%5==0)cout<<"5 ";
	if(s%7==0)cout<<"7 ";
	cout<<"����.";
	return 0;
}
