/*
	uva572.cpp: Oil Deposits
	http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19435
	2014.10.14
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
#define MAXN 101
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int m,n;
void dfs(int x,int y){
	if(x<0 || x>=m || y<0 ||y>=n)return;
	if(mat[x][y]!='@' || vis[x][y] )return;

	vis[x][y]=1;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);             dfs(x,y+1);
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}
int main()
{
	while(scanf("%d %d%*c",&m,&n) && m && n){  
		//init
		memset(mat,0,sizeof(mat));
		memset(vis,0,sizeof(vis));

		//get data
		for(int i=0; i<m; ++i)  
	        gets(mat[i]); 

	    //doit
		int count=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(!vis[i][j] && mat[i][j]=='@'){count++;dfs(i,j);}
		printf("%d\n", count);
	}
}