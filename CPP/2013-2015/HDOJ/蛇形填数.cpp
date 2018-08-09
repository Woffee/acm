/*
南阳理工 蛇形填数

在n*n方阵里填入1,2,...,n*n,要求填成蛇形。例如n=4时方阵为：
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4

2014.8.28
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

int map[101][101];
int dir[4][2]={1,0,-1,0,0,1,0,-1};

int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
#endif
	int n,t,i,j;
	while(cin>>n){
		memset(map,0,sizeof(map));
		i=1;j=n;
		map[i][j]=1;
		t=2;
		while(1){
			while(i+1<=n && map[i+1][j]==0){
				i++;
				map[i][j]=t;
				t++;
			}
			while(j-1>0 && map[i][j-1]==0){
				j--;
				map[i][j]=t;
				t++;
			}
			while(i-1>0 && map[i-1][j]==0){
				i--;
				map[i][j]=t;
				t++;
			}
			while(j+1<=n && map[i][j+1]==0){
				j++;
				map[i][j]=t;
				t++;
			}
			if(t-1==n*n)
				break;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}
	}
	printf("Time used = %.2lf\n",(double)clock()/CLOCKS_PER_SEC );
}