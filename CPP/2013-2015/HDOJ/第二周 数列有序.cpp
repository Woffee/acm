/*
Title:数列有序! 
wf原创  一次性通过
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int num[105];
int main()
{
	
	int n,m;
	while(cin>>n>>m && n && m )
	{
		
		int i=0;
		while(i<n)
		{
			cin>>num[i];
			++i;
		}
		i=0;
		int index;
		while(i<n)
		{
			if(num[i]>=m)
			{
				index=i;
				break;
			}
			++i;
		}
		for( i = 0;i < index; i++)
            printf("%d ",num[i]);
        printf("%d ",m);
        for( i = index;i < n-1; i++)
            printf("%d ",num[i]);
        printf("%d\n",num[n-1]);
	}

	return 0;
}
