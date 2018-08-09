/*
最短路 (Floyd)
http://acm.hdu.edu.cn/showproblem.php?pid=2544
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


const int MAX=105;
int d[MAX][MAX];
int m,road;
int a,b,c;
int i,j,k;

int main()
{
	while(cin>>m>>road && (m || road)){
		for( i=0; i<MAX; i++)  
            		for( j=0; j<MAX; j++) d[i][j] = 3000000;
        	//for( i=0; i<MAX; i++) d[i][i] = 0;   	

		for(i=1;i<=road;++i){
			scanf("%d%d%d", &a, &b,&c);  
			if(d[a][b]>c)d[a][b]=d[b][a]=c;//注意这个if条件
		}
		for(k=1;k<=m;++k){        
			for(i=1;i<=m;++i){
				for(j=1;j<=m;++j){
					if(d[i][k]+d[k][j]<d[i][j])
						d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
		cout<<d[1][m]<<endl;

	}
	return 0;
}