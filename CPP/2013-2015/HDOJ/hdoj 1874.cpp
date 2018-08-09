/*
    注意此题输入有重边
    Name:
    Http:
    AC? :Yes
    Date:2014.12.12
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
#include <time.h>  
using namespace std; 
const int MAXINT=10000000;
const int MAXN=205;
int map[MAXN][MAXN];
int dis[MAXN];
int pre[MAXN];
int main()
{
    int n,m,a,b,c,v0,v1;
    while(cin>>n>>m){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                map[i][j]=MAXINT;
            }
        }
        for(int i=0;i<m;++i){
            cin>>a>>b>>c;
            if(map[a][b] >c || map[b][a] > c)
                map[a][b]=map[b][a]=c;
        }
        cin>>v0>>v1;

        //Dijkstra
        bool S[MAXN];
        for(int i=0;i<n;++i){
            dis[i]=map[v0][i];
            S[i]=false;
            if(dis[i]==MAXINT)pre[i]=-1;
            else pre[i]=v0;
        }
        dis[v0]=0;
        S[v0]=true;
        for(int i=0;i<n;++i){
            int mindist=MAXINT;
            int u=v0;
            for(int j=0;j<n;++j){
                if((!S[j]) && dis[j]<mindist){
                    u=j;
                    mindist=dis[j];
                }
            }
            if(mindist==MAXINT)break;
            S[u]=true;
            for(int j=0;j<n;++j){
                if((!S[j] && map[u][j]<MAXINT)){
                    if(dis[u]+map[u][j]<dis[j]){
                        dis[j]=dis[u]+map[u][j];
                        pre[j]=u;
                    }
                }
            }
        }
        if(v0==v1)cout<<"0"<<endl;
        else if(dis[v1]<MAXINT)cout<<dis[v1]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}