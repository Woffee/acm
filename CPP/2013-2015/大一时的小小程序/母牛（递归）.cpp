#include <iostream>
using namespace std;
int f(int n)
{
	if(n==1||n==2||n==3)return 1;
	return f(n-1)+f(n-3);
}
int main()
{
	int a;
	cin>>a;        //输入年份
	cout<<f(a);    //牛数
	return 0;
}
