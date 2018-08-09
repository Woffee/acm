/*
	  ID:hdoj2084
	http://acm.hdu.edu.cn/showproblem.php?pid=2084
	DATA:2014.10.24
*/

#include <cstdio>
#include <cstring>
int t,n,num[101][101],dp[101][101];
int f(int a,int b){
	if(a<2 || a>n || b<1 || b>n)return 0;
	if(b==1)return num[a][b]+dp[a-1][1];
	if(a==b)return num[a][b]+dp[a-1][b-1];
	if(dp[a-1][b-1]>dp[a-1][b]) return num[a][b]+dp[a-1][b-1];
	else return num[a][b]+dp[a-1][b];
}
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j)
				scanf("%d",&num[i][j]);
		}

		dp[1][1]=num[1][1];
		for(int i=2;i<=n;++i){
			for(int j=1;j<=i;++j){
				dp[i][j]=f(i,j);
			}
		}

		int max=0;
		for(int i=1;i<=n;++i){
			max=dp[n][i]>max?dp[n][i]:max;
		}
		printf("%d\n",max );
	}	
}