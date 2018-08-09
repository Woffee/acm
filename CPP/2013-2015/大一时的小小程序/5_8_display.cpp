#include <iostream>
using namespace std;
void diaplay(double);
void diaplay(int);
void diaplay(char);
int main()
{
	double d=3.14159;
	float f=3.14;
	int i=3;
	char c='p';
	short s=3;
	diaplay(d);
	diaplay(f);
	diaplay(i);
	diaplay(c);
	diaplay(s);
	return 0;
}
void diaplay(double n)
{
	cout<<"A double:"<<n<<endl;
}
void diaplay(int n)
{
	cout<<"A int:"<<n<<endl;
}
void diaplay(char n)
{
	cout<<"A double:"<<n<<endl;
}