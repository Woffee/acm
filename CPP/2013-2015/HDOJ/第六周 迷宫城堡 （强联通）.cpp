/*
迷宫城堡 （强联通）
http://acm.hdu.edu.cn/showproblem.php?pid=1269
*/
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std; 
#define maxn 10001
struct Edge
{
       int v,next;
} e[maxn*10],re[maxn*10];
bool visit[maxn];
int t[maxn],n,head[maxn],size,rhead[maxn];
void AddEdge(int a,int b)
{
     e[size].v=b;
     e[size].next=head[a];
     head[a]=size;
     re[size].v=a;//建立反向图。
     re[size].next=rhead[b];
     rhead[b]=size;
     size++;
}
void DFS1(int u,int&cnt)
{
     visit[u]=true;
     for(int i=head[u]; i!=-1; i=e[i].next){
          int v=e[i].v;
          if( !visit[v])
              DFS1(v,cnt);
     }
     t[++cnt]=u;
}
void DFS2(int u)
{
     visit[u]=true;
     for(int i=rhead[u]; i!=-1; i=re[i].next){
             int v=re[i].v;
             if( !visit[v])
                 DFS2(v);
     }
}
int main()
{
    int cnt,m,a,b,i;
    while( scanf("%d%d",&n,&m)){
           if( n==0&&m==0) break; 
           
           memset(head,-1,sizeof(head));
           memset(rhead,-1,sizeof(rhead));
           memset(e,0,sizeof(e));
           size=0;
           
           while( m--){
                  scanf("%d%d",&a,&b);
                  AddEdge(a,b);
           }
           
           memset(visit,false,sizeof(visit));
           memset(t,0,sizeof(t));
           for(cnt=0,i=1; i<=n; i++){ //正向DFS
                if( !visit[i])
                    DFS1(i,cnt);
           } 
                
           memset(visit,false,sizeof(visit));
           for(cnt=0,i=n; i>=1; i--){ //反向DFS
                if( !visit[t[i]]){
                    DFS2(t[i]);
                    cnt++;
                }
           }
          
           if( cnt==1)
               printf("Yes\n");
           else
               printf("No\n"); 
    }
    return 0;
}
