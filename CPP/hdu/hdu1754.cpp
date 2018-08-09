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
const int maxn=200000+5;

int n,m;

int tree[maxn<<2];

void pushUp(int rt)
{
    tree[rt] = max( tree[rt<<1] , tree[rt<<1|1] );
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        //tree[rt]=a[l];
        scanf("%d",&tree[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
void update(int index,int value,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=value;
        return;
    }
    int m = (l+r)>>1;
    if(index<=m)update(index,value,lson);
    else update(index,value,rson);
    pushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if( L<=l && r<=R )
    {
        return tree[rt];
    }
    int m = (l+r)>>1;
    int ret = -inf;
    if( L<=m )ret= max(ret, query( L, R,lson) );
    if( m<R) ret=max(ret, query( L, R,rson) );
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        char ch[5];//如果定义为"char ch;"会超内存。
        int x,y;
        for(int i=0;i<m;++i)
        {
            scanf("%s %d %d",ch,&x,&y);
            if(ch[0]=='Q')
            {
                printf("%d\n",query(x,y,1,n,1));
            }
            else if(ch[0]=='U')
            {
                update(x,y,1,n,1);
            }
        }
    }

    return 0;
}
