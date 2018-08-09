
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

int t,n,m;
int a,b;

int aa[maxn];
int loc[maxn];


int main()
{
    freopen("in_6.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(aa,0,sizeof aa);
        memset(loc,0,sizeof loc);

        int index = 1;
        for(int i=n;i>=1;--i)
        {
            loc[i]=index++;
        }
        int tmp = n;
        for(int i=1;i<=n;++i)
        {
            aa[i]=tmp--;
        }

        while(m--)
        {
            scanf("%d %d",&a,&b);
            if( a < b )
            {
                int tmp = index-1;
                while( tmp>0 && aa[tmp] < b && aa[tmp]!=a )
                {
                    aa[tmp+1] = aa[tmp];
                    loc[ aa[tmp]  ] = tmp +1;
                    tmp --;
                }

                aa [ loc[b] ]  = 0;

                aa[tmp+1] = b;
                loc[b]=tmp+1;
                index++;
            }
        }
        tmp = inf;
        ll ans = 0;
        //printf("aa:");
        for(int i=1;i<index;++i)
        {
            //printf("%d ",aa[i]);
            if( aa[i] )
            {
                tmp = min(aa[i],tmp);
                ans +=tmp;
            }
        }
        //printf("\n");

        printf("%I64d\n",ans);
    }

    return 0;
}
