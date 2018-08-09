
#include <algorithm>  
#include <iostream>
#include <iomanip>    
#include <fstream>     
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>
#include <time.h>      
using namespace std; 

const int MAXSIZE= 1000010;
int color[MAXSIZE]={0};
int vis[30]={0};
/*inline int Max(int x1,int y1)
{
    return (x1) > (y1) ? (x1) : (y1);
}
typedef struct {
    int max ;
    int left, right ;
} NODE ;

int     n, m ;
int     num [MAXSIZE] ;
NODE    tree[MAXSIZE * 20] ;

// 构建线段树
int build (int root, int left, int right)
{
    int mid ;

    // 当前节点所表示的区间
    tree[root].left     = left ;
    tree[root].right    = right ;

    // 左右区间相同，则此节点为叶子，max 应储存对应某个学生的值
    if (left == right)
    {
        return tree[root].max = num[left] ;
    }
    mid = (left + right) / 2 ;

    // 递归建立左右子树，并从子树中获得最大值
    int a, b ;
    a = build (2 * root, left, mid) ;
    b = build (2 * root + 1, mid + 1, right) ;

    return tree[root].max = Max (a, b) ;
}

// 从节点 root 开始，查找 left 和 right 之间的最大值
int Find (int root, int left, int right)
{
    int mid ;
    // 若此区间与 root 所管理的区间无交集
    if (tree[root].left > right || tree[root].right < left)
        return 0 ;
    // 若此区间包含 root 所管理的区间
    if (left <= tree[root].left && tree[root].right <= right)
        return tree[root].max ;

    // 若此区间与 root 所管理的区间部分相交

    int a, b ;  // 不能这样 max (find(...), find(...));
    a = Find (2 * root, left, right) ;
    b = Find (2 * root + 1, left, right) ;

    return Max (a, b) ;
}

// 更新 pos 点的值
int update (int root, int pos, int val)
{
    // 若 pos 不存在于 root 所管理的区间内
    if (pos < tree[root].left || tree[root].right < pos)
        return tree[root].max ;

    // 若 root 正好是一个符合条件的叶子
    if (tree[root].left == pos && tree[root].right == pos)
        return tree[root].max = val ;

    // 否则。。。。

    int a, b ;  // 不能这样 Max (find(...), find(...));
    a = update (2 * root, pos, val) ;
    b = update (2 * root + 1, pos, val) ;

    tree[root].max = Max (a, b) ;

    return tree[root].max ;
}
*/
void update(int a,int b,int c){
    for(int i=a;i<=b;i++){
        color[i]=c;
    }
}
void output(int a,int b){
    bool t=true;
    for(int i=a;i<=b;i++){
        vis[color[i]]=1;
    }
    for(int i=1;i<30;i++){
        if(vis[i]){
            if(t)
                //cout<<i;
                printf("%d",i);
            else
                printf(" %d",i);
            t=false;
        }
    }
    cout<<endl;
    memset(vis,0,sizeof(vis));
}
int main ()
{
    char c ;
    int i ;
    int n, m ;
    while (cin>>n>>m )
    {
        //build (1, 1, n) ;
        memset(color,0,sizeof(color));
        char cmd;
        for (i = 1 ; i <= m ; ++i){
            scanf("%c ",&cmd);
            int a,b,c;
            if(cmd=='P'){
                //cin>>a>>b>>c;
                scanf("%d %d %d",&a,&b,&c);
                update(a,b,c);
            }
            else{
                //cin>>a>>b;
                scanf("%d %d",&a,&b);
                output(a,b);
            }
        }
        

    }
    return 0 ;
}
