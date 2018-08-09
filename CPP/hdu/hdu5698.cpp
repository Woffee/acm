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
const int mod = 1000000007;

int n,m;

//求ax = 1( mod m) 的x值，就是逆元(0<a<m)
ll inv(long long a,long long m)
{
    if(a == 1)return 1;
    return inv(m%a,m)*(m-m/a)%m;
}

//a<=b
ll C(int a,int b)
{
    ll t1=1,t2=1;
    for(int i = b ; i>=(b-a+1) ;i--)t1 = t1*i%mod;
    for(int i = a ; i>=1       ;i--)t2 = t2*i%mod;
    return t1*inv(t2,mod)%mod;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        if(n>m)swap(n,m);
        printf("%I64d\n", C(m-2,n+m-4) );
    }
    return 0;
}
