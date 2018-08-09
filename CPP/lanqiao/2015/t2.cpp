//´Ë¿ÓÒÑÆú

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

int a[22] = {2, 5, 9, 11, 16, 17, 19, 21, 22, 24, 26, 30, 31, 33, 35, 36 ,41 ,46, 47, 50, 52, 61};
int h[154];
bool vis[160];
int mp[160][160];
int N = 154;
stack <int>s;

void PrintMp()
{
    for(int i=0; i<N; ++i)
        {
            for(int j=0;j<N;++j)
            {
                printf("%d",mp[i][j]);
            }
            printf("\n");
        }
}

void Set(int x,int y,int len , int v)
{
    for(int i=x; i<x+len ;++i)
    {
        for(int j=y;j<y+len;++j)
        {
            mp[i][j]=v;
        }
    }
}

bool Add(int v)
{
    for(int i=0;i+v<N;++i)
    {
        for(int j=0;j+v<N;++j)
        {
            if( mp[i][j]==0 && mp[i+v-1][j+v-1]==0 )
            {
                //printf("i==%d,j==%d\n",i,j);
                Set(i,j,v,1);
                return true;
            }
        }
    }
    return false;
}

bool Ok()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0;j<N;++j)
        {
            if( mp[i][j]==0 )return false;
        }
    }
    return true;
}

void dfs()
{

    if( Ok()  )
    {
        printf("success\n");

        while(!s.empty())
        {
            printf("%d",s.top());
            s.pop();
        }

    }

    for(int i=0; i<22; ++i)
    {
        int v = a[i];
        if( !vis[v] )
        {
            if( Add(v) )
            {
                vis[v]=1;
                printf("%d\n",v);
                s.push(v);

                dfs();

                s.pop();
                vis[v]=0;
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    memset(h,0,sizeof h);
    memset(vis,0,sizeof vis);

    Add(47);
    vis[47]=1;
    Add(46);
    vis[46]=1;
    Add(61);
    vis[61]=1;

    PrintMp();

    dfs();


    return 0;
}
