//Free DIY Tour
/*
坐飞机旅游，给你n个城市，及它们的魅力值，还有航班路线。
从杭州出发，也从杭州结束，输出怎么走能获得最大魅力值。

有点像TSP问题，但是这题已经告诉我们会把最终回来到1的那点看成是n+1点。
所以直接当作是求1～n+1的最长路即可。这题还要保存路径。
用单源最短路算法或者用我刚刚学到的Floyd记录路径方法均可。
输出时需要注意，当输出n+1时要把它变成输出1.
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

int i,j,k;
int vip[105]= {0};
int map[105][105]= {0};
int dp[105];
int pre[105];

void output( int x )
{
    if ( x == -1)
        return;
    output(pre[x]);
    printf("%d->",x);
}
int main()
{
    int t;
    int n,m;
    int a,b;
    int ct=1;//case number
    cin>>t;
    while(t--) {
        //init
        cin>>n;
        for ( i = 1; i <= n+1; i++)
            for( j = 1; j <= n+1; j++)
                map[i][j] = -1;
        memset(dp,0,sizeof(dp));

        //get data
        for(j=1; j<=n; j++) {
            cin>>vip[j];
        }
        vip[n+1]=0;
        cin>>m;
        for(j=1; j<=m; j++) {
            cin>>a>>b;
            map[a][b]=vip[b];
        }

        pre[1] = -1;
        for ( i = 1; i <= n + 1; i++) {
            for ( j = 1; j < i; j++) {
                if(map[j][i]!=-1 && dp[j] + map[j][i] > dp[i] ) {
                    dp[i] = dp[j] + map[j][i];
                    pre[i] = j;
                }
            }
        }

        //cout
        if(ct!=1)
            cout<<endl;
        cout<<"CASE "<<ct++<<"#"<<endl;
        cout<<"points : "<<dp[n+1]<<endl;
        cout<<"circuit : ";
        output(pre[n+1]);
        cout<<"1"<<endl;
    }
    return 0;
}
