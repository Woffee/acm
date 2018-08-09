/*
ˮ����Ŀ DFS
http://acm.nyist.net/JudgeOnline/problem.php?pid=27
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB
�Ѷȣ�4

����һ����0��1��ɵĶ�ά��ͼ��1��ʾ�˴���ˮ�أ�0��ʾ�˴��ǵ��棬���1�����������ĸ�λ�û���1��
��������Ϊһ��ˮ�ء�
���ˮ�ظ�����

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




