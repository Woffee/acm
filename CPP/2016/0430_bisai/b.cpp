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
const int maxn=5000+5;


int n;
int a[maxn];

bool vis[maxn];

int main()
{
    //freopen("in_b.txt","r",stdin);
    //while(cin>>n)
    memset(vis,0,sizeof vis);
    cin>>n;
    int num = 0;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        if( a[i]<=n && !vis[ a[i] ])
        {
            num++;
        }
        vis[ a[i] ]=1;
    }


    //cout<<num<<" ";
    cout<<n-num<<endl;


    return 0;
}

