/*
Dividing
http://acm.hdu.edu.cn/showproblem.php?pid=1059
题意：有一些被划分为1-6价值的石头，并已知每个价值有多少块，求可否将石头分成两份且价值相等。
思路：求出总价值，除2。转化为大小为（总价值/2）的背包可否恰好装满的问题。
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
const int MAX=444444;
int dp[MAX];
int c[MAX],w[MAX];
int v;

void ZeroOnePack(int cost,int wei)//01
{
    int i;
    for(i = v;i>=cost;i--)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void CompletePack(int cost,int wei)//完全
{
    int i;
    for(i = cost;i<=v;i++)
    {
        dp[i] = max(dp[i],dp[i-cost]+wei);
    }
}

void MultiplePack(int cost,int wei,int cnt)//多重
{
    if(v<=cnt*cost)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(cost,wei);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=cnt)
        {
            ZeroOnePack(k*cost,k*wei);
            cnt = cnt-k;
            k = 2*k;
        }
        ZeroOnePack(cnt*cost,cnt*wei);
    }
}

int main()
{
    int num[7]={0};
    int i,j,k;
    int num_case=1;
    while(1){
    	v=0;
    	for(i=1;i<=6;i++){
    		cin>>num[i];
    		v+=num[i]*i;
    	}
    	if(!v)break;
	if(v & 1){
		printf("Collection #%d:\n",num_case++);
		printf("Can't be divided.\n\n");
		continue;
	}

	memset(dp, 0, sizeof(dp));

    	int halfv=v/2;
	
    	for(i=1;i<=6;i++){
    		MultiplePack(i,i,num[i]);
    	}
    	cout<<"Collection #"<<num_case++<<":"<<endl;
    	if(dp[halfv]==halfv)cout<<"Can be divided."<<endl;
    	else cout<<"Can't be divided."<<endl;
    	cout<<endl;
    }
    return 0;
}
