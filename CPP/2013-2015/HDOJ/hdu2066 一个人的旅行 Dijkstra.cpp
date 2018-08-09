/*
    Name:一个人的旅行
    Http://acm.hdu.edu.cn/showproblem.php?pid=2066
    AC? :yes
    Date:2015.1.22
*/
 
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std; 

const int INF=10000000;
const int MAXN=1000;
int t,s,d,a,b,time,ans=0,num=0;

int arr[MAXN];
int fav[MAXN];
int dis[MAXN];
int map[MAXN][MAXN];

int dijkstra(int v0){
    bool s[MAXN];
    memset(s,0,sizeof s);
    for(int i=1;i<=num;i++){
        dis[i]=map[v0][i];
    }
    dis[v0]=0;
    s[v0]=true;
    for(int i=1;i<=num;i++){
        int Mindist=INF;
        int u=v0;
        for(int j=1;j<=num;j++){
            if((!s[j]) && dis[j]<Mindist){
                u=j;
                Mindist=dis[j];
            }
        }
        if(Mindist==INF)break;
        s[u]=true;
        for(int j=1;j<=num;j++){
            if((!s[j] )){
                if(dis[u]+map[u][j]<dis[j]){
                    dis[j]=dis[u]+map[u][j];
                }
            }
        }

    }
    int min=INF;
    for(int i=1;i<=d;i++){
        if(min>dis[fav[i]])min=dis[fav[i]];
    }
    return min;
}

int main()
{
    while (cin>>t>>s>>d && t && s && d){
        for(int i=0;i<MAXN;++i)
            for(int j=0;j<MAXN;++j)
                map[i][j]=INF;
        num=0;
        for(int i=0;i<t;i++){
            cin>>a>>b>>time;
            if(time<map[a][b])map[a][b]=map[b][a]=time;
            if(num<a)num=a;
            if(num<b)num=b;
        }
        
        for(int i=1;i<=s;++i)cin>>arr[i];
        for(int i=1;i<=d;++i)cin>>fav[i];
        ans=INF;
        for(int i=1;i<=s;++i){
            int temp = dijkstra(arr[i]);
            ans = ans <temp ? ans:temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}