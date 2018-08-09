
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
const int maxn=1e5+5;

int t;
int x,k,c;
ll m;

int xh[maxn];

int f()
{
    int remainder=0;
    for(ll i=0; i<m  ;i++)
    {
        remainder=( (long long) remainder*10 + x )%k;
    }
    return remainder;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int ii=1;ii<=t;++ii)
    {
        printf("Case #%d:\n",ii);
        scanf("%d %I64d %d %d",&x,&m,&k,&c);
        m = m % k;
        if( f()==c )
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }

    return 0;
}
