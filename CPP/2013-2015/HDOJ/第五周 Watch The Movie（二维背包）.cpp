/*
Watch The Movie
http://acm.hdu.edu.cn/showproblem.php?pid=3496

题意：输入N，M，V 从 N 个 movies 中选择 M 个movies 是使得价值最大。

背包问题
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



const int MAX=1005;
int dp[MAX][MAX];
int c[MAX],w[MAX];
int inf=999999;
int main()
{
    int t;
    int n,m,l;
    int i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l;

        for(i=0;i<n;++i){
            cin>>c[i]>>w[i];
        }

        for(i=0;i<=m;i++)  
            for(j=0;j<=l;j++)  
            {  
                if(i==0)  
                    dp[i][j]=0;  
                else  
                    dp[i][j]=-inf; //注意初始化为负无穷，价值可能是负值  
            }  

        for(i=0;i<n;++i)
            for(j=m;j>=1;j--)
                for(k=l;k>=c[i];k--)
                    dp[j][k]=max(dp[j][k],dp[j-1][k-c[i]]+w[i]);
        if(dp[m][l]<0)  
            dp[m][l]=0;  
        printf("%d\n",dp[m][l]);  
    }
    return 0;
}
