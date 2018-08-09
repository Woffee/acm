/*
水池数目 DFS
http://acm.nyist.net/JudgeOnline/problem.php?pid=27
时间限制：3000 ms  |  内存限制：65535 KB
难度：4

给你一个由0和1组成的二维地图，1表示此处是水池，0表示此处是地面，如果1的上下左右四个位置还是1，
则它们视为一个水池。
输出水池个数。

2014.9.1
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
int m,n;
void dfs(int x,int y)
{
    if(x>0 && y>0 && x<=m && y <=n && map[x][y]==1){
	map[x][y]=0;
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
    }
    else
	return;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
		cin>>m>>n;
		memset(map,0,sizeof(map));
		for(int i=1;i<=m;i++){
		    for(int j=1;j<=n;j++){
			cin>>map[i][j];
		    }
		}
		
		int num=0;
		for(int i=1;i<=m;i++){
		    for(int j=1;j<=n;j++){
				if(map[i][j]==1){
				    dfs(i,j);
				    num++;
				}
		    }
		}

		cout<<num<<endl;
    }
    return 0;
}




