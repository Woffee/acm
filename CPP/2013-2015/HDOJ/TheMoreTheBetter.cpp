#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[208][208],map[208][208];
int num[208];
bool visited[208];
int N,M;

inline int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

void TreeDP(int father)
{
    visited[father]=true;           //第father号城市已访问过
    for(int i=1;i<=num[father];i++) //遍历以father为根节点的子节点
    {
        int son=map[father][i];
        if(!visited[son]) TreeDP(son);//递归遍历直至为叶子节点，然后返回
        for(int j=M;j>=2;j--)//j>=2的原因是输入a,b时j=1已经考虑进去了
            for(int k=1;k<j;k++)//拆分
            {
                if(dp[father][j-k]!=-1&&dp[son][k]!=-1)//是否可以进行拆分
                    dp[father][j]=max(dp[father][j],dp[father][j-k]+dp[son][k]);//由状态转移方程式得
            }
    }
}
int main()
{
    //dp[i][j]代表的是攻克包括第i号城市在内的共j座城市所获得的财富值
    int a,b;
    while(scanf("%d %d",&N,&M),N||M)//M原本代表ACBoy要攻打城市的个数，但为了方便森林变成数时更好统计就把M++，这样0号城市也纳入其中
    {
        memset(dp,-1,sizeof(dp));
        memset(num,0,sizeof(num));//num[father]表示以father为根节点的子节点个数有多少个
        dp[0][1]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d %d",&a,&b);
            dp[i][1]=b;         //攻打第i号城市的财富值
            map[a][++num[a]]=i; //构成一棵树,第0号城市为根节点
        }
        M++;
        for(int i=0;i<=N;i++)//初始化
         {
             dp[i][0]=0;
             visited[i]=false;
         }
        TreeDP(0);
        printf("%d\n",dp[0][M]);
    }

    return 0;
}
