/*
Title :
Status:
By wf,2016.04.22
头一次这样处理矩阵，AC了，真开心
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
#define FOR(i,s,t) for(int i = (s) ; i "= (t) ; ++i )

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1005;

int t;
int n,m,q;
int a[maxn][maxn];

int locrow[maxn];
int loccol[maxn];
int addrow[maxn];
int addcol[maxn];


int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;++i)
        {
            locrow[i]=i;
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int j=1;j<=m;++j)loccol[j]=j;

        memset(addrow,0,sizeof addrow);
        memset(addcol,0,sizeof addcol);

        int o,x,y;
        for(int i=0;i<q;++i)
        {
            scanf("%d%d%d",&o,&x,&y);
            switch (o)
            {
            case 1:
                swap(locrow[x],locrow[y]);
                break;

            case 2:
                swap(loccol[x],loccol[y]);
                break;

            case 3:
                addrow[ locrow[x] ]+=y;
                break;

            case 4:
                addcol[ loccol[x] ]+=y;
                break;

            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                int x = locrow[i];
                int y = loccol[j];
                int add = addrow[x]+addcol[y];

                //printf("x==%d,y==%d,add==%d\n",x,y,add);

                if(j==1)
                {
                    printf("%d",a[x][y]+add);
                }
                else
                {
                    printf(" %d",a[x][y]+add);
                }
            }
            printf("\n");
        }

        //printf("%d\n",ans );

    }
    return 0;
}
