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

int t,n;

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans = -inf;
        int a;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a);
            ans = max(ans,a);
        }
        printf("%d\n",ans);
    }

    return 0;
}
