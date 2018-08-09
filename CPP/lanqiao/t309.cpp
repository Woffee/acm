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

priority_queue<int,vector<int>,greater<int> >q;
bool vis[1500];

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;++i)
    {
        q.push(i);
        vis[i]=0;
    }

    char cmd[20];
    int id,newid;

    while(n--)
    {
        scanf("%s",&cmd);
        switch( cmd[0] )
        {
        case 'N':
             newid = q.top();
            q.pop();
            vis[newid]=1;

            printf("%d\n", newid );
            break;
        case 'D':
             id;
            scanf("%d",&id);

            if( vis[id]==0 )
            {
                printf("Failed\n");
            }
            else
            {
                vis[id]=1;
                q.push(id);
                printf("Successful\n");
            }

            break;
        }
    }
    return 0;
}
