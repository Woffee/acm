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

const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+5;

int n,m;
ll a[20];
int num[20];

ll s,t;

int cal(ll aa,ll bb)
{
    //n=6;
    int ret=0;
    for(int i=0;i<n;++i)
    {
        if( ((1<<i)&aa) == ((1<<i)&bb) )
        {
            ret++;
        }
    }
    //cout<<ret<<endl;
    return ret;
}
ll getnum(ll aa)
{
    ll ret = 0;
    int i=0;
    while(aa>0)
    {
        if(aa&1)
        {
            ret=ret|( 1<<i );
        }
        aa = aa>>1;
        i++;
    }
    return ret;
}

int main()
{
    freopen("in_e.txt","r",stdin);
    //cout<<cal(20,60)<<endl;
    while(cin>>n>>m)
    {
        s = inf;
        t = -1;
        for(int i=0;i<m;++i)
        {
            cin>>a[i]>>num[i];
            a[i]=getnum(a[i]);
            s=min(s,a[i]);
            t=max(t,a[i]);
        }
        int ans=0;
        cout<<s<<":"<<t<<endl;
        for(ll i=s;i<=t;++i)
        {
           // cout<<"i:"<<i<<endl;
            bool ok=1;
            for(int j=0;j<m;++j)
            {
                if( cal(i,a[j]) != num[j] )
                {
                    ok=0;
                    break;
                }
            }
            if(ok)ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}

