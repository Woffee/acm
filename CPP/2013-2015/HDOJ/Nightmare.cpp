/*
Nightmare
题意：在n×m的地图上，0表示墙，1表示空地，2表示人，3表示目的地，4表示有定时炸弹重启器。
定时炸弹的时间是6，人走一步所需要的时间是1。每次可以上、下、左、右移动一格。
当人走到4时如果炸弹的时间不是0，可以重新设定炸弹的时间为6。如果人走到3而炸弹的时间不为0时，成功走出。
求人从2走到3的最短时间。

这个题中每个结点都是可以重复访问的，但其实，炸弹重置点不要重复走
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

const int MAX = 9;

int dir[4][2]={1,0,-1,0,0,1,0,-1};

int map[MAX][MAX],step[MAX][MAX],time[MAX][MAX];
int m,n,sx,sy,ans;

void dfs(int x,int y,int steps,int bomb_time){
	if(x<0 || y<0 || x>=m || y>=n)return;
	if(bomb_time<=0 || steps>=ans)return;//!!
	if(map[x][y]==0)return;
	if(map[x][y]==3){
		if(steps<ans){
			ans=steps;
		}
		return ;
	}
	if(map[x][y]==4)bomb_time=6;

	if(steps>=step[x][y] && time[x][y]>=bomb_time)
		return ;
	step[x][y]=steps;
	time[x][y]=bomb_time;
	int px,py;
	for(int i=0;i<4;i++){
		px=x+dir[i][0];
		py=y+dir[i][1];
		dfs(px,py,steps+1,bomb_time-1);
	}

}
int main()
{
	int t;
	cin>>t;
	while(t--){
		//get data
		cin>>m>>n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>map[i][j];
				time[i][j]=0;
				step[i][j]=100000;
				if(map[i][j]==2){
					sx=i;
					sy=j;
				}
			}
		}

		//dfs
		int bomb_time=6;
		int steps=0;
		ans=1000000;
		dfs(sx,sy,steps,bomb_time);
		
		if(ans==1000000)
			cout<<"-1"<<endl;
		else 
			cout<<ans<<endl;
	}
}
