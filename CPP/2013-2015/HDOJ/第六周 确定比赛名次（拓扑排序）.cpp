/*
确定比赛名次
http://acm.hdu.edu.cn/showproblem.php?pid=1285
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

int map[505][505];
int indegree[505];
int ans[505];


void topological(int n)
{
    for(int i=1; i<=n; i++)
    {
        int j = 1 ;
        while(indegree[j])//find indegree==0
        j++ ;
        ans[i] = j ;
        indegree[j] = -1 ;
        for(int k=1; k<=n; k++)
        {
            if(map[j][k])
            indegree[k]-- ;
        }
    }

}
int main()
{
	int n,m;
	int a,b;
	int i,j,k;
	
	while(cin>>n>>m)
	{
		memset(map,0,sizeof(map));
		memset(indegree,0,sizeof(indegree));

		for(i=1;i<=m;i++){
			cin>>a>>b;
			
			if(!map[a][b]) //!
				indegree[b]++;

			map[a][b]=1;
		}
		topological(n);

		for(i=1;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<ans[n]<<endl;
	}

}
