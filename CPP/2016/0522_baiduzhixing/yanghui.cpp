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
const int mod = 1e9+7;
int n,m;

long long inv(long long a,long long b)
{
    if(a == 1)return 1;
    return inv(b%a,b)*(b-b/a)%b;
}

ll f(int n,int m)
{
    ll a=1;
    ll b=1;
    for(int i=1; i<=m; ++i)
    {
        a = a*(n-i+1)%mod;
        b = b*i%mod;
    }
    ll ret=a*inv(b,mod)%mod;
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if( n>m )swap(n,m);
        //printf("%d %d\n",n,m);
        if(n==1&&m==1)
        {
            printf("1\n");
            continue;
        }
        if(n==1||m==1)
        {
            printf("0\n");
            continue;
        }

        int N  =  n+m-3  , M;
        if(N%2==0)
        {
            M= N/2-1-abs(n-m)/2;
        }
        else
        {
            M= N/2-abs(n-m)/2;
        }
        N--;
        printf("%I64d\n" , f(N,M) );

    }
    return 0;
}
