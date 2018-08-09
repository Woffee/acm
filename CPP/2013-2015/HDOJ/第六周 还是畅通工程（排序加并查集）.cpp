/*
还是畅通工程

http://acm.hdu.edu.cn/showproblem.php?pid=1233

每行给出三个正整数，分别是两个村庄的编号，以及此两村庄间的距离。
对每个测试用例，在1行里输出最小的公路总长度。

本来是学到图才碰到的题目,结果还是用了并查集：
先按距离从小到大排序，然后合并村庄

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

using namespace std; 
const int MAX=1000005;
int ans=0;

int parent[MAX];
//int rank[MAX];

struct s
{
	int x;
	int y;
	int d;
}e[MAX];
bool cmp(const s &a,const s &b)  //此处借鉴他人
{  
      return b.d > a.d;//降序  
}  
void make_set()
{
	int i;
	for(i=1;i<MAX;i++){
		parent[i]=i;
		//rank[i]=1;
	}
}
int find(int x){
	if(x!=parent[x])
		parent[x]=find(parent[x]);
	return parent[x];
}
int union_set(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
			parent[x]=y;
			return 1;
	}
	return 0;
}
int main()
{
	int m,n;
	int i;

	while(cin>>m && m){
		make_set();
		ans=0;
		n=m*(m-1)/2;
		for(i=1;i<=n;i++){
			cin>>e[i].x>>e[i].y>>e[i].d;
		}
		sort(e+1,e+n+1,cmp);
		/*for(i=1;i<=n;i++){
			cout<<e[i].d<<" ";
		}
		cout<<endl;*/
		for(i=1;i<=n;i++){
			if(union_set(e[i].x,e[i].y))
				ans+=e[i].d;
		}
		cout<<ans<<endl;
	}
}