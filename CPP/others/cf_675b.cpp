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

int n,a,b,c,d;
ll ans;
int mp[3][3];

void print_mp()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool ok(int v)
{

    mp[0][0]=v;
    if( v<=0 || v >n )return 0;

    mp[0][2]=v+b-c;
    if( mp[0][2]<=0 || mp[0][2]>n )return 0;

    mp[2][0]=v+a-d;
    if( mp[2][0]<=0 || mp[2][0]>n )return 0;

    mp[2][2]=v+a+b-c-d;
    if( mp[2][2]<=0 || mp[2][2]>n )return 0;


    //print_mp();
    return 1;

}

int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF )
    {
        memset(mp,0,sizeof mp);
        scanf("%d%d%d%d",&a,&b,&c,&d);
        mp[0][1]=a;
        mp[1][0]=b;
        mp[1][2]=c;
        mp[2][1]=d;

        ans =0;
        for(int i=1; i<=n; ++i)
        {
            if(  ok(i) )ans++;
        }
        printf("%I64d\n",ans*n);
    }
    return 0;
}

