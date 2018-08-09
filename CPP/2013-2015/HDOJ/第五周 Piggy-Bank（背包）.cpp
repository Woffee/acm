/*
Piggy-Bank

http://acm.hdu.edu.cn/showproblem.php?pid=1114

背包

给出n种面值的硬币，每种面值的硬币有一定的重量， 
给出存钱罐的净重和存钱罐装满的重量， 
要求求出存钱罐里最少有多少钱
注：必须装满存钱罐，否则输出 This is impossible.

*/
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;

const int MAX = 10050;
int P[MAX],W[MAX];//P is the value of coins, W is the weight of coins
int dp[MAX];
int main()
{
	int t;
	int e,f,n,p,w,temp;
	cin>>t;
	while(t--)
	{
		cin>>e>>f>>n;
		for(int i=0;i<n;++i)
		{
			cin>>P[i]>>W[i];
		}//get data

		temp=f-e;

		dp[0]=0;
		for(int i=1;i<=temp;i++)  
        {  
            dp[i]=999999999;  
        } //reset

        for(int i=0;i<n;i++)  
            for(int m=W[i];m<=temp;m++)  
                if(dp[m-W[i]]+P[i]<dp[m])  
                    dp[m]=dp[m-W[i]]+P[i];
        
        if(dp[temp]==999999999)
        	cout<<"This is impossible."<<endl;
        else 
        	cout<<"The minimum amount of money in the piggy-bank is "<<dp[temp]<<"."<<endl;
	}
	return 0;
}
