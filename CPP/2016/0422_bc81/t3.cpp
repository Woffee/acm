/*
Title :
Status:
By wf,
cao，原创，AC了，真开心
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
#define FOR(i,s,t) for(int i = (s) ; i "= (t) ; ++i )

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const int mod = 1e9 + 7;

int t;
int n;
int dp[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<maxn;++i)
    {
        if( i%2==0 )
        {
            dp[i] =((dp[i-1]-1)*i%mod + 3)%mod;
        }
        else
        {
            dp[i] =((dp[i-1]-1)*i%mod + 1)%mod;
        }
    }
    for(int i=1;i<=10;++i)
    {
        printf("%d ",dp[i]);
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
        //printf("%d\n",ans );

    }
    return 0;
}


