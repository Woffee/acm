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

using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

typedef long long ll;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e5+5;

int tree[maxn<<2];

void PushUP(int rt)
{
    tree[rt] = max(tree[rt<<1] , tree[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if (l == r)
    {
        //scanf("%d",&tree[rt]);
        //printf("build l==%d,Max[%d]==%d\n",l,rt,-1);
        tree[rt] = -1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt)
{
    if (l == r)
    {
        //更新的时候要取最大值
        tree[rt] = max(sc,tree[rt]);
        //printf("l==%d,Max[%d]==%d\n",l,rt,sc);
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(p , sc , lson);
    else update(p , sc , rson);
    PushUP(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return tree[rt];
    }
    int m = (l + r) >> 1;
    int ret = -inf;
    if (L <= m) ret = max(ret , query(L , R , lson));
    if (R > m) ret = max(ret , query(L , R , rson));
    return ret;
}

int n,q,t,v,a,b;


int main()
{
    freopen("in_a.txt","r",stdin);

    scanf("%d %d",&n,&q);

    build(1 , n , 1);

    for(int i=0; i<n; ++i)
    {
        scanf("%d %d",&t,&v);
        update(t,v,1,n,1);
    }
    for(int i=0; i<q; ++i)
    {
        scanf("%d %d",&a,&b);
        int ans = query(a , b , 1 , n , 1);
        if(ans != -1)printf("%d\n",ans);
        else printf("None\n");
    }
    return 0;
}
