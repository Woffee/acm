
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

int Tmin[ maxn << 2 ];
int Tmax[ maxn << 2 ];

ll A[maxn];
int n;

ll ans [maxn];

int index;

void min_push_up(int rt)
{
    if( A[ Tmin[rt<<1] ] < A[ Tmin[rt<<1|1] ]  )
    {
        Tmin[rt] = Tmin[rt<<1];
    }
    else Tmin[rt] = Tmin[rt<<1|1];
}

void min_build(int l,int r,int rt)
{
    if( l==r )
    {
        Tmin[rt] = index++;
        return;
    }
    int m =(l+r)>>1;
    min_build(lson);
    min_build(rson);
    min_push_up(rt);
}

int min_query(int L,int R,int l,int r,int rt)
{
    if( L <= l && r <= R )
    {
        return Tmin[rt];
    }
    int m = (l+r)>>1;
    int ret1 = -1,ret2=-1;
    if( L<=m ) ret1 = min_query(L,R,lson);
    if( R>m )ret2 = min_query(L,R,rson);

    if( ret1==-1 )return ret2;
    if( ret2==-1 )return ret1;

    if(A[ret1] > A[ret2] )return ret2;
    return ret1;
}

//**************************************************

void max_push_up(int rt)
{
    if( A[ Tmax[rt<<1] ] >= A[ Tmax[rt<<1|1] ]  )
    {
        Tmax[rt] = Tmax[rt<<1];
    }
    else Tmax[rt] = Tmax[rt<<1|1];
}

void max_build(int l,int r,int rt)
{
    if( l==r )
    {
        Tmax[rt] = index++;
        return;
    }
    int m =(l+r)>>1;
    max_build(lson);
    max_build(rson);
    max_push_up(rt);
}

int max_query(int L,int R,int l,int r,int rt)
{
    if( L <= l && r <= R )
    {
        return Tmax[rt];
    }
    int m = (l+r)>>1;
    int ret1 = -1 , ret2 = -1;
    if( L<=m ) ret1 = max_query(L,R,lson);
    if( R>m )ret2 = max_query(L,R,rson);


    if( ret1==-1 )return ret2;
    if( ret2==-1 )return ret1;

    if(A[ret1] < A[ret2] )return ret2;
    return ret1;

}

// main code
void dfs(int l,int r,int n)
{
    if( r<l )return;
    int a = max_query(l,r,1,n,1);
    int b = min_query(l,r,1,n,1);

    if(a>b)swap(a,b);

    ll  d = A[a] * A[b];
    //printf("a==%d,b==%d,d==%I64d\n",a,b,d);
    for(int i = (b-a+1);i<=(r-l+1);++i  )
    {
        ans[i] = max( ans[i],d );
        //printf( "[%d,%d] ans[%d] = %I64d  (%d * %d)\n",l,r,i,ans[i],a,b);
    }
    if(A[b]>A[a])
    {
        dfs(a+1,r,n);
        dfs(l,a-1,n);
    }
    else
    {
        dfs(b+1,r,n);
        dfs(l,b-1,n);
    }

}


int main()
{
    //freopen("in.txt","r",stdin);
    while( scanf("%d",&n)!=EOF )
    {
        memset(Tmin,0,sizeof Tmin);
        memset(Tmax,0,sizeof Tmax);
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d",&A[i]);
        }

        //init
        memset(ans,0,sizeof ans);
        index = 1;
        min_build(1,n,1);
        index = 1;
        max_build(1,n,1);

        dfs(1,n,n);

        for(int i=1;i<=n;++i)
        {
            printf("%I64d\n",ans[i]);
        }

        //printf("Min:%d\n",min_query(1,n,1,n,1));
        //printf("Max:%d\n",max_query(1,n,1,n,1));


    }
    return 0;
}
