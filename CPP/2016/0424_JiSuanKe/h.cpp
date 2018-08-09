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

int dianti[5][50];
int ans[5];
int n,x;
int t;


int main()
{
    //freopen("in_h.txt","r",stdin);
    while(scanf("%d%d",&n,&x)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&dianti[i][0]);
        }
        for(int i=0;i<n;++i)
        {
            ans[i] = abs(x - dianti[i][0])*5;
            scanf("%d",&t);
            for(int j=1;j<=t;++j)
            {
                scanf("%d",&dianti[i][j]);
                if( dianti[i][0] < x )
                {
                    if( dianti[i][0] <dianti[i][j] && dianti[i][j]<x )
                    {
                        ans[i] += 15;
                    }
                }
                else if ( x <dianti[i][0] )
                {
                    if( x < dianti[i][j] && dianti[i][j]<dianti[i][0] )
                    {
                        ans[i] += 15;
                    }
                }
            }
        }
        bool first = 1;
        for(int i=0;i<n;++i)
        {
            if(first)
            {
                printf("%d",ans[i]);
                first=false;
            }

            else printf(" %d",ans[i]);
        }
        if(n)printf("\n");
    }

    return 0;
}

