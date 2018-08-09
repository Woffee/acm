/*
Problem :
Status  :

By wf,

壙扮隆頼撹。。。。。。。。。。。。。。。。。
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

int n,m;
int mp[10][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    while( scanf("%d%d",&n,&m)!=EOF  )
    {
        string str;
        for(int i=0;i<n;++i)
        {
            cin>>str;
            for(int j=0;j<m;++j)
            {
                if( str[j]=='E' )
                {
                    mp[i][j]=1;
                }
                else
                {
                    mp[i][j]=0;
                }
            }
        }


    }
    return 0;
}

