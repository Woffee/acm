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
const int maxn=8000+5;

int a[ maxn ];
int num[ maxn<<1 ];

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&a[i]);
        }
        bool first = 1;
        for(int i=1; i<=n; ++i)
        {
            memset(num,0,sizeof num);
            int ans=0;
            int mx=0;
            int mi=0;
            for(int j=i; j>=1; --j)
            {
                if(a[j]<a[i])
                {
                    mi++;
                }
                else if(a[j]>a[i])
                {
                    mx++;
                }
                num[mx-mi+maxn]++;
            }
            mx=mi=0;
            for(int j=i; j<=n; ++j)
            {
                if(a[j]<a[i])
                {
                    mi++;
                }
                else if(a[j]>a[i])
                {
                    mx++;
                }
                ans+=num[mi-mx+maxn];
            }
            if(first)first=0;
            else printf(" ");
            printf("%d",ans);
        }
        printf("\n");
    }
    return 0;
}

