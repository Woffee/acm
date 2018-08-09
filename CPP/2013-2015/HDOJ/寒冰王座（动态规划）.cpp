/*
��������

��ֻ��һ��NԪ�ĳ�Ʊ���̵겻���㣬����๺��������Ʒ��
Ѫƿ150��һ��,ħ��ҩ200��һ��,�޵�ҩˮ350��һ��
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