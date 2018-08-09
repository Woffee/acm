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

struct point
{
    int x,y;
};

char mp[10][10];
bool vis[10][10];
int step[10][10];
point K,P;

queue<point>q;
void bfs()
{
    while(!q.empty())
    {
        q.pop();
    }

    point now=K,next;

}

int main()
{
    freopen("in.txt","r",stdin);
//    for(int i=0; i<10; ++i)
//    {
//        for(int j=0; j<10; ++j)
//        {
//            mp[i][j]='$';
//        }
//    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1; i<=8; ++i)
        {
            scanf("%s",&mp[i][1]);
        }
//        for(int i=0; i<10; ++i)
//        {
//            for(int j=0; j<10; ++j)
//            {
//                printf("%c",mp[i][j]);
//            }
//            printf("\n");
//        }
        scanf("%d %d",&K.x,&K.y);
        scanf("%d %d",&P.x,&P.y);

        bfs();
    }

    return 0;
}

