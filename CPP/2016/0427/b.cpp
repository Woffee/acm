/*
Problem :
Status  :

By wf,
*/

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
const int maxn=2e6+5;

int dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    int a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0;i<maxn;++i)
        {
            if(dp[i])
            {
                if(i+a<maxn) dp[i+a]=1;
                if(i+b<maxn) dp[i+b]=1;
                if(i+c<maxn) dp[i+c]=1;
                if(i+d<maxn) dp[i+d]=1;
            }
        }
        int mmax=-1,ans=0;
        for(int i=0;i<=1000000;++i)
        {
            if(dp[i]==0)
            {
                ans++;
                mmax=max(mmax,i);
            }
        }
        for(int i=1000000+1;i<2e6;++i)
        {
            if(dp[i]==0)
            {
                mmax=max(mmax,i);
            }
        }
        if(mmax>1000000)mmax=-1;
        printf("%d\n%d\n",ans,mmax);
    }


    return 0;
}

