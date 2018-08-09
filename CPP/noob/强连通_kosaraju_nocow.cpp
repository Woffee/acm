/*Kosaraju算法的简单演示，使用邻接矩阵储存图 */
/*
	from:http://www.nocow.cn/index.php/Kosaraju%E7%AE%97%E6%B3%95
	title:Kosaraju's Algorithm
	author:JiangZX
	date:2011/8/18
*/
#include <iostream>
using namespace std;
const int MAXV = 1024;
int g[MAXV][MAXV], dfn[MAXV], num[MAXV], n, m, scc, cnt;
void dfs(int k)
{
	num[k] = 1;
	for(int i=1; i<=n; i++)
		if(g[k][i] && !num[i])
			dfs(i);
	dfn[++cnt] = k;					//记录第cnt个出栈的顶点为k 
}
void ndfs(int k)
{
	num[k] = scc;	 				//本次DFS染色的点，都属于同一个scc，用num数组做记录
	for(int i=1; i<=n; i++)
		if(g[i][k] && !num[i])		        //注意我们访问的原矩阵的对称矩阵 
			ndfs(i);
}
void kosaraju()
{
	int i, j;
	for(i=1; i<=n; i++)				//DFS求得拓扑排序 
		if(!num[i])
			dfs(i);
	memset(num, 0, sizeof num);		
	/*    我们本需对原图的边反向，但由于我们使用邻接矩阵储存图，所以反向的图的邻接矩阵 
	 即原图邻接矩阵的对角线对称矩阵，所以我们什么都不用做，只需访问对称矩阵即可*/ 
	for(i=n; i>=1; i--)
		if(!num[dfn[i]]){			//按照拓扑序进行第二次DFS 
			scc++;
			ndfs(dfn[i]); 
		}
	cout<<"Found: "<<scc<<endl;
}
int main()
{
	int i, j;
	cin>>n>>m;
	for(i=1; i<=m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = z;
	}
	kosaraju();
	return 0;
}