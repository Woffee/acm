/*
Problem:
Status :AC
By WF,
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
typedef unsigned long long ull;
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=1e6+5;

int n,m;
char mp[105][105];
bool vis[105][105];

int dir[4][2]= {-1,0,1,0,0,-1,0,1};
int dir2[4][2][2]=
{
    -2,-1,
    -2,1,
    2,-1,
    2,1,
    -1,-2,
    1,-2,
    -1,2,
    1,2

};

struct point
{
    int x,y;
    int step;
};

point mystart,myend;

//bool ok(int nx,int ny)
//{
//    if(nx<1 || nx>n)return 0;
//    if(ny<1 || ny>m)return 0;
//    if(mp[nx][ny]==1)return 0;
//    return 1;
//}

queue<point>q;

int bfs()
{
    while(!q.empty() )
    {
        q.pop();
    }
    point now,next;
    now.x=mystart.x;
    now.y=mystart.y;
    now.step = 0;

    //printf("now:%d,%d\n",now.x,now.y);
    vis[now.x][now.y]=1;
    q.push(now);


    while( !q.empty() )
    {
        now = q.front();
        q.pop();

        //printf("now:%d,%d \n",now.x,now.y);

        if(now.x == myend.x && now.y == myend.y)
        {
            if(now.step==0)return -1;
            return now.step;
        }

        for(int i=0; i<4; ++i)
        {
            int nx = now.x + dir[i][0];
            int ny = now.y + dir[i][1];

            if( nx<1 || nx>n )continue;
            if( ny<1 || ny>m )continue;
            if( mp[nx][ny]=='#')continue;


            for(int j=0; j<2; ++j)
            {
                int nnx = now.x + dir2[i][j][0];
                int nny = now.y + dir2[i][j][1];

                if( nnx<1 || nnx>n )continue;
                if( nny<1 || nny>m )continue;
                if( mp[nnx][nny]=='#')continue;
                if( vis[nnx][nny])continue;

                next.x=nnx;
                next.y=nny;
                next.step=now.step+1;
                vis[next.x][next.y]=1;
                //next.lastx=now.x;
                //next.lasty=now.y;
                q.push(next);

            }
        }
    }
    return -1;
}


int main()
{
    //freopen("in_b.txt","r",stdin);
    while(cin>>n>>m)
    {
        mystart.x = -1;
        mystart.y = -1;
        myend.x = -1;
        myend.y = -1;

        char ch;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                cin>>mp[i][j];

                if(mp[i][j]=='s')
                {
                    mystart.x=i;
                    mystart.y=j;
                    mystart.step=0;
                    //mp[i][j]=0;
                }
                else if(mp[i][j]=='e')
                {
                    myend.x=i;
                    myend.y=j;
                    myend.step=0;
                    //mp[i][j]=0;
                }

            }
        }

        if(mystart.x == -1 || mystart.y == -1)
        {
            cout<<-1<<endl;
            continue;
        }
        memset(vis,0,sizeof vis);
        cout<<bfs()<<endl;
    }
    return 0;
}
