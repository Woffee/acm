#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 111111;
bool hash[maxn];
int li[maxn] , ri[maxn];
int X[maxn*3];

int col[maxn<<4];
int cnt;

struct history{
    int start,end;
};

bool cmp(history a,history b)
{
    return a.start > b.start;
}

history a[maxn];


void PushDown(int rt)
{
    if (col[rt] != -1)
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        col[rt] = -1;
    }
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        col[rt] = c;
        return ;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) update(L , R , c , lson);
    if (m < R) update(L , R , c , rson);
}
void query(int l,int r,int rt)
{
    if (col[rt] != -1)
    {
        if (!hash[col[rt]]) cnt ++;
        hash[ col[rt] ] = true;
        return ;
    }
    if (l == r) return ;
    int m = (l + r) >> 1;
    query(lson);
    query(rson);
}
int Bin(int key,int n,int X[])
{
    int l = 0 , r = n - 1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (X[m] == key) return m;
        if (X[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main()
{
    //freopen("in_c.txt","r",stdin);

    int T , n;
    //scanf("%d",&T);
    T = 1;
    while (T --)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d %d",&a[i].start,&a[i].end);
        }
        sort(a,a+n,cmp);


        //scanf("%d",&n);
        int nn = 0;
        for (int i = 0 ; i < n ; i ++)
        {
            //scanf("%d%d",&li[i] , &ri[i]);
            li[i]=a[i].start;
            ri[i]=a[i].end;
            X[nn++] = li[i];
            X[nn++] = ri[i];
        }
        sort(X , X + nn);
        int m = 1;
        for (int i = 1 ; i < nn; i ++)
        {
            if (X[i] != X[i-1]) X[m ++] = X[i];
        }
        for (int i = m - 1 ; i > 0 ; i --)
        {
            if (X[i] != X[i-1] + 1) X[m ++] = X[i-1] + 1;
        }
        sort(X , X + m);
        memset(col , -1 , sizeof(col));
        for (int i = 0 ; i < n ; i ++)
        {
            int l = Bin(li[i] , m , X);
            int r = Bin(ri[i] , m , X);
            update(l , r , i , 0 , m , 1);
        }
        cnt = 0;
        memset(hash , false , sizeof(hash));
        query(0 , m , 1);
        printf("%d\n",n-cnt);
    }
    return 0;
}
