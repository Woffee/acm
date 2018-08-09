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

int n;
int a[maxn];
bool vis[maxn];
int ans ;

vector <int> vc[maxn];

int Gcd(int a,int b)
{
    int rem;
    while(b > 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;

}

bool bfs_vis[maxn];
void Bfs(int rt,int u,int deep)
{
    //cout<<"bfs:"<<u<<endl;
    if( vc[u].empty() )return;
    int num = vc[u].size();
    for(int i=0; i<num; ++i)
    {
        int v = vc[u][i];
        if( !vis[ v ] && !bfs_vis[v]  && rt!=v   )
        {

            if( Gcd( a[rt] , a[ v ] )==1 )
            {
                //printf("rt==%d,u==%d,v==%d,deep==%d\n",rt,u,v,deep);
                ans += deep;
            }
        }
        if( !bfs_vis[v] )
        {
            bfs_vis[v]=1;
            Bfs(rt, v , deep+1 );
            bfs_vis[v]=0;
        }

    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    memset(vis,0,sizeof vis);
    memset(bfs_vis,0,sizeof bfs_vis);
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    int u,v;
    for(int i=1; i<n; ++i)
    {
        cin>>u>>v;
        vc[u].push_back(v);
        vc[v].push_back(u);
    }

    ans = 0;
    for(int i=1; i<=n; ++i)
    {
        bfs_vis[i]=1;
        Bfs( i,i,1 );
        bfs_vis[i]=0;
        vis[i]=1;
    }
    cout<<ans<<endl;
    return 0;
}
