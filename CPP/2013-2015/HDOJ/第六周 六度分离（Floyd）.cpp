/*
六度分离  （Floyd）
http://acm.hdu.edu.cn/showproblem.php?pid=1869

六度分离:每两个人，只用6个人就可以将他们联系在一起
输入数据，判断是否符合六度分离

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
/*SP_Floyd( G )                                  //求每对节点的最短距离
 for i=1 to n do
    for j=1 to n do
      dis[i,j] = len[i][j];                   // 初始化边界条件

for k=1 to n do                                 //K放在最外层，数组少一维
   for i=1 to n do
      for j=1 to n do
        if( dis[i,k]+dis[k][j]<dis[i,j])        //状态转移
            dis[i,j] = dis[i][k]+dis[k][j];     
*/  
using namespace std; 

const int MAX=150;
int d[MAX][MAX];
bool flag=true;
int m,n;
int a,b;
int i,j,k;

int main()
{
	while(cin>>m>>n){
		for( i=0; i<MAX; i++)  
            		for( j=0; j<MAX; j++) d[i][j] = 3000000;
        	for( i=0; i<MAX; i++) d[i][i] = 0;   	
		flag=true;
		for(i=1;i<=n;++i){
			scanf("%d%d", &a, &b);  
			d[a][b]=d[b][a]=1;
		}
		for(k=0;k<m;++k){          //注意此处是总人数m，不是n
			for(i=0;i<m;++i){
				for(j=0;j<m;++j){
					if(d[i][k]+d[k][j]<d[i][j])
						d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
		for(i=0;i<m;++i){
			for(j=0;j<m;++j)
				if(d[i][j]>7){
					flag=false;
					break;
				}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;

	}
	return 0;
}