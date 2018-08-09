/*
FATE 二维完全背包
2014.8.27
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

int n,m,k,s;//经验 忍耐 怪物种类数量 最多杀怪
int dp[105][105];
int Sco[105];//score
int Pat[105];//patience

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
void beibao() //三维01背包
{
    int i;
    for(i=1; i<=m; i++) { //忍耐
        for(int j=1; j<=k; j++) { //怪物种数
            for(int k=1; k<=s; k++) { //最多杀怪
                int cnt = 1;
                while(cnt*Pat[j]<=i && cnt<=k) {
                    dp[i][k] = max(dp[i][k],dp[ i-cnt*Pat[j] ][k-cnt]+cnt*Sco[j]);
                    cnt++;
                }
            }
        }
        if(dp[i][s]>=n)
            break;
    }
    if(i>m)
        cout<<"-1"<<endl;
    else
        cout<<m-i<<endl;
}

int main()
{

    while(cin>>n>>m>>k>>s) {
        memset(dp,0,sizeof(dp));
        int a,b;
        for(int i=1; i<=k; i++) {
            cin>>Sco[i]>>Pat[i];
        }
        beibao();
        //cout<<dp[m][s]<<endl;
    }
}
