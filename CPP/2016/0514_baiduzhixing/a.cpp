/*
Problem :
Status  :AC

这道题目，官方的数据范围有误。

如果超出范围，输出上一次的结果。

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
const int mod=9973;

const int maxn = 1e6+5;

char str[1000000+5];
int sum[maxn<<2];
int index;
int len;

void PushUP(int rt)
{
    sum[rt] =( sum[rt<<1] * sum[rt<<1|1] )%mod;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt] = str[index++]-28;
    }

    if (l == r) return ;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 1;
    if (L <= m) ret = (ret * query(L , R , lson) )%mod ;
    if (R > m) ret = (ret* query(L , R , rson) ) %mod;
    //printf("ret==%d\n",ret);
    return ret;
}

int main()
{
    //freopen("in_a.txt","r",stdin);
    int n,a,b;
    int ans = 0;
    while (~scanf("%d",&n))
    {
        index=0;
        scanf("%s",&str);
        len = strlen(str);
        build(1 , len  , 1);

        int a,b;
        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&a,&b);
            if(a>=1 && a<=len && 1<=b && b<=len) ans = query(a,b,1,len,1);
            printf("%d\n", query(a,b,1,len,1) );
        }


    }

    return 0;
}

