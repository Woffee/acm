/*
小明系列故事--买年货 三维01背包
HDOJ4501 && 腾讯2013编程马拉松第1场第二题

有个商店，小明有n件物品想买，可以用钱或积分，由于是会员，还能免费拿走k件
问怎样选择价值最大

2014.8.26
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
int n,v1,v2,v3;
int dp[101][101][101];
int max(int a,int b){
  if(a>b)
    return a;
  return b;
}
void beibao(int m,int s,int v){//三维0/1背包
	for(int i=v1;i>=0;i--){//注意此处跟背包的不一样，如果写成i>=v1,j>=v2,k>=1,则是需要三个同时成立
		for(int j=v2;j>=0;j--){//写成>=0,然后再用if判断则可以达到三者其中之一成立就可以购买
			for(int k=v3;k>=0;k--){
				int temp=0;
				if(i>=m)temp = max(temp,dp[i-m][j][k]+v);
				if(j>=s)temp = max(temp,dp[i][j-s][k]+v);
				if(k>0)temp = max(temp,dp[i][j][k-1]+v);
				dp[i][j][k] = max(temp,dp[i][j][k]);
			}
		}
	}

}

using namespace std; 

int main()
{
	
	int money,score,value;
	while(cin>>n>>v1>>v2>>v3){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>money>>score>>value;
			beibao(money,score,value);
		}
		cout<<dp[v1][v2][v3]<<endl;
	}
}