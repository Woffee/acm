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

int a[305];
int b[305];
int c[305];
int n;

int main()
{
    //freopen("in_c.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }
        b[1]=1;
        for(int i=2;i<=n;++i)
        {
            if(a[i]>a[i-1])
            {
                b[i]=b[i-1]+1;
            }
            else if(a[i]==a[i-1])
            {
                b[i]=b[i-1];
            }
            else
            {
                b[i]=1;
            }
        }
        c[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>a[i+1])
            {
                c[i]=c[i+1]+1;
            }
            else if(a[i]==a[i+1])
            {
                c[i]=c[i+1];
            }
            else
            {
                c[i]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            ans += max(b[i],c[i]);
        }
        printf("%d\n",ans);
    }

    return 0;
}

