/*
ACboy needs your help  分组背包
http://acm.hdu.edu.cn/showproblem.php?pid=1712

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
const int MAX=105;

int a[MAX][MAX];
int dp[MAX];

int main()
{
	int n,m;
	int i,v,k;
	while(cin>>n>>m && (n||m))
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]); 
		memset(dp,0,sizeof(dp));

		for(i=1;i<=n;i++)//n节课程
			for(v=m;v>=0;v--)
				for(k=1;k<=m;k++)//学习k天
					if(v-k>=0)
						dp[v]=max(dp[v],dp[v-k]+a[i][k]);

		cout<<dp[m]<<endl;

	}

}

