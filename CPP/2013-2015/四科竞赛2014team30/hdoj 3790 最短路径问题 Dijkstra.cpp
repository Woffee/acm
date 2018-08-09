/*
    AC:YES. 
    Made by myself
    2014.12.18
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;
const int MAXN=3000;
const int INF=10000000;
int map[MAXN][MAXN];
int val[MAXN][MAXN];
int dis[MAXN];
int mon[MAXN];
int n,m;
void Dijkstra(int v0){
    bool S[MAXN];
    for(int i=1;i<=n;++i){
        dis[i]=map[v0][i];
        mon[i]=val[v0][i];
        S[i]=false;
    }
    dis[v0]=0;
    mon[v0]=0;
    S[v0]=true;
    for(int i=1;i<=n;++i){
        int Mindist=INF;
        int u=v0;
        for(int j=1;j<=n;++j){
            if((!S[j]) && dis[j]<Mindist){
                u=j;
                Mindist=dis[j];
            }
        }
        if(Mindist==INF)break;
        S[u]=true;
        for(int j=1;j<=n;++j){
            if((!S[j] && map[u][j] <INF)){
                if(dis[u]+map[u][j]<dis[j]){
                    dis[j]=dis[u]+map[u][j];
                    mon[j]=mon[u]+val[u][j];
                }
                else if( (dis[u]+map[u][j])==dis[j] && (mon[u]+val[u][j])<mon[j] ){
                    mon[j]=mon[u]+val[u][j];
                }
            }
        }
    }
}

int main(){
    //freopen("4.txt","r",stdin);

    int a,b,d,p,s,t;
    while(scanf("%d %d",&n,&m) ){
        memset (dis,0,sizeof dis);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                map[i][j]=INF;
                val[i][j]=INF;
            }
        }
        if(n==0 && m==0)break;
        for(int i=0;i<m;i++){
            scanf("%d %d %d %d",&a,&b,&d,&p);
            if(map[a][b]>d){
                map[a][b]=map[b][a]=d;
                val[a][b]=val[b][a]=p;
            }
            if(map[a][b]==d && val[a][b]>p)
                val[a][b]=val[b][a]=p;
        }
        scanf("%d %d",&s,&t);
        Dijkstra(s);
        printf("%d %d\n",dis[t],mon[t]);
    }
    //fclose(stdin);
    return 0;
}
