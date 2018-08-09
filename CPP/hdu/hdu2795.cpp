/*
Problem :http://acm.hdu.edu.cn/showproblem.php?pid=2795
Status  :AC

By wf,2016.04.26
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
const int maxn=2e5+5;

int h,w,n;
int tree[maxn<<2]; //注意不是maxn

void pushUp(int rt)
{
    tree[rt] = max ( tree[rt<<1],tree[rt<<1|1] );
}

void build(int l,int r,int rt)
{
    tree[rt]=w;
    if(l==r)
    {

        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
}

int query(int x,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]-=x;//注意是rt，不是l
        //printf("query ret: %d\n",l);
        return l;
    }
    int m = (l+r)>>1;
    int ret;
    if( tree[rt<<1]>=x )
    {
        ret = query(x,lson);
    }
    else
    {
        ret = query(x,rson);
    }
    pushUp(rt);
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        if(h>n)h=n; // !!
        build(1,h,1);
        int l;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&l);
            if( tree[1] < l )
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",query(l,1,h,1));
            }
        }
    }

    return 0;
}

