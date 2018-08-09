/*
Wiskey 的眼神
http://acm.hdu.edu.cn/showproblem.php?pid=1577
竟然是大公约数问题
2014.8.27
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 

int l,sx,sy,px,py;
int gcd(int a,int b)
{ 
	int temp;
	if(a<b)
	{
	/*交换两个数，使大数放在a上*/
	temp=a;
	a=b;
	b=temp;
	}
	while(b!=0)
	{
	/*利用辗除法，直到b为0为止*/
	temp=a%b;
	a=b;
	b=temp;
	}
	return a;
}
int see()
{
	if(abs(px)>l || abs(py)>l)
		return 0;

	int x,y;
	x=abs(sx-px);  
    y=abs(sy-py); 
    if(gcd(x,y)==1)
		return 1;
	else 
		return 2;
}


int main()
{
	while(cin>>l && l){
		cin>>sx>>sy>>px>>py;
		if( see()==0 )
			cout<<"Out Of Range"<<endl;
		else if(see()==1)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}
}