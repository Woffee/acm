#include "algorithm"
#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "stack"
#include "cmath"
#include "queue"
#include "set"
#include "map"
 
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
 
typedef long long ll;
using namespace std;
 
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
 
int alltime,n;
struct P
{
    int time,attr;
}p[maxn];
 
bool cmp(P b, P c)
{
    return b.time<c.time;
}
 
struct Node
{
    int time;  //提交时间
    int attr;  //总吸引力
    int num;   //解决的题目数量
    int pena;  //总罚时
}dp[maxn];
 
void print_arr(int a[],int n)
{
    for(int i=0; i<n; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof dp);
 
        scanf("%d %d",&alltime,&n);
 
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&p[i].time);
        }
        //sort(mytime,mytime+n);
        //print_arr(time,n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&p[i].attr);
        }
 
        sort(p,p+n,cmp); // 不排序会错
 
        for(int i=0;i<n;++i)
        {
            for(int v = alltime;v>=0;v--)
            {
                if( v<p[i].time )continue;
 
                if( dp[v].attr < dp[ v-p[i].time ].attr + p[i].attr )
                {
                    dp[v].attr = dp[ v-p[i].time ].attr + p[i].attr;
                    dp[v].num = dp[ v-p[i].time ].num + 1;
                    dp[v].time = dp[ v-p[i].time ].time + p[i].time;
                    dp[v].pena = dp[ v-p[i].time ].pena + dp[v].time;
                }
                else if( dp[v].attr == dp[ v-p[i].time ].attr + p[i].attr )
                {
                    if( dp[v].num < dp[ v-p[i].time ].num +1 )
                    {
                        dp[v].num = dp[ v-p[i].time ].num +1;
                        dp[v].time = dp[ v-p[i].time ].time + p[i].time;
                        dp[v].pena = dp[ v-p[i].time ].pena + dp[v].time;
                    }
                    else if( dp[v].num == dp[ v-p[i].time ].num +1 )
                    {
                        if( dp[v].pena > dp[ v-p[i].time ].time + dp[ v-p[i].time ].pena  )
                        {
                            dp[v].time = dp[ v-p[i].time ].time + p[i].time;
                            dp[v].pena = dp[ v-p[i].time ].pena + dp[v].time;
                        }
                    }
                }
            }
        }
 
        int ans = alltime;
        for(int i = alltime-1 ;i>=0;i--)
        {
            if( dp[ans].attr < dp[i].attr )ans = i;
            else if( dp[ans].attr == dp[i].attr )
            {
                if( dp[ans].num < dp[i].num )ans = i;
                else if( dp[ans].num == dp[i].num )
                {
                    if( dp[ans].pena > dp[i].pena )ans=i;
                }
            }
        }
        printf("%d %d %d\n",dp[ans].attr,dp[ans].num,dp[ans].pena);
    }
    return 0;
}