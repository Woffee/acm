/*
Nightmare
���⣺��n��m�ĵ�ͼ�ϣ�0��ʾǽ��1��ʾ�յأ�2��ʾ�ˣ�3��ʾĿ�ĵأ�4��ʾ�ж�ʱը����������
��ʱը����ʱ����6������һ������Ҫ��ʱ����1��ÿ�ο����ϡ��¡������ƶ�һ��
�����ߵ�4ʱ���ը����ʱ�䲻��0�����������趨ը����ʱ��Ϊ6��������ߵ�3��ը����ʱ�䲻Ϊ0ʱ���ɹ��߳���
���˴�2�ߵ�3�����ʱ�䡣

�������ÿ����㶼�ǿ����ظ����ʵģ�����ʵ��ը�����õ㲻Ҫ�ظ���
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
