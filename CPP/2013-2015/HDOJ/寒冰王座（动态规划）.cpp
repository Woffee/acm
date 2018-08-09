/*
寒冰王座

你只有一张N元的钞票，商店不找零，尽最多购买以下物品：
血瓶150块一个,魔法药200块一个,无敌药水350块一个
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
int a[3]={150,200,350};
int dp[10005];

void ComPack(){
	for(int j=0; j<3; j++) { 
        for(int k=1; k<=10005; k++) { 
            int cnt = 1;
            while(cnt*a[j]<=k ) {
                dp[k] = max(dp[k],dp[ k-cnt*a[j] ]+cnt*a[j]);
                cnt++;
            } 
        }
    }
}

int main()
{
    int n;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));


        ComPack();
            

        cout<<n-dp[n]<<endl;
    }
}