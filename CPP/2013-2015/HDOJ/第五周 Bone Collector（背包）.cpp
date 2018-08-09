/*
Bone Collector    

http://acm.hdu.edu.cn/showproblem.php?pid=2602

赤裸裸的 01背包问题
*/
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>  
using namespace std;

int value[1005],dp[1005],volume[1005]; 

int main()
{
    int t;
    int n,v;
    int i,j;
    cin>>t;
    while(t--)
    {
    	cin>>n>>v;
        for(i = 1; i<=n; i++)
            scanf("%d",&value[i]);
        for(i = 1; i<=n; i++)
            scanf("%d",&volume[i]);
        
        memset(dp,0,sizeof(dp));

        for (i=1;i<=n;i++)
        {
    		for (j=v;j>=volume[i];j--)
	        		dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
        }
		printf("%d\n",dp[v]); 
    }
    return 0;
}


