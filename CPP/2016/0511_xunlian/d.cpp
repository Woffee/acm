/*
Problem :
Status  :

1.在第i点把油加满，直到用完都没能找到比i点价格便宜的，那么果断加满，开到下一点去；
2.在第i点把油加满，用完之前能够找到比i点便宜的点，或者是到达终点，
那么只要将油加到能到达这个点即可，然后直接到达这个点。最后，把每个点所需油费加起来即可。


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
int n;
ll cap;

struct Route
{
    ll miles,consume,price;
};


bool cmp(Route a,Route b)
{
    return a.price < b.price;
}


Route routes[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        bool ok = true;

        scanf("%d %lld",&n,&cap);
        for(int i=0;i<n;++i)
        {
            scanf("%lld%lld%lld",&routes[i].miles,&routes[i].consume,&routes[i].price);

            if( routes[i].miles * routes[i].consume > cap )
            {
                ok=false;
            }
        }
        if(!ok)
        {
            printf("Impossible\n");
            continue;
        }

        ll ans = 0,gas = 0;
        int i=0,j=0;
        while(i<n)
        {
            j = i+1;

            //临时耗油量
            int tmp_gas = routes[i].miles * routes[i].consume;

            while( j<n && routes[j].price >= routes[i].price && cap-tmp_gas >= routes[j].consume*routes[j].miles )
            {
                tmp_gas+=routes[j].consume*routes[j].miles;
                j++;
            }
            if( j>=n || routes[j].price < routes[i].price )
            {
                if( gas > tmp_gas ) gas-=tmp_gas;
                else
                {
                    ans += routes[i].price * (tmp_gas-gas);
                    //printf("add:%d\n",routes[i].price * (tmp_gas-gas));
                    gas = 0;
                }
                i = j;
            }
            else
            {
                ans += (cap-gas)*routes[i].price;
                //printf("add:%d\n", (cap-gas)*routes[i].price );
                gas = cap - routes[i].consume * routes[i].miles;
                i++;
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}

