/*
Problem :http://acm.hdu.edu.cn/showproblem.php?pid=1166
Status  :AC

在接下来的几场比赛前，重新熟悉下线段树。

By wf,2016.04.23
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
const int maxn=5e4+5;

int t,n;
int a[maxn];

int tree[maxn<<2];

void pushUp(int rt)
{
    tree[rt] = tree[rt<<1] +tree[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=a[l];
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
        tree[rt]+=value;
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
    int ret=0;
    if( L<=m )ret+=query(L,R,lson);
    if( R>m)ret+=query(L,R,rson);
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    for(int ii=1;ii<=t;++ii)
    {
        //cout<<"Case "<<ii<<":"<<endl;
        printf("Case %d:\n",ii);
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }

        build(1,n,1);
        char cmd[10];
        while(scanf("%s",&cmd)!=EOF)
        {
            int x,y;
            if(cmd[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                //cout<<query(x,y,1,n,1)<<endl;
                printf("%d\n",query(x,y,1,n,1));
            }
            else if(cmd[0]=='A')
            {
                scanf("%d%d",&x,&y);
                update(x,y,1,n,1);
            }
            else if(cmd[0]=='S')
            {
                scanf("%d%d",&x,&y);
                update(x,-y,1,n,1);
            }
            else if(cmd[0]=='E')break;
        }
    }


    return 0;
}

