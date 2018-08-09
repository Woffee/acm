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
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;
const int mod = 1e9 +7;

//从右开始顺时针
int dir4[4][2]= {0,1,1,0,0,-1,-1,0};
int dir8[8][2]= {0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};

int n;


int lisan[maxn<<1];
int lsum[maxn<<1];
int rsum[maxn<<1];

struct Ship
{
    int x,y,h,d;
    int l,r;
    bool see()
    {
        return (y-x) <= (h<<1) ;
    }
} ship[10000+5];

int main()
{
    //freopen("in_3.txt","r",stdin);
    int t;
    scanf("%d",&t);
    for(int ii=1; ii<=t; ii++)
    {
        printf("Case #%d:\n",ii);

        memset(lsum,0,sizeof lsum);
        memset(rsum,0,sizeof rsum);

        scanf("%d",&n);
        int index = 0;

        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&ship[i].x,&ship[i].y,&ship[i].h,&ship[i].d);
            if( !ship[i].see() )
            {
                //printf("cant see:%d\n",i);
                continue;
            }

            ship[i].l = ship[i].y-ship[i].h;
            ship[i].r = ship[i].x+ship[i].h;

            lisan[index++] = ship[i].l;
            lisan[index++] = ship[i].r;
        }

        sort(lisan,lisan+index);

        int mm=1;
        for(int i=1;i<index;++i)
        {
            if( lisan[i]!=lisan[i-1] )
            {
                lisan[mm++]=lisan[i];
            }
        }

        for(int i=0;i<n;++i)
        {
            if( !ship[i].see() )
            {
                //printf("cant see:%d\n",i);
                continue;
            }

            int l = lower_bound(lisan,lisan+mm,ship[i].l) - lisan;
            int r = lower_bound(lisan,lisan+mm,ship[i].r) - lisan;

            if( ship[i].d==1 ) //right
            {
                rsum[l] ++;
                rsum[r+1]--;
            }
            else
            {
                lsum[l] ++;
                lsum[r+1]--;
            }
        }

        for(int i=1 ;i<mm;++i)
        {
            rsum[i] +=rsum[i-1];
            lsum[i] +=lsum[i-1];
        }

        int rm = 0,ans=0;
        for(int i=0;i<mm;++i)
        {
            rm = max(rm,rsum[i]);
            ans = max(ans,rm+lsum[i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}