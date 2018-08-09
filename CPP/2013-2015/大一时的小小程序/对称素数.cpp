#include <iostream>
using namespace std;
int main()
{
	for(int i=100;i<=999;i++)
	{
		for(int m=2;m<=(i/2);m++)
		{
			if(i%m==0)break;
			if(m==(i/2))
				{
					int a,b,c;
	                
	                a=i/100;
	                b=(i-a*100)/10;
	                c=i-a*100-b*10;
					if(a==c)cout<<i<<endl;
				}
		}
		
	}
}